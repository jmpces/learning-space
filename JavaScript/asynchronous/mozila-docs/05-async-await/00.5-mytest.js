async function foo(){
  return new Promise((resolve)=>{
    setTimeout(()=>{
      resolve('hi');
    },2000);
  });
}

console.log(foo());
foo().then(console.log);