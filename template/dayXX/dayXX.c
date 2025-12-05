/******************************************************************************
 * @file dayXX.c
 * @brief Solutions for day XX of Advent of Code 2024.
 * @author Raphael CAUSSE
 *****************************************************************************/

/***** Includes **************************************************************/

#include "aoc_20YY.h"

/***** Definitions ***********************************************************/

#define AOC_DAY 0

/***** Globals ***************************************************************/

/***** Functions *************************************************************/

t_aoc_status read_input(void)
{
    FILE *input_file;

    input_file = fopen(INPUT_FILE, "r");
    if (input_file == NULL)
    {
        LOG_ERROR_FILE();
        return AOC_ERROR;
    }

    LOG_WARNING_NOT_IMPLEMENTED();

    if (fclose(input_file) != 0)
    {
        LOG_ERROR_FILE();
        return AOC_ERROR;
    }

    return AOC_SUCCESS;
}

t_aoc_status solve_part_one(void)
{
    LOG_WARNING_NOT_IMPLEMENTED();

    return AOC_SUCCESS;
}

t_aoc_status solve_part_two(void)
{
    LOG_WARNING_NOT_IMPLEMENTED();

    return AOC_SUCCESS;
}

/***** Main ******************************************************************/

int main(void)
{
    t_aoc_timer timer;

    if (read_input() == AOC_ERROR)
    {
        return EXIT_FAILURE;
    }

    aoc_solve_start(AOC_DAY, AOC_PART_1);
    aoc_timer_start(&timer);
    if (solve_part_one() == AOC_ERROR)
    {
        return EXIT_FAILURE;
    }
    aoc_timer_end(&timer);
    aoc_banner_end();

    aoc_solve_start(AOC_DAY, AOC_PART_2);
    aoc_timer_start(&timer);
    if (solve_part_two() == AOC_ERROR)
    {
        return EXIT_FAILURE;
    }
    aoc_timer_end(&timer);
    aoc_banner_end();

    return EXIT_SUCCESS;
}