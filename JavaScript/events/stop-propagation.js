const grandparent = document.querySelector('.grandparent');
const parent = document.querySelector('.parent');
const child = document.querySelector('.child');

grandparent.addEventListener('click', event => {
  console.log('grandparent 1');
});

/* Stopping events to further happend after an event */
parent.addEventListener('click', event => {
  console.log('parent 1');
  event.stopPropagation(); // this stops the capture, target, and bubbling phases
}, {capture: true});

child.addEventListener('click', evenet => console.log('child 1'));

// in this case if we click the grand parent, the event of the grand parent will run

// if we click the parent, only the parent will run because grandparent bubbling phase is unreachable
// since we stop the event propagation

// if we click the child, the console output will be the same as the parent, because we stop the
// event propagation and it did not reach the child element