const EventEmitter = require("events"); // Module name does not match class name

const net = require("net");
const { addListener } = require("process");

let server = new net.Server(); // create a Server object

console.log(server instanceof EventEmitter); // => true: Servers are EventEmitters

server.on('connection', socket => {
    socket.end('Hello world','utf8');
});

process.on('exit',()=>{
  // counter-part for removing === .off('event',cb);
  console.log('added using .on');
});

process.addListener('exit',()=>{
  // counter-part for removing === .removeListener('event',cb);
  console.log('added using .addListener');
});