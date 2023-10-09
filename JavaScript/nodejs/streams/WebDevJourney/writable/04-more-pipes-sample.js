const fs = require('fs');

const writeStream = fs.createWriteStream('./written.txt');

// read stream from stdinput the pipe write it to the written.txt using writeStream
process.stdin.pipe(writeStream);

/* AN INTERSETING SHELL COMMAND

the "|" is a pipe symbol in unix systems that enable passing streams of data to
another program or pipe:

echo "hello world from commandline using pipe" | node 04-more-pipes-sample.js
*/