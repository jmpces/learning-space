// OBJECT LITERALS

/* 
  Objects are basically maps in JavaScript but thay are dynamic typed maps,
  it is also the same for arrays in JavaScript
  they are basically hash tables and does not occupy a continuous block in the memory
  despite the name array 
*/

let constants = {
  pi  : 3.14159,
  phi : 1.61803,
  "Key with Space" : "value in string" // an object property with a complicated key name
}

// accessing object properties in two different ways
console.log(constants.pi);
console.log(constants["pi"]);

// accessing object properties that has a complicated key name,
// since they cannot be accessed using the `.` operator we enclose them in qotes, double qotes or back ticks instead
console.log(constants[`Key with Space`]);
// we use the double or single qotes to access a specific key that is named unconventionally