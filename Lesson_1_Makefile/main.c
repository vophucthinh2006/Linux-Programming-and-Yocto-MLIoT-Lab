#include <stdio.h>
#include "strutils.h"

int main() {
    char str[] = "    2026    ";
    
    printf("Original string: '%s'\n", str);
    printf("Reversed string: '%s'\n", str_reverse(str));
    printf("Trimmed string: '%s'\n", str_trim(str));
    printf("Integer value: %d\n", str_to_int(str));

    return 0;
}