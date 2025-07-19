/******************************************************************************
 * @file day02.c
 * @brief Solutions for the day 2 challenges of Advent of Code 2024.
 * @author Raphael CAUSSE
 *****************************************************************************/

/***** Includes **************************************************************/

#include "aoc_2024.h"

/***** Definitions ***********************************************************/

#define AOC_DAY 2

#define MAX_REPORTS 1024
#define MAX_LEVELS 16

#define DIFF_MIN 1
#define DIFF_MAX 3

/***** Globals ***************************************************************/

size_t num_reports = 0;
int32_t reports[MAX_REPORTS][MAX_LEVELS] = {0};
size_t report_lengths[MAX_REPORTS] = {0};

/***** Functions *************************************************************/

err_t read_input(void)
{
    FILE *input_file;
    size_t num_levels = 0;

    input_file = fopen(INPUT_FILE, "r");
    if (input_file == NULL)
    {
        LOG_ERROR_FILE();
        return AOC_ERROR;
    }

    while (!feof(input_file))
    {
        num_levels = 0;
        while (fscanf(input_file, "%d", &reports[num_reports][num_levels]) == 1)
        {
            num_levels++;
            if (getc(input_file) == '\n')
            {
                break;
            }
        }

        if (num_levels >= 2)
        {
            report_lengths[num_reports] = num_levels;
            num_reports++;
        }
    }

    if (fclose(input_file) != 0)
    {
        LOG_ERROR_FILE();
        return AOC_ERROR;
    }

    return AOC_SUCCESS;
}

bool is_report_safe(int32_t levels[], size_t num_levels)
{
    int32_t diff;
    uint8_t num_pos = 0;
    uint8_t num_neg = 0;

    for (size_t i = 0; i < num_levels - 1; i++)
    {
        diff = levels[i + 1] - levels[i];

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
            return false;
        }
    }

    return (num_pos == 0 || num_neg == 0);
}

err_t solve_part_one(void)
{
    uint32_t count_safe_reports = 0;

    for (size_t r = 0; r < num_reports; r++)
    {
        if (is_report_safe(reports[r], report_lengths[r]))
        {
            count_safe_reports++;
        }
    }

    printf("output: %u\n", count_safe_reports);

    return AOC_SUCCESS;
}

err_t solve_part_two(void)
{
    uint32_t count_safe_reports = 0;
    bool safe_with_dampener = false;

    for (size_t r = 0; r < num_reports; r++)
    {
        if (is_report_safe(reports[r], report_lengths[r]))
        {
            count_safe_reports++;
            continue;
        }

        /* Problem dampener */
        safe_with_dampener = false;
        for (size_t i = 0; i < report_lengths[r]; i++)
        {
            int32_t tmp_levels[MAX_LEVELS] = {0};
            size_t k = 0;

            for (size_t j = 0; j < report_lengths[r]; j++)
            {
                if (j != i)
                {
                    tmp_levels[k] = reports[r][j];
                    k++;
                }
            }

            if (is_report_safe(tmp_levels, k))
            {
                safe_with_dampener = true;
                break;
            }
        }

        if (safe_with_dampener)
        {
            count_safe_reports++;
        }
    }

    printf("output: %u\n", count_safe_reports);

    return AOC_SUCCESS;
}

int main(void)
{
    if (read_input() == AOC_ERROR)
    {
        return EXIT_FAILURE;
    }

    BANNER_START(AOC_DAY, AOC_PART_1);
    if (solve_part_one() == AOC_ERROR)
    {
        return EXIT_FAILURE;
    }
    BANNER_END();

    BANNER_START(AOC_DAY, AOC_PART_2);
    if (solve_part_two() == AOC_ERROR)
    {
        return EXIT_FAILURE;
    }
    BANNER_END();

    return EXIT_SUCCESS;
}