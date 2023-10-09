// this is a closure function, a function that
// references bindings from local scopes around it
function wrapValue(n){
  let local = n;
  return () => local;
}

let wrap1 = wrapValue(1);
let wrap2 = wrapValue(2);

console.log(wrap1());
console.log(wrap2());

function multiplier(factor){
  // number is a parameter here not a name, there is no recursion going on
  return number => number * factor;
}

let twice = multiplier(2);
console.log(twice(5));