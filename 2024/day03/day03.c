/******************************************************************************
 * @file day03.c
 * @brief Solutions for the day 3 challenges of Advent of Code 2024.
 * @author Raphael CAUSSE
 *****************************************************************************/

/***** Includes **************************************************************/

#include "aoc_2024.h"

/***** Definitions ***********************************************************/

#define AOC_DAY 3

/***** Globals ***************************************************************/

/***** Functions *************************************************************/

aoc_status_t read_input(void)
{
    FILE *input_file;

    input_file = fopen(INPUT_FILE, "r");
    if (input_file == NULL)
    {
        LOG_ERROR_FILE();
        return AOC_ERROR;
    }

    LOG_WARN_NOT_IMPLEMENTED();

    if (fclose(input_file) != 0)
    {
        LOG_ERROR_FILE();
        return AOC_ERROR;
    }

    return AOC_SUCCESS;
}

aoc_status_t solve_part_one(void)
{
    LOG_WARN_NOT_IMPLEMENTED();

    return AOC_SUCCESS;
}

aoc_status_t solve_part_two(void)
{
    LOG_WARN_NOT_IMPLEMENTED();

    return AOC_SUCCESS;
}

/***** Main ******************************************************************/

int main(void)
{
    aoc_timer_t timer;

    if (read_input() == AOC_ERROR)
    {
        return EXIT_FAILURE;
    }

    aoc_banner_start(AOC_DAY, AOC_PART_1);
    aoc_timer_start(&timer);
    if (solve_part_one() == AOC_ERROR)
    {
        return EXIT_FAILURE;
    }
    aoc_timer_end(&timer);
    aoc_banner_end();

    aoc_banner_start(AOC_DAY, AOC_PART_2);
    aoc_timer_start(&timer);
    if (solve_part_two() == AOC_ERROR)
    {
        return EXIT_FAILURE;
    }
    aoc_timer_end(&timer);
    aoc_banner_end();

    return EXIT_SUCCESS;
}