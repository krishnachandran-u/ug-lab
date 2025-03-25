// RECURSIVE DESCENT PARSER
#include <stdio.h>
#include <stdlib.h>

/*
 * E -> iF
 * F -> +iF | ε
*/

char lookAhead;
char* str;

void match(char c) {
    if (lookAhead == c) {
        str++;
        lookAhead = str[0]; 
    }
    else {
        printf("ERROR"); 
        exit(1);
    }
}

void F() {
    if (lookAhead == '+') {
        match('+');
        match('i');
        F();
    }
}

void E() {
    if (lookAhead == 'i') {
        match('i');
        F();
    }
    return;
}

void parse() {
    lookAhead = str[0];
    E();
    if (lookAhead == '\0') printf("SUCCESS");    
    else printf("ERROR");
}

int main() {
    str = (char*)malloc(100*sizeof(char));    
    printf("Enter the string: ");
    scanf("%s", str);
    parse();
    return 0;
}
