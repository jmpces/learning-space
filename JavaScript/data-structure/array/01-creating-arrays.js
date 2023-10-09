/* array literals */
{
  let empty = [];
  // An array with no elements

  let primes = [2, 3, 5, 7, 11]; // An array with 5 numeric elements

  let misc = [ 1.1, true, "a", ]; // 3 elements of various types + trailing comma

  // arrays containing object literals
  let b = [[1, {x: 1, y: 2}], [2, {x: 3, y: 4}]];

  let count = [1,,3]; // Elements at indexes 0 and 2. No element at index 1

  let undefs = [,,]; // An array with no elements but a length of 2
}

/* spread operators */
{
  let a = [1, 2, 3];
  let b = [0, ...a, 4];
  // b == [0, 1, 2, 3, 4]

  // shallow copy
  let original = [1,2,3];
  let copy = [...original];
  copy[0] = 0; // Modifying the copy does not change the original
  console.log(original[0]);  // => 1

  // string to array :
  //    The spread operator works on any iterable object, and strings are
  //    iteratable so you can use the spread operator to turn strings to array of characters
  let digits = [..."0123456789ABCDEF"];
  console.log(digits); // => ["0","1","2","3","4","5","6","7","8","9","A","B","C","D","E", "F"]

  // string too array but without duplicates
  //    Sets  
  let letters = [..."hello world"];
  letters = [...new Set(letters)]; // => ["h","e","l","o",","w","r","d"]
  console.log(letters);
}

/* using array constructor */
{
  // empty array
  let arr1 = new Array();

  // empty array with length
  let arr2 = new Array(10);

  // array with values
  let arr3 = new Array(5, 4, 3, 2, 1,"testing, testing");

  console.log(arr1);
  console.log(arr2);
  console.log(arr3);

  /* Array() constructor treats multiple arguments as array elements
  but it treats 1 argument as a length, so creating a single element
  array is not possible using Array() constructor.

  Hence in ES6 the Array.of() method is introduce where any arguments
  pass to it will be an array element, making the creation of single
  array element possible. */

  arr1 = Array.of();      // => []; returns empty array with no arguments
  arr2 = Array.of(10);    // => [10]; can create arrays with a single numeric argument
  arr3 = Array.of(1,2,3); // => [1, 2, 3] 

  console.log(arr1);
  console.log(arr2);
  console.log(arr3);


  /* Array.from() - Expects an iterable or array-like object as its first argument and returns
  a new array that contains the elements of that object */

  let truearray = Array.from(arr3);
}