/* ============== LOADING HTML ELEMENTS TO JAVASCRIPT ============== */

// just a helper function
function Paint(htmlElement,Color){
  htmlElement.style.backgroundColor = Color;
}

/* document : 
    imagine document is an element, and it is the root parent in an
    html, and from the root parent you can traverse elements down the
    family tree, or heirarchy
    
    this also applies to other elements you load, you can traverse
    up or down the heirarchy from that element. */


/* 1.) Load by ID */
const grandparent = document.getElementById("f-gp");
grandparent.style.border = '5px solid blue';

/* 2.) Load by Class */
const parents = Array.from(document.getElementsByClassName("parent"));
parents.forEach(elements => Paint(elements,'yellow')); // Change CSS property
parents[0].style.backgroundImage = 'linear-gradient(47deg,orange,red,blue)';
/* NOTE :
    getElementByClassName returns a collection so we need to
    convert it first to an array so we can work with it's
    elements*/

/* 3.) Load by Query Selector/CSS selector - (Select by ID) */
// querySelector - returns the first occurence matched element.
// it traverse down the tree and sub-trees of the DOM and finds
// the first occurence of the queried element
const GrandParent = document.querySelector("#f-gp");
GrandParent.style.backgroundColor = 'violet';

/* 4.) Load by Query Selector/CSS selector - (Select by Class) */
// querySelectorAll - returns all matched elements
const Parents = document.querySelectorAll('.parent');
Parents[0].style.borderRadius = '1em';

/* 5.) Load Children of an Element */
const GrandParentChild = Array.from(grandparent.children);
// or
// const GrandParentChild = Array.from(document.getElementById("f-gp").children);
for(let i=0; i<GrandParentChild.length; ++i){
  GrandParentChild[i].style.border = '5px solid purple';
}

/* 6.) Load Elements only from a certain Scope/element */
//  (OR MOVING DOWN THE TREE FROM A CERTAIN NODE)
//    instead of using 'document' we can use the element itself and traverse
//    the DOM from it like in line 49
const Parent2 = document.getElementById('f-p2');
const Parent2Children = Parent2.querySelectorAll('.child');
// or
// const Parent2Children = Array.from(Parent2.getElementsByClassName('child'));
Parent2Children.forEach(element => Paint(element,'grey'));

/* 7.) Load Parent Element */
const Parent2sChild2 = document.getElementById('f-p2-c2');
const Child2sParent = Parent2sChild2.parentElement;
Child2sParent.style.borderTop = '8px red solid';

/* 8.) Load Elements from a starting element UP the DOM tree heirarchy */
// (BACKTRACKING TO A PARENT NODE FROM A CERTAIN NODE)
const BackTrackedGrandParent = Parent2sChild2.closest('.grandparent');
BackTrackedGrandParent.style.borderRadius = '2em';
/* NOTE:
    .closest can only traverse up the tree, meaning on a certain node
    or element node, closest won't be able to get it's siblings and cousins,
    only the parent can be traversed back up the tree. */ 

/* --------------------------------------------------------------------------------------
/* 9. Loading Siblings of an element */
const FirstChild  = document.querySelector('#f-p1-c1');
const SecondChild = FirstChild.nextElementSibling;
const FirstChildReference = SecondChild.previousElementSibling;

FirstChild.style.borderBottom = '8px solid pink';
SecondChild.style.backgroundColor = 'orange';
FirstChildReference.style.borderRadius = '1em';