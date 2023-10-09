// foo1();  // calling this function here will throw an error
foo2();
// foo3();  // calling this function here will throw an error
// foo4();  // calling this function here will throw an error
// foo5();  // calling this function here will throw an error
// foo6();  // calling this function here will throw an error

// basic function binding
const foo1 = function(){
  console.log("foo1");
}

// global function binding, this function is automatically added to the global scope at compile time
function foo2(){
  console.log("foo2");
}

// arrow functions - this is a shorthand for the basic function binding
//                   instead of using the function key word it uses ()=> which is much shorted
//                   other than that everything is still the same.
const foo3 = ()=>{
  console.log("foo3");
}

// if the arrow function has only one line of code the currly braces can be ommited
const foo4 = () => console.log("foo4"); // or // const foo4 = x => console.log("foo4"); // <- x is a parameter

{// inner scope
  const foo5 = function(){
    console.log("foo5");
  }
  // after going out of scope the foo5 binding will be destroyed
  // so using or calling the foo5 function after this will throw an error
  // because there will be no foo5 function
}

{// inner scope global function binding
  function foo6(){
    console.log("foo6");
  }
  // after going out of scope the foo6 binding will NOT be destroyed and will be
  // available in the global scope, though since this function is binded inside a
  // scope the scope is executed at runtime so the function foo6 will not be available
  // when the scope is not executed at runtime.
}

console.log("--------\n");

foo1();
foo2();
foo3();
foo4();
// foo5(); // calling this function here will throw an error
foo6();