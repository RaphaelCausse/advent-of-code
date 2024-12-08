/******************************************************************************
 * @file day02.c
 * @brief Solutions for the day 2 challenges of Advent of Code 2024.
 * @author Raphael CAUSSE
 *****************************************************************************/

/***** Includes **************************************************************/

#include "aoc_2024.h"

/***** Definitions ***********************************************************/

#define AOC_DAY 2

#define REPORTS_MAX 1024
#define LEVELS_MAX 16

#define DIFF_MIN 1
#define DIFF_MAX 3

/***** Globals ***************************************************************/

size_t num_reports = 0;
int32_t reports[REPORTS_MAX][LEVELS_MAX] = {0};
size_t report_lengths[REPORTS_MAX] = {0};

/***** Functions *************************************************************/

err_t read_input(void)
{
    FILE *input_file;
    size_t num_levels = 0;

    input_file = fopen(INPUT_FILE, "r");
    if (input_file == NULL)
    {
        printf("ERROR\t%s: %s: (%d) %s\n", __func__, INPUT_FILE, errno, strerror(errno));
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
        printf("ERROR\t%s: %s: (%d) %s\n", __func__, INPUT_FILE, errno, strerror(errno));
        return AOC_ERROR;
    }

    return AOC_OK;
}

err_t solve_part_one(void)
{
    uint32_t count_safe_reports = 0;
    bool safe_report = true;
    uint8_t num_pos = 0;
    uint8_t num_neg = 0;

    for (size_t r = 0; r < num_reports; r++)
    {
        safe_report = true;
        num_pos = 0;
        num_neg = 0;

        for (size_t i = 0; i < report_lengths[r] - 1; i++)
        {
            int32_t diff = reports[r][i + 1] - reports[r][i];

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

    return AOC_OK;
}

err_t solve_part_two(void)
{
    /* TODO */

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