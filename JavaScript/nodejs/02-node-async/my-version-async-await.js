const fs = require('fs');

async function readConfigFile(path){
  return await new Promise((resolve, reject) => {
    fs.readFile(path, "utf8", (err, text) => {
      if(err)
        reject(err);

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

async function WholeProcess(){
  try{
    let obj = await readConfigFile('./object.txt');
    console.log(obj);
    console.log('successful');
  }
  catch(err){
    console.error('\n\nAn error occured :\n', err);
  }
}
WholeProcess();

console.log('end');