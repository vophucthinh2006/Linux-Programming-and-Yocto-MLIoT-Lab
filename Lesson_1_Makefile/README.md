# C Static and Shared Libraries Tutorial

As a C programming project grows, organizing source code into reusable modules becomes crucial. Libraries allow you to package a set of related functions to share across multiple projects without duplicating source code.

- **Static Library (`.a`):** Library code is copied and embedded directly into your executable at compile time. The executable becomes larger but can run independently.
- **Shared Library (`.so` - Shared Object):** Library code is not embedded into the executable. Instead, the operating system loads the library into memory once at runtime, allowing multiple programs to share it.

---

## 1. Building the String Utility Library (`strutils`)

### Source Code Structure
* `strutils.h`: Defines the functions provided by the library:
  * `str_reverse`: Reverses a string in-place.
  * `str_trim`: Removes leading and trailing whitespace from a string.
  * `str_to_int`: Safely converts a string to an integer[cite: 1].
* `strutils.c`: Source code implementing the functions defined in `strutils.h`[cite: 1].
* `main.c`: Main program used to test the functions in the `strutils` library[cite: 1].

### Packaging the Library
* **Create a Static Library (`libstrutils.a`)**[cite: 1]
* **Create a Shared Library (`libstrutils.so`)**[cite: 1]

### Using the Library
Write a main program to test the functions in the `strutils` library[cite: 1], then compile and link:

* **With Static Library:**
  ```bash
  gcc main.c -L. -lstrutils -o main_static
```

* **With Shared Library:**
  ```bash
gcc main.c -L. -lstrutils -o main_shared
```

---

## 2. Automation with Makefile

Create a file named `Makefile` to automate the build process[cite: 1]. You can use the following standard targets:

* `all`: The default target, which builds both `main_static` and `main_shared` versions[cite: 1].
* `static`: Builds only the static library (`libstrutils.a`) and the static executable (`main_static`)[cite: 1].
* `shared`: Builds only the shared library (`libstrutils.so`) and the shared executable (`main_shared`)[cite: 1].
* `clean`: Removes all temporary and compiled files generated during the build process (`.o`, `.a`, `.so`, and executables)[cite: 1].