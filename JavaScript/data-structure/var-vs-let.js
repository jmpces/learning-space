function fooVar(){
  console.log(test);    // hoisted to top of eclosing function as undefined
  var test = 5;
}

function fooLet(){
  // console.log(test);  // < throw an error
  let test = 5;
}

fooVar();
fooLet();