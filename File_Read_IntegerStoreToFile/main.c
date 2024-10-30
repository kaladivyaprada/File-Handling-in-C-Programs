#include <stdio.h>
#include <stdlib.h>

int main()

        FILE *fp;
        int num;

        fp = fopen("prada.txt","w");
        if(fp == NULL){
            printf("Error opening file for writing\n");

            return 1;
        }
        printf("Enter the integer:");
        scanf("%d", &num);

        fprintf(fp, "%d\n",num);
        fclose(fp);

        fp = fopen("prada.txt","r");
        if(fp == NULL){
            printf("Error opening file for reading\n");
            return 1;
        }

        printf("Contents of the file:\n");
        fscanf(fp, "%d", &num);
        printf("%d\n",num);
        fclose(fp);
        return 0;
}
