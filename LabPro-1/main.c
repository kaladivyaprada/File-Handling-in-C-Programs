#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee
{
    int empid;
    char name[20];
    char dept[20];
    int salary;
    int age;
}e;

void add_record(FILE *fp)
{
    printf("\n Enter the details of the employee--------\n");
    printf("ID:");
    scanf("%d", &e.empid);
    printf("Name:");
    scanf("%s", e.name);
    printf("Department:");
    scanf("%s", e.dept);
    printf("Salary:");
    scanf("%d", &e.salary);
    printf("Age:");
    scanf("%d", &e.age);

    fprintf(fp,"%d\t\t%s\t\t%s\t\t%d\t\t%d\n",e.empid,e.name,e.dept,e.salary,e.age);
    printf("\n Record Saved Successfully");
}

void display_records(FILE *fp)
{
    printf("ID\t\tNAME\tDEPT\tSALARY\tAGE\n");
    printf("------------------------------------------\n");

    while((fscanf(fp,"%d%s%s%d%d",&e.empid,e.name,e.dept,&e.salary,&e.age))!=EOF)
        printf("%d\t\t%s\t\t%s\t\t%d\t\t%d\n",e.empid,e.name,e.dept,e.salary,e.age);
}

void search_record(FILE *fp)
{
    int flag=0;
    char dept[20];
    printf("\nEnter the dept to search:");
    scanf("%s",dept);

    while((fscanf(fp,"%d%s%s%d%d",&e.empid,e.name,e.dept,&e.salary,&e.age))!=EOF)
        if(strcmp(e.dept)==0){
            if(flag == 0){
                printf("\n Search Successful");
                printf("\tNAME\tDEPT\tSALARY\tAGE\n");
                printf("---------------------------------");
                flag=1;
            }
            printf("%d\t\t%s\t\t%s\t\t%d\t\t%d\n",e.empid,e.name,e.dept,e.salary,e.age);
        }

}
























