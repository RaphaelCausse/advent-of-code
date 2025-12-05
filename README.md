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
cd <YEAR>
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
cd <YEAR>/day<XX>
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

1. Create a new directory with the correct year
2. Copy all contents from the `template` directory into the new directory
3. Edit the project name in `CMakeLists.txt` 
4. Rename and edit the file `aoc_20YY.h` with the correct year, and edit the define `AOC_YEAR`
5. Rename the day directories and source files, and edit the source file define `AOC_DAY`

That's all — CMake will detect and build everything automatically.

---

## Author

Raphael CAUSSE
