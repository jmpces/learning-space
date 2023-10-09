/*  Iterable Objects - the contents of these data sctructures
    can be iterared -- looped over with the for/of loop,
    
    Arrays, TypedArrays, Strings, Set and Map objects */

function SeparatorDisplay(number){
  console.log('\n==================',number,'==================');
}

SeparatorDisplay(1);
let sum = 0;
for(let i of [1,3,5]){
  sum += i;
}
console.log('sum = ',sum);

// 1.) Iterators can be use with the (...) operator to expand or "Spread"
// an iterable object into an array initializer of function invocation

// 1.A) to expand or "Spread" an iterable object into an array initializer
SeparatorDisplay(1.1);
let vowels = [..."aeiou"];
console.log('vowels :',vowels);

// 1.B) to spread elements as paremeters in function invocation
SeparatorDisplay(1.2);
let integers = [0,8,-2,4,-5,6,-7,1,-9];
let MaxOfFirstThreeElements = function(first,second,third){
  if(first>second && first>third)
    return first;
  else if(second > third)
    return second;
  else
    return third;
}
console.log('Max = ',MaxOfFirstThreeElements(...integers));

// 2.) Iterators can also be used with destructuring assignment
SeparatorDisplay(2.1);
let pixel = Uint8Array.of(128,64,32,8);
let [r,g,b,a] = pixel;
console.log(`r = ${r}\ng = ${g}\nb = ${b}\na = ${a}`);

SeparatorDisplay(2.2);
let StopLight = { red : 0, yellow : 1, green : 3};
let {red : first, yellow : second, green : third} = StopLight;
console.log('red : ',first,'\tblue : ',second,'\tgreen : ',third);

// 3. Iterable Maps or KeyValue Pair Objects returns [key,value] pair
//    which works well with destructuring assignment in a for/of loop
SeparatorDisplay(3);
let RomanNumeral = new Map([["I",1],["II",2],["III",3],["IV",4],["V",5]]);
// Here's how you add element to a map
// RomanNumeral.set("I",1);
// RomanNumeral.set("II",2);
// RomanNumeral.set("III",3);
// RomanNumeral.set("IV",4);
// RomanNumeral.set("V",5);
// this will produce the same map with the initialized version using 2d array
console.log(RomanNumeral);

for(let [k,v] of RomanNumeral){
  console.log(`${k} = ${v}`);
}
// for(let k of RomanNumeral.keys()) console.log(k);   // keys only
// for(let v of RomanNumeral.values()) console.log(v); // values only

/* 4.) To understand how iterable object works, first we
       need to know about these 3 key concepts

        4.1) Iterable Objects - any object with a special iteratir method that returns an iterator object
        4.2) Iterator - any object with a next() method that returns an iteration result object
        4.3) Iteration Result Objects - an object with properties named 'value' and 'done'

      a.) To iterate an iterable object, you first call its iterator method to get an iterator object.
      b.) Then you call the next() method of the iterator object repeatedly until the returned value
          has its 'done' property set to 'true'

    NOTE: Iterator method of an iterable objects does not have a conventional name but uses the Symbol
          'Symbol.iterator' as its name
*/

// writing iterator the hard way
SeparatorDisplay(4);
let iterable = [1,3,5,7,9];
let iterator =  iterable[Symbol.iterator]();
for(let result = iterator.next(); !result.done; result = iterator.next()){
  console.log(result.value);
}

// iterating through partially used iterators
SeparatorDisplay(4.5);
let list = [1,2,3,4,5];
let iter = list[Symbol.iterator]();
let front = iter.next().value;
let remain = [...iter]
console.log('front : ',front);
console.log('remain  : ',remain);