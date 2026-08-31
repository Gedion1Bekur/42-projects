*This project has been created as part of the 42 curriculum by gbekur.*

# Get Next Line

## Description

Get Next Line is a project from the 42 curriculum focused on reading a file descriptor one line at a time.

The goal is to implement the `get_next_line()` function in C without using the standard `getline()` function. The function uses the `read()` system call to read data from a file descriptor and returns one line every time it is called.

The main challenge is that `read()` does not necessarily read exactly one line. Depending on the `BUFFER_SIZE`, a single read may contain part of a line, one complete line, or several lines.

The implementation therefore needs to store the data that has already been read, find the next newline character, return the corresponding line, and preserve any remaining data for the next call.

This project provides practical experience with:

- File descriptors
- The `read()` system call
- Dynamic memory allocation
- Pointers
- Structures
- Linked lists
- Static variables
- String manipulation
- Memory management
- Error handling
- End-of-file handling

---

## How It Works

The main function is:

```c
char *get_next_line(int fd);
```

It receives a file descriptor and returns the next line from that file.

For example, if the file contains:

```text
Hello
World
This is Get Next Line
42
```

Calling `get_next_line()` repeatedly returns:

```text
Hello
World
This is Get Next Line
42
```

When there is no more data to read, the function returns `NULL`.

Every returned string is dynamically allocated and must be freed by the caller:

```c
char *line;

line = get_next_line(fd);
while (line)
{
    printf("%s", line);
    free(line);
    line = get_next_line(fd);
}
```

---

## BUFFER_SIZE

The project uses `BUFFER_SIZE` to determine how many bytes are requested from `read()` at a time.

For example:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main.c
```

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 get_next_line.c get_next_line_utils.c main.c
```

The implementation should work correctly regardless of the chosen buffer size.

A small `BUFFER_SIZE` means that a line may need to be assembled from many separate reads.

A large `BUFFER_SIZE` may cause one read to contain multiple lines.

The implementation must therefore correctly handle both situations.

---

## Linked List Buffering

The implementation uses a linked list to store chunks of data read from the file descriptor.

The node structure is:

```c
typedef struct s_node
{
    char            *str_buf;
    struct s_node   *next;
}   t_node;
```

Each node contains:

- `str_buf` - the chunk of data read from the file.
- `next` - a pointer to the next node.

For example, a long line may be stored as several chunks:

```text
[Hello] -> [ Worl] -> [d\n]
```

The chunks are then combined to create the complete line.

Using a linked list makes it possible to store data even when one line is larger than `BUFFER_SIZE`.

---

## Static State

A static variable is used to preserve the linked list between calls to `get_next_line()`.

This is necessary because a call to `read()` can read more data than is needed for the current line.

For example, the file may contain:

```text
Hello
World
```

A single read could retrieve:

```text
Hello
World
```

The first call should return:

```text
Hello
```

but the data belonging to:

```text
World
```

must remain available for the next call.

The stored list therefore preserves unread data between function calls.

---

## Reading Process

The general process of `get_next_line()` is:

1. Check that the file descriptor and `BUFFER_SIZE` are valid.
2. Read data from the file descriptor using `read()`.
3. Store each read buffer in the linked list.
4. Search the stored data for a newline character.
5. Continue reading if a complete line has not been found.
6. Calculate the length of the line.
7. Allocate enough memory for the returned line.
8. Copy the line from the linked-list nodes.
9. Remove the data that belongs to the returned line.
10. Preserve any remaining data for the next call.
11. Return the newly allocated line.

---

## Newline Handling

A normal line ends with:

```c
'\n'
```

When a newline is found, it is included in the returned string.

For example:

```text
Hello\n
```

is returned as:

```c
"Hello\n"
```

If the final line does not contain a newline, it is still returned.

For example, a file containing:

```text
Hello
World
42
```

where `42` has no final newline should return:

```text
"Hello\n"
"World\n"
"42"
```

The following call then returns:

```c
NULL
```

---

## End Of File

When `read()` returns `0`, the end of the file has been reached.

If there is still remaining data stored in the linked list, that data is returned as the final line.

If there is no remaining data, `get_next_line()` returns `NULL`.

This allows the function to correctly handle files that do not end with a newline.

---

## Memory Management

Memory management is an important part of this project.

The implementation dynamically allocates memory for:

- Read buffers
- Linked-list nodes
- Returned lines

Allocated memory must be released when it is no longer needed.

The returned line belongs to the caller and must be freed:

```c
free(line);
```

The internal linked-list nodes and their buffers are also freed when their data has been consumed or when an error occurs.

Correct memory management is important to avoid:

- Memory leaks
- Invalid memory access
- Double frees
- Use-after-free errors

---

## Error Handling

The implementation handles several error cases, including:

- Invalid file descriptors
- Invalid `BUFFER_SIZE`
- `read()` errors
- `malloc()` failures
- End of file

