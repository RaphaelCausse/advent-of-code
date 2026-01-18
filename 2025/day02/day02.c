/******************************************************************************
 * @file day02.c
 * @brief Solutions for day 2 of Advent of Code 2025.
 * @author Raphael CAUSSE
 *****************************************************************************/

/***** Includes **************************************************************/

#include "aoc.h"

/***** Definitions ***********************************************************/

#define AOC_DAY (2)

#define MAX_RANGES (64)

/***** Types *****************************************************************/

typedef struct
{
    uint64_t start;
    uint64_t end;
} t_range;

/***** Globals ***************************************************************/

size_t num_ranges = 0;
t_range ranges[MAX_RANGES] = {0};

/***** Functions *************************************************************/

t_aoc_result aoc_read_input(void)
{
    FILE *input_file = NULL;
    uint64_t start = 0;
    uint64_t end = 0;
    int c = 0;

    input_file = fopen(INPUT_FILE, "r");
    if (NULL == input_file)
    {
        LOG_ERROR_FILE();
        return aoc_result_error();
    }

    while (true)
    {
        /* Read range */
        if (fscanf(input_file, "%llu-%llu", &start, &end) != 2)
        {
            if (feof(input_file))
            {
                break;
            }

            LOG_ERROR("Invalid range format");
            fclose(input_file);
            return aoc_result_error();
        }

        if (num_ranges >= MAX_RANGES)
        {
            LOG_ERROR("Max ranges reached");
            fclose(input_file);
            return aoc_result_error();
        }

        ranges[num_ranges].start = start;
        ranges[num_ranges].end = end;
        num_ranges++;

        /* Check separator */
        c = fgetc(input_file);
        if (EOF == c)
        {
            break;
        }
        if (',' != c)
        {
            LOG_ERROR("Expected ',' separator");
            fclose(input_file);
            return aoc_result_error();
        }
    }

    fclose(input_file);
    return aoc_result_ok();
}

t_aoc_result aoc_solve_part_one(void)
{
    uint64_t sum_invalid_id = 0;

    return aoc_result_notimpl();

    // for (size_t i = 0; i < num_ranges; i++)
    // {
    //     printf("%llu - %llu\n", ranges[i].start, ranges[i].end);
    // }

    // return aoc_result_u64(sum_invalid_id, 1227775554); /* Example solution is 1227775554 */
}

t_aoc_result aoc_solve_part_two(void)
{
    return aoc_result_notimpl();
}

/***** Main ******************************************************************/

int main(void)
{
    return aoc_run(AOC_DAY);
}
