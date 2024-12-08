/******************************************************************************
 * @file aoc_2024.h
 * @brief Header for Advent of Code 2024.
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

/***** Definitions ***********************************************************/

#define AOC_YEAR 2024

#ifdef TEST
#define INPUT_FILE "tests/test.txt"
#else
#define INPUT_FILE "tests/input.txt"
#endif

/***** Macros ****************************************************************/

#define BANNER_START(day, part) (printf("========== AOC %d - day %02d - part %d ==========\n", AOC_YEAR, day, part))
#define BANNER_END() (printf("================================================\n\n"))

/***** Types *****************************************************************/

typedef enum
{
    AOC_ERROR = -1,
    AOC_OK = 0,
} err_t;

#endif /* _AOC_2024_H_ */