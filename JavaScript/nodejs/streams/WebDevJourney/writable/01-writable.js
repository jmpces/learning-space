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

  /* THE PROBLEM WITH THIS APPROACH
  
  excessive calls to write() without allowing the buffer to drain
  will cause high memory usage (will generate high RSS value),
  poor garbage collector performance, and could even cause Node.js
  to crash with an Allocation failed - JavaScript heap out of memory error.

  While calling .write() on a stream that is not draining is allowed,
  Node.js will buffer all written chunks until maximum memory usage occurs,
  at which point it will abort unconditionally.
  
  We solve this issue in 02-writable-handles-backperssure.js*/

  writeStream.write(chunk);
});

readStream.on('error', (err) => {
  console.log('\n\nAn error occured:');
  console.error(err);
});

readStream.on('end', () => {
  writeStream.end();
});

writeStream.on('close', ()=> {
  let end = performance.now();
  console.log('Writable Copy Done!',(end-start)/1000,'seconds');
});

process.on('exit', ()=> {
  DisplayMemoryStatus();
});