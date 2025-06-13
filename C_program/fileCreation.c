#include<stdio.h>
#include<stdlib.h>
int main() {
    for(int i=1;i<=5;i++){
        char command[20];
        sprintf(command,"type nul > hello%d.c",i);
        system(command);
    }
    printf("File created");
    return 0;
}
