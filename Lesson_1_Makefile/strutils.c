#include "strutils.h"

char* str_reverse(char* s) {
    int a = 0;
    for(int i = 0; i < strlen(s) / 2; i++) {
        a = s[i];
        s[i] = s[strlen(s) - 1 - i];
        s[strlen(s) - 1 - i] = a;
    }
    return s;
}

char* str_trim(char* s) {
    if (s == NULL) return NULL;
    int i = 0, j = 0;
    while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n') {
        i++;
    }
    while (s[i] != '\0') {
        s[j] = s[i];
        i++;
        j++;
    }
    s[j] = '\0';
    while (j >= 0 && (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')) {
        s[j] = '\0';
        j--;
    }
    return s;
}

int str_to_int(char* s) {  
    int result = 0;
    int sign = 1;
    int i = 0;   
    for (; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            result = result * 10 + digit;
        } else {
            printf("Error: This string contains non-numeric character(s).\n");
            return 0;
        }
    }
    return result * sign;
}