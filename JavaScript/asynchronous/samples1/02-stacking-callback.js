/* this shows how we can stack multiple asynchronous functionos sequentially using callbacks
  and void data race between them

  Here we will simulate a login proccess
  first we will define the steps:

    1. GetLoginInfo
    2. Authenticate
    3. GetStatus

  all of this steps will also be our function name and lets assume that they are asynchronous
*/

function GetLoginInfo(Username, Password, callback){
  console.log('Waiting for login information arrival...');
  setTimeout(()=>{ // we simulate that after some time we receive the Username and Password from the client
    console.log('Login information arrived.');
    callback(Username,Password);
  },3000);
}

function Authenticate(Username, Password, callback){
  console.log('Verifying login credentials...');
  setTimeout(()=>{
    let status = {};
    status.user = Username;
    if(Username === 'Admin' && Password === 'admin123')
      status.admin = true;
    else
      status.admin = false;
    console.log('Done Veryfying');
    callback(status)
  },3000);
}

function GetStatus(status, callback){
  console.log('Reading Status...')
  setTimeout(()=>{
    console.log('status object :',status);
    callback(status);
  },2000);
}

GetLoginInfo('Admins','admin123',(username,password)=>{
  Authenticate(username,password,(status)=>{
    GetStatus(status);
  })
});