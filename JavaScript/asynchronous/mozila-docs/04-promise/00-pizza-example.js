/** ALL OF THESE EXAMPLES ARE DOING THE SAME THING
 * HERE WE ARE SHOWING WHAT PROMISES CAN DO AND IT's
 * BASIC STRUCTURE OF USE
 */

// 1.) Old Style : aysnc chaining using callbacks
// to execute asynchronous function sequentially

chooseToppings(function(toppings) {
  placeOrder(toppings, function(order) {
    collectOrder(order, function(pizza) {
      eatPizza(pizza);
    }, failureCallback);
  }, failureCallback);
}, failureCallback);

// 2.) New Style : aysnc chaining using promises
// to execute asynchronous function sequentially

chooseToppings()
.then(function(toppings) {
  return placeOrder(toppings);
})
.then(function(order) {
  return collectOrder(order);
})
.then(function(pizza) {
  eatPizza(pizza);
})
.catch(failureCallback);

// 3.) Similar with the second one but uses arrow
// functions instead
// This works because with arrow functions "() => x" is valid shorthand for "() => { return x; }".
chooseToppings()
.then(toppings => placeOrder(toppings))
.then(order => collectOrder(order))
.then(pizza => eatPizza(pizza))
.catch(failureCallback);

// 4.) You could even do this, since the functions just pass their arguments directly,
// so there isn't any need for that extra layer of functions:
chooseToppings().then(placeOrder).then(collectOrder).then(eatPizza).catch(failureCallback);

// This is not quite as easy to read, however, and this syntax might not be
// usable if your blocks are more complex than what we've shown here.