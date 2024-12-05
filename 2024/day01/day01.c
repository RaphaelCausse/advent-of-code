/***** Includes ***************************************************************/

#include "aoc_2024.h"

/***** Definitions ************************************************************/

#ifdef TEST
#define EXPECTED_OUTPUT 11
#endif

#define ARRAY_MAX 1024

typedef enum
{
    E_ERROR = -1,
    E_OK = 0,
} err_t;

/***** Globals ***************************************************************/

size_t len = 0;
uint32_t left[ARRAY_MAX] = {0};
uint32_t right[ARRAY_MAX] = {0};

/***** Functions *************************************************************/

err_t read_input(void)
{
    int ret;
    FILE *input_file;

    input_file = fopen(INPUT_FILE, "r");
    if (input_file == NULL)
    {
        printf("ERROR\t%s: %s: (%d) %s\n", __func__, INPUT_FILE, errno, strerror(errno));
        return E_ERROR;
    }

    ret = fscanf(input_file, "%u   %u\n", &left[len], &right[len]);
    while (ret != EOF)
    {
        len++;
        ret = fscanf(input_file, "%u   %u\n", &left[len], &right[len]);
    }

    ret = fclose(input_file);
    if (ret != 0)
    {
        printf("ERROR\t%s: %s: (%d) %s\n", __func__, INPUT_FILE, errno, strerror(errno));
        return E_ERROR;
    }

    return E_OK;
}

int compare(const void *first, const void *second)
{
    uint32_t first_value = *(uint32_t *)first;
    uint32_t second_value = *(uint32_t *)second;
    return first_value - second_value;
}

err_t compute(void)
{
    uint32_t sum = 0;

    qsort(left, len, sizeof(*left), compare);
    qsort(right, len, sizeof(*right), compare);

    for (size_t i = 0; i < len; i++)
    {
        sum += abs(left[i] - right[i]);
    }

#ifdef TEST
    printf("output: %u (expected: %d) ... %s\n", sum, EXPECTED_OUTPUT, (sum == EXPECTED_OUTPUT ? "PASSED" : "FAILED"));
#else
    printf("output: %u\n", sum);
#endif

    return E_OK;
}

int main(void)
{
    if (read_input() == E_ERROR)
    {
        return EXIT_FAILURE;
    }

    if (compute() == E_ERROR)
    {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}