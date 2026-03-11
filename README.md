# File Encryption/Decryption Project (C++)

This project implements a custom, reversible encryption algorithm in C++ and supports file-based encryption/decryption through a command-line menu.

## Algorithm Overview

The encryption process applies three methods in sequence to each line:

1. Shifting (Caesar-style):
	- Uppercase letters are shifted by `key` positions in `A-Z`.
	- Lowercase letters are shifted by `key` positions in `a-z`.
2. Substitution (Atbash-style):
	- Uppercase letters are mirrored (`A <-> Z`, `B <-> Y`, ...).
	- Lowercase letters are mirrored (`a <-> z`, `b <-> y`, ...).
3. Transposition:
	- The entire line is reversed.

Decryption performs the exact inverse order:

1. Reverse the line (undo transposition)
2. Apply mirrored substitution again (self-inverse)
3. Shift letters backward by `key` (undo shifting)

Because each step is reversible and decryption runs the inverse order, the original text is recovered.

## File Input/Output Behavior

- Input: plain text file for encryption, encrypted text file for decryption.
- Output: newly created text file with transformed content.
- Processing is line-by-line.

## Build and Run

### Requirements

- Linux/macOS/Windows with a C++ compiler that supports C++11 or newer (for example, `g++`).

### Compile

```bash
g++ -std=c++17 -O2 -o cipher main.cpp
```

### Run

```bash
./cipher
```

Program flow:

1. Choose `1` for encryption or `2` for decryption.
2. Enter input filename.
3. Enter output filename.
4. Enter integer key.

## User Guide (Beginner Friendly)

### Example: Encrypt a file

If your input file contains:

```text
Hello World
```

Run the program and enter:

- Choice: `1`
- Input file: `plain.txt`
- Output file: `encrypted.txt`
- Key: `3`

`encrypted.txt` will contain encrypted text.

### Example: Decrypt a file

Run the program again and enter:

- Choice: `2`
- Input file: `encrypted.txt`
- Output file: `decrypted.txt`
- Key: `3`

`decrypted.txt` should match the original plaintext.

## Error Handling Included

- Invalid menu input (not an integer)
- Invalid menu choice (not 1 or 2)
- Invalid key input (not an integer)
- File open failures for input/output files

## Project Files

- `main.cpp`: source code
- `testfile.txt`: sample plaintext input
- `encrypted_sample.txt`: encrypted sample output
- `decrypted_sample.txt`: decrypted sample output
- `ASSIGNMENT_WRITEUP.md`: rubric-oriented explanation
