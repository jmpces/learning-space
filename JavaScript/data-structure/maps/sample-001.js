let m = new Map();
 // Create a new, empty map

let n = new Map([
 // A new map initialized with string keys mapped to numbers
  ["one", 1],
  ["two", 2]
]);

console.log(m);
console.log(n);



let copy = new Map(n); // A new map with the same keys and values as map n
let o = { x: 1, y: 2}; // An object with two properties
let p = new Map(Object.entries(o)); // Same as new map([["x", 1], ["y", 2]])

console.log(copy);
console.log(p);