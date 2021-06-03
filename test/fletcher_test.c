#include <criterion/criterion.h>

#include "../src/fletcher.h"

Test(fletcher, fletcher16)
{
    uint8_t data[] = {1, 2, 3, 4};
    size_t bytes = sizeof(data);
    cr_expect(fletcher16(data, bytes) == 5130,
              "fletcher16 calculation failed");
}