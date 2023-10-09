const http = require('http');
const fs   = require('fs');
const stream = require('stream');

const PORT = 3000;
const filename = 'jojo.mp4';
/* raw version */
// http.createServer((req,res) => {
//   res.writeHead(200, {
//     'Content-Type': 'video/mp4'
//   });

//   fs.createReadStream(filename).
//     pipe(res);

// }).listen(PORT, ()=> console.log('server running on port'+PORT+'...'));

/* improved version */
// http.createServer(async (req,res) => {
//   const {size} = await fs.promises.stat(filename);
  
//   res.writeHead(200, {
    
//     // tells the browser the size of file, this will let them know how
//     // much they need to show in the advance loaded buffer in the video
//     'Content-Length': size,
    
//     'Content-Type': 'video/mp4'
//   });

//   console.log(size);

//   fs.createReadStream(filename).
//     pipe(res);

// }).listen(PORT, ()=> console.log('server running on port'+PORT+'...'));

/* With Range Request*/
http.createServer(async (req,res) => {
  const { size } = await fs.promises.stat(filename);
  const range = req.headers.range;

  if(range) {
    let [start, end] = range.replace(/bytes=/,'').split('-');
    start = parseInt(start, 10);
    end = end ? parseInt(end, 10) : size-1;

    console.log(`start:end = ${start}:${end}`);

    res.writeHead(206, {
      'Content-Range': `bytes ${start}-${end}/${size}`,
      'Accept-Ranges': 'bytes',
      'Content-Length': (start-end) + 1,
      'Content-Type': 'video/mp4'
    });

    fs.createReadStream(filename, {start,end}).pipe(res);
  }
  else {
    res.writeHead(200, {
      'Content-Length': size,
      'Content-Type': 'video/mp4'
    });
    fs.createReadStream(filename).pipe(res);
  }

}).listen(PORT, ()=> console.log('server running on port '+PORT+'...'));