# get_next_line

A 42 school project that implements a function to read a file line by line. Each call to `get_next_line()` returns the next line from a file descriptor, making it easy to process text files one line at a time.

---

## How It Works

`get_next_line` reads from a file descriptor using a static buffer of size `BUFFER_SIZE`. On each call, it:

1. Reads chunks of `BUFFER_SIZE` bytes from the file into an internal buffer.
2. Extracts characters one by one until a newline (`\n`) is found or the file ends.
3. Returns the complete line (including the newline character, if present).
4. Returns `NULL` when there are no more lines to read or on error.

### Files

| File | Description |
|------|-------------|
| `get_next_line.c` | Main function `get_next_line()` that manages the static buffer and delegates to helper functions |
| `get_next_line_utils.c` | Helper functions: `read_line()`, `buffer_read()`, and `append_char_to_line()` |
| `get_next_line.h` | Header file with function prototypes and includes |

---

## Compilation

Since this is a library function (not a standalone program), you need to compile it together with a `main.c` test file.

### Basic compilation

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o gnl
```

### With a custom buffer size

You can override the default `BUFFER_SIZE` (42) at compile time:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main.c -o gnl
```

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1024 get_next_line.c get_next_line_utils.c main.c -o gnl
```

---

## Usage

### 1. Create a test file

```bash
echo "Hello, World!
This is line two.
And line three." > test.txt
```

### 2. Write a main.c

```c
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```

### 3. Compile and run

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o gnl
./gnl
```

### Expected output

```
Hello, World!
This is line two.
And line three.
```

---

## Function Prototype

```c
char	*get_next_line(int fd);
```

**Parameters:**
- `fd` - The file descriptor to read from.

**Return value:**
- The next line from the file (including `\n` if present).
- `NULL` if there is nothing more to read or an error occurred.

---

## Notes

- The returned line must be freed by the caller after each call.
- `BUFFER_SIZE` can be set to any positive value at compile time. The default is `42`.
- The function handles reading from standard input (`fd = 0`) as well as regular files.
- Passing an invalid file descriptor (negative value) returns `NULL`.
