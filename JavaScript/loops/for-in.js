/* 
  for-in loops
    
    The for/in statement loops through the PROPERTY names of a
    specified object, NOT the value.

    - variable declarations in for in loop should not have initializers(initial value assign to them)
    - it only loops over the enumerable properties
    
  The for/in loop does not actually enumerate all properties of an
  object. It does not enumerate properties whose names are symbols.
  And of the properties whose names are strings, it only loops over the
  enumerable properties

  All
  properties and methods defined by your code are enumerable, by
  default. (You can make them non-enumerable)

*/

let o = { x: 1, y: 2, z: 3 };
let a = ['e'], i = 0;
// the property names is assigned or added to the index of the array 'a'
for(a[i++] in o) /* empty */;
console.log(a);

// NOTE : for in only read the property name of the object not the value
//        in an array the index are actually it's property names
let odd = [1,3,5,7];
for(let num in odd){
  console.log(`At index ${num} the value is ${odd[num]}`);
}