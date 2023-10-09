'use strict';
let success = true;

let p = new Promise((resolve)=>{
  console.log('promise created')
  setTimeout(()=>{
    console.log('first delay done');
    resolve('I should be the final message!!!');
  },2000);
});

p
.then((finalMessage)=>{
  console.log('first then');
  let arr = [finalMessage];
  arr.push('I am the Second Message');
  return arr; // the array here is automatically wrapped on a promise.
})
.then((msg)=>{
  console.log('second then');
  msg.push('I am the third Message')
  return msg;
})
.then((display)=>{
  console.log('last then');
  console.log(display);
});