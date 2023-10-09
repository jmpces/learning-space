function hello() { return "Hello" };
console.log('not async :', hello());

async function AsyncHello() { return "Hello" };
console.log('async     :', AsyncHello());

/* Ah. Invoking the function now returns a promise.
This is one of the traits of async functions — their
return values are guaranteed to be converted to promises. */

// let hello = async function() { return "Hello" };
// let hello = async () => "Hello";
// hello();

// These all do basically the same thing.

// To actually consume the value returned when the promise fulfills,
// since it is returning a promise, we could use a .then() block:
AsyncHello().then((value) => console.log('in then   :', value));
// or even just shorthand such as
AsyncHello().then(console.log);

// So the async keyword is added to functions to tell them to return a promise rather than directly returning the value.