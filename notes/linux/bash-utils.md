# Images To GIF

```bash
ffmpeg -framerate 50 -pattern_type glob -i '*.jpg' -r 15 -vf scale=680:-1 flappy.gif
```

1. `-framerate 50`: This flag sets the input frame rate to 50 frames per second.
2. `-pattern_type glob`: This flag specifies the pattern type for input files.
3. `-i '*.jpg'`: This is the input file specifier. It tells `ffmpeg` to use all files with the '*.jpg' extension in the current directory as input for creating the GIF.
4. `-r 15`: This flag sets the output frame rate to 15 frames per second. The resulting GIF will play at this frame rate.
5. `-vf scale=680:-1`: This flag applies a video filter (`-vf`) to the output. It resizes the frames to have a width of 680 pixels while preserving the aspect ratio. The `-1` in the height parameter indicates that the height will be automatically calculated to maintain the original aspect ratio.
6. `flappy.gif`: The resulting GIF animation will be saved with the name "flappy.gif" in the current directory.

-----
