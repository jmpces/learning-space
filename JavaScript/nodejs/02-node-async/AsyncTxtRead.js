const fs = require('fs');

console.log('start');
fs.readFile("test.txt", "utf8", (err, text)=>{
  if(err) {
    console.error(err);
    return;
  }

  console.log(text);
});
console.log('end');

// node AsyncTxtRead.js