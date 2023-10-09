const grandparent = document.querySelector('.grandparent');
const parent = document.querySelector('.parent');
const child = document.querySelector('.child');

let childCnt = 0;
let parentCnt = 0;

// There is no way for us to remove events that is created by arrow functions
// since we have no way to reference that function
grandparent.addEventListener('click', element =>{
  console.log('grandparent : you cannot remove me');
});

// we can remove a binded function event be cause we can use the variable childEvent to reference that
// event when we call the method for removing events 
let childEvent = function(event){
  console.log(`child : I will only run 5 times cnt : ${++childCnt}`);
  if(childCnt >= 5)
    this.removeEventListener('click', childEvent); // in this case, using 'this' is equivalent to child.removeEventListener
    // child.removeEventListener('click', childEvent);
}
child.addEventListener('click', childEvent);

// you can also use global hoisted functions like below as events
parent.addEventListener('click', parentEvent);
function parentEvent(e){
  console.log(`parent : I will only run 10 times cnt : ${++parentCnt}`);
  if(parentCnt >= 10)
    parent.removeEventListener('click',parentEvent);
}