## Tutorial On Callback, Promises, and Async & Await

here I'm going to only simulate a video fetching API.

I'm gonna create a **Callback Version**, a **Promise Version**, and an **Async & Await Version** of the said API

### These are the simulated steps when trying to request a video

1. Request the video by providing it's name
2. check the database if the video exist
3. if true:
    1. Encode the video
    2. Send back to client/client is downloading the video

    if false:
    1. send an error message back to client
    2. stop the proccess
4. decode the video
5. play the video