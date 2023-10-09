// PRE ES6

// a constructor function

// This is classes are created before the introduction of class and constructor keywords

function User(email, name){
  this.email = email;
  this.name = name;
  this.online = false;
  this.login = function(){
    console.log(this.email, "has logged in");
  }
}

let FirstUser  = new User("ryujin@gmail.com", "Ryujin");
let SecondUser = new User("yeji@gmail.com", "Yeji");

console.log(FirstUser);
SecondUser.login();