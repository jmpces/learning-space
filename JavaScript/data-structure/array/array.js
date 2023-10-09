function println(){
  console.log('-----------------------------------------------------------');
}

//====================================================
//  Arrays in Javascript
//====================================================

let listOfNumbers = [3,5,7,11,13];

console.log(listOfNumbers[2]);
console.log(listOfNumbers[0]);
console.log(listOfNumbers[2-1]);
println();

/* ====================================================
  Arrays can contain anything
    - it can have different datatypes and yes you can store functions in an array along with other basic datatypes
*/

// this array contains all sorts of different types
let arrayFoos = [
  75,
  "A string",
  0.54,
  (params='default_val') =>{
    console.log(`Function Param : ${params}`);
    console.log('I am an array element that is also a function w/ one parameter and returns the number 1')
    return 1;
  },
  () => "An array element that is also a function that returns this string message"
];

// we can also add a function in an array
arrayFoos.push((x=0) => x*x);

for(let i=0; i<arrayFoos.length; ++i){
  console.log('=============================');
  console.log(arrayFoos[i]);
  console.log(`arrayFoos[${i}] = ${arrayFoos[i]}`);
  if(i>2){
    console.log(`arrayFoos[${i}]() = ${arrayFoos[i]()}`);
  }
}

console.log('\n2nd Power of 7 = '+arrayFoos[5](7));
println();

// arrays that have objects
let journal = [
  { events: ["Wordl", "Touch"],
    squirrel: false
  },
  { events: ["Lasangnya", "test"],
    squirrel: true
  },
  7
];