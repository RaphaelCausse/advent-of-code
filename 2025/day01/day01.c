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

t_aoc_status aoc_read_input(void)
{
    FILE *input_file = NULL;
    size_t index = 0;

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
        LOG_ERROR("Max instructions reached");
        fclose(input_file);
        return AOC_ERROR;
    }
    num_rotations = index;

    fclose(input_file);
    return AOC_SUCCESS;
}

uint32_t rotate_one_click(uint32_t dial_pos, char direction)
{
    switch (direction)
    {
    case 'L':
        dial_pos = (dial_pos + (DIAL_MAX - 1)) % DIAL_MAX;
        break;

    case 'R':
        dial_pos = (dial_pos + 1) % DIAL_MAX;
        break;

    default:
        break;
    }
    return dial_pos;
}

t_aoc_result aoc_solve_part_one(void)
{
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

    return aoc_result_u32(password, 3); /* Example solution is 3 */
}

t_aoc_result aoc_solve_part_two(void)
{
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

    return aoc_result_u32(password, 6); /* Example solution is 6 */
}

/***** Main ******************************************************************/

int main(void)
{
    return aoc_run(AOC_DAY);
}
