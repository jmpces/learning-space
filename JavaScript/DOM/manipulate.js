/* Adding Elements in a page */

// get the page body
const PageBody = document.body;

// Append String - Does not parse special characters and html tags in string form
// append() : can add string and html element variables (not raw string html tags)
PageBody.append('<p>Bye',' world</p>'); // when appending string you cannot use appendChild()

// Append Elements
// appendChild() : can only add html elements
const appendedMessage = document.createElement('h3');
PageBody.appendChild(appendedMessage); // here you can also use append() if you like
appendedMessage.innerText = 'An <h3> tag added by JavaScript'; // (set after the appendedMessage is already appended)

// Append To Child
const MyList = document.querySelector('ul');  // 1. get the target parent
const newItem = document.createElement('li'); // 2. create the child to be appended
newItem.textContent = 'Train';                // 3. set the inner text value of the child (set before the newItem is appended)
MyList.appendChild(newItem);                  // 4. append the child to the parent

/* NOTE :
      both .innerText, and .textContent can be set either before
      the element is added or when the element is already added to the page
      and it will still work.
      
      .innerText returns only the visible text in the page,
      if an html element's display is set to none, we would not be
      able to get the .innerText's value
      
      .textContent on the other hand will return the text even if the
      element that contains it is visible or invisible*/

// Modify HTML
// .innerHTML directly write string to the html, so any html tag inside
//  the string will display in the page
// PageBody.innerHTML = '<h1>Content Was Cleared</h1>'; // according to webdev siplified using .innerHTML can lean to some security issues


// Remove elements in the DOM
const ListItems = document.querySelectorAll('li');
ListItems[0].remove(); // removes <li>Books<li> the element to the HTML (NOTE: the item is not removed in ListItems array only in the HTML)

const FooterMessage = document.querySelector('footer');
FooterMessage.remove();

// Remove child of an element in the DOM
const UnorderedList = document.querySelector('ul');
UnorderedList.removeChild(ListItems[3]); // removes <li>Candy</li>
console.log(ListItems)

// Get attributes
const MyDiv = document.querySelector('.mydiv');
// using the get attribute method
console.log('--GET ATTRIBUTES--');
console.log('using method :', MyDiv.getAttribute('id'));
console.log('using method :', MyDiv.getAttribute('class'));
// or
// using the property name
console.log('using property :', MyDiv.id);
console.log('using property :', MyDiv.className);

// the advantage of get attribute is that it returns 'null' if the
// specified attribute is not used or not set in the html, the method will return null
// which can be check using conditionals

// Set attributes
console.log('--SET ATTRIBUTES--');
MyDiv.setAttribute('id', 'my-new-div-id');
MyDiv.setAttribute('class', 'my-new-div-class');
console.log('using method :', MyDiv.getAttribute('id'));
console.log('using method :', MyDiv.getAttribute('class'));
// or
MyDiv.id = 'newIDName';
MyDiv.className = 'newClassName';
console.log('using property :', MyDiv.id);
console.log('using property :', MyDiv.className);

// Remove attributes
MyDiv.removeAttribute('id');
MyDiv.removeAttribute('class');
console.log('using property :', MyDiv.id);
console.log('using property :', MyDiv.className);


// Get Data Attribute
console.log(MyList.dataset);
console.log(MyList.dataset.another);

// Add Data Attribute
MyList.dataset.newData = 'hello Im new here';
console.log(MyList.dataset.newData);

// Add and Remove class
MyList.classList.add('new-class');
MyList.classList.remove('mylist');

// toggle add or remove
// remove the class if it exist or add it if it does not
MyList.classList.toggle('new-class-2'); // adds new class because 'new-class-2' does not exist
MyList.classList.toggle('new-class');   // removes the 'new-class' because it exist

// Modify CSS property
const CookingRiceSteps = Array.from(document.querySelector('ol').children);
for(let i=0; i<CookingRiceSteps.length; ++i){
  if(i%2===0){
    console.log('true');
    CookingRiceSteps[i].style.color = 'purple';
  }
  else{
    console.log('false');
    CookingRiceSteps[i].style.color = 'red';
  }
}