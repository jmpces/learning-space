## Async callbacks

Async callbacks are functions that are specified as arguments when calling a function which will start executing code in the background. When the background code finishes running, it calls the callback function to let you know the work is done, or to let you know that something of interest has happened. Using callbacks is slightly old-fashioned now, but you'll still see them in use in a number of older-but-still-commonly-used APIs.

An example of an async callback is the second parameter of the addEventListener() method (as we saw in action above):

```javascript
btn.addEventListener('click', () => {
  alert('You clicked me!');

  let pElem = document.createElement('p');
  pElem.textContent = 'This is a newly-added paragraph.';
  document.body.appendChild(pElem);
});
```

The first parameter is the type of event to be listened for, and the second parameter is a callback function that is invoked when the event is fired.

When we pass a callback function as an argument to another function, we are only passing the function's reference as an argument, i.e, the callback function is not executed immediately. It is "called back" (hence the name) asynchronously somewhere inside the containing function's body. The containing function is responsible for executing the callback function when the time comes.

------

## Promises

Promises are the new style of async code that you'll see used in modern Web APIs. A good example is the fetch() API, which is basically like a modern, more efficient version of XMLHttpRequest. Let's look at a quick example, from our Fetching data from the server article:

```javascript
fetch('products.json').then(function(response) {
  return response.json();
}).then(function(json) {
  let products = json;
  initialize(products);
}).catch(function(err) {
  console.log('Fetch problem: ' + err.message);
});
```

Here we see fetch() taking a single parameter — the URL of a resource you want to fetch from the network — and returning a promise. The promise is an object representing the completion or failure of the async operation. It represents an intermediate state, as it were. In essence, it's the browser's way of saying "I promise to get back to you with the answer as soon as I can," hence the name "promise."

This concept can take practice to get used to; it feels a little like Schrödinger's cat in action. Neither of the possible outcomes have happened yet, so the fetch operation is currently waiting on the result of the browser trying to complete the operation at some point in the future. We've then got three further code blocks chained onto the end of the fetch():

- Two then() blocks. Both contain a callback function that will run if the previous operation is successful, and each callback receives as input the result of the previous successful operation, so you can go forward and do something else to it. Each .then() block returns another promise, meaning that you can chain multiple .then() blocks onto each other, so multiple asynchronous operations can be made to run in order, one after another.

- The catch() block at the end runs if any of the .then() blocks fail — in a similar way to synchronous try...catch blocks, an error object is made available inside the catch(), which can be used to report the kind of error that has occurred. Note however that synchronous try...catch won't work with promises, although it will work with async/await, as you'll learn later on.

------

## Promises versus callbacks

Promises have some similarities to old-style callbacks. They are essentially a returned object to which you attach callback functions, rather than having to pass callbacks into a function.

However, promises are specifically made for handling async operations, and have many advantages over old-style callbacks:

- You can chain multiple async operations together using multiple .then() operations, passing the result of one into the next one as an input. This is much harder to do with callbacks, which often ends up with a messy "pyramid of doom" (also known as callback hell).

- Promise callbacks are always called in the strict order they are placed in the event queue.

- Error handling is much better — all errors are handled by a single .catch() block at the end of the block, rather than being individually handled in each level of the "pyramid".

- Promises avoid inversion of control, unlike old-style callbacks, which lose full control of how the function will be executed when passing a callback to a third-party library.

[reference](https://developer.mozilla.org/en-US/docs/Learn/JavaScript/Asynchronous/Introducing)
