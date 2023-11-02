# Images To GIF

```bash
ffmpeg -framerate 50 -pattern_type glob -i '*.jpg' -r 15 -vf scale=680:-1 flappy.gif
```
