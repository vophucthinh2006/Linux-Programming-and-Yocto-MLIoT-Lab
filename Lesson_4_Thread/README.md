# Linux Multithreading Programming

This module covers fundamental operations with POSIX threads (pthreads) in Linux, including thread lifecycle management, synchronization mechanisms, race conditions, Mutexes, Condition Variables, and Read-Write Locks[cite: 4].

---

## Exercise 1: Basic Thread Creation and Execution

Introduces foundational thread operations: creating new execution threads from the main thread and waiting for their completion[cite: 4].

### Requirements
1. **Thread Creation:** Write a C program that creates two threads[cite: 4].
2. **Thread Execution:** Each thread prints a message including its thread ID (e.g., `"Thread with ID <thread_id> is running!"`)[cite: 4].
3. **Synchronization:** The main thread must use `pthread_join()` to wait for both child threads to fully terminate before exiting[cite: 4].

### Analysis Questions
* Explain the roles and key parameters of `pthread_create()` and `pthread_join()`[cite: 4].
* When does a thread terminate[cite: 4]?

---

## Exercise 2: Race Conditions and Mutex Solutions

Demonstrates the classic "race condition" bug in multithreaded programming and introduces Mutex (Mutual Exclusion) to ensure safe access to shared resources[cite: 4].

### Requirements
1. Declare a global variable: `long long counter = 0;`[cite: 4].
2. Create 3 threads[cite: 4]. Each thread executes a loop to increment `counter` 1,000,000 times[cite: 4].
3. Use a `pthread_mutex_t` to protect the counter increment[cite: 4]. Each thread must lock the mutex before incrementing and unlock it immediately after[cite: 4].
4. The main thread uses `pthread_join()` to wait for all three threads to complete, then prints the final `counter` value[cite: 4].

### Analysis Questions
* Why is a mutex necessary in this scenario[cite: 4]?
* What happens if the mutex is omitted[cite: 4]? Explain why the final result may be inaccurate and inconsistent[cite: 4].

---

## Exercise 3: Synchronization with Condition Variables (Producer-Consumer Model)

Solves the classic Producer-Consumer problem using Condition Variables to allow a thread to wait for a specific condition efficiently instead of busy-waiting[cite: 4].

### Requirements
1. Build a program with one **Producer** thread and one **Consumer** thread[cite: 4].
2. Use a global variable `data` and a flag `data_ready` to share data[cite: 4].
3. **Producer:** Loops 10 times; in each iteration, generates a random number, sets `data`, turns on `data_ready`, and signals the Consumer[cite: 4].
4. **Consumer:** Waits until signaled by the Producer[cite: 4]. Once awakened, reads and prints `data`, then turns off `data_ready`[cite: 4].
5. Use a Mutex and a `pthread_cond_t` for precise synchronization between the two threads[cite: 4].

---

## Exercise 4: Read-Write Lock Optimization

Optimizes access in high-read, low-write scenarios where standard Mutexes cause unnecessary bottlenecks using Read-Write Locks (`pthread_rwlock_t`)[cite: 4].

### Requirements
1. Simulate a shared data resource (a global integer variable)[cite: 4].
2. Create **5 Reader threads** and **2 Writer threads**[cite: 4].
3. **Reader:** Reads and prints the resource value[cite: 4].
4. **Writer:** Increments the resource value by 1[cite: 4].
5. **Synchronization:** Use `pthread_rwlock_t`[cite: 4]:
   * Readers must request read locks via `pthread_rwlock_rdlock`[cite: 4].
   * Writers must request write locks via `pthread_rwlock_wrlock`[cite: 4].
6. Observe and print read/write activities to demonstrate concurrent reading by multiple Readers versus exclusive writing by Writers[cite: 4].