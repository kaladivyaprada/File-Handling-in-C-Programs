#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char ch;


    printf("Enter the char: ");
    scanf(" %c", &ch);

    fp = fopen("Simple.txt", "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return EXIT_FAILURE;
    }

    fputc(ch, fp);
    fclose(fp);


    fp = fopen("Simple.txt", "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        return EXIT_FAILURE;
    }

    printf("\nChar Read from the file: %c\n", fgetc(fp));

    fclose(fp);
    return 0;
}
