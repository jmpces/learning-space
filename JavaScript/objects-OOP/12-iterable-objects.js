/* In order to make a class iterable: 

  1.) you must implement a method whose name is the Symbol 'Symbol.iterator'

  2.) That method must return an iterator object that has a 'next()' method.

  3.) And that next() method must return an iteration result object that has a 'value' property and/or boolean 'done' property
*/

class Range{
  constructor(from,to){
    this.from = from;
    this.to = to;
  }

  has(x) { return typeof x === "number" && this.from <= x && x <= this.to; }

  toString() { return `x | ${this.from} <= x <= ${this.to}`; }

  [Symbol.iterator](){
    let next = Math.ceil(this.from);
    let last = this.to;
    return {
      next() {
        return (next <= last) ? { value: next++ } : { done: true};
      },
      [Symbol.iterator]() { return this; } // for convinience, could also work without this
    };
  }
}

for(let x of new Range(1,10)){
  console.log(x);
}
console.log([...new Range(-2,2)]);

class Fibonacci{
  constructor(base0, base1, nth=Number.MAX_VALUE){
    this.base0 = base0;
    this.base1 = base1;
    this.nth = nth;
  }

  [Symbol.iterator](){

    let b0 = this.base0;
    let b1 = this.base1;
    let N = this.nth;
    let i = 2;

    return {
      next(){
        let next = b0 + b1;
        b0 = b1;
        b1 = next;
        return (++i <= N) ? { value: next } : { done: true };
      },
      [Symbol.iterator]() { return this; }
    }
  }
}

for(let nthFib of new Fibonacci(2,4,10)){
  console.log('Fib :',nthFib);
}

function map(iterable, f){
  let iterator = iterable[Symbol.iterator]();
  return {
    [Symbol.iterator]() { return this; },
    next() {
      let v = iterator.next();
      if(v.done){
        return v;
      }
      else{
        return { value: f(v.value) };
      }
    }
  }
}

let arr = [1,3,5,7,9];

let squared = map(arr, x => x*x);
console.log(...squared);