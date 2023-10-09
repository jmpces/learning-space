let buffer = Buffer.from([0x41,0x42,0x43]); // 65, 66, 67

// in hex the 4 most significant bit is the first digit
// then the next 4 least significant bit is the second digit
// hex are just `unsigned char` type but the 8 bits is treated
// more like 2 four bits combined, see example below:

// 0x41 -> [4 = 0100] & [1 = 0001] --> 01000001 ---> 65

console.log(buffer);
console.log(buffer.toString());
console.log(buffer.toString('hex'),'\n');

let computer = Buffer.from("IBM3111", "ascii");
console.log(computer);
console.log(computer.toString());
console.log(computer.toString('ascii'),'\n');

// this one is an interesting coincidence
for(let i=0; i<computer.length; ++i){
  computer[i]--;
}
console.log(computer);
console.log(computer.toString());
console.log(computer.toString('ascii'),'\n');

console.log(computer.subarray(0,3).map(x=>x+1).toString(),'\n');

// creates 1024 bytes of data with values 0 or 0x00
let zeros = Buffer.alloc(1024);
console.log(zeros,'\n');

// creates 128 bytes of data with values of 1 or 0x01
let ones = Buffer.alloc(128,1);
console.log(ones,'\n');

// creates 1024 bytes of data that contains repeated values
// 0xde 0xad 0xbe 0xef until to the last bit
// NOTE : each 2 characters of the given string (utf8 default)
// is converted to a hex value 
 let dead = Buffer.alloc(1024, "DEADBEEF", "hex");
console.log(dead,'\n');

console.log(dead.readUInt32BE(0)); // reads 4 bytes by default (the first 4 hex values 0xdeadbeef --> 3735928559)
console.log(dead.readUInt32BE(1)); // start at index 1, then reads 4 bytes. // => 0xADBEEFDE
console.log(dead.readBigUInt64BE(6)); // => 0xBEEFDEADBEEFDEADn
console.log(dead.readUInt32LE(1020)); // => 0xEFBEADDE

// 1100 1101 = 12 13