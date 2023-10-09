let fs = require('fs');
let http = require('http');
let file = './jojo.mp4';

http.createServer((req, res) => {

  res.writeHeader(200, { 'Content-Type': 'video/mp4' });
  fs.createReadStream(file)
    .pipe(res)
    .on('error', console.error);

}).listen(3000, () => console.log('stream - http://localhost:3000'));

// node --trace_gc ./stream.js

/* More efficient than buffer, will not flood the memory of the server */