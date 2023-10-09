/* THESE VARIABLES ARE ALREADY LOADED IN THE MOUSE.JS
let LeftDiv = document.querySelector('.left');
let Parent  = document.querySelector('.parent');
let child   = document.querySelector('.child');

let RightDiv = document.querySelector('.right');
let MousePos = document.getElementById('mouse-value');*/

let Message = MousePos;
let Text = '';

let RenderText = function(Key, event){
  Text = Message.textContent;
  console.log(Key);

  if(Key === 13){
    Message.innerText = 'Cleared';
    Text = 'Entered';
  }
  else if(Key === 126)
    Message.innerText = 'Saved Key';
  else if(Key === 32)
    Text += ' ';
  else
    Text += String.fromCharCode(Key);

  Message.innerText = Text;
}

let LogKey = function(event){
  let Key;

  if(window.event)
    Key = event.keyCode; // for IE
  else if(event.which)
    Key = event.which; // other browsers
  
  RenderText(Key, event);
}

document.addEventListener('keypress', LogKey);