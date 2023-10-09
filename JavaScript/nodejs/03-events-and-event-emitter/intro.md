## Events and EventEmitter

As described, all of Node’s APIs are asynchronous by default.

For many of them, this asynchrony takes the form of two-argument _**error-first** callbacks_ that are invoked when the requested operation is complete.

```javascript
foo('param',(error,value) => {
    // error-first callback
    // takes a callback that has
    // error as it's _first argument
    // then the value argument
});
```

-----

But some of the more complicated APIs are **event-based** instead.

This is typically the case when the API is _designed_ around an **object** rather than a function, or when a _callback function_ needs to be **invoked multiple times**, or when there are **multiple types** of _callback functions_ that may be required.

-----

Consider the ```net.Server``` class, for example:
- an object of this type is a server socket that is used to accept incoming connections from clients.
- It emits a “listening” event when it first starts listening for connections.
- a “connection” event every time a client connects.
- and a “close” event when it has been closed and is no longer listening.

-----

In Node, **objects** that **emit events** are _instances_ of ```EventEmitter``` or a **subclass** of ```EventEmitter```:

[Example](./event-emmiter.js) :
```javascript
const EventEmitter = require("events"); // Module name does not match class name

const net = require("net");

let server = new net.Server(); // create a Server object

console.log(server instanceof EventEmitter); // => true: Servers are EventEmitters
```

-----

- The main feature of EventEmitters is that they allow you to register event handler functions with the on() method.

- EventEmitters can emit multiple types of events, and event types are identified by name.

- To register an event handler, call the on() method, passing the name of the event type and the function that should be invoked when an event of that type occurs.

- EventEmitters can invoke handler functions with any number of arguments, and you need to read the documentation for a specific kind of event from a specific EventEmitter to know what arguments you should expect to be passed:

```javascript
const net = require('net');
let server = new net.Server();
server.on('connection', socket => {
    socket.end('Hello world','utf8');
});
```