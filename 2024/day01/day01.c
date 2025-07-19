/******************************************************************************
 * @file day01.c
 * @brief Solutions for the day 1 challenges of Advent of Code 2024.
 * @author Raphael CAUSSE
 *****************************************************************************/

/***** Includes **************************************************************/

#include "aoc_2024.h"

/***** Definitions ***********************************************************/

#define AOC_DAY 1

#define ARRAY_MAX 1024

/***** Globals ***************************************************************/

size_t length = 0;
int32_t left[ARRAY_MAX] = {0};
int32_t right[ARRAY_MAX] = {0};

/***** Functions *************************************************************/

aoc_status_t read_input(void)
{
    FILE *input_file;

    input_file = fopen(INPUT_FILE, "r");
    if (input_file == NULL)
    {
        LOG_ERROR_FILE();
        return AOC_ERROR;
    }

    while (fscanf(input_file, "%d   %d\n", &left[length], &right[length]) != EOF)
    {
        length++;
    }

    if (fclose(input_file) != 0)
    {
        LOG_ERROR_FILE();
        return AOC_ERROR;
    }

    return AOC_SUCCESS;
}

int compare(const void *first, const void *second)
{
    int32_t first_value = *(int32_t *)first;
    int32_t second_value = *(int32_t *)second;
    return first_value - second_value;
}

aoc_status_t solve_part_one(void)
{
    uint32_t sum = 0;

    /* Ascending order sort */
    qsort(left, length, sizeof(*left), compare);
    qsort(right, length, sizeof(*right), compare);

    for (size_t i = 0; i < length; i++)
    {
        sum += abs(left[i] - right[i]);
    }

    printf("output: %u\n", sum);

    return AOC_SUCCESS;
}

aoc_status_t solve_part_two(void)
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

    printf("output: %u\n", similarity);

    return AOC_SUCCESS;
}

/***** Main ******************************************************************/

int main(void)
{
    aoc_timer_t timer;

    if (read_input() == AOC_ERROR)
    {
        return EXIT_FAILURE;
    }

    aoc_banner_start(AOC_DAY, AOC_PART_1);
    aoc_timer_start(&timer);
    if (solve_part_one() == AOC_ERROR)
    {
        return EXIT_FAILURE;
    }
    aoc_timer_end(&timer);
    aoc_banner_end();

    aoc_banner_start(AOC_DAY, AOC_PART_2);
    aoc_timer_start(&timer);
    if (solve_part_two() == AOC_ERROR)
    {
        return EXIT_FAILURE;
    }
    aoc_timer_end(&timer);
    aoc_banner_end();

    return EXIT_SUCCESS;
}