# The C (and Rust) Programming Language

> All exercises from the famous K&R book implemented in both C and Rust!

2020 is the year to learn even more about programming. Why not start learning the C language? Why not learn Rust as well?

Language war is not new. You can find a lot of people saying that Rust will replace C in the future because of all of its security features. Some others are saying C will never go away, as it is the foundation of most things used today. This repo is a shy initiative to those seeking to learn both languages and maybe get the best of both worlds.

**Just don't fight the Borrow Checker and don't let those pointer dereferences scare you!**

```
!!! Disclaimer !!!

This repo is intended as a way to learn about syntax and structure from both languages. It is not supposed to be a deep comparison of their features. These are for demonstration/educational purposes only.

```

## Structure

A tree defining the structure of this repo.

```
├── C
│   ├── chapter   // Book chapters (1-8)
│   │   └── number.c    // Exercise code (numbered within the book)
│   └── bin       // Contains executables and object files
└── rustlang
│   ├── chapter    // Book chapters (1-8)
│   │   └── number.rs    // Exercise code (numbered within the book)
│    └── bin     // Contains executables files
├── LICENSE      // License file
├── Makefile     // File used to generate executables and object files
├── README.md    // The file you are reading
```


## Table of Contents

 The exercises are linked in the table below using the same pattern from the book (e.g. `[chapter]-[number]`).

