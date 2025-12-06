/******************************************************************************
 * @file day01.c
 * @brief Solutions for day 1 of Advent of Code 2025.
 * @author Raphael CAUSSE
 *****************************************************************************/

/***** Includes **************************************************************/

#include "aoc.h"

/***** Definitions ***********************************************************/

#define AOC_DAY (1)

#define DIAL_MIN (0)
#define DIAL_MAX (99)
#define DIAL_START (50)

#define MAX_INSTRUCTIONS (8192)

/***** Types *****************************************************************/

typedef struct
{
    char direction;
    uint32_t distance;
} t_rotation;

/***** Globals ***************************************************************/

t_rotation instructions[MAX_INSTRUCTIONS] = {0};

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

    size_t idx = 0;
    while (fscanf(input_file, "%c%u\n", &instructions[idx].direction, &instructions[idx].distance) != EOF)
    {
        fprintf(stdout, "%c%u\n", instructions[idx].direction, instructions[idx].distance);
        idx++;
    }

    if (fclose(input_file) != 0)
    {
        LOG_ERROR_FILE();
        return AOC_ERROR;
    }

    return AOC_SUCCESS;
}

t_aoc_status solve_part_one(void)
{
    aoc_solve_start(AOC_DAY, AOC_PART_1);

    uint32_t password = 0;

    LOG_WARNING_NOT_IMPLEMENTED();

    aoc_solve_end(password);
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
