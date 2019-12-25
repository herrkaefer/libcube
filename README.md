            _____ ______  _______ _    _  _____
     |        |   |_____] |______  \  /  |     | |
     |_____ __|__ |_____] |______   \/   |_____| |_____

![Language](https://img.shields.io/badge/language-C-lightgrey.svg?style=flat)

``libevol`` — An evolutionary algorithm framework in pure C.


## Usage

A demo with string can be found in `evol_test()` in `src/evol.c`.


## Evol module

The evolutionary algorithm framework. Detailed explanation of the model will be added in the future.

## Helper contrainers

### arrayset

Set with a built-in hash table, implemented with array.

### hash

Hash table, or dictionary.

### listu

List container of usigned integers implemented with array.

### listx

Generic double-linked list container.

### matrixd / matrixu

Double / size_t type dense matrix. You set and get, it resize silently.

### queue

Simple queue container, implemented with double-linked list.

### rng

Random number generator. A wrapper of [PCG](http://www.pcg-random.org/) RNGs.

### timer

Timer.

### arrayi

Extension of int type array.

### arrayu

Extension of size_t type array.

### date_ext

Extension of date type.

### numeric_ext

Extension of numeric type.

### string_ext

Extension of string type.


## Build and install

```sh
git clone https://github.com/herrkaefer/libevol.git
cd libevol
make
make install
```


## License

Mozilla Public License Version 2.0
