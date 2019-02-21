### imgspit
This simple program spits images out as C arrays of uint8_t.

If you just want to easily include some graphic directly into
your program without having to import it using some library,
this might be useful to you.

#### Compiling
```
cc -lm -o imgspit imgspit.c
```

#### Usage
```
imgspit /path/to/file.png > file.h
```
