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

size_t length = 0;
t_rotation instructions[MAX_INSTRUCTIONS] = {0};
uint32_t dial_pos = DIAL_START;

/***** Functions *************************************************************/

t_aoc_status read_input(void)
{
    FILE *input_file = NULL;
    size_t index = 0;

    printf("Input file : '%s'\n", INPUT_FILE);
    input_file = fopen(INPUT_FILE, "r");
    if (NULL == input_file)
    {
        LOG_ERROR_FILE();
        return AOC_ERROR;
    }

    while (fscanf(input_file, "%c%u\n", &instructions[index].direction, &instructions[index].distance) != EOF)
    {
        index++;
    }
    if (index >= MAX_INSTRUCTIONS)
    {
        LOG_ERROR_MAX_REACHED("Max instructions reached", MAX_INSTRUCTIONS, index);
        fclose(input_file);
        return AOC_ERROR;
    }
    length = index;

    if (fclose(input_file) != 0)
    {
        LOG_ERROR_FILE();
    }

    return AOC_SUCCESS;
}

uint32_t rotate_dial(t_rotation rotation)
{
    // printf("dial %u -> %c%u ", dial_pos, rotation.direction, rotation.distance);
    switch (rotation.direction)
    {
    case 'L':
        if (rotation.distance > dial_pos)
        {
            dial_pos = (DIAL_MAX + 1) - ((rotation.distance - dial_pos) % (DIAL_MAX + 1));
        }
        else
        {
            dial_pos -= rotation.distance;
        }
        break;

    case 'R':
        dial_pos = (dial_pos + rotation.distance) % (DIAL_MAX + 1);
        break;

    default:
        break;
    }
    /* Not allowing 100 as it actually means 0 */
    if ((DIAL_MAX + 1) == dial_pos)
    {
        dial_pos = DIAL_MIN;
    }

    // printf("-> dial %u\n", dial_pos);
    return dial_pos;
}

t_aoc_status solve_part_one(void)
{
    aoc_solve_start(AOC_DAY, AOC_PART_1);

    uint32_t password = 0;

    /* Counting number of time dial stops at 0 */
    for (size_t i = 0; i < length; i++)
    {
        dial_pos = rotate_dial(instructions[i]);
        if (0 == dial_pos)
        {
            password++;
        }
    }

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
