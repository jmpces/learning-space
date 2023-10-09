function DisplayMemoryStatus(){
  let report = process.memoryUsage();
  console.log('RSS       :',(report.rss/1024)/1024, 'MiB');
  console.log('HeapTotal :',(report.heapTotal/1024)/1024, 'MiB');
  console.log('HeapUsed  :',(report.heapUsed/1024)/1024, 'MiB');
  console.log('external  :',(report.external/1024)/1024, 'MiB');
  console.log('ArrayBuffers  :',(report.arrayBuffers/1024)/1024, 'MiB');
}

const stream = require('stream');

/* IMPLEMENTING OUR OWN DUPLEX */

class Throttle extends stream.Duplex {
  constructor(delay_ms){
    super();
    this.delay = delay_ms;
  }

  _read(){
    // leave it as is
  }

  _write(chunk, encoding, callback){
    this.push(chunk);
    setTimeout(callback, this.delay);
  }

  _final(){
    this.push(null);
  }
}

let throttle = new Throttle(5);

const fs = require('fs');

let copy = fs.createWriteStream('./copy.mp4');
let read = fs.createReadStream('./jojo.mp4');

let result = new stream.PassThrough();

read.pipe(throttle).pipe(result).pipe(copy);

let TotalBytes = 0;
result.on('data', (chunk) => {
  TotalBytes += chunk.length;
  console.log('copying chunk size of', chunk.length);
});

copy.on('close', ()=>{
  console.log('Total MiB Copied :', (TotalBytes/1024)/1024);
  DisplayMemoryStatus();
});

