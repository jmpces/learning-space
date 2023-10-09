let numbers = [5,10,15,20];
let sum = 0;

/* ------ FOREACH ------ */

// shorthand
numbers.forEach(integer => sum+=integer);

// equivalent to the code above, same as short hand, use for multi-line functions cases
// numbers.forEach((integer) => {
//   sum+=integer;
// });

console.log('sum using forEach = ',sum);


/* ------ REDUCE ------ */
let FirstArgumentValue = 0;

console.log('sum using reduce  = ',numbers.reduce(
  // fist argument of reduce : a function
  (FirstArgument,ArrayElement) => {
    return FirstArgument + ArrayElement;
  },
  // second argument of reduce : initial value of first argument
  FirstArgumentValue
));

// short hand
// console.log('sum using reduce  = ',numbers.reduce((FirstArgument,arrayElement) => FirstArgument + arrayElement,FirstArgumentValue));

/* ------ FLAT ------ */
// flattening arrays on a certain index
let a = [1, [2, [3, [4]]]];
a.flat(1) // => [1, 2, [3, [4]]]
a.flat(2) // => [1, 2, 3, [4]]
a.flat(3) // => [1, 2, 3, 4]
a.flat(4) // => [1, 2, 3, 4]
 
/* ------ MAP ------ */
let odd = [1,3,5,7,9,11,13,15];
let even = odd.map(n => ++n);
console.log('odd  = ',odd);
console.log('even = ',even);



