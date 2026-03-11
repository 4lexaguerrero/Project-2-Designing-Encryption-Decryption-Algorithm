# Assignment Write-Up: Custom Encryption/Decryption Algorithm

## 1) Custom Algorithm Design

This program uses a custom reversible algorithm made of three methods:

1. Shifting
- Each alphabetic character is shifted by an integer key (ex:3).
- Uppercase and lowercase are handled in their own ranges.

2. Substitution
- Atbash-style substitution is applied:
  - `A <-> Z`, `B <-> Y`, ...
  - `a <-> z`, `b <-> y`, ...

3. Transposition
- The entire line is reversed.

Encryption order:
1. Shift
2. Substitution
3. Reverse (transposition)

Decryption order:
1. Reverse (undo transposition)
2. Substitution (self-inverse)
3. Reverse shift by key (undo shifting)

This design avoids long `if x == 'A'` style decision trees.

## 2) Input and Output

- Input file is read line by line.
- Encrypted output is written to a new output file.
- Decryption reads the encrypted file and writes a new decrypted output file.

Program functions:
- `encryptFile(...)` handles plaintext -> encrypted file.
- `decryptFile(...)` handles encrypted -> decrypted file.

## 3) User Interaction

The menu in `main()` asks the user to choose:
- `1` Encrypt
- `2` Decrypt

Then it asks for:
- input file name
- output file name
- integer key

## 4) Error Handling

The program handles common errors:
- invalid menu input (non-integer)
- invalid menu choice (not 1 or 2)
- invalid key input (non-integer)
- missing/unopenable files

## 5) How to Run

Compile:

```bash
g++ -std=c++17 -O2 -o cipher main.cpp
```

Run:

```bash
./cipher
```

## 6) Sample Input and Output

- Sample plaintext file: `testfile.txt`
- Sample encrypted file: `encrypted_sample.txt`
- Sample decrypted file: `decrypted_sample.txt`

`decrypted_sample.txt` should match the original plaintext when the same key is used.

## 7) Rubric Mapping

- 3 methods implemented and commented in source code:
  - shifting
  - substitution
  - transposition
- File input/output implemented for encryption and decryption
- Menu-driven user interface implemented
- Error handling included for common failures
- Documentation included (README + this write-up)
