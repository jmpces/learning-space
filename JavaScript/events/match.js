// add event to all elements of the HTML
document.addEventListener('click', event => {
  // if the HTML element clicked was a div execute the code block
  if(event.target.matches('div'))
    console.log('you clicked a div');
});