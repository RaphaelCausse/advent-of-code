/******************************************************************************
 * @file aoc.h
 * @brief Header for Advent of Code.
 * @author Raphael CAUSSE
 *****************************************************************************/

#ifndef __AOC_H__
#define __AOC_H__

/***** Includes **************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <time.h>

/***** Definitions ***********************************************************/

#define AOC_YEAR (2024)

#define AOC_PART_1 (1)
#define AOC_PART_2 (2)

#ifdef TEST
#define INPUT_FILE "data/test.txt"
#else
#define INPUT_FILE "data/input.txt"
#endif

/***** Macros ****************************************************************/

#define LOG_WARNING_NOT_IMPLEMENTED() \
    (printf("[WARNING] Not implemented\n"))

#define LOG_ERROR(msg) \
    (printf("[ERROR] %s: %s\n", __func__, msg))

#define LOG_ERROR_FILE() \
    (printf("[ERROR] %s: %s: %s (%d)\n", __func__, INPUT_FILE, strerror(errno), errno))

/***** Types *****************************************************************/

typedef struct
{
    clock_t start_time;
    clock_t end_time;
} t_aoc_timer;

typedef enum
{
    AOC_SUCCESS, /* Success */
    AOC_ERROR,   /* Error occured */
    AOC_NOTIMPL, /* Not implemented */
} t_aoc_status;

typedef enum
{
    AOC_VAL_NONE,
    AOC_VAL_U32,
    AOC_VAL_U64,
    AOC_VAL_F32,
    AOC_VAL_F64,
} t_aoc_value_type;

typedef struct
{
    t_aoc_value_type type;
    union
    {
        uint32_t u32;
        uint64_t u64;
        float f32;
        double f64;
    } v;
} t_aoc_value;

typedef struct
{
    t_aoc_status status;
    t_aoc_value obtained;
    t_aoc_value expected;
} t_aoc_result;

/***** Public Functions Prototypes **************************************************/

extern t_aoc_status aoc_read_input(void);
extern t_aoc_result aoc_solve_part_one(void);
extern t_aoc_result aoc_solve_part_two(void);

/***** Static Functions Prototypes **************************************************/

static inline t_aoc_value aoc_val_none(void);
static inline t_aoc_value aoc_val_u32(uint32_t v);
static inline t_aoc_value aoc_val_u64(uint64_t v);
static inline t_aoc_value aoc_val_f32(float v);
static inline t_aoc_value aoc_val_f64(double v);
static inline t_aoc_result aoc_result_u32(uint32_t obtained, uint32_t expected);
static inline t_aoc_result aoc_result_u64(uint64_t obtained, uint64_t expected);
static inline t_aoc_result aoc_result_f32(float obtained, float expected);
static inline t_aoc_result aoc_result_f64(double obtained, double expected);
static inline t_aoc_result aoc_result_notimpl(void);
static inline t_aoc_result aoc_result_error(void);
static void aoc_print_value(const char *label, t_aoc_value val);
static void aoc_solve_start(int day, int part);
static void aoc_solve_end(t_aoc_result result);
static int aoc_run(int day);

/***** Static Variables *************************************************************/

static t_aoc_timer v_aoc_timer = {0};

/***** Static Functions *************************************************************/

static inline t_aoc_value aoc_val_none(void)
{
    return (t_aoc_value){.type = AOC_VAL_NONE};
}

static inline t_aoc_value aoc_val_u32(uint32_t v)
{
    return (t_aoc_value){.type = AOC_VAL_U32, .v.u32 = v};
}

static inline t_aoc_value aoc_val_u64(uint64_t v)
{
    return (t_aoc_value){.type = AOC_VAL_U64, .v.u64 = v};
}

static inline t_aoc_value aoc_val_f32(float v)
{
    return (t_aoc_value){.type = AOC_VAL_F32, .v.f32 = v};
}

static inline t_aoc_value aoc_val_f64(double v)
{
    return (t_aoc_value){.type = AOC_VAL_F64, .v.f64 = v};
}

static inline t_aoc_result aoc_result_u32(uint32_t obtained, uint32_t expected)
{
    return (t_aoc_result){.status = AOC_SUCCESS, .obtained = aoc_val_u32(obtained), .expected = aoc_val_u32(expected)};
}

static inline t_aoc_result aoc_result_u64(uint64_t obtained, uint64_t expected)
{
    return (t_aoc_result){.status = AOC_SUCCESS, .obtained = aoc_val_u64(obtained), .expected = aoc_val_u64(expected)};
}

static inline t_aoc_result aoc_result_f32(float obtained, float expected)
{
    return (t_aoc_result){.status = AOC_SUCCESS, .obtained = aoc_val_f32(obtained), .expected = aoc_val_f32(expected)};
}

static inline t_aoc_result aoc_result_f64(double obtained, double expected)
{
    return (t_aoc_result){.status = AOC_SUCCESS, .obtained = aoc_val_f64(obtained), .expected = aoc_val_f64(expected)};
}

static inline t_aoc_result aoc_result_notimpl(void)
{
    return (t_aoc_result){.status = AOC_NOTIMPL, .obtained = aoc_val_none(), .expected = aoc_val_none()};
}

static inline t_aoc_result aoc_result_error(void)
{
    return (t_aoc_result){.status = AOC_ERROR, .obtained = aoc_val_none(), .expected = aoc_val_none()};
}

static void aoc_print_value(const char *label, t_aoc_value value)
{
    switch (value.type)
    {
    case AOC_VAL_U32:
        printf("%-15s: %u\n", label, value.v.u32);
        break;

    case AOC_VAL_U64:
        printf("%-15s: %llu\n", label, value.v.u64);
        break;

    case AOC_VAL_F32:
        printf("%-15s: %f\n", label, value.v.f32);
        break;

    case AOC_VAL_F64:
        printf("%-15s: %lf\n", label, value.v.f64);
        break;

    case AOC_VAL_NONE:
        printf("%-15s: (none)\n", label);
        break;

    default:
        break;
    }
}

static void aoc_solve_start(int day, int part)
{
    printf("================ AOC %04d - Day %02d - Part %01d ================\n", AOC_YEAR, day, part);

    v_aoc_timer.start_time = clock();
}

static void aoc_solve_end(t_aoc_result result)
{
    v_aoc_timer.end_time = clock();

    switch (result.status)
    {
    case AOC_SUCCESS:
        aoc_print_value("Obtained", result.obtained);
#ifdef TEST
        aoc_print_value("Expected", result.expected);
#endif
        double elapsed = (double)(v_aoc_timer.end_time - v_aoc_timer.start_time) / CLOCKS_PER_SEC;
        printf("Execution time : %.6f s\n", elapsed);
        break;

    case AOC_NOTIMPL:
        LOG_WARNING_NOT_IMPLEMENTED();
        break;

    default:
        break;
    }

    printf("============================================================\n\n");
}

static int aoc_run(int day)
{
    t_aoc_result result;

    result.status = aoc_read_input();
    if (AOC_ERROR == result.status)
    {
        return EXIT_FAILURE;
    }

    /* Part 1 */
    aoc_solve_start(day, AOC_PART_1);
    result = aoc_solve_part_one();
    aoc_solve_end(result);
    if (AOC_ERROR == result.status)
    {
        return EXIT_FAILURE;
    }

    /* Part 2 */
    aoc_solve_start(day, AOC_PART_2);
    result = aoc_solve_part_two();
    aoc_solve_end(result);
    if (AOC_ERROR == result.status)
    {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

#endif /* __AOC_H__ */
