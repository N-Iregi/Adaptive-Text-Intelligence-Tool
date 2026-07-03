# Adaptive Text Intelligence Tool

## Project Description

The **Adaptive Text Intelligence Tool** is a C program that dynamically processes and analyzes a paragraph entered by the user. It demonstrates the use of dynamic memory allocation, pointer traversal, structures, and function pointers to perform text analysis.

The program reads a paragraph from the user, separates it into individual words, stores each unique word along with its frequency, and performs several analyses on the collected data.

---

## Features

- Dynamically allocates memory for storing user input.
- Splits text into words using pointer traversal.
- Stores unique words and their occurrence counts.
- Prints the memory addresses of dynamically allocated data structures.
- Uses function pointers to execute different analysis functions.
- Performs the following analyses:
  - Total number of words
  - Longest word
  - Most frequent word
  - Average word length (custom analysis)

---

## Concepts Demonstrated

This project demonstrates the following C programming concepts:

- Dynamic memory allocation (`malloc`, `free`)
- Pointer traversal
- Structures
- Arrays of structures
- Function pointers
- String manipulation functions:
  - `strlen()`
  - `strcmp()`
  - `strcpy()`
- Character classification using `isalnum()` and `tolower()`

---

## Data Structure

```c
struct wordStat
{
    char name[40];
    int count;
};
```

Each structure stores:

- **name** – the unique word.
- **count** – the number of times the word appears.

---

## Compilation

Compile the program using GCC:

```bash
gcc text_intel.c -o text_intel
```

To enable compiler warnings:

```bash
gcc -Wall -Wextra -pedantic text_intel.c -o text_intel
```

---

## Running the Program

```bash
./text_intel
```

---

## Example

### Input

```text
Enter the paragraph to analyse:

The cat chased the cat across the garden.
```

### Output

```text
Memory Addresses
Paragraph stored at: 0x55d2d32fc2a0
Word array stored at: 0x55d2d32fc6b0

Analysis Results
----------------
Total words: 7
Longest word: chased (6 letters)
Most frequent word: the (3 times)
Average word length: 4.29 characters
```

> **Note:** Memory addresses will differ each time the program is executed.

---

## Program Workflow

1. Prompt the user to enter a paragraph.
2. Dynamically allocate memory for the paragraph.
3. Copy the paragraph into the allocated memory.
4. Traverse the paragraph using a pointer.
5. Extract each word.
6. Store unique words and their frequencies.
7. Execute the analysis functions using function pointers.
8. Display the analysis results.
9. Free all dynamically allocated memory.

---

## Project Structure

```text
Adaptive-Text-Intelligence-Tool/
├── text_intel.c
└── README.md
```

---

## Requirements Satisfied

-  Dynamic memory allocation for storing text.
- Pointer traversal to split text into words.
- Uses the `struct wordStat` structure.
- Dynamically allocated array for word statistics.
- Function pointers for analysis functions.
- Implements:
  - `count_words()`
  - `longest_word()`
  - `most_frequent()`
  - `avg_word_len()` (custom analysis)
- Demonstrates the use of:
  - `strlen()`
  - `strcmp()`
  - `strcpy()`
- Prints the memory addresses of key data structures.

---

## Author

**Name:** *Neville Ngothe*  
**Course:** *Programming in C*  
