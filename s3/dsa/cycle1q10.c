/*
    author: krishnachandran u
    github: https://github.com/krishnachandran-u
    text-editor: NVIM v0.9.1
    compiler: gcc 11.4.0
*/

/*
10. Write a C program to read student names stored in a file. Sort the names in alphabetical order
using bubble sort. Implement binary search to search for a given name. Implement sort and
search routines as separate functions.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

void bubblesort(char names[100][100], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(strcmp(names[j], names[j + 1]) > 0){
                char temp[100];
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}

int binarysearch(char names[100][100], int n, char *x){
    int l = -1, r = n;
    while(r - l > 1){
        int m = l + (r - l)/2;
        if(strcmp(names[m], x) <= 0) l = m;
        else r = m;
    }
    return (l >= 0 && strcmp(names[l], x) == 0)? l: -1;
}

int main(){
    char names[100][100];
    FILE *fp = fopen("studentname.txt", "r");
    if(!fp){
        printf("error\n");
        return 0;
    }

    int num = 0;
    while(fscanf(fp, "%s", names[num]) == 1){
        num++;
    }

     
    fclose(fp);
    bubblesort(names, num);

    printf("Sorted names: \n");
    for(int i = 0; i < num; i++){
        printf("%s\n", names[i]);
    }

    char searchname[100];
    printf("enter name to search: ");
    scanf("%s", searchname);
    int result = binarysearch(names, num, searchname); 

    if(result != -1){
        printf("found at position %d\n", result);
    }
    else{
        printf("not found\n");
    }

    return 0;
}

/*

Sorted names: 
Abigail
Aiden
Alexander
Alice
Amelia
Andrew
Anthony
Aria
Ava
Avery
Benjamin
Bob
Carter
Charlie
Chloe
Christopher
Daniel
Daniel
David
Ella
Emily
Emma
Ethan
Eva
Gabriel
Grace
Grace
Hannah
Henry
Isabella
Jackson
James
John
Joseph
Liam
Lily
Lucy
Madison
Matthew
Mia
Michael
Nicholas
Olivia
Olivia
Samuel
Scarlett
Sofia
Sophia
William
Zoe
enter name to search: Sophia
found at position 47

*/
