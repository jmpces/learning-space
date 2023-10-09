function sayHi(who) {
  console.log(`Hello ${who}!`);
}
let myGreeting = setTimeout(sayHi, 2000, 'Mr. Universe');
clearTimeout(myGreeting);