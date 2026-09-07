# Linux Process Management and Operations

This module explores the fundamental lifecycle of processes in Linux, process creation, execution replacement, environment manipulation, and special process states such as Zombie and Orphan[cite: 3].

---

## Exercise 1: Process Initialization and Cleanup

Explore the basic lifecycle of a process: creation, execution, termination, and parent waiting[cite: 3].

### Requirements
* **Parent Process:** Print its own PID and the child's PID[cite: 3]. Then, use `wait()` to wait for the child to finish[cite: 3]. Use `WIFEXITED()` and `WEXITSTATUS()` to record and print the exit code of the child process[cite: 3].
* **Child Process:** Print its own PID, then call `exit()` with a specific value (e.g., `exit(10)`)[cite: 3].

---

## Exercise 2: Executable Replacement and Environment Interaction

Learn how a process can completely replace its running code with another program and how to pass information via environment variables[cite: 3].

### Requirements
* **Parent Process:** Set up an environment variable (e.g., `MY_COMMAND=ls`)[cite: 3].
* **Child Process:** Read this environment variable[cite: 3]. Based on the value read, use the `exec()` family of functions (e.g., `execlp()`) to execute the corresponding command (e.g., `ls`, `date`)[cite: 3].
* **Report Analysis:** Explain what happens to the address space and instruction code of the child process after `exec()` is called successfully[cite: 3].

---

## Exercise 3: Investigation of Special Process States

Observe and analyze two special process states commonly encountered in process management: Zombie and Orphan[cite: 3].

### Requirements
* **Create a Zombie Process:**
  * Write a program where the child process exits immediately, but the parent process does not call `wait()` and instead enters a `sleep()` state for a long period[cite: 3].
  * Use the `ps` command in the terminal to observe the `<defunct>` status of the child process[cite: 3].
* **Create an Orphan Process:**
  * Write a program where the parent process exits immediately after creating the child[cite: 3].
  * The child process sleeps for a while, and during that time, continuously prints its parent's PID (PPID) to observe changes[cite: 3].
* **Report Analysis:** Explain why these two states appear and what their significance is within the Linux system[cite: 3].