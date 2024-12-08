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
uint32_t left[ARRAY_MAX] = {0};
uint32_t right[ARRAY_MAX] = {0};

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

    while (fscanf(input_file, "%u   %u\n", &left[length], &right[length]) != EOF)
    {
        length++;
    }

    if (fclose(input_file) != 0)
    {
        printf("ERROR\t%s: %s: (%d) %s\n", __func__, INPUT_FILE, errno, strerror(errno));
        return AOC_ERROR;
    }

    return AOC_OK;
}

int compare(const void *first, const void *second)
{
    uint32_t first_value = *(uint32_t *)first;
    uint32_t second_value = *(uint32_t *)second;
    return first_value - second_value;
}

err_t solve_part_one(void)
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

    return AOC_OK;
}

err_t solve_part_two(void)
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