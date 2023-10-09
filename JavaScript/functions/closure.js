/*
JavaScript uses lexical
scoping. This means that functions are executed using the variable
scope that was in effect when they were defined, not the variable scope
that is in effect when they are invoked

closures: they capture the local variable (and parameter) bindings of the
outer function within which they are defined.
*/

let uniqueInteger = (function() { // Define and invoke
  let counter = 0;
  
  // Private state of function below
  return function() { return counter++; };
}());

let foo = function(){
  let cnt = 0;

  return function() { return cnt++; };
}();

console.log(uniqueInteger()); // => 0
console.log(uniqueInteger()); // => 1
console.log(uniqueInteger());


/* My Example */

let CounterFunction = function(Name){
  let cnt = 0;
  return function() { return `${Name} : ${cnt++}`; };
}

// when we invoke the CounterFunction(), it returns and binds the
// defenition of the local function inside it to a variable.
// each invokation of the CounterFunction() creates it's own
// internal state, those state is then assigned to the counterN function.
// each state captures all of the local variables inside the CounterFunction()
// invokation

let counter1 = CounterFunction("counter 1");
let counter2 = CounterFunction("counter 2");

// now when we invoke the counter1 or counter2 functions we are actually invoking
// the local function defined in the separted invokations of the CounterFunction()

// the local function defined in it creates a closure around the local variables
// of the CounterFunction and that local variable is binded to the local function,
// that is the one that is being accessed by the binded counterN functions,
// making a pesudo property or class like behaviour where the cnt variable is like a member
// or property of the counterN functions

console.log(counter1());
console.log(counter2());
console.log(counter2());
console.log(counter1());

console.log(counter1());
console.log(counter1());
console.log(counter2());