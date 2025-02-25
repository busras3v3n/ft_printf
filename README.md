# ft_printf

This project is an imitation of the printf() function from stdio.h<br>
The main difference is that ft_printf doesn't do buffer management and instead prints every character one by one.<br>
It handles these flags:

| %c | %s | %p | %d | %i | %u | %x | %X | %%
|----|----|----|----|----|----|----|----|----|
|prints a single character|prints an array of characters (string)|prints a void * pointer in hexadecimal form|prints a decimal in base 10|prints an integer in base 10|prints an unsigned integer in base 10|prints a hexadecimal (base 16) number in lowercase|prints a hexadecimal (base 16) number in uppercase|prints the character '%'
