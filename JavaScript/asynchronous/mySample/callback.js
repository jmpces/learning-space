let { getRandomIntInclusive : RNG } = require('./helpers.js');
let { VideoDatabase } = require('./pretend-database.js');

// [client] simulating a function in the client that request
// a video from a server's database
function RequestVideo(name,cb=(()=>{}),error_cb=(()=>{})){
  console.log('establishing connection...');
  if(typeof name !== 'string') {
    error_cb(new Error('Request Video Failed, '+name+' is not a string'));
  }
  else {
    setTimeout(()=>{
      console.log('connection establised.\n');
      cb(name);
    },RNG(500,5000)); // we use the RNG function to sumulate the delay of connection in a network
  }
}

// [server] simulating a function that is in the database
// that find the name of the video if it exist
function FindVideo(name,cb=(()=>{}),error_cb=(()=>{})){
  console.log('searching database...');
  setTimeout(()=>{
    if(VideoDatabase.hasOwnProperty(name)){
      console.log('video found\n');
      cb(VideoDatabase[name]);
    }
    else{
      error_cb(new Error('video('+name+') not found in database'));
    }
  },RNG(500,5000));
}

// [server] simulating that we are encoding a video,
// here we always assume that the encoding will always succeed
function EncodeVideo(video,cb=(()=>{}),error_cb=(()=>{})){
  console.log('Encoding',video.title,'...');
  setTimeout(()=>{
    video.encoded = true;
    console.log(video.title,'was encoded\n');
    cb(video);
  },RNG(500,5000));
}

// [server to client] simulating a function that the video
// is being sent to the client, this is the download phase
// for the client, we cannot send or download a video that
// is not encoded
function DownloadVideo(video,cb=(()=>{}),error_cb=(()=>{})){
  console.log('Sending',video.title,'...');
  setTimeout(()=>{
    if(video.encoded && video !== undefined)
    {
      console.log(video.title,'was downloaded\n');
      cb(video);
    }
    else{
      error_cb(new Error('Downloading is not possible, the video ('+video.title+') is not encoded'));
    }
  },RNG(500,5000));
}

// [client] simulating that we are decoding a video,
// here we always assume that the decoding will always succeed
function DecodeVideo(video,cb=(()=>{}),error_cb=(()=>{})){
  console.log('Decoding',video.title,'...');
  setTimeout(()=>{
    video.encoded = false;
    console.log(video.title,'was decoded\n');
    cb(video);
  },RNG(500,5000));
}

// [client] simulating that the video is being played
function PlayVideo(video,cb=(()=>{}),error_cb=(()=>{})){
  console.log(video.title,'playing...');
  if(video.encoded && video !== undefined){
    error_cb(new Error('Cannot play '+video.title+' because video is not decoded'));
  }
  else{
    setTimeout(()=>{
      video.encoded = false;
      console.log(video.title,'finished.\n');
    },video.length*10);
  }
}

// our error handler function
function GetError(error,cb=(()=>{})){
  console.log(error);
}

// // =============  Perfect step by step chaining =============  

// RequestVideo('My Monalisa.mp4',(name)=>{
//   // some user defined extra code
//   FindVideo(name,(video)=>{
//     // some user defined extra code
//     EncodeVideo(video,(encodedVideo)=>{
//       // some user defined extra code
//       DownloadVideo(encodedVideo,(downloadedVideo)=>{
//         // some user defined extra code
//         DecodeVideo(downloadedVideo,(decodedVideo)=>{
//           // some user defined extra code
//           PlayVideo(decodedVideo,(playingVideo)=>{
//             // some user defined extra code
//           },GetError);
//         },GetError);
//       },GetError);
//     },GetError);
//   },GetError);
// },GetError);

/* If we observe above, we are actually defining an anonymous function instead of
passing the next asynchrnous function in our callback parameter, we do this
for convenience sake and for flexibility so that we can input out own code
between each chains of callbacks if needed...

but I just want to tell that... it is also possible to just directly pass a
named function in a callback parameter (like what we did in the GetError)
but you will need to structure that function in a way that it would match
the invokation signatures of the callback function inside the parent
aynchronous function in the chain

if we also want to costumize our error methods we would invoke it inside
an anonymous function:
RequestVideo('My Monalisa.mp4',(name)=>{
  // success handler
},(error)=>{
  // error handler
  // do some stuffs
  GetError(error);
})

now we can see why they call it callback hell, because if we chained so many callback
the indentation will make the code hard to read, and if we even further add our own code
in each level of the chain it just becomes so messy and hard to understand given that we
only define our costum code in a success handler, if we also define a costum error handler
for each level of chain the code will just become an abomination.
*/


// // =============  if we pass something that is not a string =============  

// RequestVideo([1,2,3],(name)=>{
//   console.log(name);
// },GetError);


// // =============  if we pass a filename that is not in a database =============  

// RequestVideo('I am not in Database.mp4',(name)=>{
//   FindVideo(name,(video)=>{
//     console.log(video);
//   },GetError);
// },GetError);


// // =============  if we try to send or download a video that is not encoded =============  

// RequestVideo('Adorable Dogs.mp4',(name)=>{
//   FindVideo(name,(video)=>{
//     DownloadVideo(video,(notEncoded)=>{
//       console.log(notEncoded);
//     },GetError);
//   },GetError);
// },GetError);


// // =============  if we try to play a downloaded video that is not decoded =============  

RequestVideo('Scary Zombies.mp4',(name)=>{
  FindVideo(name,(video)=>{
    EncodeVideo(video,(VidEncoded)=>{
      DownloadVideo(VidEncoded,(DwnloadedVideo)=>{
        PlayVideo(DwnloadedVideo,(playingVideo)=>{
          console.log(playingVideo);
        },GetError);
      },GetError);
    },GetError);
  },GetError);
},GetError);