/*
  The first-defined operator ?? evaluates to its first defined operand: if
  its left operand is not null and not undefined, it returns that value.
  Otherwise, it returns the value of the right operand. */

let a = 5, b, c = 7;

console.log(a ?? b);        // 5
console.log(a ?? c);        // 5
console.log(b ?? c);        // 7

console.log(a ?? b ?? c);   // 5
console.log(a ?? c ?? b);   // 5

console.log(b ?? a ?? c);   // 5
console.log(b ?? c ?? a);   // 7
console.log(b ?? b ?? c);   // 7