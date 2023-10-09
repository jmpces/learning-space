### Readable and Writable streams

1. ```ReadableStream``` and ```WritableStream``` classes and other classes that extends from it are either directly or indirectly derived from ```Stream``` classes.
2. ```Stream``` class are derived from ```EventEmitter``` class. Hench we are able to use the same event driven way... using the ```.on()``` methods.