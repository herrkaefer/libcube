![](https://ws2.sinaimg.cn/large/006tKfTcly1fqyius8nkvj30go0akdhb.jpg)

# libcube

![Language](https://img.shields.io/badge/language-C-lightgrey.svg?style=flat)

``libcube`` — handy building cubes for C.

## Modules

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

### evol

An evolutionary algorithm framework.

## Build and install

```sh
git clone https://github.com/herrkaefer/libcube.git
cd libcube
make
make install
```
