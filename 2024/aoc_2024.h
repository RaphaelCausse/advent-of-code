/******************************************************************************
 * @file aoc_2024.h
 * @brief Header for Advent of Code Year 2024.
 * @author Raphael CAUSSE
 *****************************************************************************/

#ifndef _AOC_2024_H_
#define _AOC_2024_H_

/***** Includes **************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <time.h>

/***** Definitions ***********************************************************/

#define AOC_YEAR 2024

#define AOC_PART_1 1
#define AOC_PART_2 2

#ifdef TEST
#define INPUT_FILE "tests/test.txt"
#else
#define INPUT_FILE "tests/input.txt"
#endif

/***** Macros ****************************************************************/

#define LOG_ERROR_FILE() (printf("[ERROR] %s: %s: (%d) %s\n", __func__, INPUT_FILE, errno, strerror(errno)))
#define LOG_WARN_NOT_IMPLEMENTED() (printf("[WARNING] %s: not implemented\n", __func__))

/***** Types *****************************************************************/

typedef enum
{
    AOC_ERROR = false,
    AOC_SUCCESS = true,
} aoc_status_t;

typedef struct
{
    clock_t start_time;
    clock_t end_time;
} aoc_timer_t;

/***** Functions *************************************************************/

static inline void aoc_banner_start(int day, int part)
{
    printf("================ AOC %d - DAY %02d - PART %d ================\n", AOC_YEAR, day, part);
}

static inline void aoc_banner_end(void)
{
    printf("============================================================\n\n");
}

static inline void aoc_timer_start(aoc_timer_t *t)
{
    t->start_time = clock();
}

static inline void aoc_timer_end(aoc_timer_t *t)
{
    t->end_time = clock();
    double elapsed = (double)(t->end_time - t->start_time) / CLOCKS_PER_SEC;
    printf("Execution time: %.6f seconds\n", elapsed);
}

#endif /* _AOC_2024_H_ */