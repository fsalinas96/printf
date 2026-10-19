*This project has been created as part of the 42 curriculum by fsalinas.*

# ft_printf

## Description

**ft_printf** is a recreation of a subset of the standard C `printf` function. The goal is to learn how variadic functions work, how formatted output is processed, and how to convert different data types into printable characters using low-level output.

The function takes a format string followed by optional arguments, writes the resulting text to standard output, and returns the number of characters printed.

### Supported conversions

| Specifier | Output |
| --- | --- |
| `%c` | A single character |
| `%s` | A string |
| `%p` | A pointer address in hexadecimal |
| `%d` | A signed decimal base 10 |
| `%i` | A signed integer |
| `%u` | An unsigned decimal integer |
| `%x` | An unsigned hexadecimal integer (lowercase) |
| `%X` | An unsigned hexadecimal integer (uppercase) |
| `%%` | A literal percent sign |

Only the mandatory conversions are implemented; bonus format flags, width, and precision are outside the scope of this project.

## Instructions

### Compilation

From the repository root, build the static library with:

```sh
make
```

This produces `libftprintf.a`. The usual Makefile targets can be used to manage build files:

```sh
make clean    # Remove object files
make fclean   # Remove object files and the library
make re       # Rebuild from scratch
```

### Usage

Include the header in a C program:

```c
#include "ft_printf.h"

int main(void)
{
    int age = 30;

    ft_printf("Age: %d | Hex: %x | Text: %s\n", age, age, "hello");
    return (0);
}
```

After building the library, compile and link the program:

```sh
cc main.c -L. -lftprintf -o demo
./demo
```

Expected output:

```text
Age: 30 | Hex: 1e | Text: hello
```

## Algorithm and Data Structure Choices

The implementation follows a **single-pass, character-by-character parsing strategy**:

1. Initialize a `va_list` with `va_start` to access the optional arguments.
2. Traverse the format string from left to right using an index.
3. Write ordinary characters directly to standard output with `write`.
4. When `%` is encountered, inspect the following character to identify the conversion.
5. Retrieve the corresponding argument with `va_arg`, using the appropriate type, and dispatch it to a dedicated printing helper.
6. Add the number of characters written by each helper to the running total. Finish with `va_end` and return that total.

**Number conversion:** Decimal and hexadecimal output use recursive division and modulo. The recursive calls process the higher-order digits first, then each call writes its remaining digit. Hexadecimal uses base 16 and maps remainders from 10 to 15 to `a`–`f` or `A`–`F`.

**Data structures:** A `va_list` keeps track of variadic arguments, while a format-string index and integer counter track parsing and output length. No dynamically allocated output buffer is needed: characters are written as they are processed. This keeps auxiliary memory usage small and avoids allocation solely for formatting.

**Special cases:** The implementation distinguishes the character `\0` from a string terminator, handles zero as a printable number, and treats null string and pointer arguments separately. Their textual representation can depend on the C library and platform.

## Testing

The project can be tested by comparing `ft_printf` against the standard `printf`, checking both the resulting bytes and the return value. Relevant cases include ordinary text, consecutive specifiers, zero, negative numbers, integer limits, empty strings, null arguments, hexadecimal conversions, and literal percent signs.

## Resources

- **My peers at Codam** — discussions, reviews, and feedback on the implementation and edge cases.
- [TutorialsPoint — What is the use of `%p` in `printf` in C?](https://www.tutorialspoint.com/article/what-is-the-use-of-p-in-printf-in-c) — pointer formatting.
- [GeeksforGeeks](https://www.geeksforgeeks.org/) — C language concepts, variadic functions, and numeric conversions.
- [cppreference](https://en.cppreference.com/w/c/variadic) — reference documentation for `va_list`, `va_start`, `va_arg`, and `va_end`.

### Use of AI

AI was used as a **learning and debugging aid** to explain variadic arguments, review the logic of recursive conversion functions, identify possible edge cases, and help develop tests comparing output and return values. AI also assisted in organizing and drafting this README. The project implementation was developed and revised by the author.
