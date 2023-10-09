/* Here we have an asynchronous function called ExpensiveComputation */

/* But since the function contains is a blocking operation (the for loop)
   inside it, it will stop the event loop from executing the other loops */

function ExpensiveComputation(fooName){
  setTimeout((name)=>{
    console.log(`${fooName} has started`);
    let afterValue = 0;
    for(let i=0; i<1000000000; ++i){
      afterValue++;
    }
    console.log(`${fooName} has ended`);
  },0);
}

console.log('start');

setTimeout(() => {console.log("this is the first message")}, 5000);
setTimeout(() => {console.log("this is the second message")}, 3000);
setTimeout(() => {console.log("this is the third message")}, 1000);

ExpensiveComputation('nana');

let loopInc = 0;
for(let i=0; i<1000000000; ++i){
  if(i===0)
    console.log('loop started');
    loopInc++;
  if(i===999999999)
    console.log('loop ended');
}

ExpensiveComputation('micha');

console.log('end');
