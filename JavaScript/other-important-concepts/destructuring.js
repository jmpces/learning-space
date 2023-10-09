/*
  The destructuring assignment syntax is a JavaScript expression
  that makes it possible to unpack values from arrays, or
  properties from objects, into distinct variables.*/

console.log("Destructuring Arrays");
function foo(){
  return [1,2,3,4,5];
}

[a, b, ...rest] = foo();
console.log(a,b,rest);

console.log("\n=======================================================\
\nDestructuring Object Literals");
let {first ,second, ...N} = {first: 10, second: 20, third: 30, fourth: 40};
console.log(first); // 10
console.log(second); // 20
console.log(N); // { c: 30, d: 40 }

console.log("\n=======================================================\
\nDestructuring Object Literals with new Key");
let {four : quatro ,twenty : bente, ...iba} = {four: 4, twenty: 20, thirty: 30, forty: 40};
console.log(quatro); // 4
console.log(bente); // 20
console.log(iba); // { c: 30, d: 40 }

console.log("\n=======================================================\
\nDestructuring function parameters with default values (or no default)");
function drawChart({size = 'big', coords = {x: 0, y: 0}, radius = 25} = {}) {
  console.log(size, coords, radius);
  // do some chart drawing
}

drawChart({
  coords: {x: 18, y: 30},
  radius: 30
});

console.log("\n=======================================================\
\nLooping through object entries with destructuring");
let o = { x: 1, y: 2 }; // The object we'll loop over
for(const [name, value] of Object.entries(o)) {
  console.log(name, value); // Prints "x 1" and "y 2"
}


// Nested Destructuring is allowed
// let [a, [b, c]] = [1, [2,2.5], 3];