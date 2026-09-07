# Linux Programming and Yocto Project

A comprehensive collection of source code, lab exercises, and project notes covering Linux system programming, kernel development, device drivers, and Yocto custom distribution building from the **MLIoT Lab** curriculum.

## Course Overview & Theoretical Foundation

This repository contains the complete implementation and study materials for the **MLIoT - Linux Programming and Yocto** course. The curriculum bridges high-level user-space applications with low-level kernel development and custom embedded Linux operating system generation. 

For detailed theoretical notes, concepts, and course documentation, refer to the official [MLIoT - Linux Programming and Yocto (Notion Course Notes)](https://app.notion.com/p/3d369cf6c466803a912de67bb8ecf6da?v=3d369cf6c46680c4a090000c6c995a8f).

---

## Course Structure & Contents

### Part 1: System Programming & IPC (Sessions 1 - 10)
* **Makefile & Filesystem:** Automated build workflows, static/shared library compilation, and file metadata inspection (`filestat` using `stat`/`lstat`)[cite: 1, 2].
* **Process Management:** Process lifecycles, `fork()`, `wait()`, executable replacement (`exec()`), and special process states (Zombie and Orphan)[cite: 3].
* **Multithreading (pthreads):** Thread creation/joining, race conditions, Mutexes, Condition Variables (Producer-Consumer model), and Read-Write Locks[cite: 4].
* **Inter-Process Communication (IPC):** 
  * Signals (`SIGINT`, `SIGALRM`, `SIGUSR1`, and concurrent I/O with `select`/`poll`)[cite: 5].
  * Sockets, Message Queues, Pipes & FIFO, Shared Memory, and Semaphores.

### Part 2: Yocto Project & Embedded Systems (Sessions 11 - 14)
* Introduction to Yocto, SDK, and Devtool.
* Building custom Linux distributions and images for Raspberry Pi.

### Part 3: Linux Kernel & Device Drivers (Sessions 15 - 26)
* Linux Kernel Introduction & Hello World Kernel Modules.
* Character Device Drivers, GPIO, Device Tree, and Pinctrl configuration.
* Bus Drivers & Interfaces: I2C (Client device drivers), SPI, and `ioctl` implementations.
* Kernel debugging with GDB.

### Capstone Project
* **Final Project:** Integrating Linux system programming, kernel drivers, or custom Yocto components into a cohesive embedded solution.

---

## Getting Started

Clone the repository and navigate into any specific session folder to explore the source code, implementation examples, and individual README guides.