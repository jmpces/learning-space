# Streams

When implementing an algorithm to process data, it is almost always
easiest to read all the data into memory, do the processing, and then
write the data out. For example, you could write a Node function to
copy a file like this :

```javascript
const fs = require("fs"); // An asynchronous but non-streaming (and therefore inefficient) function.

function copyFile(sourceFilename, destinationFilename, callback) {
    fs.readFile(sourceFilename, (err, buffer) => {
        if (err)
            callback(err);
        else
            fs.writeFile(destinationFilename, buffer, callback);
    });
}
```

## This function though is inefficient

Even though it uses ```fs.readFile()``` & ```fs.writeFile()``` which is both an **async non-blocking** function... The big problem is when we are reading a very large file (example <= 1GB), this function would allocate the exactyl the same size in memory, that alone is already slow, it might not block the main code flow, but it will block other calls of ```fs.readFile()``` & ```fs.writeFile()```. And it will also possibly slow down the server that has a very limited amount of RAM.

---- 

## Solution

The solution to these problems is to use **streaming algorithms** where
data “flows” into your program, is processed, and then flows out of
your program.

The idea is that your algorithm processes the data in
small chunks and the full dataset is never held in memory at once.

```javascript
const fs = require("fs");

// A streaming file copy function, using "flowing mode".
// Copies the contents of the named source file to the named destination file.
// On success, invokes the callback with a null argument. On error,
// invokes the callback with an Error object.

function copyFile(sourceFilename, destinationFilename, callback) {
    let input = fs.createReadStream(sourceFilename);
    let output = fs.createWriteStream(destinationFilename);

    input.on("data", (chunk) => {          // When we get new data,
        let hasRoom = output.write(chunk); // write it to the output stream.
        if (!hasRoom)           // If the output stream is full
            input.pause();      // then pause the input stream.
    });

    input.on("end", () => {     // When we reach the end of input,
        output.end();           // tell the output stream to end.
    });

    input.on("error", err => {  // If we get an error on the input,
        callback(err);          // call the callback with the error
        process.exit();         // and quit.
    });

    output.on("drain", () => {  // When the output is no longer full
        input.resume();         // resume data events on the input
    });

    output.on("error", err => { // If we get an error on the output,
        callback(err);          // call the callback with the error
        process.exit();
    });

    output.on("finish", () => { // When output is fully written
        callback(null);         // call the callback with no error.
    });
}

// Here's a simple command-line utility to copy files
let from = process.argv[2], to = process.argv[3];

console.log(`Copying file ${from} to ${to}...`);

copyFile(from, to, err => {
    if (err)
        console.error(err);
    else
        console.log("done.");
});

```