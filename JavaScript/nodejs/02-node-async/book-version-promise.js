const util = require("util");

const fs = require("fs"); // Require the filesystem module

const pfs = {
 // Promise-based variants of some fs functions
  readFile: util.promisify(fs.readFile)
};

async function readConfigFile(path) {
  return pfs.readFile(path, "utf-8").then(text => {
    return JSON.parse(text);
  });
}

(()=>{
  readConfigFile('object.txt')
  .then((obejct)=>{
    console.log(obejct);;
  })
})();