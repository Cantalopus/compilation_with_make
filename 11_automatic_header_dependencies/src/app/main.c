#include "helper.h"

int main(void)
{
    // Triggers -Wall warning in preprocessing stage
    int unused_number = 123;

    return get_number();
}
