# <center>Get next line - 42 School project</center>

## Description
Write a function that returns a line read from a file descriptor. Repeated calls to get_next_line() function should let you read the text file pointed to by the file descriptor, **one line at a time**.

If there is nothing else to read or if an error occurred, it should return NULL. Makre sure that your function works as expected both when reading a file and when reading from the standard input.

**Please note** that the returned line should include the terminating \n character, except if the end of file was reached and does not end with a \n character.

lseek() and global variables are **Forbidden**. Detailed project requirements can be found [here](get_next_line.pdf).

<br>

## Language used
[![Language used](https://skills.thijs.gg/icons?i=c)](https://skills.thijs.gg)

<br>

## Usage
Because you will have to read files in get_next_line(), add this option to your compiler call: -D BUFFER_SIZE=n. It will define the buffer size for read(). For example: cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

<br>

## Testing

*External testers:*

+ [gnlTester](https://github.com/Tripouille/gnlTester.git)

<br>

## Related Projects

+ [libft](https://github.com/lanximaomao/libft)
+ [ft_printf](https://github.com/lanximaomao/ft_printf)
