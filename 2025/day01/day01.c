/******************************************************************************
 * @file day01.c
 * @brief Solutions for day 1 of Advent of Code 2025.
 * @author Raphael CAUSSE
 *****************************************************************************/

/***** Includes **************************************************************/

#include "aoc.h"

/***** Definitions ***********************************************************/

#define AOC_DAY 1

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
    t_aoc_status status;

    status = read_input();
    if (AOC_ERROR == status)
    {
        return EXIT_FAILURE;
    }

    status = solve_part_one();
    if (AOC_ERROR == status)
    {
        return EXIT_FAILURE;
    }

    status = solve_part_two();
    if (AOC_ERROR == status)
    {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
