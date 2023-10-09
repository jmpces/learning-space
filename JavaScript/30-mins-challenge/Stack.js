'use strict';
// push
// pop
// get

class Node{
  constructor(Value){
    this.Value = Value;
    this.Up = null;
    this.Down = null;
  }
}

class Stack{
  constructor(){
    this.Top = new Node(null);
    this.Bottom = this.Top;
    this.Size = 0;
  }

  push(Value){
    let newNode = new Node(Value);
    if(this.Size===0){
      this.Top = newNode;
      this.Bottom = newNode;
      this.Top.Down = this.Bottom;
      this.Bottom.Up = this.Top;
    }
    else{
      newNode.Down = this.Top;
      this.Top.Up = newNode;
      this.Top = newNode;
    }
    this.Size++;
  }

  pop(){
    let topValue = this.Top.Value;

    if(this.Size===0){
      return 'Stack is empty';
    }
    else{
      let Reference = this.Top;
      this.Top = this.Top.Down;
      this.Size--;
      delete Reference;
    }

    return topValue;
  }
}

let Papers = new Stack();

Papers.push('House Papers');
Papers.push('Bills');
Papers.push('Receipt');
Papers.push('HomeWorks');
Papers.push('Something');


console.log(Papers.pop());
console.log(Papers.pop());
console.log(Papers.pop());
console.log(Papers.pop());
console.log(Papers.pop());
console.log();

console.log(Papers.pop());
console.log(Papers.pop());
console.log(Papers.Size);
console.log();

Papers.push('Diploma');
Papers.push('Recepie');
Papers.push('Medical Bills');
Papers.push('Contract');

console.log(Papers.pop());
console.log(Papers.pop());
console.log(Papers.pop());
console.log(Papers.pop());
console.log();

console.log(Papers.pop());
console.log(Papers.pop());