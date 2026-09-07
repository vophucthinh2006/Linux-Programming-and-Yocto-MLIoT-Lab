# Linux IPC Signal Operations

This module explores Inter-Process Communication (IPC) using Linux signals, covering fundamental signal handling, timer implementation, inter-process signal transmission, and concurrent signal management alongside keyboard input[cite: 5].

---

## Exercise 1: Catching and Handling `SIGINT`

Learn how to intercept and handle standard terminal signals[cite: 5].

### Requirements
1. Write a program to catch the `SIGINT` signal (triggered by pressing `Ctrl+C`) and print a notification message[cite: 5].
2. Use the `signal()` function to register a handler for `SIGINT`[cite: 5].
3. In the handler function, print `"SIGINT received"` every time the signal is caught[cite: 5].
4. Continue running until `SIGINT` is received for the 3rd time, then terminate[cite: 5].
* *Hint:* Use a global counter variable to track the number of received `SIGINT` signals[cite: 5].

### Analysis Question
* What happens when pressing `Ctrl+C` if the `SIGINT` signal is ignored[cite: 5]?

---

## Exercise 2: Creating a Timer with `SIGALRM`

Explore how to implement timer-based periodic tasks using alarms[cite: 5].

### Requirements
1. Write a program that creates a timer using the `SIGALRM` signal[cite: 5].
2. Use the `alarm()` function to trigger `SIGALRM` every second[cite: 5].
3. Upon receiving `SIGALRM`, increment a counter and print `"Timer: <seconds> seconds"`[cite: 5].
4. Stop the program after counting up to 10 seconds[cite: 5].
* *Hint:* Use `signal()` to register a handler for `SIGALRM`, and call `alarm(1)` to repeat the timer every second[cite: 5].

### Analysis Question
* What happens if `alarm(1)` is not called again inside the handler function[cite: 5]?

---

## Exercise 3: Inter-Process Communication Using Signals (`SIGUSR1`)

Demonstrate process-to-process communication utilizing user-defined signals[cite: 5].

### Requirements
1. Use `fork()` to create a child process from a parent process[cite: 5].
2. The parent process sends the `SIGUSR1` signal to the child process every 2 seconds[cite: 5].
3. Upon receiving `SIGUSR1`, the child process prints `"Received signal from parent"`[cite: 5].
4. Stop the program after sending the signal 5 times[cite: 5].
* *Hint:* Use `kill()` to send signals from the parent to the child, and use `signal()` in the child process to catch `SIGUSR1`[cite: 5].

### Analysis Question
* Why do we need to use `kill()` to send signals in this exercise[cite: 5]?

---

## Exercise 4: Concurrent Signal Handling and Keyboard Input

Build robust programs that handle asynchronous signals without disrupting synchronous user input[cite: 5].

### Requirements
1. Use `select()` or `poll()` to allow the program to process signals without interruption while receiving keyboard input[cite: 5].
2. When `SIGINT` is received, print `"SIGINT received."`[cite: 5].
3. If `SIGTERM` is received, exit the program[cite: 5].
4. When the user types input and presses `Enter`, print the content to the console[cite: 5].