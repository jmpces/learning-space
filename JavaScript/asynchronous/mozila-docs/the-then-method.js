/* Chained Promises
The methods promise.then(), promise.catch(), and promise.finally()
are used to associate further action with a promise that becomes settled.

The .then() method takes up to two arguments; the first argument is
a callback function for the resolved case of the promise, and the second
argument is a callback function for the rejected case.
Each .then() returns a newly generated promise object, which can
optionally be used for chaining; for example:*/

const myPromise = new Promise((resolve, reject) => {
  setTimeout(() => {
    resolve('foo');
  }, 300);
});

myPromise
  .then(handleResolvedA, handleRejectedA)
  .then(handleResolvedB, handleRejectedB)
  .then(handleResolvedC, handleRejectedC);
