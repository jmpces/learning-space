// Define all the functions, public and private
let globalModuleFoo = function(){
  console.log("Hello I am a global function in exporting.js module");
}

/* exporting functions */
const sum = (x, y) => x + y;
const square = x => x * x;
const mean = data => data.reduce(sum)/data.length;
const stddev = d => {
  let m = mean(d);
  return Math.sqrt(d.map(x => x - m).map(square).reduce(sum)/(d.length-1));
};

/* exporting functions inside a function namespace */
// This is how we could define a stats module
const stats = (function() {
  
  // Utility functions private to the module
  const sum = (x, y) => x + y;
  const square = x => x * x;
  
  // A public function that will be exported
  function mean(data) {
    return data.reduce(sum)/data.length;
  }

  // A public function that we will export
  function stddev(data) {
    let m = mean(data);
    return Math.sqrt(
      data.map(x => x-m).map(square).reduce(sum)/(data.length-1)
    );
  }

  // We export the public function as properties of an object
  return { mean, stddev };
}());

/* exporting Class */
class Collection{
  constructor(data){
    this.data = [...data];
  }

  display(){
    console.log(this.data);
  }

  sum(){
    return this.data.reduce((accumulate,element) => accumulate+element,0);
  }

  average(){
    return this.sum()/this.data.length;
  }
}

// Now export only the public ones

// node export
module.exports = { mean, stddev, stats, Collection };

// ES6 export
// export { mean, stddev, stats, Collection };