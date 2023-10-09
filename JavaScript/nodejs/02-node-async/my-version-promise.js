const { rejects } = require('assert');
const fs = require('fs');

function readConfigFile(path){
  return new Promise((resolve,reject)=>{
    fs.readFile(path, "utf8", (err, text) => {
      if(err)
        reject(null);

      let data = null;

      try{
        data = JSON.parse(text);
      }
      catch(e){
        console.error(e);
        reject(e);
      }

      resolve(data);
    });
  });
}

console.log('start');

readConfigFile('./object.txt')
.then((text)=>{
  console.log(text);
  console.log('successful');
})
.catch((error)=>{
  console.error('\n\nAn Error Occured :\n',error);
})

console.log('end');