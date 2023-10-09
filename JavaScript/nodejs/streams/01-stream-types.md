## Stream Types

Node supports four basic stream types;

- **Readable** --> sources of data :
    - The stream returned by **```fs.createReadStream()```**, for example, is a stream from which the content of a specified file can be read.
    - **```process.stdin```** is another Readable stream that returns data from standard input.

<br>

- **Writable** --> destinations for data :
    - The return value of **```fs.createWriteStream()```**, for example, is a Writable stream: it allows data to be written to it in chunks, and outputs all of that data to a specified file.

<br>

- **Duplex** --> combination of readable and writable streams.
    - The Socket objects returned by **```net.connect()```** and other Node networking APIs, for example, are Duplex streams.
        - If you _write_ to a socket, your data is sent across the network to whatever computer the socket is connected to.
        - If you _read_ from a socket, you access the data written by that other computer.

<br>

- **Transform** --> also writable and readable, but the data written to it becomes readable usually in some transformed from from the same stream.
    - The **```zlib.createGzip()```** function, for example, returns a Transform stream that compresses (with the gzip algorithm) the data written to it.
    - In a similar way, the **```crypto.createCipheriv()```** function returns a Transform stream that encrypts or decrypts data that is written to it.

-----

### By default, streams read and write buffers.

- If you call the **```setEncoding()```** method of a Readable stream, it will return decoded strings to you instead of Buffer objects.
- And if you write a string to a Writable buffer, it will be automatically encoded using the buffer’s default encoding or whatever encoding you specify.

Node’s
stream API also supports an “object mode” where streams read and
write objects more complex than buffers and strings. None of Node’s
core APIs use this object mode, but you may encounter it in other
libraries.
