# Advent of Code

This repository contains my solutions to the annual **[Advent of Code](https://adventofcode.com/)** challenge, implemented in **C**.

---

## Repository Structure

```
.
├── 2024/
│   ├── aoc.h
│   ├── day01/
│   │   ├── day01.c
│   │   ├── Makefile
│   │   └── data/
│   │        ├── test.txt
│   │        └── input.txt
│   ├── day02/
│   │   └── ...
│   └── ...
├── ...
├── template/
│   ├── aoc.h
│   └── dayXX/
│       ├── dayXX.c
│       ├── Makefile
│       └── data/
│            ├── test.txt
│            └── input.txt
└── README.md
```

- Each year folder contains several `day<XX>` directories.
- Each day directory builds a single executable in the same folder.
- Each day has its own `data/` directory containing:
  - `test.txt` (example input from the AoC website)
  - `input.txt` (your personal puzzle input)

---

## Requirements

- **GCC / Clang / MSVC supporting C99**
- **Make**

---

## Build

Each day solutions is an independent program with its own Makefile.

Move to the corresponding day directory :
```bash
cd <YEAR>/day<DAY_NUMBER>
```

Build the solution :
```bash
make build
```

The executable will automatically load its input from the local `data/` directory.

You can build the solution to use the test input :
```bash
make test
```

---

## Execution

Run the executable :
```bash
make run
```

---

## Cleaning

Clean generated files (executable, dependency) :
```bash
make clean
```

---

## Adding a New Year

To add another year:

1. Create a new directory with the correct year
2. Copy all contents from the `template` directory into the new directory
3. Edit the define `AOC_YEAR` in the header file `aoc.h`
4. Rename the day directory and source file.
5. Edit the define `AOC_DAY` in the source file.

---

## Author

Raphael CAUSSE
