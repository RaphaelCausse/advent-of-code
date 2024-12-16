/******************************************************************************
 * @file aoc_20YY.h
 * @brief Header for Advent of Code 20YY.
 * @author Raphael CAUSSE
 *****************************************************************************/

#ifndef _AOC_20YY_H_
#define _AOC_20YY_H_

/***** Includes **************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

/***** Definitions ***********************************************************/

#define AOC_YEAR 2099

#ifdef TEST
#define INPUT_FILE "tests/test.txt"
#else
#define INPUT_FILE "tests/input.txt"
#endif

/***** Macros ****************************************************************/

#define BANNER_START(day, part) (printf("========== AOC %d - day %02d - part %d ==========\n", AOC_YEAR, day, part))
#define BANNER_END() (printf("================================================\n\n"))

#define LOG_ERROR_FILE() (printf("ERROR\t%s: %s: (%d) %s\n", __func__, INPUT_FILE, errno, strerror(errno)))

#define LOG_WARN_NOT_IMPLEMENTED() (printf("WARN\t%s: not implemented\n", __func__))

/***** Types *****************************************************************/

typedef enum
{
    AOC_ERROR = -1,
    AOC_OK = 0,
} err_t;

#endif /* _AOC_20YY_H_ */