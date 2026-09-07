# Linux Process Management and Operations

This module explores the fundamental lifecycle of processes in Linux, process creation, execution replacement, environment manipulation, and special process states such as Zombie and Orphan.

---

## Exercise 1: Process Initialization and Cleanup

Explore the basic lifecycle of a process: creation, execution, termination, and parent waiting.

### Requirements
* **Parent Process:** Print its own PID and the child's PID. Then, use `wait()` to wait for the child to finish. Use `WIFEXITED()` and `WEXITSTATUS()` to record and print the exit code of the child process.
* **Child Process:** Print its own PID, then call `exit()` with a specific value (e.g., `exit(10)`).

---

## Exercise 2: Executable Replacement and Environment Interaction

Learn how a process can completely replace its running code with another program and how to pass information via environment variables.

### Requirements
* **Parent Process:** Set up an environment variable (e.g., `MY_COMMAND=ls`).
* **Child Process:** Read this environment variable[cite: 3]. Based on the value read, use the `exec()` family of functions (e.g., `execlp()`) to execute the corresponding command (e.g., `ls`, `date`).
* **Report Analysis:** Explain what happens to the address space and instruction code of the child process after `exec()` is called successfully.

---

## Exercise 3: Investigation of Special Process States

Observe and analyze two special process states commonly encountered in process management: Zombie and Orphan.

### Requirements
* **Create a Zombie Process:**
  * Write a program where the child process exits immediately, but the parent process does not call `wait()` and instead enters a `sleep()` state for a long period.
  * Use the `ps` command in the terminal to observe the `<defunct>` status of the child process.
* **Create an Orphan Process:**
  * Write a program where the parent process exits immediately after creating the child.
  * The child process sleeps for a while, and during that time, continuously prints its parent's PID (PPID) to observe changes.
* **Report Analysis:** Explain why these two states appear and what their significance is within the Linux system.