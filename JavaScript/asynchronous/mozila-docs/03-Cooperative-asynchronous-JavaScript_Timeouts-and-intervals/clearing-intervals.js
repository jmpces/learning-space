function myFunction(){
  console.log('display');
}
const myInterval = setInterval(myFunction, 2000);
clearInterval(myInterval);