# peekat
A monostask image viewer

## Foreword:
This project is distributed under Zlib license

Only tested on Debian 9 (testing) with AMD64 architecture.

## Prerequisite
Peekat require Make, the GCC compiler, SDL2 and SDL2_image in order to work.

Move to the top of the folder and use `make` to compile the program. Use `make clean` or `make fclean` to delete .o files or .o files and complied program.

## Usage

Peekat is intended to be a simple image viewer that will not overflow out of the screen — the windows will be contained within preset dimensions (defined by the const variables within the code).

The complied software is not automatically moved to another folder, so you will need to call it directly

`./peekat [option] [file]

Peekat supports the following options

```
-b	Bordered mode (implicit default).
-f	Fullscreen mode.
-h	Help.
-v	Version.
```

Once started, Peekat is stopped by pressing the Esc key, the q key or simply the window's cross.

Peekat supports the following images formats: BMP, GIF (first frame), JPEG, PNG, TGA, TIFF, LBM, PNM, PCX, WEBP, XCF, XPM or XV.