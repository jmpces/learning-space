console.log(Object.getPrototypeOf({}));
// => Object.prototype

console.log(Object.getPrototypeOf([]));
// => Array.prototype

console.log(Object.getPrototypeOf(()=>{}));
// => Function.prototype