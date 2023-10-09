let fs = require('fs');
let http = require('http');
let file = './jojo.mp4';

http.createServer((req, res) => {

  fs.readFile(file, (error, data) => {
    if(error)
      console.error(error);
    
      res.writeHeader(200, { 'Content-Type': 'video/mp4' });
      res.end(data);
  });

}).listen(3000, () => console.log('stream - http://localhost:3000'));

// node --trace_gc ./buffer.js

/* If the video is too big, it will flood the memory of the server
if there are many clients playing the video one at a time */