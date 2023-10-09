/**
 * To enable method chaining we just need to return the object itself after everymethod
 * we can achieve this by returning the `this` keyword in our methods
 */

class CookRice {
  constructor(){
    this.step = 0;
  }

  youMessedUp(){
    console.log('You Messed Up!');
    throw 'User Dumb!';
  }

  getRice(){
    this.step++;
    if(this.step==1){
      console.log('Getting rice from the sack into the pot');
      return this;
    }
    else this.youMessedUp();
  }

  washRice(){
    this.step++;
    if(this.step==2){
      console.log('Washing the rice');
      return this;
    }
    else this.youMessedUp();
  }

  measureWater(){
    this.step++;
    if(this.step==3){
      console.log('Measuring the water level');
      return this;
    }
    else this.youMessedUp();
  }

  putPotInRiceCooker(){
    this.step++;
    if(this.step==4){
      console.log('On to the Stove');
      return this;
    }
    else this.youMessedUp();
  }

  riceDone(){
    this.step++;
    if(this.step==5){
      console.log('Yum Yum!');
      console.log('cook success!!!')
      return this;
    }
    else this.youMessedUp();
  }
}

let Bob = new CookRice();

// Bob.getRice().washRice().measureWater().putPotInRiceCooker().riceDone();

Bob.getRice().putPotInRiceCooker(); // Oga boga! cave man brain