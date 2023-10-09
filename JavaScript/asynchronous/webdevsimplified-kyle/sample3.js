/* Promise Version */

const userLeft = true;
const userWatchingCatMeme = false;

function watchTutorialCallback() {
  return new Promise((resolve,reject)=>{
    setTimeout(()=>{
      if(userLeft) {
        reject({
          name: 'User Left',
          message: ':('
        });
      }
      else if(userWatchingCatMeme) {
        reject({
          name: 'User Watching Cat Meme',
          message: 'WebDevSimplified < Cat'
        });
      }
      else
        resolve('Thumbs up and SubScribe');
    },2000);
  });
}

watchTutorialCallback()
.then((message)=>{
  console.log('Success:', message);
})
.catch((error)=>{
  console.error(error.name, error.message);
});