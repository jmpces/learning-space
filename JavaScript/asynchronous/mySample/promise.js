/* THIS IS A PROMISFIED CHAINING VERSION OF `callback.js` */

let { getRandomIntInclusive : RNG } = require('./helpers.js');
let { VideoDatabase } = require('./pretend-database.js');

function RequestVideo(name){
  console.log('establishing connection...');
  return new Promise((resolve,reject)=>{
    if(typeof name !== 'string') {
      reject(new Error('Request Video Failed, '+name+' is not a string'));
    }
    else {
      setTimeout(()=>{
        console.log('connection establised.\n');
        resolve(name);
      },RNG(500,5000));
    }
  });
}

function FindVideo(name){
  console.log('searching database...');
  return new Promise((resolve,reject)=>{
    setTimeout(()=>{
      if(VideoDatabase.hasOwnProperty(name)){
        console.log('video found\n');
        resolve(VideoDatabase[name]);
      }
      else{
        reject(new Error('video('+name+') not found in database')); // WARNING : throwing an error inside setTimeout might produce weird error message
      }
    },RNG(500,5000));
  });
}

function EncodeVideo(video){
  console.log('Encoding',video.title,'...');
  return new Promise((resolve)=>{
    setTimeout(()=>{
      video.encoded = true;
      console.log(video.title,'was encoded\n');
      resolve(video);
    },RNG(500,5000));
  });
}

function DownloadVideo(video){
  console.log('Sending',video.title,'...');
  return new Promise((resolve,reject)=>{
    setTimeout(()=>{
      if(video.encoded && video !== undefined)
      {
        console.log(video.title,'was downloaded\n');
        resolve(video);
      }
      else{
        reject(new Error('Downloading is not possible, the video ('+video.title+') is not encoded'));
      }
    },RNG(500,5000));
  });
}

function DecodeVideo(video){
  console.log('Decoding',video.title,'...');
  return new Promise((resolve)=>{
    setTimeout(()=>{
      video.encoded = false;
      console.log(video.title,'was decoded\n');
      resolve(video);
    },RNG(500,5000));
  });
}

function PlayVideo(video){
  console.log(video.title,'playing...');
  return new Promise((resolve,reject)=>{
    if(video.encoded && video !== undefined){
      reject(new Error('Cannot play '+video.title+' because video is not decoded'));
    }
    else{
      setTimeout(()=>{
        video.encoded = false;
        console.log(video.title,'finished.\n');
        resolve(true);
      },video.length*5);
    }
  });
}

function GetError(error){
  return new Promise((resolve)=>{
    setTimeout(()=>{
      console.log(`${error}`);
      resolve(false);
    },RNG(1000,5000));
  });
}

// =============  Promise Chaining =============  

RequestVideo('My Monalisa.mp4')
.then((name)=>{
  // some user defined extra code
  return FindVideo(name);
})
.then((video)=>{
  // some user defined extra code
  return EncodeVideo(video);
})
.then((encodedVideo)=>{
  // some user defined extra code
  return DownloadVideo(encodedVideo);
})
.then((downloadedVideo)=>{
  // some user defined extra code
  return DecodeVideo(downloadedVideo);
})
.then((decodedVideo)=>{
  // some user defined extra code
  return PlayVideo(decodedVideo);
})
// .catch(GetError) // <- this works because GetError already returns a promise
.catch((error)=>{ // if we want to costumize our error handler we do this instead
  // some user defined extra code
  return GetError(error); // for this method don't forget to return a promise to chain perfectly
})
.finally(()=>{
  // A finally callback will not receive any argument,
  // since there's no reliable means of determining if
  // the promise was fulfilled or rejected.
  console.log('all proccess done')
});

/* if we don't need to add our costum code,
we can write the code above line by line like this:

    (variable) => another_variable

this works because the arrow function above
is just a shorthand version of the method below :

    (variable) => { return another_variable; }

Look at this version below: */

// RequestVideo('My Monalisa.mp4')
// .then((name) => FindVideo(name))
// .then((video) => EncodeVideo(video))
// .then((encodedVideo) => DownloadVideo(encodedVideo))
// .then((downloadedVideo) => DecodeVideo(downloadedVideo))
// .then((decodedVideo) => PlayVideo(decodedVideo))
// .catch((error) => GetError(error))
// .finally(()=> console.log('All done!!!'));

// It can also be written like the example below but you don't really want to do this

// let database = RequestVideo('Cute Cats.mp4');
// let found = database.then((name) => FindVideo(name));
// let EncodedVideo = found.then((video) => EncodeVideo(video));
// let DonloadedVideo = EncodedVideo.then((video) => DownloadVideo(video));
// let DecodedVideo = DonloadedVideo.then((video) => DecodeVideo(video));
// let PlayingVideo = DecodedVideo.then((video) => PlayVideo(video));

// // =============  if we pass something that is not a string =============  

// RequestVideo([1,2,3])
// .then((name)=>{
//   console.log(name);
// })
// .catch((e) => console.error(e));

// // =============  if we pass a filename that is not in a database =============  

// RequestVideo('I am not in database.mp4')
// .then((name)=>{
//   return FindVideo(name);
// })
// .then((video)=>{
//   return EncodeVideo(video);
// })
// .then((encodedVideo)=>{
//   return DownloadVideo(encodedVideo);
// })
// .then((downloadedVideo)=>{
//   return DecodeVideo(downloadedVideo);
// })
// .then((decodedVideo)=>{
//   return PlayVideo(decodedVideo);
// })
// .catch((error)=>{ 
//   return GetError(error);
// })
// .finally(()=>{
//   console.log('all proccess done')
// });

// // ============  if we try to send or download a video that is not encoded ============  

// RequestVideo('Adorable Dogs.mp4')
// .then((name) => FindVideo(name))
// .then((encodedVideo) => DownloadVideo(encodedVideo))
// .then((downloadedVideo) => DecodeVideo(downloadedVideo))
// .then((decodedVideo) => PlayVideo(decodedVideo))
// .catch((error) => GetError(error))
// .finally(() => console.log('all proccess done'));

// // ============  if we try to play a downloaded video that is not decoded ============  

// RequestVideo('Scary Zombies.mp4')
// .then((name) => FindVideo(name))
// .then((video) => EncodeVideo(video))
// .then((encodedVideo) => DownloadVideo(encodedVideo))
// .then((decodedVideo) => PlayVideo(decodedVideo))
// .catch((error) => GetError(error))
// .finally(() => console.log('all proccess done'));