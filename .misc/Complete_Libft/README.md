# Libft

## Overview

My custom C library that implements essential functions.
Includes functions for memory management, string manipulation, and more.

This is the In-Use Version of Libft for the Libft I programmed during the Project see [here](../../Libft/)

## Content

### [ft_printf](./ft_printf/)

A function that takes a format string and a variable number of arguments, and returns the number of characters printed.
It prints the formatted string to the standard output.
The function should handle the conversion specifiers %c, %s, %p, %d, %i, %u, %x, %X, %%.

For the Project version see [here](../../ft_printf/)

### [get_next_line](./get_next_line/)

A function that reads a line from a file descriptor and returns it as a string.
The function returns the line read, or NULL if the end of the file is reached.

For the Project version see [here](../../get_next_line/)

### [ft_atoi](./ft_atoi.c)

A function that converts a string to an integer. Includes negtative numbers. Skips over leading whitespaces.
Returns an integer.

### [ft_bzero](./ft_bzero.c)

A function that sets *n* bytes of the memory area pointed to by *s* to zero.

### [ft_calloc](./ft_calloc.c)

A function that allocates memory for an array of nmemb elements of size size bytes each and returns a pointer to the allocated memory. The memory is set to zero.
Returns NULL if the allocation fails and the pointer if it succeeds.

### [ft_isalnum](./ft_isalnum.c)

A function that checks if a character is an alphanumeric character.
Returns 1 if true, 0 if false.

### [ft_isalpha](./ft_isalpha.c)

A function that checks if a character is an alphabetical character.
Returns 1 if true, 0 if false.

### [ft_isascii](./ft_isascii.c)

A function that checks if a character is an ASCII character.
Returns 1 if true, 0 if false.

### [ft_isdigit](./ft_isdigit.c)

A function that checks if a character is a digit.
Returns 1 if true, 0 if false.

### [ft_isprint](./ft_isprint.c)

A function that checks if a character is printable.
Returns 1 if true, 0 if false.

### [ft_itoa](./ft_itoa.c)

A function that converts an integer to a string.
Returns a pointer to the string.

### [ft_memchr](./ft_memchr.c)

A function that locates the first occurrence of a character in a string.
Returns a pointer to the first occurrence of the character, or NULL if the character is not found.

### [ft_memcmp](./ft_memcmp.c)

A function that compares two blocks of memory.
Returns an integer less than, equal to, or greater than zero if the first block is less than, equal to, or greater than the second block, respectively.

### [ft_memcpy](./ft_memcpy.c)

A function that copies *n* bytes from memory area *src* to memory area *dest*. The memory areas must not overlap.
Returns a pointer to *dest*.

### [ft_memmove](./ft_memmove.c)

A function that copies *n* bytes from memory area *src* to memory area *dest*. The memory areas may overlap.
Returns a pointer to *dest*.

### [ft_memset](./ft_memset.c)

A function that sets *n* bytes of the memory area pointed to by *s* to the constant byte *c*.
Returns a pointer to *s*.

### [ft_putchar_fd](./ft_putchar_fd.c)

A function that writes a character to a file descriptor.

### [ft_putendl_fd](./ft_putendl_fd.c)

A function that writes a string to a file descriptor, followed by a newline.

### [ft_putnbr_fd](./ft_putnbr_fd.c)

A function that writes an integer to a file descriptor.

### [ft_putstr_fd](./ft_putstr_fd.c)

A function that writes a string to a file descriptor.

### [ft_split](./ft_split.c)

A function that splits a string *s* into an array of strings separated by the character *c*.
Returns a pointer to the array of strings, or NULL if the allocation fails.

### [ft_strchr](./ft_strchr.c)

A function that locates the first occurrence of a character in a string.
Returns a pointer to the first occurrence of the character, or NULL if the character is not found.

### [ft_strdup](./ft_strdup.c)

A function that duplicates a string.
Returns a pointer to the duplicated string, or NULL if the allocation fails.

### [ft_striteri](./ft_striteri.c)

A function that applies a function to each character of a string, passing its index as an argument.

### [ft_strjoin](./ft_strjoin.c)

A function that concatenates two strings.
Returns a pointer to the resulting string, or NULL if the allocation fails.

### [ft_strlcat](./ft_strlcat.c)

A function that concatenates two strings, with a maximum of *size* bytes in the resulting string.
Returns the length of the resulting string.

### [ft_strlcpy](./ft_strlcpy.c)

A function that copies a string, with a maximum of *size* bytes in the resulting string.
Returns the length of the resulting string.

### [ft_strlen](./ft_strlen.c)

A function that returns the length of a string.
Returns the length of the string.

### [ft_strmapi](./ft_strmapi.c)

A function that applies a function to each character of a string, passing its index and character as arguments.

### [ft_strncmp](./ft_strncmp.c)

A function that compares two strings.
Returns an integer less than, equal to, or greater than zero if the first string is less than, equal to, or greater than the second string, respectively.

### [ft_strnstr](./ft_strnstr.c)

A function that locates a substring in a string.
Returns a pointer to the first occurrence of the substring, or NULL if the substring is not found.

### [ft_strrchr](./ft_strrchr.c)

A function that locates the last occurrence of a character in a string.
Returns a pointer to the last occurrence of the character, or NULL if the character is not found.

### [ft_strtrim](./ft_strtrim.c)

A function that removes leading and trailing spaces from a string.
Returns a pointer to the resulting string, or NULL if the allocation fails.

### [ft_substr](./ft_substr.c)

A function that creates a substring from a string.
Returns a pointer to the substring, or NULL if the allocation fails.

### [ft_tolower](./ft_tolower.c)

A function that converts a character to lowercase.
Returns the lowercase character.

### [ft_toupper](./ft_toupper.c)

A function that converts a character to uppercase.
Returns the uppercase character.
