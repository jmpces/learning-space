'use strict'
let test = {};

Object.defineProperty(test,'msg',{
  writable: true,
  enumerable: true,
  configurable: true,
  value : 5
});

Object.defineProperty(test,'concept',{
  writable: true,
  enumerable: true,
  configurable: false,
  value : 7
});

Object.defineProperty(test, 'concept', { writable: false } );

console.log('test =',);

console.log('\ntest property attributes =',Object.getOwnPropertyDescriptors(test));

