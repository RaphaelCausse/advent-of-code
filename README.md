# Advent of Code

This repository contains my solutions to the annual **[Advent of Code](https://adventofcode.com/)** challenge, implemented in **C** and built using **CMake**.  

---

## Repository Structure

```
.
├── 2024/
│   ├── CMakeLists.txt        <-- Year-level CMake build entry
│   ├── aoc_2024.h            <-- Shared header for the year
│   ├── day01/
│   │    ├── day01.c
│   │    ├── tests/           <-- Input files for this day
│   │    └── CMakeLists.txt
│   ├── day02/
│   │    └── ...
│   └── ...
├── ...
└── README.md
```

Each `day<XX>` directory:

- builds one executable inside the same folder
- contains a `tests/` directory with input files

---

## Requirements

- **CMake ≥ 3.16**
- **GCC / Clang / MSVC supporting C99**
- Optional (Windows MSYS2):
  - `mingw32-make` for command-line builds

---

## Build

### 1. Navigate to a specific year

```bash
cd <YEAR_DIR>
```

Each year is an independent CMake project.

### 2. Configure the build

```bash
cmake -S . -B build
```

This generates build files inside the `build/` folder.

### 3. Build all days of the year

```bash
cmake --build build
```

This compiles all `day<XX>` executables.

---

## Execution

### Option A — Run from the day directory (normal)

Because each solution expects to find its `tests/` folder, it must be executed **from its own directory**:

```bash
cd <YEAR_DIR>/day<XX>
./day<XX>
```

### Option B — Run from the year directory using CMake targets

The year-level CMakeLists generates convenience targets:

```bash
cmake --build build --target run_day<XX>
```

---

## Enabling Test Mode

Some solutions may support a `TEST` build mode.  
Enable it during configuration:

```bash
cmake -S . -B build -DTEST=ON
```

Then rebuild:

```bash
cmake --build build
```

---

## Cleaning the Build

Since CMake does not provide a project-wide `clean` rule, simply delete the build directory `build`.
---

## Adding a New Year

To add another year:

1. Copy the directory `template/20YY` at the root and rename it with the correct year
2. Rename and edit the `aoc_20YY.h` with the correct year
3. Rename and edit the day directories and source files

That's all — CMake will detect and build everything automatically.

---

## Author

Raphael CAUSSE
