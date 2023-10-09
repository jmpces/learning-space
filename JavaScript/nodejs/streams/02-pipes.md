## Pipes

Sometimes, you need to read data from a stream simply to turn around and write that same data to another stream.

-----

Imagine, for example, that you are writing a simple HTTP server that serves a directory of static files. In this case, you will need to read data from a file input stream and write it out to a network socket. But instead of writing your own code to handle the reading and writing, you can instead simply connect the two sockets together as a “pipe” and let Node handle the complexities for you. Simply pass the Writable stream to the pipe() method of the Readable stream:

```javascript
const fs = require('fs');

function pipeFileToSocket(filename, socket) {
    fs.createReadStream(filename).pipe(socket);
}

// pipes one stream to another and invokes a callback
// when done or when an error occurs
function pipe(readable, writeable, callback) {
    
    // First, setup an error handling function
    function handleError(err) {
        readable.close();
        writable.close();
        callback(err);
    }

    // Next define the pipe and handle the normal termination
    readable
        .on('error', handleError)
        .pipe(writable)
        .on('error',handleError)
        .on('finish',callback);
}

// a function that compresses a file
const zlib = require('zlib');

function gzip(filename, callback) {
    // Create the streams
    let source = fs.createWriteStream(filename);
    let destination = fs.createWriteStream(filename + '.gz');
    let gzipper = zlib.createGzip();

    // Setup the pipeline
    source
        .on('error',callback) // call callback on read error
        .pipe(gzipper)
        .pipe(destination)
        .on('error',callback) // call callback on write error
        .on('finish', callback); // call callback when writing is complete
}
```