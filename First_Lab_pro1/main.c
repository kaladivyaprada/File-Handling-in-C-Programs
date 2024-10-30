#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct EMPLOYEE
{
    int empid;
    char name[20];
    char dept[20];
    int salary;
    int age;
} e;

void add_record(FILE*fp)
{
    printf("\n Enter the details of the employee...\n");
    printf("ID:");
    scanf("%d",&e.empid);
    printf("NAME:");
    scanf("%s",e.name);
    printf("DEPATMENT:");
    scanf("%s",e.dept);
    printf("SALARY:");
    scanf("%d",&e.salary);
    printf("AGE:");
    scanf("%d",&e.age);
    fprintf(fp,"%d\t%s\t%s\t%d\t%d \n ",e.empid,e.name,e.dept,e.salary,e.age);
    printf("\n Record saved successfully");
}

void display_record(FILE*fp)
{
    printf("ID \t\t NAME \t\t DEPT \t\t SALARY \t\t AGE \n");
    printf("--------------------------------------------\n");
    while(fscanf(fp,"%d%s%s%d%d",&e.empid,e.name,e.dept,&e.salary,&e.age)!=EOF)
        printf("%d \t\t %s \t\t %s \t\t %d \t\t %d \n",e.empid,e.name,e.dept,e.salary,e.age);
}

void search_record(FILE*fp)
{
    int flag = 0;
    char dept[20];
    printf("\n Enter the dept to search : ");
    scanf("%s",dept);
    while(fscanf(fp,"%d%s%s%d%d",&e.empid,e.name,e.dept,&e.salary,&e.age)!=EOF)
    {
        if(strcmp(e.dept,dept)==0)
        {
            if(flag==0)
            {
                printf("\n Searched successful !!");
                printf("\n ID \t\t NAME \t\t DEPT \t\t SALARY \t\t AGE \n");
                printf("-----------------------------------------------\n");
                flag=1;
            }
            printf("%d \t\t %s \t\t %s \t\t %d \t\t  %d \t\t ",e.empid,e.name,e.dept,e.salary,e.age);
        }
    }
    if (flag==0)
    printf("\n Failure no such record found \n");
}
int main()
{
    FILE*fp;
    int choice;
    while(1)
    {
        printf("\n\n 1:Add record \n 2:search record \n 3:Display record \n 4:exit");
        printf("\n Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:fp=fopen("cmpfile","a");
            if (fp==NULL)
                printf("\n Error in opening file");
            else
            {
                add_record(fp);
                fclose(fp);
            }
            break;
            case 2: fp=fopen("cmpfile","r");
            if(fp==NULL)
                printf("\n Error in opening file");
            else
            {
                search_record(fp);
                fclose(fp);
            }
            break;
            case 3:fp=fopen("cmpfile","r");
            if (fp==NULL)
                printf("\n No such record found to display!!");
            else
            {
                display_record(fp);
                fclose(fp);
            }
            break;
            case 4:exit(0);
            default :printf("\n invalid choice !!");
        }
    }
    return 0;
}
