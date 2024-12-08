/******************************************************************************
 * @file dayXX.c
 * @brief Solutions for the day XX challenges of Advent of Code 2024.
 * @author Raphael CAUSSE
 *****************************************************************************/

/***** Includes **************************************************************/

#include "aoc_20YY.h"

/***** Definitions ***********************************************************/

#define AOC_DAY 99

/***** Globals ***************************************************************/

/***** Functions *************************************************************/

err_t read_input(void)
{
    FILE *input_file;

    input_file = fopen(INPUT_FILE, "r");
    if (input_file == NULL)
    {
        printf("ERROR\t%s: %s: (%d) %s\n", __func__, INPUT_FILE, errno, strerror(errno));
        return AOC_ERROR;
    }

    printf("INFO: read_input not implemented !\n");

    if (fclose(input_file) != 0)
    {
        printf("ERROR\t%s: %s: (%d) %s\n", __func__, INPUT_FILE, errno, strerror(errno));
        return AOC_ERROR;
    }

    return AOC_OK;
}

err_t solve_part_one(void)
{
    printf("INFO: solve_part_one not implemented !\n");

    return AOC_OK;
}

err_t solve_part_two(void)
{
    printf("INFO: solve_part_two not implemented !\n");

    return AOC_OK;
}

int main(void)
{
    if (read_input() == AOC_ERROR)
    {
        return EXIT_FAILURE;
    }

    BANNER_START(AOC_DAY, 1);
    if (solve_part_one() == AOC_ERROR)
    {
        return EXIT_FAILURE;
    }
    BANNER_END();

    BANNER_START(AOC_DAY, 2);
    if (solve_part_two() == AOC_ERROR)
    {
        return EXIT_FAILURE;
    }
    BANNER_END();

    return EXIT_SUCCESS;
}