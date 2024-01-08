#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
} Term;

Term* createTerm(int coefficient, int exponent) {
    Term* term = (Term*)malloc(sizeof(Term));
    term->coefficient = coefficient;
    term->exponent = exponent;
    term->next = NULL;
    return term;
}

void insertTerm(Term** polynomial, int coefficient, int exponent) {
    Term* term = createTerm(coefficient, exponent);
    if (*polynomial == NULL) {
        *polynomial = term;
    } else {
        Term* curr = *polynomial;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = term;
    }
}

void displayPolynomial(Term* polynomial) {
    Term* curr = polynomial;
    while (curr != NULL) {
        printf("%dx^%d ", curr->coefficient, curr->exponent);
        if (curr->next != NULL) {
            printf("+ ");
        }
        curr = curr->next;
    }
    printf("\n");
}

Term* multiplyPolynomials(Term* poly1, Term* poly2) {
    Term* result = NULL;
    Term* curr1 = poly1;
    while (curr1 != NULL) {
        Term* curr2 = poly2;
        while (curr2 != NULL) {
            int coefficient = curr1->coefficient * curr2->coefficient;
            int exponent = curr1->exponent + curr2->exponent;
            insertTerm(&result, coefficient, exponent);
            curr2 = curr2->next;
        }
        curr1 = curr1->next;
    }
    return result;
}

Term* addPolynomials(Term* poly1, Term* poly2) {
    Term* result = NULL;
    Term* curr1 = poly1;
    Term* curr2 = poly2;
    while (curr1 != NULL && curr2 != NULL) {
        if (curr1->exponent > curr2->exponent) {
            insertTerm(&result, curr1->coefficient, curr1->exponent);
            curr1 = curr1->next;
        } else if (curr1->exponent < curr2->exponent) {
            insertTerm(&result, curr2->coefficient, curr2->exponent);
            curr2 = curr2->next;
        } else {
            int coefficient = curr1->coefficient + curr2->coefficient;
            int exponent = curr1->exponent;
            insertTerm(&result, coefficient, exponent);
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
    }
    while (curr1 != NULL) {
        insertTerm(&result, curr1->coefficient, curr1->exponent);
        curr1 = curr1->next;
    }
    while (curr2 != NULL) {
        insertTerm(&result, curr2->coefficient, curr2->exponent);
        curr2 = curr2->next;
    }
    return result;
}

int main() {
    Term* poly1 = NULL;
    Term* poly2 = NULL;

    int n1;
    printf("Enter the number of terms for polynomial 1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        int coefficient, exponent;
        printf("Enter the coefficient and exponent for term %d: ", i+1);
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly1, coefficient, exponent);
    }

    int n2;
    printf("Enter the number of terms for polynomial 2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        int coefficient, exponent;
        printf("Enter the coefficient and exponent for term %d: ", i+1);
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly2, coefficient, exponent);
    }

    Term* product = multiplyPolynomials(poly1, poly2);
    displayPolynomial(product);

    Term* sum = addPolynomials(poly1, poly2);
    printf("Polynomial A:\n");
    displayPolynomial(poly1);
    printf("Polynomial B:\n");
    displayPolynomial(poly2);
    printf("Sum:\n");
    displayPolynomial(sum);
    return 0;
}
