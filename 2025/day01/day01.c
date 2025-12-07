/******************************************************************************
 * @file day01.c
 * @brief Solutions for day 1 of Advent of Code 2025.
 * @author Raphael CAUSSE
 *****************************************************************************/

/***** Includes **************************************************************/

#include "aoc.h"
#include <math.h>

/***** Definitions ***********************************************************/

#define AOC_DAY (1)

#define DIAL_MIN (0)
#define DIAL_MAX (100)
#define DIAL_START (50)

#define MAX_ROTATIONS (8192)

/***** Types *****************************************************************/

typedef struct
{
    char direction;
    uint32_t distance;
} t_rotation;

/***** Globals ***************************************************************/

size_t num_rotations = 0;
t_rotation rotations[MAX_ROTATIONS] = {0};

/***** Functions *************************************************************/

t_aoc_status read_input(void)
{
    FILE *input_file = NULL;
    size_t index = 0;

    LOG_INPUT_FILE();
    input_file = fopen(INPUT_FILE, "r");
    if (NULL == input_file)
    {
        LOG_ERROR_FILE();
        return AOC_ERROR;
    }

    while (fscanf(input_file, "%c%u\n", &rotations[index].direction, &rotations[index].distance) != EOF)
    {
        index++;
    }
    if (index >= MAX_ROTATIONS)
    {
        LOG_ERROR_MAX_REACHED("Max instructions reached", MAX_ROTATIONS, index);
        fclose(input_file);
        return AOC_ERROR;
    }
    num_rotations = index;

    if (fclose(input_file) != 0)
    {
        LOG_ERROR_FILE();
    }

    return AOC_SUCCESS;
}

uint32_t rotate_one_click(uint32_t dial_pos, char direction)
{
    if (direction == 'L')
    {
        dial_pos = (dial_pos + (DIAL_MAX - 1)) % DIAL_MAX;
    }
    else
    {
        dial_pos = (dial_pos + 1) % DIAL_MAX;
    }
    return dial_pos;
}

t_aoc_status solve_part_one(void)
{
    aoc_solve_start(AOC_DAY, AOC_PART_1);

    uint32_t dial_pos = DIAL_START;
    uint32_t password = 0;

    /* Counting number of time dial stops at 0 at the end of a rotation */
    for (size_t i = 0; i < num_rotations; i++)
    {
        for (uint32_t k = 0; k < rotations[i].distance; k++)
        {
            dial_pos = rotate_one_click(dial_pos, rotations[i].direction);
        }
        if (DIAL_MIN == dial_pos)
        {
            password++;
        }
    }

    aoc_solve_end(password);
    return AOC_SUCCESS;
}

t_aoc_status solve_part_two(void)
{
    aoc_solve_start(AOC_DAY, AOC_PART_2);

    uint32_t dial_pos = DIAL_START;
    uint32_t password = 0;

    /* Counting number of time dial points at 0, during a rotation or at the end of one */
    for (size_t i = 0; i < num_rotations; i++)
    {
        for (uint32_t k = 0; k < rotations[i].distance; k++)
        {
            dial_pos = rotate_one_click(dial_pos, rotations[i].direction);
            if (DIAL_MIN == dial_pos)
            {
                password++;
            }
        }
    }

    aoc_solve_end(password);
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
