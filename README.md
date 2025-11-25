# ft_printf

This project is a partial imitation of the [printf()](https://man7.org/linux/man-pages/man3/fprintf.3.html) function which is a standart library function for C.<br>
The main difference is that ft_printf doesn't do buffer management and instead prints every character one by one.<br>
It handles these flags:

| %c | %s | %p | %d | %i | %u | %x | %X | %%
|----|----|----|----|----|----|----|----|----|
|prints a single character|prints an array of characters (string)|prints a void * pointer in hexadecimal form|prints a decimal in base 10|prints an integer in base 10|prints an unsigned integer in base 10|prints a hexadecimal (base 16) number in lowercase|prints a hexadecimal (base 16) number in uppercase|prints the character '%'

## Bonus

In addition to the flags above, bonus includes:


| - | 0 | . | # | (space) | +
|----|----|----|----|----|----|
|The converted value is to be left adjusted on the field boundary.  (The default is right justification.)  The converted value is padded on the right with blanks, rather than on the left with blanks or zeros.  A - overrides a 0 if both are given. | The value should be zero padded. For d, i, u, x, X, the converted value is padded on the left with zeros rather than blanks.  If the 0 and - flags both appear, the 0 flag is ignored.  If a precision is given with an integer conversion (d, i, u, x, and X), the 0 flag is ignored.  For other conversions, the behavior is undefined. | An optional precision, in the form of a period ('.')  followed by an optional decimal digit string.  Instead of a decimal digit string one may write "*" to specify that the precision is given in the next argument, which must be of type int. If the precision is given as just '.', the precision is taken to be zero.  A negative precision is taken as if the precision were omitted.  This gives the minimum number of digits to appear for d, i, u, x, and X conversions, or the maximum number of characters to be printed from a string for s conversions. | For x and X conversions, a nonzero result has the string "0x" (or "0X" for X conversions) prepended to it.  For a, For other conversions, the result is undefined. | (a space) A blank should be left before a positive number (or empty string) produced by a signed conversion. | A sign (+ or -) should always be placed before a number produced by a signed conversion.  By default, a sign is used only for negative numbers.  A + overrides a space if both are used.

## Usage

`make` to make the library (libftprintf.a)<br>
`make bonus` to make the bonus library (libftprintf.a)
