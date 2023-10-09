const recordVideoOne = new Promise((resolve)=>{
  resolve('Video 1 Recorded');
})

const recordVideoTwo = new Promise((resolve)=>{
  resolve('Video 2 Recorded');
})

const recordVideoThree = new Promise((resolve)=>{
  resolve('Video 3 Recorded');
})

Promise.all([recordVideoOne,recordVideoTwo,recordVideoThree])
.then((videos)=>{
  console.log(videos);
})

Promise.race([recordVideoOne,recordVideoTwo,recordVideoThree])
.then((videos)=>{
  console.log(videos);
})