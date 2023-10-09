/* To handle errors using callbacks we use a 2nd callback parameter that accepts an error handling function */

function GetLoginInfo(Username, Password, callback=(()=>{})){
  console.log('Waiting for login information arrival...');
  setTimeout(()=>{
    console.log('Login information arrived.');
    callback(Username,Password);
  },3000);
}

// see this example, we modified this function from sample `02-stacking-callback.js` to
// accept a 4th function that will be called if the user is not the admin.
// this is how we handle error cases on callbacks
function Authenticate(Username, Password, onSuccess=(()=>{}), onFailure=(()=>{})){
  console.log('Verifying login credentials...');
  setTimeout(()=>{
    let status = {};
    status.user = Username;
    if(Username === 'Admin' && Password === 'admin123')
    {
      status.admin = true;
      onSuccess(status);
    }
    else
    {
      status.admin = false;
      onFailure(status);
    }
  },1000);
}

function GetStatus(status, callback=(()=>{})){
  console.log('Reading Status...')
  setTimeout(()=>{
    console.log('status object :',status);
    callback(status);
  },2000);
}

// then you can pass an error function to the second argument of Authenticate
// or create you own error callback function definition using an arrow function
// like the example below in line 49 and line 59
GetLoginInfo('Admin','admin123',(username,password)=>{
  Authenticate(username,password,
    (status)=>{ // if admin
      GetStatus(status);
    },
    (status)=>{ // if not admin
      console.log(status.user,'is not an admin');
    }
  )
});

GetLoginInfo('Ella','itzy',(uname,pass)=>{
  Authenticate(uname,pass,
    (status)=>{ // if admin
      GetStatus(status);
    },
    (status)=>{ // if not admin
      console.log(status.user,'is not an admin');
    }
  )
});