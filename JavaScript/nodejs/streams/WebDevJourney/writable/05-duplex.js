function DisplayMemoryStatus(){
  let report = process.memoryUsage();
  console.log('RSS       :',(report.rss/1024)/1024, 'MiB');
  console.log('HeapTotal :',(report.heapTotal/1024)/1024, 'MiB');
  console.log('HeapUsed  :',(report.heapUsed/1024)/1024, 'MiB');
  console.log('external  :',(report.external/1024)/1024, 'MiB');
  console.log('ArrayBuffers  :',(report.arrayBuffers/1024)/1024, 'MiB');
}

/* ___________ Heirarchy ___________ /
PassThrough -- extends from --> Transform
Transform   -- extends from --> Duplex
Duplex      -- (extends Readable & implements Writable)
Readable    -- extends from --> Stream
Writable    -- extends from --> Stream
Stream      -- extends from --> internal
internal    -- extends from --> EventEmitter */

const stream = require('stream');
const fs = require('fs');

let copy = fs.createWriteStream('./copy.mp4');
let read = fs.createReadStream('./jojo.mp4');

// we create a writable and readable stream
let result = new stream.PassThrough();

read.pipe(result).pipe(copy);

result.on('data', (chunk) => {
  TotalBytes += chunk.length;
});

copy.on('close', ()=>{
  console.log('Total MiB Copied :', (TotalBytes/1024)/1024);
  DisplayMemoryStatus();
});

let TotalBytes = 0;

