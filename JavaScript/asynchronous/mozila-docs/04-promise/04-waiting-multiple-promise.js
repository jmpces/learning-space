/** if you want to run some code only after a whole bunch of promises have
all fulfilled you can do this. This takes an array of promises as an
input parameter and returns a new Promise object that will fulfil only
if and when all promises in the array fulfil. It looks something like this:*/

Promise.all([a, b, c]).then(values => {
  // ...
});

/** If they all fulfil, the chained .then() block's callback function will be
passed an array containing all those results as a parameter. If any of the
promises passed to Promise.all() reject, the whole block will reject. */