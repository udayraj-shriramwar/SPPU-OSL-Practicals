# SPPU OSL Practicals

This repository contains **Operating Systems Laboratory (OSL) practical programs** and solutions based on the SPPU problem statements.

## 📚 Practicals

### 1. Address Book
Implement an address book with options to:
- Create address book
- View address book
- Insert a record
- Delete a record
- Modify a record
- Exit

### 2. Zombie Process
Implement process creation using the `fork()` and `wait()` system calls and demonstrate the **Zombie state**.

### 3. Orphan Process
Implement process creation using the `fork()` and `wait()` system calls and demonstrate the **Orphan state**.

### 4. Fork, Execve and Reverse Array
Create a child process using `fork()`. The child process uses the `execve()` system call to load a new program that displays the array in reverse order.

### 5. SJF CPU Scheduling
Implement **Shortest Job First (SJF) Preemptive CPU Scheduling** with different arrival times.

### 6. Round Robin CPU Scheduling
Implement **Round Robin CPU Scheduling** with different arrival times.

### 7. Producer-Consumer
Implement thread synchronization using **counting semaphores and mutex** to demonstrate the Producer-Consumer problem.

### 8. Reader-Writer
Implement thread synchronization and mutual exclusion using **mutex** to demonstrate the Reader-Writer problem.

### 9. Banker's Algorithm
Implement the **Banker's Algorithm** for deadlock avoidance.

### 10. FCFS Page Replacement
Implement the **FCFS Page Replacement Algorithm** with a minimum frame size of three.

### 11. LRU Page Replacement
Implement the **LRU Page Replacement Algorithm** with a minimum frame size of three.

### 12. Optimal Page Replacement
Implement the **Optimal Page Replacement Algorithm** with a minimum frame size of three.

### 13. FIFOS - Full Duplex Communication
Implement full-duplex communication between two independent processes using pipes.

The first process:
- Accepts sentences
- Writes them to the first pipe

The second process:
- Reads the sentences
- Counts characters, words and lines
- Writes the output to a text file
- Sends the file contents through the second pipe

The first process then displays the output on standard output.

### 14. Client-Server using Shared Memory
Implement Client and Server programs using **shared memory**.

The server:
- Creates a shared memory segment
- Writes a message to shared memory

The client:
- Reads the message from shared memory
- Displays it on the screen

### 15. SSTF Disk Scheduling
Implement **SSTF (Shortest Seek Time First) Disk Scheduling** considering the initial head position moving away from the spindle.

### 16. SCAN Disk Scheduling
Implement **SCAN Disk Scheduling** considering the initial head position moving away from the spindle.

### 17. C-Look Disk Scheduling
Implement **C-Look Disk Scheduling** considering the initial head position moving away from the spindle.

---

## 🛠️ Technologies Used

- C
- Shell Script
- Linux / UNIX System Calls
- Process Management
- Threads
- Semaphores
- Mutex
- Pipes
- Shared Memory
- CPU Scheduling
- Page Replacement
- Disk Scheduling

## 📂 Repository Structure

```text
SPPU-OSL-Practicals/
│
├── README.md
│
├── 01-Address-Book.sh
├── 02-Zombie-Process.c
├── 03-Orphan-Process.c
├── 04-Fork-Execve-Reverse/
│   ├── Main.c
│   └── reverse.c
│
├── 05-SJF-Preemptive.c
├── 06-Round-Robin.c
├── 07-Producer-Consumer.c
├── 08-Reader-Writer.c
├── 09-Bankers-Algorithm.c
│
├── 10-FCFS-Page-Replacement.c
├── 11-LRU-Page-Replacement.c
├── 12-Optimal-Page-Replacement.c
│
├── 13-Full-Duplex-Pipes/
│   ├── program1.c
│   └── program2.c
│
├── 14-Shared-Memory-Client-Server/
│   ├── client.c
│   └── server.c
│
├── 15-SSTF-Disk-Scheduling.c
├── 16-SCAN-Disk-Scheduling.c
└── 17-C-Look-Disk-Scheduling.c
