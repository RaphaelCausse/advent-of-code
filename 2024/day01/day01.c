/******************************************************************************
 * @file day01.c
 * @brief Solutions for day 1 of Advent of Code 2024.
 * @author Raphael CAUSSE
 *****************************************************************************/

/***** Includes **************************************************************/

#include "aoc.h"

/***** Definitions ***********************************************************/

#define AOC_DAY (1)

#define ARRAY_MAX (1024)

/***** Globals ***************************************************************/

size_t length = 0;
int32_t left[ARRAY_MAX] = {0};
int32_t right[ARRAY_MAX] = {0};

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

    while (fscanf(input_file, "%d   %d\n", &left[length], &right[length]) != EOF)
    {
        length++;
    }

    fclose(input_file);
    return AOC_SUCCESS;
}

int compare(const void *first, const void *second)
{
    int32_t first_value = *(int32_t *)first;
    int32_t second_value = *(int32_t *)second;
    return first_value - second_value;
}

t_aoc_result aoc_solve_part_one(void)
{
    uint32_t sum = 0;

    /* Ascending order sort */
    qsort(left, length, sizeof(*left), compare);
    qsort(right, length, sizeof(*right), compare);

    for (size_t i = 0; i < length; i++)
    {
        sum += abs(left[i] - right[i]);
    }

    return aoc_result_u32(sum, 11); /* Example solution is 11 */
}

t_aoc_result aoc_solve_part_two(void)
{
    uint32_t similarity = 0;
    uint32_t count = 0;
    size_t last_index = 0;

    /* Ascending order sort */
    qsort(left, length, sizeof(*left), compare);
    qsort(right, length, sizeof(*right), compare);

    for (size_t i = 0; i < length; i++)
    {
        while (left[i] > right[last_index] && last_index < length)
        {
            last_index++;
        }

        while (left[i] == right[last_index] && last_index < length)
        {
            count++;
            last_index++;
        }

        similarity += left[i] * count;

        if (left[i + 1] != left[i])
        {
            count = 0;
        }
    }

    return aoc_result_u32(similarity, 31); /* Example solution is 31 */
}

/***** Main ******************************************************************/

int main(void)
{
    return aoc_run(AOC_DAY);
}
