/******************************************************************************
 * @file aoc.h
 * @brief Header for Advent of Code.
 * @author Raphael CAUSSE
 *****************************************************************************/

#ifndef __AOC_H__
#define __AOC_H__

/***** Includes **************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <time.h>

/***** Definitions ***********************************************************/

#define AOC_YEAR (2024)

#define AOC_PART_1 (1)
#define AOC_PART_2 (2)

#ifdef TEST
#define INPUT_FILE "tests/test.txt"
#else
#define INPUT_FILE "tests/input.txt"
#endif

/***** Macros ****************************************************************/

#define LOG_ERROR_FILE() \
    (printf("[ERROR] %s: %s: (%d) %s\n", __func__, INPUT_FILE, errno, strerror(errno)))

#define LOG_WARNING_NOT_IMPLEMENTED() \
    (printf("[WARNING] %s: not implemented\n", __func__))

/***** Types *****************************************************************/

typedef enum
{
    AOC_ERROR = false,
    AOC_SUCCESS = true,
} t_aoc_status;

typedef struct
{
    clock_t start_time;
    clock_t end_time;
} t_aoc_timer;

/***** Static Variables *************************************************************/

static t_aoc_timer _global_timer;

/***** Static Functions *************************************************************/

static void aoc_solve_start(int day, int part)
{
    printf("================ A0C %d - Day %02d - Part %d ================\n", AOC_YEAR, day, part);

    _global_timer.start_time = clock();
}

static void aoc_solve_end(uint32_t result)
{
    _global_timer.start_time = clock();

    double elapsed = (double)(_global_timer.end_time - _global_timer.start_time) / CLOCKS_PER_SEC;

    printf("Result         : %u\n", result);
    printf("Execution time : %.6f s\n", elapsed);
    printf("============================================================\n\n");
}

/***** Public Functions *************************************************************/

extern t_aoc_status solve_part_one(void);
extern t_aoc_status solve_part_two(void);

#endif /* __AOC_H__ */
