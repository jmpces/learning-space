/*
  The for/of loop works with iterable objects.
  
  arrays, strings, sets, and maps are iterable:
  
    they represent a sequence or set of elements that you can loop
    or iterate through using a for/of loop.
*/

function for_of_arrays(){
  let data = [1, 2, 3, 4, 5, 6, 7, 8, 9];
  let sum = 0;
  for(let element of data){
    sum += element;
  }
  console.log('for_of_arrays =',sum);
  // => 45
}

// INVALID!!! : Objects are not (by default) iterable
function for_of_objects(){
  let o = { x: 1, y: 2, z: 3 };
  for(let element of o) { // Throws TypeError because o is not iterable
    console.log(element);
  }
}

function for_of_objects_keys(){
  let o = { x: 1, y: 2, z: 3 };
  let keys = "";
    for(let k of Object.keys(o)) {
      // changes to the object o made in the loop body
      // will have no effect on the iteration.
      keys += k;
    }
  console.log('for_of_objects_keys =',keys); // => "xyz"
}

function for_of_objects_value(){
  let o = { x: 1, y: 2, z: 3 };
  let sum = 0;
  for(let v of Object.values(o)) {
    sum += v;
  }
  console.log('for_of_objects_value =',sum); // => 6
}

function for_of_objects_key_value(){
  let o = { x: 1, y: 2, z: 3 };
  let pairs = "";
  for(let [k, v] of Object.entries(o)) {
    pairs += k + v;
  }
  console.log('for_of_objects_key_value =',pairs); // => "x1y2z3"
}

function for_of_strings(){
  let frequency = {};
  for(let letter of "mississippi") {
    if (frequency[letter]) {
      frequency[letter]++;
    } else {
      frequency[letter] = 1;
    }
  }
  console.log('for_of_strings =',frequency);
 // => {m: 1, i: 4, s: 4, p: 2}
}

function for_of_set(){
  let text = "Na na na na na na na na Batman!";
  let wordSet = new Set(text.split(" "));
  let unique = [];
  for(let word of wordSet) {
    unique.push(word);
  }
  console.log('for_of_set =', unique); // => ["Na", "na", "Batman!"]
}

function for_of_map(){
  let m = new Map([[1, "one"]]);
  for(let [key, value] of m) {
    console.log('for_of_map = ',key,':',value);   // => 1 : one
  }
}

async function for_of_await(stream) {
  for await (let chunk of stream) {
    console.log(chunk);
  }
}

for_of_await('ASYNC');
for_of_arrays();
// for_of_objects(); // not valid cause objects are not iteratable in general
for_of_objects_keys();
for_of_objects_value();
for_of_objects_key_value();
for_of_set();
for_of_map();

