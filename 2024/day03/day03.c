/******************************************************************************
 * @file day03.c
 * @brief Solutions for day 3 of Advent of Code 2024.
 * @author Raphael CAUSSE
 *****************************************************************************/

/***** Includes **************************************************************/

#include "aoc.h"

/***** Definitions ***********************************************************/

#define AOC_DAY (3)

/***** Globals ***************************************************************/

/***** Functions *************************************************************/

t_aoc_status aoc_read_input(void)
{
    FILE *input_file = NULL;

    input_file = fopen(INPUT_FILE, "r");
    if (NULL == input_file)
    {
        LOG_ERROR_FILE();
        return AOC_ERROR;
    }

    fclose(input_file);
    return AOC_NOTIMPL; /* Not implemented */
}

t_aoc_result aoc_solve_part_one(void)
{
    return aoc_result_notimpl();
}

t_aoc_result aoc_solve_part_two(void)
{
    return aoc_result_notimpl();
}

/***** Main ******************************************************************/

int main(void)
{
    return aoc_run(AOC_DAY);
}
