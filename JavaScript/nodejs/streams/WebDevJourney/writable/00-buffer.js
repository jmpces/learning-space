function DisplayMemoryStatus(){
  let report = process.memoryUsage();
  console.log('RSS       :',(report.rss/1024)/1024, 'MiB');
  console.log('HeapTotal :',(report.heapTotal/1024)/1024, 'MiB');
  console.log('HeapUsed  :',(report.heapUsed/1024)/1024, 'MiB');
  console.log('external  :',(report.external/1024)/1024, 'MiB');
  console.log('ArrayBuffers  :',(report.arrayBuffers/1024)/1024, 'MiB');
}

const fs = require('fs');

let start = performance.now();
fs.readFile('./jojo.mp4', (err, data) => {
  if(err){
    console.error(err);
  }
  else{
    fs.writeFile('./copy.mp4', data, (err)=>{
      let end = performance.now();
      if(err)
        console.log(err);
      else{
        console.log('Buffer Copy done! Took ',(end-start)/1000,'seconds');
      }
    });
  }
});


process.on('exit', ()=> {
  DisplayMemoryStatus();
});