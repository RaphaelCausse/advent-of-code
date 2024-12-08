/******************************************************************************
 * @file day02.c
 * @brief Solutions for the day 2 challenges of Advent of Code 2024.
 * @author Raphael CAUSSE
 *****************************************************************************/

/***** Includes **************************************************************/

#include "aoc_2024.h"

/***** Definitions ***********************************************************/

#define AOC_DAY 2

#define NUM_LEVEL 32

#define DIFF_MIN 1
#define DIFF_MAX 3

/***** Globals ***************************************************************/

/***** Functions *************************************************************/

err_t solve_part_one(void)
{
    FILE *input_file;
    int32_t levels[NUM_LEVEL] = {0};
    size_t num_levels = 0;
    uint32_t count_safe_reports = 0;
    int32_t diff = 0;
    uint8_t num_pos = 0;
    uint8_t num_neg = 0;
    bool safe_report = false;

    input_file = fopen(INPUT_FILE, "r");
    if (input_file == NULL)
    {
        printf("ERROR\t%s: %s: (%d) %s\n", __func__, INPUT_FILE, errno, strerror(errno));
        return AOC_ERROR;
    }

    while (!feof(input_file))
    {
        num_levels = 0;
        while (fscanf(input_file, "%d", &levels[num_levels]) == 1)
        {
            num_levels++;
            if (getc(input_file) == '\n')
            {
                break;
            }
        }

        if (num_levels < 2)
        {
            continue;
        }

        num_pos = 0;
        num_neg = 0;
        safe_report = true;

        for (size_t i = 0; i < num_levels - 1; i++)
        {
            diff = levels[i] - levels[i + 1];
            if (diff > 0)
            {
                num_pos++;
            }
            else if (diff < 0)
            {
                num_neg++;
            }

            if (abs(diff) < DIFF_MIN || abs(diff) > DIFF_MAX)
            {
                safe_report = false;
                break;
            }
        }
        if (!(num_pos == 0 || num_neg == 0))
        {
            safe_report = false;
        }

        if (safe_report)
        {
            count_safe_reports++;
        }
    }

    printf("output: %u\n", count_safe_reports);

    if (fclose(input_file) != 0)
    {
        printf("ERROR\t%s: %s: (%d) %s\n", __func__, INPUT_FILE, errno, strerror(errno));
        return AOC_ERROR;
    }

    return AOC_OK;
}

err_t solve_part_two(void)
{
    /* TODO */

    return AOC_OK;
}

int main(void)
{
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