// Conditional property access with ?. and ?.[]

// -------------------------------------------- //
// * ?.
let a = { b: null };
a.b?.c.d
 // => undefined

// a.b.c;  <=  throw a TypeError

// -------------------------------------------- //
// ?.[]
let a; // Oops, we forgot to initialize this variable!
let index = 0;
try {
  a[index++]; // Throws TypeError
} catch(e) {
  index; // => 1: increment occurs before TypeError is thrown
}
a?.[index++]; // => undefined: because a is undefined
index; // => 1: not incremented because ?.[] short- circuits
a[index++]; // !TypeError: can't index undefined. 