#include "ascii.h"
#include "binary.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        for (unsigned int value = 32; value <= 126; value++) {
            print_row(value);
        }
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        unsigned int value = binary_to_decimal(argv[i]);
        print_row(value);
    }
    return 0;
}
