# brainfuck-interpreter

Interpreter for the esoteric programming language: brainfuck

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
