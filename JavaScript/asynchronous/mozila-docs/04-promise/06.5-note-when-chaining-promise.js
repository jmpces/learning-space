function PromiseSetTimeout(cbfn,time){
  return new Promise((resolve,reject)=>{
    setTimeout(()=>{
      cbfn();
      resolve();
    },time);
  });
}

// WARNING NOTE !!!
// notice here that the second PromiseSetTimeout in line 17 did not wait for 5 seconds
// after the first PromiseSetTimeout in line 14 instead he appeared 1 second after the
// output of the first PromiseSetTimeout
PromiseSetTimeout(()=>{
  console.log('wrong chaining : I waited for 5 seconds');
},5000)
.then(PromiseSetTimeout(()=>{
  console.log('wrong chaining : I waited for 6 seconds after');
},6000));

/* this is because the `.then()` method should only accept a callback function,
now you might be wondering isn't it the `PromiseSetTimeout` is also a function?
and should be treated as a callback function by the .then() method?

the answer to that is NO. remember that the PromiseSetTimeout is an asynchronous
function that returns a promise ` look at this example : */

let promise = PromiseSetTimeout(()=>{
  // code
},2000);
// console.log(promise);

/* you see that the value of `let promise` is not a function but instead a
pending promise (output of console.log(promise) in the nextline):

    Promise { <pending> }

if you pass the `PromiseSetTimeout` function directly to .then() method,
the .then() method will not be able to run a callback inside it because
the argument passed to it is not a function but instead an object in
this case a pending promise.

the .then() did not execute the callback (since it's not a function) and
the PromiseSetTimeout was executed right away since now it's just an ordinary invokation

to solve this we want to only pass a callback to .then() so we should wrap our
`PromiseSetTimeout` inside a callback. see example below :*/

PromiseSetTimeout(()=>{
  console.log('correct chaining : I waited for 5 seconds');
},5000)
.then(()=>{
  PromiseSetTimeout(()=>{
    console.log('correct chaining : I waited for 6 seconds after');
  },6000);
});