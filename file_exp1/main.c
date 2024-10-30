#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindrome(const char *str)
{
   int len = strlen(str);
   for (int i = 0; i < len / 2; i++) {
       if (str[i] != str[len - 1 - i]) {
           return 0;
       }
   }
   return 1;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    const char *inputString = argv[1];

    if (palindrome(inputString)) {
        printf("\"%s\" is a palindrome.\n", inputString);
    } else {
        printf("\"%s\" is not a palindrome.\n", inputString);
    }

    return 0;
}
