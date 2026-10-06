*This project has been created as part of the 42 curriculum by mabd-elh*

# Get Next Line

## Description
Get Next Line is a C programming project designed to implement a function that reads a single line from a given file descriptor (`fd`). This project introduces the concept of static variables in C, allowing the function to retain its state and keep track of the reading position between multiple function calls. The function successfully handles reading from files as well as standard input, returning the extracted line (including the newline character) or `NULL` if there is nothing left to read or an error occurs. 

## Instructions

### Compilation
The project requires you to define a buffer size during compilation. You can compile the project files alongside your own test files using the following command:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c your_main.c
```
*(Note: You can change `42` to any positive integer to test different buffer sizes).*

If you are compiling the bonus files, run:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c your_main.c
```

### Usage
Include the header file in your C code:
```c
#include "get_next_line.h"
```
Call `get_next_line(fd)` within a loop to read a file line by line until it returns `NULL`. Remember to `free()` the returned string after use to prevent memory leaks.

## Algorithm and Technical Choices
**Algorithm**: The core of the algorithm relies on a single static variable (`buffer`) to remember unread characters between function calls. 

1. The function first checks if this static buffer already contains a newline (`\n`).
2. If it doesn't, it uses `read()` to pull up to `BUFFER_SIZE` bytes from the file into the buffer. 
3. It continuously joins these new chunks of text together until it finds a newline or reaches the end of the file.
4. Once a newline is found, it extracts the line to return. Any extra characters that were read after the newline are kept in the static buffer so they are ready for the next call.

**Justification**: This method is efficient because it minimizes the number of times read() is called. The static variable safely stores the reading state across multiple calls without breaking the rule against global variables.

## Resources
* [man read](https://linux.die.net/man/3/read)
* [max num of files per proccess](https://stackoverflow.com/questions/30108288/max-number-of-open-files-per-process-in-linux)
* [@khaledhajeid](https://github.com/khaledhajeid)
* **AI Usage:** *AI was used solely for formatting this README and generating test concepts, not for writing the core algorithm logic."*