For example:

```c
if (fd < 0 || BUFFER_SIZE <= 0)
    return (NULL);
```

If a memory allocation fails or `read()` returns an error, allocated data is cleaned up before returning.

---

## Project Structure

```text
get_next_line/
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
└── main.c
```

### `get_next_line.c`

Contains the main `get_next_line()` function and the logic responsible for coordinating the reading process.

It:

- Validates the file descriptor.
- Reads data when necessary.
- Creates the returned line.
- Cleans the consumed data.
- Maintains the static linked-list state.

### `get_next_line_utils.c`

Contains helper functions used by the main implementation.

These functions are responsible for:

- Reading buffers
- Adding buffers to the linked list
- Calculating line length
- Creating the returned line
- Cleaning consumed data
- Freeing the linked list

### `get_next_line.h`

Contains:

- Header guards
- Required libraries
- `BUFFER_SIZE`
- The linked-list structure
- Function prototypes

### `main.c`

Used as a local testing program.

It:

1. Opens a file.
2. Calls `get_next_line()` repeatedly.
3. Prints every returned line.
4. Frees each returned line.
5. Closes the file descriptor.

---

## Compilation

Compile the project with:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

Then run:

```bash
./a.out
```

You can change `BUFFER_SIZE` to test different reading situations.

---

## Testing

The implementation was tested using multiple `BUFFER_SIZE` values.

### BUFFER_SIZE = 1

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main.c && ./a.out
```

Example output:

```text
LINE: Hello
LINE: World
LINE: This is Get Next Line
LINE: 42
```

### BUFFER_SIZE = 42

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c && ./a.out
```

Example output:

```text
LINE: Hello
LINE: World
LINE: This is Get Next Line
LINE: 42
```

### BUFFER_SIZE = 9999

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 get_next_line.c get_next_line_utils.c main.c && ./a.out
```

Example output:

```text
LINE: Hello
LINE: World
LINE: This is Get Next Line
LINE: 42
```

The same lines were correctly returned with different buffer sizes.

---

## Testing A File Without A Final Newline

The project was also tested with a file whose final line does not contain a newline.

The test file was created with:

```bash
printf "Hello\nWorld\n42" > no_newline.txt
```

The file contains:

```text
Hello
World
42
```

but the final `42` does not have a trailing `\n`.

Running the program correctly returns:

```text
LINE: Hello
LINE: World
LINE: 42
```

This confirms that the implementation handles the final line correctly even when the file does not end with a newline.

---

## Norminette

The project was checked using Norminette:

```bash
norminette get_next_line.c get_next_line_utils.c get_next_line.h
```

The final implementation passed the Norminette check:

```text
get_next_line.c: OK!
get_next_line_utils.c: OK!
get_next_line.h: OK!
```

---

## What I Learned

Through this project, I practiced working with low-level file input in C and gained a better understanding of how data can be processed when it does not arrive in convenient chunks.

The main concepts I worked with were:

- File descriptors
- `read()`
- `malloc()`
- `free()`
- Pointers
- Structures
- Linked lists
- Static variables
- Null-terminated strings
- Dynamic memory allocation
- Memory management
- Error handling
- End-of-file handling

The project helped me understand how `read()` works with different buffer sizes and why the program needs to preserve data between calls.

It also gave me practical experience managing dynamically allocated memory and linked-list nodes.

---

## Resources

- GNU C Library I/O documentation:
  https://www.gnu.org/software/libc/manual/html_node/I_002fO.html

- `read()` manual:
  https://man7.org/linux/man-pages/man2/read.2.html

- `malloc()` manual:
  https://man7.org/linux/man-pages/man3/malloc.3.html

- `free()` manual:
  https://man7.org/linux/man-pages/man3/free.3.html

- 42 documentation and community resources related to Get Next Line, file descriptors, linked lists, and memory management.

---

## AI Usage

AI was used as a learning and debugging support tool during the development of this project.

It was used to help with:

- Understanding the Get Next Line requirements
- Understanding `read()` and `BUFFER_SIZE`
- Understanding linked-list buffering
- Understanding static variables
- Debugging memory-management issues
- Checking edge cases
- Understanding EOF behavior
- Debugging compiler errors
- Fixing Norminette errors
- Reviewing the project structure

The implementation was adapted, tested, and verified by the author as part of the learning process.

---

## Conclusion

Get Next Line is a project that demonstrates how to build a line-reading function using low-level C functionality.

The main challenge is managing data that may be split across multiple reads while preserving data that belongs to future calls.

By combining:

- `read()`
- Dynamic memory allocation
- Linked lists
- Static state
- String manipulation

the implementation can return one line at a time while handling different buffer sizes, long lines, and files without a final newline.

This project strengthened my understanding of:

- Memory management
- Pointers
- Linked lists
- File descriptors
- Static variables
- Low-level input/output in C
- Error handling
- EOF handling
