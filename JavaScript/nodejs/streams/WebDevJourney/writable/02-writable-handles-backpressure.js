function DisplayMemoryStatus(){
  let report = process.memoryUsage();
  console.log('RSS       :',(report.rss/1024)/1024, 'MiB');
  console.log('HeapTotal :',(report.heapTotal/1024)/1024, 'MiB');
  console.log('HeapUsed  :',(report.heapUsed/1024)/1024, 'MiB');
  console.log('external  :',(report.external/1024)/1024, 'MiB');
  console.log('ArrayBuffers  :',(report.arrayBuffers/1024)/1024, 'MiB');
}

const fs = require('fs');

let readStream = fs.createReadStream('./jojo.mp4');
let writeStream = fs.createWriteStream('./copy.mp4');

let start;

readStream.on('open',()=>{
  start = performance.now();
});

readStream.on('data', (chunk) => {

  // hear we solve the issue in 01-writable.js
  let lessthanHighWaterMark = writeStream.write(chunk);

  /* we check if the internal buffer is less than the highWaterMark
  if it's not then we stop the reading of data, this will cause this
  callback data event handler to not run, so the .write() will stop
  for a moment until drain. */

  if(!lessthanHighWaterMark)
    readStream.pause();
});

readStream.on('error', (err) => {
  console.log('\n\nAn error occured:');
  console.error(err);
});

readStream.on('end', () => {
  writeStream.end();
});

writeStream.on('drain', ()=> {
  /* when the internal buffer is emptied (drained), we resume reading
  the readStream again and this will cause the callback data event handler
  to run again enabling the .write() inside it. */
  readStream.resume();
});

writeStream.on('close', ()=> {
  let end = performance.now();
  console.log('Backpressure Copy Done!',(end-start)/1000,'seconds');
});

process.on('exit', ()=> {
  DisplayMemoryStatus();
});