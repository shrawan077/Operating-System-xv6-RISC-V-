# xv6-riscv Custom System Calls

This project extends the xv6 RISC-V operating system with custom system calls.

## Added System Calls

| Syscall | Number | Description |
|---|---|---|
| `getppid()` | 22 | Returns the parent process ID |
| `setlimit(n)` | 24 | Sets a memory limit (in bytes) for the current process |
| `getlimit()` | 25 | Returns the current memory limit of the process |

## Setup & Run

### Prerequisites
- WSL2 Ubuntu
- QEMU 8.2.0
- RISC-V cross compiler

### Build & Run
```bash
make qemu
```

### Test System Calls
```bash
ppidtest
readcounttest
limittest
```

## How to exit QEMU
Press `Ctrl+A` then `X`
