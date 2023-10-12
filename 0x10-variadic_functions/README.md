Variadic Functions in C
Introduction:
In C, functions typically have a fixed number of parameters. But what if you wanted a function to accept a variable number of arguments? This is where variadic functions come in.

Learning Objective 1: What are variadic functions?
Variadic Functions are functions in C that allow for an indefinite number of arguments.
The most common example is printf(). You can give printf() any number of arguments, and it handles them: printf("%d %s", age, name);.
Learning Objective 2: How to use va_start, va_arg, and va_end macros?
To handle variadic functions, C provides a set of macros defined in stdarg.h:

va_list: A type to hold the information about variable arguments.
va_start: Initializes the va_list to point to the first variable argument.
va_arg: Retrieves the next variable argument.
va_end: Cleans up the va_list.