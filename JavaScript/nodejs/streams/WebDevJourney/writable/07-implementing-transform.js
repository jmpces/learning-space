const fs = require('stream');

class ReplaceText extends fs.Transform {
  constructor() {
    super();
  }

  _transform(chunk, encoding, callback) {
    let transformChunk = chunk.toString().replace(/a/g,'A');
    transformChunk = transformChunk.replace(/e/g,'E');
    transformChunk = transformChunk.replace(/i/g,'I');
    transformChunk = transformChunk.replace(/o/g,'O');
    transformChunk = transformChunk.replace(/u/g,'U');
    this.push(transformChunk);
    callback();
  }

  _flush(callback) {
    this.push('more stuff is being passed through...');
    callback();
  }
}

const NaNi = new ReplaceText();

process.stdin.pipe(NaNi).pipe(process.stdout);