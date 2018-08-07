# Questions

## What's `stdint.h`?

`stdint.h` is a c standard library which allow programmers to write portable code by providing a set of typedefs that specify exact width integr types. `stdint.h` for C and `cstdint` for C++.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

The naming convention for exact integer types is `intN_t` for signed int and `uintN_t` for unsigned int. Thus the `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` are the typedefs for declaring unsigned 8, unsigned 32, signed 32, and unsigned 16 width intergers.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

`BYTE` is 1 byte, `DWORD` is 4 bytes, `LONG` is 4 bytes, `WORD` is 2 bytes. 

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

`0x42 0x4D` hecadecimal which represents B and M

## What's the difference between `bfSize` and `biSize`?

`bfSize` : size in bytes of bitmap file. `bisize` number of bytes required by the structure.

## What does it mean if `biHeight` is negative?

If biHeight is negative, the bitmap is a top-down DIB and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

`biBitCount` specifies the bits per pixel.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

If the file fails to open the fopen return NULL else it return the pointer to the bit in the file, position of which depened on the format in which file is opened.

## Why is the third argument to `fread` always `1` in our code?

Because that arguments specifies the number of elements of size specified in second arguments has to be read. And in case of this, the only 1 elements of `BITMAPFILEHEADER` and `BITMAPINFOHEADER` are to be read.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

fseek set the file pointer to the location as specified using the arguments

## What is `SEEK_CUR`?

It gives the current position of the file pointer.
