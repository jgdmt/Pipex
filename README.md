# Pipex - 42Cursus Project

**Pipex** is a **42 cursus** project that introduces the concept of **UNIX system calls** by emulating the functionality of the shell pipe (`|`). 

## ✨ Project Overview

The objective is to create a program that will imitates the behavior of the shell command:
```bash
$ < infile cmd1 | cmd2 > outfile
```

### 🎯 Key Objectives:

- **Pipes**: Used to pass the output of a command as input of another.
- **File descriptors**: Manage input and output to files or pipes.
- **Process duplication**: Using fork() to create child processes that execute commands.
- **Redirections**: Handle file redirection by redirecting input/output streams to and from files.

## ⭐ Mandatory Part

**Pipex** replicates the behavior of the following command:
```bash
$ < infile cmd1 | cmd2 > outfile
```
- `infile`: File from which `cmd1` will read its data.
- `cmd1`: First command that reads its data from `infile`. 
- `cmd2`: Second command that reads its data from the output of `cmd1` via a pipe.
- `outfile`: File where the output of `cmd2` will be written.

### Usage
```bash
./pipex infile cmd1 cmd2 outfile
```

### Example
```bash
./pipex infile "ls -l" "wc -l" outfile
```

## 💫 Bonus Part
The following bonus has been implemented: **Multiple pipes**. The program handles multiple pipes, emulating more complex behaviors such as:
```bash
$ < infile cmd1 | cmd2 | cmd3 | cmd4 | cmd5 > outfile
```

## 🛠️ Installation & Compilation Guide

### 📦 Dependencies

Make sure you have the following installed:

- **GCC** or another C compiler
- **Make**

### 🏗️ Compilation

1. Clone the repository
  ```bash
  git clone https://github.com/jgdmt/Pipex.git
  ```

2. Compile with make
  ```bash
  make
  ```
  The `pipex` executable will be created.

3. Clean up the objects files
  ```bash
  make clean
  ```

4. Fully clean the project (object files and the executable)
  ```bash
  make fclean
  ```

5. Rebuild the project from scratch
  ```bash
  make re
  ```

6. Run the bonus
  ```bash
  make bonus # Will create the executable pipex_bonus
  ./pipex_bonus infile cmd1 cmd2 cmd3 cmd4 cmd5 outfile
  ```
