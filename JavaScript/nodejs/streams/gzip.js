const fs = require('fs');
const zlib = require('zlib');

function gzip(filename, callback) {
  // Create the streams
  let source = fs.createReadStream(filename);
  let destination = fs.createWriteStream(filename + '.gz');
  let gzipper = zlib.createGzip();

  // Setup the pipe
  source
    .on('error', callback)
    .pipe(gzipper)
    .pipe(destination)
    .on('error', callback)
    .on('finish', callback);
}

function gunzip(filename, SuccessCallback, ErrorCallback){
  let source = fs.createReadStream(filename);
  let destination = fs.createWriteStream(filename.replace('.gz',''));
  let gunzipper = zlib.createGunzip();

  source
    .on('error', ErrorCallback)
    .pipe(gunzipper)
    .pipe(destination)
    .on('error', ErrorCallback)
    .on('finish', SuccessCallback);
}

// gzip('./text.txt', (err)=>{
//   if(err){
//     console.log('an error occur');
//     console.error(err);
//   }
//   else{
//     console.log('success');
//   }
// })


gunzip('text.txt.gz',()=>{
  console.log('successfuly unziped the file');
},(err) => {
  console.log('\nError: gunzip');
  if(err.errno === -2){
    console.log(`\t"${err.path}" was not found`);
  }
});
