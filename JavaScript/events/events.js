/* SHOWS THE BASIC WAY TO ADD EVENTS */

const grandparent = document.querySelector('.grandparent');
const parent = document.querySelector('.parent');
const child = document.querySelector('.child');

/* EVENT FLOW PHASES : CAPTURE > TARGET > BUBBLING
    CAPTURE  :
      - The events captured by nodes down the tree until it hit the target element
      
    TARGET   :
      - The main destination element where the event was triggered
      
    BUBBLING :
      - The events captured per node from the Target element up the tree
*/

// you can add an event listener to an element
// by default addEventListener adds a bubble event capture
grandparent.addEventListener('click', event => {
  console.log('grandparent 1');
});

// You can add multiple event listeners to one element
// grandparent.addEventListener('click', event => {
//   console.log('grandparent 2');
// });

// a capture event, executes first before executing the target element
parent.addEventListener('click', event => console.log('parent 1'),true);

// a bubble event, executes after the event of the target element
child.addEventListener('click', evenet => console.log('child 1'));