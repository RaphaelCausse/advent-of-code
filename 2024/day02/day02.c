/******************************************************************************
 * @file day02.c
 * @brief Solutions for the day 2 challenges of Advent of Code 2024.
 * @author Raphael CAUSSE
 *****************************************************************************/

/***** Includes **************************************************************/

#include "aoc_2024.h"

/***** Definitions ***********************************************************/

#define AOC_DAY 2

/***** Globals ***************************************************************/

/***** Functions *************************************************************/

err_t read_input(void)
{
    FILE *input_file;

    input_file = fopen(INPUT_FILE, "r");
    if (input_file == NULL)
    {
        printf("ERROR\t%s: %s: (%d) %s\n", __func__, INPUT_FILE, errno, strerror(errno));
        return E_ERROR;
    }

    /* TODO */

    if (fclose(input_file) != 0)
    {
        printf("ERROR\t%s: %s: (%d) %s\n", __func__, INPUT_FILE, errno, strerror(errno));
        return E_ERROR;
    }

    return E_OK;
}

err_t solve_part_one(void)
{
    /* TODO */

    return E_OK;
}

err_t solve_part_two(void)
{
    /* TODO */

    return E_OK;
}

int main(void)
{
    if (read_input() == E_ERROR)
    {
        return EXIT_FAILURE;
    }

    BANNER_START(AOC_DAY, 1);
    if (solve_part_one() == E_ERROR)
    {
        return EXIT_FAILURE;
    }
    BANNER_END();

    BANNER_START(AOC_DAY, 2);
    if (solve_part_two() == E_ERROR)
    {
        return EXIT_FAILURE;
    }
    BANNER_END();

    return EXIT_SUCCESS;
}