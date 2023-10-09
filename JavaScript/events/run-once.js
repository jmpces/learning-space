const grandparent = document.querySelector('.grandparent');
const parent = document.querySelector('.parent');
const child = document.querySelector('.child');

grandparent.addEventListener('click', element => {
  console.log('I run everytime');
}, true); // you can set a capture event by passing true as a third argument

parent.addEventListener('click', element => {
  console.log('I also run everytime');
});

child.addEventListener('click', element => {
  console.log('I only run once');
},
{ // you can also set a capture event by passing an object literal with 'capture: true' property in it
  capture: true,
  once: true
});