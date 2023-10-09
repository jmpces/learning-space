function Login(Email, Pass){
  // set timeout is use to simulate the latency delay when
  // communicating with a server
  setTimeout(()=>{
    return { User: Email }; // and after some time passed the data will be returned
  },2000);
}

let Someone = Login('MyEmail@idk.com','masterPassword'); // this though won't work
console.log(Someone); // we won't get the email because Login() is still processing when you assign it to `Someone`


// So instead we create a function with a callback parameter (see line 17).
// this is where we will pass a callback function (see line 29) that will
// contain the code for processing the passed object { User: Email } in line 19

function AsyncLogin(Email, Pass, callback){
  setTimeout(()=>{
    callback( { User: Email } );
  },2000);
}

// when we call the AsyncLogin function we define a callback function into the callback 
// parameter or the 3rd argument of the AsyncLogin (see line 29), that callback definition's
// parameter count should match the numbers of argument passed to the callback parameter
// call inside the AsynLogin (see line 19)

// hence we use only one parameter in our callback definition below in line 29
AsyncLogin('MyEmail@idk.com','masterPassword', (user)=>{
  let Someone = user;
  console.log(Someone);
})

// This is How we deal with async functions in javascript when Promises and Async Await is still not introduce.

// we cannot use the expression like in line 10, but with Promises and Async Await in modern javascript this would be possible