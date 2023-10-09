const fs = require('fs');

// by default objects created by fs.createReadStream are in flowing mode
// meaning their stream buffer is continously being read by node chunk by chunk

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