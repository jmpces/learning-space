## Buffers

A Buffer is a lot like a string, except that it is a sequence of bytes instead of a sequence of characters.

-----

Node was created before core JavaScript supported typed arrays and there was no Uint8Array to represent an array of unsigned bytes.

Node defined the Buffer class to fill that need. Now that Uint8Array is part of the JavaScript language, Node’s Buffer class is a subclass of Uint8Array. 

-----

### Designed to interoperate with JavaScript strings:
- bytes in a buffer can be initialized from character strings.
- a buffer can be converted to character strings.