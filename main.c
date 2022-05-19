#include <stdio.h>

#include "Emitter.h"

int main() {
    printf("Hello, World!\n");
    struct Emitter* e = Emitter_new("Vincent");
    Emitter_print(e);
    return 0;
}
