// Jumps - Javascript feature to use continue and break keywords with a loop label

// this example instead breaking out of the inner
// loop it instead breaks out of the outer loop
let cnt = 1;
outer : for(let i=1; i<=10; ++i){
  for(let j=1; j<=10; ++j){
    console.log(++cnt);
    if(cnt===7) break outer;
  }
}

console.log('\n no label continue : ')
for(let i=0; i<3; ++i){
  console.log('alpha');
  for(let j=0; j<6; ++j){
    console.log('beta');
    for(let k=0; k<9; ++k){
      if(k===1){
        continue; // continues only to the next iteration of the k'th loop
                  // causing only to display charlies instead of 9 inside the k'th loop
      }
      console.log('charlie');
    }
  }
}

console.log('\n labeled continue : ')
alpha : for(let i=0; i<3; ++i){
  console.log('alpha');
  beta : for(let j=0; j<6; ++j){
    console.log('beta');
    charlie : for(let k=0; k<9; ++k){
      if(k===1){
        continue alpha; // continues to the next iteration of the alpha loop
                        // causing to display alpha, beta, charlie 3 times
      }
      console.log('charlie');
    }
  }
}