let foo1 = function(param){
  console.log(':',param);
}

let foo2; // undefined

function wrapper(param1,foo){
  foo?.(param1);
}

let HasValue = 7845;

wrapper(HasValue,foo1); // will call foo reference to the foo1 function inside
wrapper(HasValue,foo2); // will not call the foo function because it is undefined
wrapper(HasValue,foo3); // will throw an error because foo3 is not declared