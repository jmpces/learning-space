let LeftDiv = document.querySelector('.left');
let Parent  = document.querySelector('.parent');
let child   = document.querySelector('.child');

let RightDiv = document.querySelector('.right');
let MousePos = document.getElementById('mouse-value');

/* Mose Move Event */
let MouseMove = function(event){
  MousePos.innerText = `x = ${event.clientX}, y = ${event.clientY}`;
}
RightDiv.addEventListener('mousemove',MouseMove, false);

/* Mose Over Event */
let MouseOver = function(event){
  MousePos.innerText = 'Mouse Over';
}
child.addEventListener('mouseover', MouseOver);

/* Mouse Enter Event */
let MouseEnter = function(event){
  MousePos.innerText = 'Mouse Enter';
  child.style.cursor = 'wait';
}
child.addEventListener('mouseenter',MouseEnter);

/* Mouse Leave Event */
let MouseLeave = function(event){
  MousePos.innerText = 'Mouse Left';
}
child.addEventListener('mouseleave',MouseLeave);