# advent-of-code

My solutions for the [Advent of Code](http://adventofcode.com/) annual challenge.

## Prerequisites

- CMake >= 3.20
- C compiler (gcc, clang, MinGW, GCC from MSYS2/UCRT64...)

---

## Build

### Configure the project

From the root of the repository:

```bash
cmake -S . -B build
```

### Build all days solutions

```bash
cmake --build build
```

### Build a single day solution

```bash
cmake --build build --target day<XX>
```

---

## Running a solution

Each executable expects to run **inside its own folder** to access its `tests/` directory for input files.  
So you need to move to the folder containing the executable before running it.

### Example: Running Day 01

```bash
# Move to the folder of the executable
cd 2024/day01

# Run the executable
./day01    # on Linux/MSYS2
day01.exe  # on Windows
```

---

## Test Mode

To enable the TEST mode (for using test input file):

```bash
cmake -S . -B build -DTEST=ON
```

---

## Cleaning

### Standard clean

```bash
cmake --build build --target clean
```

### Full clean / reset

```bash
rm -rf build
```

---

## Project Structure

```
2024/
├── aoc_2024.h
├── day01/
│   ├── day01.c
│   ├── tests/
│   └── CMakeLists.txt
├── day02/
│   ├── day02.c
│   ├── tests/
│   └── CMakeLists.txt
└── ...
```

Each `dayXX` folder contains :

- Source file `dayXX.c`
- A `tests/` folder with input files
- A `CMakeLists.txt` defining the build and run targets

---

## Author

Raphael CAUSSE
