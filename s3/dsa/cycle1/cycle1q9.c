#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <string.h>

struct employee{
    int empid;
    char name[100];
    int salary;
};

int main(){
    int n; printf("n: "); scanf("%d", &n);
    struct employee *emp;
    emp = (struct employee*) malloc(sizeof(struct employee*)*n);

    for(int i = 0; i < n; i++){
        printf("%d: empid: ", i); scanf("%d" , &emp[i].empid);
        printf("%d: name: ", i); scanf("%s", emp[i].name);
        printf("%d: salary: ", i); scanf("%d", &emp[i].salary);
    }

    int x; printf("x: "); scanf("%d", &x);
    for(int i = 0; i < n; i++){
        if(emp[i].empid == x){
            printf("found at %d\n", i);
            return 0;
        }
    }
    printf("not found\n");
    return 0;
}

/*

n: 3
0: empid: 6  
0: name: john
0: salary: 5000
1: empid: 7
1: name: chris
1: salary: 40000
2: empid: 5     
2: name: amanda
2: salary: 40000
x: 5
found at 2

*/