| Description |  `C` |  `Rust` |
|:------------:|:----:|:---------:|
|**Chapter 1**|---|---|
|Hello, World!|[1-1](./C/1/1.c)|[1-1](./rustlang/1/1.rs)|
|Printing with backlashed characters|[1-2](./C/1/2.c)|[1-2](./rustlang/1/2.rs)|
|Fahrenheit to Celsius table (_while_ loops)|[1-3](./C/1/3.c)|[1-3](./rustlang/1/3.rs)|
|Celsius to Fahrenheit table (_while_ loops)|[1-4](./C/1/4.c)|[1-4](./rustlang/1/4.rs)|
|Fahrenheit to Celsius in reversed order (_for_ loops)|[1-5](./C/1/5.c)|[1-5](./rustlang/1/5.rs)|
|I/O with _getchar_ and _putchar_|[1-6](./C/1/6.c)|[1-6](./rustlang/1/6.rs)|
|Checking _EOF_ value|[1-7](./C/1/7.c)|[1-7](./rustlang/1/7.rs)|
|Counting blanks, tabs and newlines from stdin|[1-8](./C/1/8.c)|[1-8](./rustlang/1/8.rs)|
|Replacing blanks from stdin|[1-9](./C/1/9.c)|[1-9](./rustlang/1/9.rs)|
|Replacing tabs, backspaces and backlashes from stdin|[1-10](./C/1/10.c)|[1-10](./rustlang/1/10.rs)|
|Implementing _wc_ unix program and questioning its behavior|[1-11](./C/1/11.c)|[1-11](./rustlang/1/11.rs)|
|Reading stdin and printing one word per line|[1-12](./C/1/12.c)|[1-12](./rustlang/1/12.rs)|
|Drawing an histogram of the length of words from input|[1-13](./C/1/13.c)|[1-13](./rustlang/1/13.rs)|
|Drawing an histogram of the frequencies of chars from input|[1-14](./C/1/14.c)|[1-14](./rustlang/1/14.rs)|
|A _function_ to convert Fahrenheit to Celsius|[1-15](./C/1/15.c)|[1-15](./rustlang/1/15.rs)|
|Computing the longest line from input (using _arrays_ and _functions_)|[1-16](./C/1/16.c)|[1-16](./rustlang/1/16.rs)|
|Printing lines from input greater than threshold (using _arrays_ and _functions_)|[1-17](./C/1/17.c)|[1-17](./rustlang/1/17.rs)|
|Removing trailing whitespaces/blanks/tabs from input (using _arrays_ and _functions_)|[1-18](./C/1/18.c)|[1-18](./rustlang/1/18.rs)|
|Reversing strings (using _arrays_ and _functions_)|[1-19](./C/1/19.c)|[1-19](./rustlang/1/19.rs)|
|A program to _detab_ (replace tabs with a _constant_ number of whitespaces)|[1-20](./C/1/20.c)|[1-20](./rustlang/1/20.rs)|
|A program to _entab_ (replace blanks with the minimum amount of tabs and blanks)|[1-21](./C/1/21.c)|[1-21](./rustlang/1/21.rs)|
|A program to _fold_ lines at a given limit|[1-22](./C/1/22.c)|[1-22](./rustlang/1/22.rs)|
|A program to remove all comments from a C source file|[1-23](./C/1/23.c)|[1-23](./rustlang/1/23.rs)|
|A program to check a C source file for rudimentary syntax errors.|[1-24](./C/1/24.c)|[1-24](./rustlang/1/24.rs)|
|**Chapter 2**|---|---|
|Checking ranges of basic data types.|[2-1](./C/2/1.c)|[2-1](./rustlang/2/1.rs)|
|Learning about logical operators.|[2-2](./C/2/2.c)|[2-2](./rustlang/2/2.rs)|
|Converting hex strings to integer values.|[2-3](./C/2/3.c)|[2-3](./rustlang/2/3.rs)|
|Squeezing characters from string.|[2-4](./C/2/4.c)|[2-4](./rustlang/2/4.rs)|
|Finding characters inside string.|[2-5](./C/2/5.c)|[2-5](./rustlang/2/5.rs)|
|Setting positioned bits in a number (_bitwise operators_).|[2-6](./C/2/6.c)|[2-6](./rustlang/2/6.rs)|
|Inverting bits in a number (_bitwise operators_).|[2-7](./C/2/7.c)|[2-7](./rustlang/2/7.rs)|
|Rotating bits in a number (_bitwise operators_).|[2-8](./C/2/8.c)|[2-8](./rustlang/2/8.rs)|
|Counting 1-bits in a number (_bitwise operators_).|[2-9](./C/2/9.c)|[2-9](./rustlang/2/9.rs)|
|Converting ascii letters to lower case (_ternary operator_).|[2-10](./C/2/10.c)|[2-10](./rustlang/2/10.rs)|
|**Chapter 3**|---|---|
|Binary search (_if-else statements_).|[3-1](./C/3/1.c)|[3-1](./rustlang/3/1.rs)|
|Converting scape sequences (_switch statements_).|[3-2](./C/3/2.c)|[3-2](./rustlang/3/2.rs)|
|Expanding string sequences (_loops_).|[3-3](./C/3/3.c)|[3-3](./rustlang/3/3.rs)|
|Converting numbers to strings (_loops_).|[3-4](./C/3/4.c)|[3-4](./rustlang/3/4.rs)|
|Converting numbers to strings in a different base (_loops_).|[3-5](./C/3/5.c)|[3-5](./rustlang/3/5.rs)|
|Converting numbers to strings with padding characters (_loops_).|[3-6](./C/3/6.c)|[3-6](./rustlang/3/6.rs)|
|**Chapter 4**|---|---|
|Search for a pattern inside a string (_functions_).|[4-1](./C/4/1.c)|[4-1](./rustlang/4/1.rs)|
|Converting strings with scientific notation into doubles (_functions_).|[4-2](./C/4/2.c)|[4-2](./rustlang/4/2.rs)|
|Adding modulus operation to a reverse Polish notation calculator (_functions_).|[4-3](./C/4/3.c)|[4-3](./rustlang/4/3.rs)|
|Adding new stack operations to a reverse Polish notation calculator (_functions_).|[4-4](./C/4/4.c)|[4-4](./rustlang/4/4.rs)|
|Adding new math operations to a reverse Polish notation calculator (_functions_).|[4-5](./C/4/5.c)|[4-5](./rustlang/4/5.rs)|
|Handling variables in a reverse Polish notation calculator (_functions_).|[4-6](./C/4/6.c)|[4-6](./rustlang/4/6.rs)|
|Input buffering in a reverse Polish notation calculator (_functions_).|[4-7](./C/4/7.c)|[4-7](./rustlang/4/7.rs)|
|Changing input buffering in a reverse Polish notation calculator (_functions_).|[4-8](./C/4/8.c)|[4-8](./rustlang/4/8.rs)|
|Dealing with EOF in the buffer of a reverse Polish notation calculator (_functions_).|[4-9](./C/4/9.c)|[4-9](./rustlang/4/9.rs)|
|Remove buffering in a reverse Polish notation calculator (_functions_).|[4-10](./C/4/10.c)|[4-10](./rustlang/4/10.rs)|
|Modifying variable visibility in a reverse Polish notation calculator (_header files, external and static variables_).|[4-11](./C/4/11/main.c)|[4-11](./rustlang/4/11/main.rs)|
|Converting int to string recursively (_recursive functions_).|[4-12](./C/4/12.c)|[4-12](./rustlang/4/12.rs)|
|Reversing a string recursively (_recursive functions_).|[4-13](./C/4/13.c)|[4-13](./rustlang/4/13.rs)|
|Swapping values using macros (_macro substitutions_).|[4-14](./C/4/14.c)|[4-14](./rustlang/4/14.rs)|
|**Chapter 5**|---|---|
|Reading ints from char stream (_pointers_).|[5-1](./C/5/1.c)|[5-1](./rustlang/5/1.rs)|
|Reading floats from char stream (_pointers_).|[5-2](./C/5/2.c)|[5-2](./rustlang/5/2.rs)|
|Implementing strcat (_pointers_).|[5-3](./C/5/3.c)|[5-3](./rustlang/5/3.rs)|
|Implementing strend (_pointers_).|[5-4](./C/5/4.c)|[5-4](./rustlang/5/4.rs)|
|Implementing strncpy, strncat and strncmp (_pointers_).|[5-5](./C/5/5.c)|[5-5](./rustlang/5/5.rs)|
|Reimplementing some functions using pointers (_pointers_).|[5-6](./C/5/6.c)|[5-6](./rustlang/5/6.rs)|
|Implementing 'sort' unix command (_pointers_).|[5-7](./C/5/7.c)|[5-7](./rustlang/5/7.rs)|
|Manipulating dates (_pointers_).|[5-8](./C/5/8.c)|[5-8](./rustlang/5/8.rs)|
|Manipulating dates without array indexing (_pointers_).|[5-9](./C/5/9.c)|[5-9](./rustlang/5/9.rs)|
|Reverse Polish notation calculator (_command line arguments_).|[5-10](./C/5/10.c)|[5-10](./rustlang/5/10.rs)|
|**Chapter 6**|---|---|
||[TBI](./C/)|[TBI](./rustlang/)|
|**Chapter 7**|---|---|
||[TBI](./C/)|[TBI](./rustlang/)|
|**Chapter 8**|---|---|
||[TBI](./C/)|[TBI](./rustlang/)|

## Resources

- [B. Kernighan and D. Ritchie, "The C Programming Language", 2nd ed., 1988.](https://en.wikipedia.org/wiki/The_C_Programming_Language)

- [S. Klabnik and C. Nichols, "The Rust Programming Language", 2018.](https://doc.rust-lang.org/stable/book/)


> Created by [ad80](https://github.com/adeilsonsilva).
