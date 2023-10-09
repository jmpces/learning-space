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

/* A BUILT IN BETTER APPROACH

We can avoid all the hassle we did in 02-writable-handles-backpressure.js
and use a built in method to handle backpressure. */

readStream.pipe(writeStream).on('error', console.error);

writeStream.on('close', ()=> {
  let end = performance.now();
  console.log('Pipe Copy Done!',(end-start)/1000,'seconds');
});

process.on('exit', ()=> {
  DisplayMemoryStatus();
});