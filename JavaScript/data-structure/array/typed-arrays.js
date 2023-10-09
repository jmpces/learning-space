/* Type array are like C arrays, they are more low level than javascript arrays
   they can only hold numeric types

          Int8Array()         - signed bytes
          Uint8Array()        - unsigned bytes
          Uint8ClampedArray() - unsigned bytes without rollover
          Int16Array()        - signed 16-bit short integers
          Uint16Array()       - unsigned 16-bit short integers
          Int32Array()        - signed 32-bit integers
          Uint32Array()       - unsigned 32-bit integers
          BigInt64Array()     - signed 64-bit BigInt values (ES2020)
          BigUint64Array()    - unsigned 64-bit BigInt values (ES2020)
          Float32Array()      - 32-bit floating-point value
          Float64Array()      - 64-bit floating-point value: a regular JavaScript number

  Remember that typed arrays have fixed lengths, so the length
  property is read-only, and methods that change the length of the array
  (such as push(), pop(), unshift(), shift(), and splice())
  are not implemented for typed arrays. Methods that alter the contents
  of an array without changing the length (such as sort(),
  reverse(), and fill()) are implemented. Methods like map()
  and slice() that return new arrays return a typed array of the same
  type as the one they are called on. */


/*  Creating Typed Arrays  */
let bytes = new Uint8Array(1024);    // 1024 bytes
let matrix = new Float64Array(9);    // A 3x3 matrix
let point = new Int16Array(3);       // A point in 3D space
let rgba = new Uint8ClampedArray(4); // A 4-byte RGBA pixel value
let sudoku = new Int8Array(81);      // A 9x9 sudoku board

let white = Uint8ClampedArray.of(255, 255, 255, 0); // RGBA opaque white
// let ints = Uint32Array.from(white);  // The same 4 numbers, but as ints

let buffer = new ArrayBuffer(1024*1024);
console.log(buffer.byteLength); // => 1024*1024; one megabyte of memory

let asbytes = new Uint8Array(buffer); // Viewed as bytes
let asints = new Int32Array(buffer); // Viewed as 32-bit signed ints
let lastK = new Uint8Array(buffer, 1023*1024); // Last kilobyte as bytes
let ints2 = new Int32Array(buffer, 1024, 256); // 2nd kilobyte as 256 integers


/* set()

  The set() method takes an array or typed array as its first argument
  and an element offset as its optional second argument, which defaults
  to 0 if left unspecified. If you are copying values from one typed array
  to another, the operation will likely be extremely fast. */

// let bytes = new Uint8Array(1024); // A 1K buffer
let pattern = new Uint8Array([0,1,2,3]); // An array of 4 bytes
bytes.set(pattern); // Copy them to the start of another byte array
bytes.set(pattern, 4); // Copy them again at a different offset
bytes.set([0,1,2,3], 8); // Or just copy values direct from a regular array
bytes.slice(0, 12) // => new Uint8Array([0,1,2,3,0,1,2,3,0,1,2,3])


/* subarray()

  takes the same arguments as the slice() method and
  seems to work the same way. But there is an important difference.
  slice() returns the specified elements in a new, independent typed
  array that does not share memory with the original array.
  subarray() does not copy any memory; it just returns a new view
  of the same underlying values: */

// Typed arrays also have a subarray method that returns a portion of
// the array on which it is called: 

let ints = new Int16Array([0,1,2,3,4,5,6,7,8,9]); // 10 short integers
let last3 = ints.subarray(ints.length-3, ints.length); // Last 3 of them
console.log(last3[0]); // => 7: this is the same as ints[7]
ints[9] = -1; // Change a value in the original array and...
console.log(last3[2]); // => -1: it also changes in the subarray


/* Endianness

  If the integer 0x00000001 is arranged in memory as 01 00 00 00, then
  we're on a little-endian platform. On a big-endian platform, we'd get
  bytes 00 00 00 01 instead.*/

let littleEndian = new Int8Array(new Int32Array([1]).buffer);
console.log('little endian :',littleEndian[0]===1);


/* DataView

  Assume we have a typed array of bytes of binary data to process. First,
  we create a DataView object so we can flexibly read and write
  values from those bytes

  DataView defines 10 get methods for each of the 10 typed array
  classes (excluding Uint8ClampedArray). They have names like
  getInt16(), getUint32(), getBigInt64(), and
  getFloat64(). The first argument is the byte offset within the
  ArrayBuffer at which the value begins. All of these getter methods,
  other than getInt8() and getUint8(), accept an optional
  boolean value as their second argument. If the second argument is
  omitted or is false, big-endian byte ordering is used. If the second
  argument is true, little-endian ordering is used.*/


let view = new DataView(bytes.buffer,bytes.byteOffset,bytes.byteLength);
let int = view.getInt32(0); // Read big-endian signed int from byte 0
int = view.getInt32(4, false); // Next int is also big-endian
int = view.getUint32(8, true); // Next int is little-endian and unsigned
view.setUint32(8, int, false); // Write it back in big-endian format


/* get methods

  DataView defines 10 get methods for each of the 10 typed array
  classes (excluding Uint8ClampedArray). They have names like
  getInt16(), getUint32(), getBigInt64(), and
  getFloat64(). The first argument is the byte offset within the
  ArrayBuffer at which the value begins. All of these getter methods,
  other than getInt8() and getUint8(), accept an optional
  boolean value as their second argument. If the second argument is
  omitted or is false, big-endian byte ordering is used. If the second
  argument is true, little-endian ordering is used.*/