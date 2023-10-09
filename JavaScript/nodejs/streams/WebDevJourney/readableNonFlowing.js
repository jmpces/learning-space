const fs = require('fs');

const readStream = fs.createReadStream('./RankingOfKings-Op2.mp4');

readStream.on('data', (stream_buffer) => {
  console.log('stream buffer size:', stream_buffer.length);
});

readStream.on('end', () => {
  console.log('read stream ended');
});

readStream.on('error', (err) => {
  console.log('\n\nan error occur:\n');
  console.error(err);
});

// make the readStream from "flowing mode" to "non-flowing mode"
readStream.pause();

process.stdin.on('data', (stream_buffer) => {

  if(stream_buffer.toString().trim() === 'flowing'){
    // .resume() will bring back the readStream to "flowing mode"
    readStream.resume();
  }
  else if(stream_buffer.toString().trim() === 'exit'){
    console.log('bye-bye!');
    process.exit();
  }

  // in "non-flowing mode" calling the '.read()' will read the next chunk
  readStream.read();
});