let objLiteral = {
  email       : 'someone@gmail.com',
  'user name' : "someone's name",
  
  // Using Arrow function or basic function binding like below is wrong because it will
  // destroy all the local objects inside its scope after the object literals decleration
  // and definition, causing it to display undefined values for `email` and `user name`

  // NOT VALID : returns undefined with this
  display1 : ()=> {
    console.log('========== Display 1 ==========');
    console.log(`email : ${this.email}`);
    console.log(`uname : ${this['user name']}\n`);
  },

  // VALID
  display2 : function () {
    console.log('========== Display 2 ==========');
    console.log(`email : ${this.email}`);
    console.log(`uname : ${this['user name']}\n`);
  },

  // VALID - short hand of display2()
  display3(){
    console.log('========== Display 3 ==========');
    console.log(`email : ${this.email}`);
    console.log(`uname : ${this['user name']}\n`);
  }
};

console.log(objLiteral);
console.log(objLiteral.email);
console.log(objLiteral['user name']);

console.log();

objLiteral.display1();
objLiteral.display2();
objLiteral.display3();