const fs = require('fs');

function readConfigFile(path, calllback){
  fs.readFile(path, "utf8", (err, text) => {
    if(err) {
      console.error(err);
      calllback(null);
      return;
    }

    let data = null;

    try{
      data = JSON.parse(text);
    }
    catch(e){
      console.error(e);
    }
    calllback(data);
  });
}

readConfigFile('./object.txt',(text)=>{
  if(text===null){
    throw new Error("the textfile was not an object");
  }
  else{
    console.log('successful');
  }
});