# Linux IPC Signal Operations

This module explores Inter-Process Communication (IPC) using Linux signals, covering fundamental signal handling, timer implementation, inter-process signal transmission, and concurrent signal management alongside keyboard input.

---

## Exercise 1: Catching and Handling `SIGINT`

Learn how to intercept and handle standard terminal signals.

### Requirements
1. Write a program to catch the `SIGINT` signal (triggered by pressing `Ctrl+C`) and print a notification message.
2. Use the `signal()` function to register a handler for `SIGINT`.
3. In the handler function, print `"SIGINT received"` every time the signal is caught.
4. Continue running until `SIGINT` is received for the 3rd time, then terminate.
* *Hint:* Use a global counter variable to track the number of received `SIGINT` signals.

### Analysis Question
* What happens when pressing `Ctrl+C` if the `SIGINT` signal is ignored?

---

## Exercise 2: Creating a Timer with `SIGALRM`

Explore how to implement timer-based periodic tasks using alarms.

### Requirements
1. Write a program that creates a timer using the `SIGALRM` signal.
2. Use the `alarm()` function to trigger `SIGALRM` every second.
3. Upon receiving `SIGALRM`, increment a counter and print `"Timer: <seconds> seconds"`.
4. Stop the program after counting up to 10 seconds.
* *Hint:* Use `signal()` to register a handler for `SIGALRM`, and call `alarm(1)` to repeat the timer every second.

### Analysis Question
* What happens if `alarm(1)` is not called again inside the handler function?

---

## Exercise 3: Inter-Process Communication Using Signals (`SIGUSR1`)

Demonstrate process-to-process communication utilizing user-defined signals.

### Requirements
1. Use `fork()` to create a child process from a parent process.
2. The parent process sends the `SIGUSR1` signal to the child process every 2 seconds.
3. Upon receiving `SIGUSR1`, the child process prints `"Received signal from parent"`.
4. Stop the program after sending the signal 5 times.
* *Hint:* Use `kill()` to send signals from the parent to the child, and use `signal()` in the child process to catch `SIGUSR1`.

### Analysis Question
* Why do we need to use `kill()` to send signals in this exercise?

---

## Exercise 4: Concurrent Signal Handling and Keyboard Input

Build robust programs that handle asynchronous signals without disrupting synchronous user input.

### Requirements
1. Use `select()` or `poll()` to allow the program to process signals without interruption while receiving keyboard input.
2. When `SIGINT` is received, print `"SIGINT received."`.
3. If `SIGTERM` is received, exit the program.
4. When the user types input and presses `Enter`, print the content to the console.