/* the spread operator (...) can be used to create a new
object where it contains the properties of
two object literals

spread operator only spread the OWN properties fo an object not the INHERITED ones
*/

let integers = { even:[2,4,6,8], odd:[1,3,5,7] };
let irrational = { pi : 3.14159, phi : 1.618 };
let reference = irrational;

let numbers = {...integers, ...irrational}; // copies the properties of integers and irrational

console.log('-----------------------------------');
console.log('integers   = ',integers);
console.log('irrational = ',irrational);
console.log('numbers    = ',numbers);

delete irrational['pi'];

console.log('-----------------------------------');
console.log('integers   = ',integers);
console.log('irrational = ',irrational);
console.log('numbers    = ',numbers);
