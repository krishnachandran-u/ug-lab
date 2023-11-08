#include <stdio.h>

#define MAX 100

void insert(int data[MAX][3], int *len, int r, int c, int val) {
    data[*len][0] = r;
    data[*len][1] = c;
    data[*len][2] = val;
    (*len)++;
}

void add(int a[MAX][3], int alen, int b[MAX][3], int blen, int row, int col) {
    int apos = 0, bpos = 0;
    int result[MAX][3];
    int reslen = 0;

    while (apos < alen && bpos < blen) {
        if (a[apos][0] > b[bpos][0] ||
           (a[apos][0] == b[bpos][0] &&
            a[apos][1] > b[bpos][1])) {
            insert(result, &reslen, b[bpos][0], b[bpos][1], b[bpos][2]);
            bpos++;
        } else if (a[apos][0] < b[bpos][0] ||
                   (a[apos][0] == b[bpos][0] &&
                    a[apos][1] < b[bpos][1])) {
            insert(result, &reslen, a[apos][0], a[apos][1], a[apos][2]);
            apos++;
        } else {
            int addedval = a[apos][2] + b[bpos][2];
            if (addedval != 0)
                insert(result, &reslen, a[apos][0], a[apos][1], addedval);
            apos++;
            bpos++;
        }
    }

    while (apos < alen)
        insert(result, &reslen, a[apos][0], a[apos][1], a[apos++][2]);

    while (bpos < blen)
        insert(result, &reslen, b[bpos][0], b[bpos][1], b[bpos++][2]);

    printf("\nDimension: %dx%d", row, col);
    printf("\nSparse Matrix: \nRow\tColumn\tValue\n");
    for (int i = 0; i < reslen; i++) {
        printf("%d\t%d\t%d\n", result[i][0], result[i][1], result[i][2]);
    }
}

void transpose(int data[MAX][3], int *len, int col) {
    int count[col + 1];
    int index[col + 1];

    for (int i = 1; i <= col; i++)
        count[i] = 0;

    for (int i = 0; i < *len; i++)
        count[data[i][1]]++;

    index[0] = 0;

    for (int i = 1; i <= col; i++)
        index[i] = index[i - 1] + count[i - 1];

    int result[MAX][3];
    int reslen = *len;

    for (int i = 0; i < *len; i++) {
        int rpos = index[data[i][1]]++;
        result[rpos][0] = data[i][1];
        result[rpos][1] = data[i][0];
        result[rpos][2] = data[i][2];
    }

    *len = reslen;

    printf("\nDimension: %dx%d", col, (*len > 0) ? result[*len - 1][0] + 1 : 0);
    printf("\nSparse Matrix: \nRow\tColumn\tValue\n");
    for (int i = 0; i < *len; i++) {
        printf("%d\t%d\t%d\n", result[i][0], result[i][1], result[i][2]);
    }
}

int main() {
    int a[MAX][3];
    int b[MAX][3];

    int alen = 0, blen = 0;

    insert(a, &alen, 1, 2, 10);
    insert(a, &alen, 1, 4, 12);
    insert(a, &alen, 3, 3, 5);
    insert(a, &alen, 4, 1, 15);
    insert(a, &alen, 4, 2, 12);

    insert(b, &blen, 1, 3, 8);
    insert(b, &blen, 2, 4, 23);
    insert(b, &blen, 3, 3, 9);
    insert(b, &blen, 4, 1, 20);
    insert(b, &blen, 4, 2, 25);

    printf("Addition: ");
    add(a, alen, b, blen, 4, 4);

    printf("\nTranspose A: ");
    transpose(a, &alen, 4);


    return 0;
}

