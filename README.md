# 📝 get_next_line – Read a Line From a File Descriptor

## 📌 Description

g get_next_line is a fundamental project written in C at 42 School, designed to read and return a line from a file descriptor, one line at a time. It handles both standard input and files efficiently, even when reading large files or using different buffer sizes.

This project challenges your understanding of file handling, dynamic memory allocation, and string manipulation in C.

## 🎯 Key Features

-   💄 Reads a line from a file descriptor (including stdin or any file).
-   🔄 Handles multiple lines through repeated calls to get_next_line().
-   🧪 Handles any buffer size with the BUFFER_SIZE macro.
-   📝 Supports multiple file descriptors simultaneously (BONUS).
-   🚫 Proper error management (memory allocation failures, read errors, etc.).

## 🛠 Compilation and Usage

### 🔧 Compilation

You can compile your project using the provided Makefile:

```
make
```

### ▶️ Usage

Include the header in your source file:

```c
#include "get_next_line.h"

char *line;
int fd = open("example.txt", O_RDONLY);
while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

## 🔄 BUFFER_SIZE

Define the buffer size during compilation:

```
cc -D BUFFER_SIZE=42 your_program.c get_next_line.c get_next_line_utils.c
```

Alternatively, define it in the code:

```c
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
```

## 📂 Project Structure

```
get_next_line/
├── get_next_line.c          # Core logic to read a line from a file descriptor
├── get_next_line_utils.c    # Utility functions for string manipulation
├── get_next_line.h          # Header file containing function prototypes
├── Makefile                 # Project compilation rules
├── README.md                # Project documentation
```

## 🔑 File Descriptions

-   get_next_line.c – Main logic to read and return a line from a file descriptor.
-   get_next_line_utils.c – String manipulation functions (e.g., ft_strjoin, ft_strdup, ft_strlen, ft_strchr, ft_substr, ft_strlcpy, ft_strlcat).
-   get_next_line.h – Function prototypes and includes.

## ⚙️ Functions Overview

| Function      | Description                                              |
| ------------- | -------------------------------------------------------- |
| get_next_line | Reads the next line from a file descriptor.              |
| ft_strlen     | Returns the length of a string.                          |
| ft_strchr     | Locates the first occurrence of a character in a string. |
| ft_strdup     | Duplicates a string into a newly allocated memory.       |
| ft_strjoin    | Concatenates two strings into a newly allocated memory.  |
| ft_substr     | Extracts a substring from a string.                      |
| ft_strlcpy    | Copies a string with buffer size protection.             |
| ft_strlcat    | Concatenates two strings with buffer size protection.    |

## ✅ Mandatory and Bonus Parts

| Part      | Description                                                                              |
| --------- | ---------------------------------------------------------------------------------------- |
| Mandatory | Basic get_next_line() functionality to read a line from a file descriptor.               |
| Bonus     | Supports multiple file descriptors at the same time (e.g., reading from multiple files). |

## 🚀 Testing

You can create a simple test file main.c like this:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Compile and run:

```
cc -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
./a.out
```

## 📜 Author

-   vbonnard (vbonnard@student.42perpignan.fr)

## 📌 Note

This project is part of 42 School’s curriculum.
If you encounter any issues or have suggestions, feel free to contribute or reach out! 🚀
