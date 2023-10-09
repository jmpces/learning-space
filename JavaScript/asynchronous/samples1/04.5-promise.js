let success = true;

// remember that resolve and reject only accept one argument
// so if you want to pass multiple value inside it, you need
// to wrap or group those value in a datastructure, most commonly
// used are Object Literals and Arrays
let promise = new Promise((resolve,reject)=>{
  console.log('Instantiation of Promise : Anything runs inside\n')
  setTimeout( ()=>{
    if(success)
      resolve(['Success',0]);
    else
      reject(['Failure',1]);
  },2000);
});

// imagine the 'let promise' is a special object where every line of code
// is executed in the instantiation, but when the resolve and reject parameters
// are called inside the callback function '(resolve,reject)=>{...}' they are
// are put on hold, or PAUSE, these resolve

promise
.then(msg => {
  console.log('first then');
  return new Promise((resolve,reject)=>{ // we return a new promise
    setTimeout(()=>{
      console.log('Resolve 2 Message :',msg[0],'\n');
      resolve(msg);
    },1000);
  });
})
.then(msg => {
  console.log('second then',msg);
  return new Promise((resolve,reject)=>{
    setTimeout(()=>{
      console.log('Resolve 3 StatusCode :',msg[1],'\n');
      resolve(msg);
      // return msg; // This won't work because
      // because we aren't returning a promise from the .then() handler - we're returning it from
      // the setTimeout() callback which does us no good.
      // so instead we wrap the setTimeout around a new Promise instance and we return that promise
    },3000);
  });
})
.then(msg => {
  console.log('third then')
  if(msg[1]===0)
    console.log('the operation is a '+msg[0]);
  return 2; // this value is automatically wrapped in a promise
})
.then(msg => {
  console.log('fourth then',msg);
  setTimeout(dummy=>{
    console.log('done forth then...');
  },2000);
})
.then(msg => {
  console.log('fifth then',msg);
  setTimeout(dummy=>{
    console.log('done fifth then...');
  },2000);
})
.catch(msg => {
  console.log('catch',msg);
});