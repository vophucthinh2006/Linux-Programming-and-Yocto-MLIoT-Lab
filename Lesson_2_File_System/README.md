# Linux File Metadata Inspector (`filestat`)

Every file and directory on a Linux file system contains not only data but also a large amount of metadata stored in a structure called an inode. Metadata includes file type, size, permissions, owner information, and crucial timestamps.

The `stat` family of system calls is the most accurate and efficient way for a C program to access this information without parsing shell command outputs like `ls -l`.

In this exercise, you will build a small command-line tool named `filestat`, similar to the built-in `stat` command on Linux, to read and display key information of any given file.

---

## Exercise: Writing the `filestat.c` Program

### Requirements
1. **Command-Line Arguments:** The program must accept exactly one argument from the command line: the path to a file or directory.
2. **Validation:** If no argument is provided, print the usage guide (e.g., `Usage: ./filestat <file_path>`) and exit.
3. **System Call:** Use the `lstat()` system call to retrieve information about the object at the specified path and store it in a `struct stat` variable.

### Displayed Information
The program must output the following details:
* **File Path:** The path entered by the user.
* **File Type:** The type of the object. You must identify and print at least three main types:
  * `"Regular File"`
  * `"Directory"`
  * `"Symbolic Link"`
  * *Hint:* Use the macros `S_ISREG()`, `S_ISDIR()`, and `S_ISLNK()` from `<sys/stat.h>` to check the `st_mode` field.
* **Size:** The size of the file, retrieved from the `st_size` field (printed with the unit "bytes").
* **Last Modified:** The last modification time of the file.
  * Retrieve the `time_t` value from the `st_mtime` field.
  * Convert this timestamp into a human-readable date-time string.
  * *Hint:* Use the `ctime()` or `strftime()` function from `<time.h>` to format the time.