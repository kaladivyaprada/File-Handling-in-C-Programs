#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp;
  char ch;
  fp = fopen("Simple.txt","w");
  if(fp == NULL){
    printf("Unable to file create");
  }
  else{
    printf("File Successfully Created\n");
  }

  fp = fopen("Simple.txt", "r");
  if(fp == NULL){
    printf("Unable to file Open");
  }
  else{
    printf("\nFile Successfully Open \n");
  }

  return 0;
}
