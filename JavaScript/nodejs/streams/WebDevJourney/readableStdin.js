// process.stdin is an example of a non-flowing stream, meaning the
// stream_buffers or chunk of data is not read continuously and
// it has a behaviour of waiting for a certain condition before
// reading the next stream buffer or chunk of data.

process.stdin.on('data', (stream_buffer) => {
    let input_buffer = stream_buffer.toString().trim();

    console.log('\nYour input :',input_buffer);
});