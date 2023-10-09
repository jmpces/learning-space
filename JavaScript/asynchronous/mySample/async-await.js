/* THIS IS A PROMISFIED ASYNC/AWAIT VERSION OF `callback.js` */

let { getRandomIntInclusive : RNG } = require('./helpers.js');
let { VideoDatabase } = require('./pretend-database.js');

/* old callback api's are really not compatible to be used with promise
specifically the setTimeout and setInterval because you really cannot
return a value inside the callback you passed to it, so here we promisfy
the setTimeout to make it compatible with promises. */

async function setTimeoutPromise(cb_input,cb,interval){
  return new Promise((resolve)=>{
    setTimeout(()=>{
      resolve(cb(cb_input));
    },interval);
  });
}

async function RequestVideo(name){
  console.log('establishing connection...');
  
  if(typeof name !== 'string'){
    /* here we can use throw because it will still propagate in the
       synchronous catch block.
       
       we can also use the return Promise.reject(); method
       both techniques  will be handled in the catch block. */
    
       throw new Error('Request Video Failed, '+name+' is not a string');
    
    // return Promise.reject(new Error('Request Video Failed, '+name+' is not a string'));
  }
  else{
    return await setTimeoutPromise(name,(name)=>{
      console.log('connection establised.\n');
      return Promise.resolve(name);
    },RNG(500,5000));
  }
}

async function FindVideo(name){
  console.log('searching databse...');
  return await setTimeoutPromise(name,(name)=>{
    if(VideoDatabase.hasOwnProperty(name)){
      console.log('video found\n');
      return Promise.resolve(VideoDatabase[name]);
    }
    else{
      /* WARNING : throwing an error inside setTimeout will not
         trigger the catch block outside of its scope, that is why
         it is not recommended to used the old style asynchronous
         callback api's with promises and async await:*/

      // this wont display the 'An unfortunate error occur:\n\n' in the catch block;
      // throw new Error('video('+name+') not found in database');

      // instead we use the Promise.reject method to trigger the catch block
      return Promise.reject(new Error('video('+name+') not found in database'));
    }
  },RNG(500,5000)); 
}

async function EncodeVideo(video){
  console.log('Encoding',video.title,'...');
  return await setTimeoutPromise(video,(video)=>{
    video.encoded = true;
    console.log(video.title,'was encoded\n');
    return Promise.resolve(video);
  },RNG(500,5000));
}

async function DownloadVideo(video){
  console.log('Sending',video.title,'...');
  return await setTimeoutPromise(video,(video)=>{
    if(video.encoded && video !== undefined)
      {
        console.log(video.title,'was downloaded\n');
        return Promise.resolve(video);
      }
      else{
        return Promise.reject(new Error('Downloading is not possible, the video ('+video.title+') is not encoded'));
      }
  },RNG(500,5000));
}

async function DecodeVideo(video){
  console.log('Decoding',video.title,'...');
  return await setTimeoutPromise(video,(video)=>{
    video.encoded = false;
    console.log(video.title,'was decoded\n');
    return Promise.resolve(video);
  },RNG(500,5000));
}

async function PlayVideo(video){
  console.log(video.title,'playing...');
  if(video.encoded && video !== undefined){
    throw new Error('Cannot play '+video.title+' because video is not decoded');
  }
  else{
    return await setTimeoutPromise(video,(video)=>{
      video.encoded = false;
      console.log(video.title,'finished.\n');
      return Promise.resolve(true);
    },video.length*5);  
  }
}

// async function CompleteProcess(){
//   try{
//     let name = await RequestVideo('Cute Cats.mp4');
//     let video = await FindVideo(name);
//     let Encoded = await EncodeVideo(video);
//     let downloaded = await DownloadVideo(Encoded);
//     let decoded = await DecodeVideo(downloaded);
//     PlayVideo(decoded);
//   }
//   catch(error){
//     console.log('An unfortunate error occur:\n\n');
//     console.error(error);
//   }
// }
// CompleteProcess();


// async function If_we_pass_something_that_is_not_a_string(){
//   try{
//     let name = await RequestVideo([1,'Cute Cats.mp4']);
//     let video = await FindVideo(name);
//     let Encoded = await EncodeVideo(video);
//     let downloaded = await DownloadVideo(Encoded);
//     let decoded = await DecodeVideo(downloaded);
//     PlayVideo(decoded);
//   }
//   catch(error){
//     console.log('An unfortunate error occur:\n\n');
//     console.error(error);
//   }
// }
// If_we_pass_something_that_is_not_a_string();


// async function If_we_pass_a_filename_that_is_not_in_database(){
//   try{
//     let name = await RequestVideo('I am not in database.mp4');
//     let video = await FindVideo(name);
//     let Encoded = await EncodeVideo(video);
//     let downloaded = await DownloadVideo(Encoded);
//     let decoded = await DecodeVideo(downloaded);
//     PlayVideo(decoded);
//   }
//   catch(error){
//     console.log('An unfortunate error occur:\n\n');
//     console.error(error);
//   }
// }
// If_we_pass_a_filename_that_is_not_in_database();


// async function If_we_try_to_send_or_download_a_video_that_is_not_encoded(){
//   try{
//     let name = await RequestVideo('Adorable Dogs.mp4');
//     let video = await FindVideo(name);
//     // let Encoded = await EncodeVideo(video);
//     let downloaded = await DownloadVideo(video);
//     let decoded = await DecodeVideo(downloaded);
//     PlayVideo(decoded);
//   }
//   catch(error){
//     console.log('An unfortunate error occur:\n\n');
//     console.error(error);
//   }
// }
// If_we_try_to_send_or_download_a_video_that_is_not_encoded();


async function If_we_play_a_video_that_is_not_decoded(){
  try{
    let name = await RequestVideo('Cute Cats.mp4');
    let video = await FindVideo(name);
    let Encoded = await EncodeVideo(video);
    let downloaded = await DownloadVideo(Encoded);
    // let decoded = await DecodeVideo(downloaded);
    await PlayVideo(downloaded);

    /* NOTE WARNING : if we call the PlayVideo(downloaded); without
    the `await` keyword we will not be able to trigger the catch
    block below.
    
    so use await inside synchronous try/catch blocks everytime.*/
    // PlayVideo(downloaded); // <- don't do this
  }
  catch(error){
    console.log('An unfortunate error occur:\n\n');
    console.error(error);
  }
}
If_we_play_a_video_that_is_not_decoded();