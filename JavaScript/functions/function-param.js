// ========================================================
//                PARAMETERS WITH DEFAULT VALUE
// ========================================================

const foo = (a,b="I am default B value",c) => {
  console.log('------------------');
  console.log(a);
  console.log(b);
  console.log(c);
}

foo();
foo(2);
foo("test");
foo("what?",3);
foo("take","me",6);
println();

// ========================================================
//                REST PARAMETERS (Vardic Function in C++)
// ========================================================

// use to accept any number of arguments

let getMax = (...numbers) => {
  let result = -Infinity;
  for(let num of numbers) {
    if(num > result) result = num;
  }
  return result;
}

console.log(getMax(-5,2,5,100,-76));
println();



// ======================== END ============================
function println(){
  console.log('-----------------------------------------------------------');
}