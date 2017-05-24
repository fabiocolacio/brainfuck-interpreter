# brainfuck-interpreter

Interpreter for the esoteric programming language, brainfuck.

## What is Brainfuck?

Brainfuck is an esoteric programming language in which there is an array of ascii
characters (with a size of at least 30,000 cells), and a pointer which can move
from cell to cell one at a time. The pointer can also increment or decrement the values in each cell
one at a time. The language consists of only 8 commands as follows:

Command | Action
-------:|---
``>``   | move to next cell
``<``   | move to previous cell
``+``   | increment the value of the current cell by 1
``-``   | decrement the value of the current cell by 1
``.``   | print the ascii character of the current cell to stdout
``,``   | get a character from stdin and store it in the current cell
``[``   | if the current cell is 0, jump to the matching ``]``
``]``   | if the current cell is **not** 0, jump to the matching ``[``

**Note:**
My implementation of Brainfuck is memory safe.
In other words, using ``<`` from cell 0 will wrap around to the
last cell, and using ``>`` from the last cell will wrap around to
the first cell, eliminating the possibility of dangling pointers.

If you would like to learn more about the brainfuck language,
you can check out [the esolangs wiki.](http://esolangs.org/wiki/brainfuck)

If you would like to try to master the language, feel free to build my interpreter on
your system (instructions below)
or try out this [nifty brainfuck visualizer.](http://fatiherikli.github.io/brainfuck-visualizer/)

## Build Instructions:

```
$ git clone https://github.com/fabiocolacio/brainfuck-interpreter
$ cd brainfuck-interpreter
$ mkdir build
$ cd build
$ cmake ..
$ make
```

There is a debugging mode which was added for the purposes of writing
this interpreter. Debug mode can optionally be enabled with the following flag:

```
$ cmake -DDEBUG=ON
```

## Install Instructions

After building, run:

```
$ sudo make install
```
