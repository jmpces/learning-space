/*The advantage of an async function only becomes
apparent when you combine it with the await keyword.

await only works inside async functions within regular JavaScript code,
however it can be used on its own with JavaScript modules.

await can be put in front of any async promise-based function to
pause your code on that line until the promise fulfills,
then return the resulting value.

You can use await when calling any function that returns a Promise,
including web API functions.

Here is a trivial example:*/

async function hello() {
  return await Promise.resolve("Hello");
};

hello().then(console.log);

/* NOTE WARNING : Keep in mind the await keyword causes the
JavaScript runtime to pause your code on this line, not allowing
further code to execute in the meantime until the async function
call has returned its result */