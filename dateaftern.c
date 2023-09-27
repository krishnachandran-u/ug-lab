#include <stdio.h>

struct date {
    int day;
    int month;
    int year;
};

int isleapyear(int year);
int daysinmonth(int month, int year);
int isvaliddate(struct date *d);
void findnextdate(struct date *d, int n);

int main() {
    struct date d;
    int n;
    printf("Enter date (dd mm yyyy): ");
    scanf("%d %d %d", &d.day, &d.month, &d.year);
    printf("Enter number of days: ");
    scanf("%d", &n);
    if (!isvaliddate(&d)) {
        printf("Invalid date\n");
        return 1;
    }
    findnextdate(&d, n);
    return 0;
}

int isleapyear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int daysinmonth(int month, int year) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isleapyear(year))
        return 29;
    return days[month];
}

int isvaliddate(struct date *d) {
    if (d->year < 0 || d->month < 1 || d->month > 12 || d->day < 1 || d->day > daysinmonth(d->month, d->year))
        return 0;
    return 1;
}

void findnextdate(struct date *d, int n) {
    int t = n;
    while (n > 0) {
        int daysincurrentmonth = daysinmonth(d->month, d->year);
        if (d->day + n <= daysincurrentmonth) {
            d->day += n;
            n = 0;
        } else {
            n -= (daysincurrentmonth - d->day + 1);
            d->day = 1;
            if (d->month < 12)
                d->month++;
            else {
                d->month = 1;
                d->year++;
            }
        }
    }
    printf("Date after %d days: %02d %02d %04d\n", t, d->day, d->month, d->year);
}

