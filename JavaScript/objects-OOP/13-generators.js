/* We can also make an iterable object using Generators

A kind of iteratir defined with powerful new ES6 syntax;

it's particularly useful when the values to be iterated
are not the elements of a data structure, but the result
of a computation

To **Create** a generator, we must first defined a 'generator function'
a 'generator function' is syntactically like a regular JavaScript
function but is defined with the keyword 'function *' rather than
just 'fuction' se the '*'

**Invoking**  a generator function does not actually execute the function
body, but instead returns a generator object, and this generator object is
an iterator, calling its next() method causes the body of the generator
function to run from the start until it reaches a 'yield' statement.

'yield' statement is new in ES6 and it is like the 'return' statement,
the value of the yield statement becomes the value returned by the next()
call on the iterator*/

// Sample 1
function* oneDigitPrimes(){
  yield 2;
  yield 3;
  yield 5;
  yield 7;
}

let primes = oneDigitPrimes();

console.log(primes.next().value);
console.log(primes.next().value);
console.log(primes.next().value);
console.log(primes.next().value);
console.log(primes.next().done);

// Sample 2
const seq = function*(from,to){
  for(let i=from; i<=to; ++i)
    yield i;
}

console.log([...seq(3,6)]);

// Sample 3
let obj = {
  x:1, y:2, z:3,
  *foo(){
    for(let key of Object.keys(this)){
      yield key;
    }
  }
};

console.log([...obj.foo()]);

class Range{
  constructor(from,to){
    this.from = from;
    this.to = to;
  }

  has(x) { return typeof x === "number" && this.from <= x && x <= this.to; }

  toString() { return `x | ${this.from} <= x <= ${this.to}`; }

  // a much shorter way to make an object iterable,
  // see '12-iterable-objects.js at line 10,
  // this is the same exact iterator method but shorter
  *[Symbol.iterator](){
    for(let x = Math.ceil(this.from); x <= this.to; ++x) yield x;
  }
}
for(let x of new Range(1,10)){
  console.log(x);
}
console.log([...new Range(-2,2)]);

// when the 'next()' method of a generator is invoked, the generator
// function runs until it reach a 'yield' expression.
// The expression that follows the 'yield' keyword is evaluated, and that values
// becomes the return value of the 'next()' invocation
// At this point, the generator function stops executing right in the middle of evaluating the 'yield' expression
// then continue again for the next invocation of next()