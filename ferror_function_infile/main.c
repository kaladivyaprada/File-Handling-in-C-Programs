#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char ch;
    fp = fopen("Simple.txt","w");
    fputc('A',fp);
    rewind(fp);
    ch = fgetc(fp);
    if(ferror(fp)){
        printf("Error in reading from file");
    }
    else{
        printf("ch= %c",ch);
        fclose(fp);
    }
    return 0;
}
