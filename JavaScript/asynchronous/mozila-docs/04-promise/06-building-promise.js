// Using the Promise() constructor

/* The main situation in which you'll want to do this is
when you've got code based on an old-school asynchronous
API that is not promise-based, which you want to promisify.
This comes in handy when you need to use existing, older
project code, libraries, or frameworks along with modern
promise-based code. */

// my example

function PromiseSetTimeout(cbfn,time){
  return new Promise((resolve,reject)=>{
    setTimeout(()=>{
      cbfn();
      resolve(); // we want this to always resolve so we can chain the promises
    },time);
  });
}

// The above example is not very flexible — it doesn't have any kind of
// reject() condition specified (admittedly, setTimeout() doesn't really
// have a fail condition, so it doesn't matter for this simple example).

PromiseSetTimeout(()=>{
  console.log('I waited for 3 seconds');
},3000)
.then(()=>{
  return PromiseSetTimeout(()=>{
    console.log('I waited for 1 second after');
  },1000);
})
.then(()=>{
  return PromiseSetTimeout(()=>{
    console.log('I waited for 4 seconds after');
  },4000);
})
.then(()=>{
  PromiseSetTimeout(()=>{
    console.log('I waiter for 2 seconds after');
  },2000);
})