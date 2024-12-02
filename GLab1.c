#include <stdio.h>
#include <stdlib.h>
void classify_triangle();
void filter_integers();
void filter_integers_error();
void intersect_ranges();
double read_and_swap(double *a, double *b);

int main() {
    int choice;

    printf("Choose an option (1-5):\n");
    printf("1. Classify Triangle\n");
    printf("2. Filter Integers\n");
    printf("3. Filter Integers with Error Handling\n");
    printf("4. Intersect Ranges\n");
    printf("5. Exit\n");

    if (scanf("%d", &choice) != 1 || choice < 1 || choice > 5) {
        printf("Invalid input.\n");
        return 1;
    }

    switch (choice) {
        case 1:
            classify_triangle();
            break;
        case 2:
            filter_integers();
            break;
        case 3:
            filter_integers_error();
            break;
        case 4:
            intersect_ranges();
            break;
        case 5:
            printf("Exiting.\n");
            return 0;
    }

    return 0;
}


void classify_triangle() {
    double angle1, angle2;

    printf("Enter two angles: ");
    if (scanf("%lf %lf", &angle1, &angle2) != 2) {
        printf("Error reading input.\n");
        return;
    }

    double angle3 = 180 - (angle1 + angle2);

    if (angle1 <= 0 || angle2 <= 0 || angle3 <= 0) {
        printf("Not a triangle\n");
    } else if (angle1 == angle2 && angle2 == angle3) {
        printf("Equilateral triangle\n");
    } else if (angle1 == angle2 || angle1 == angle3 || angle2 == angle3) {
        printf("Isosceles triangle\n");
    } else {
        printf("Scalene triangle\n");
    }
}

void filter_integers() {
    int numbers[10];
    int sum = 0;

    printf("Enter 10 integers: ");
    for (int i = 0; i < 10; i++) {
        if (scanf("%d", &numbers[i]) != 1) {
            printf("Invalid input\n");
            return;
        }
        sum += numbers[i];
    }

    for (int i = 0; i < 10; i++) {
        if (numbers[i] < sum) {
            printf("%d ", numbers[i]);
        }
    }
    printf("\n");
}

void filter_integers_error() {
    int numbers[10];
    int sum = 0;
    int count = 0;

    printf("Enter up to 10 integers: ");
    for (int i = 0; i < 10; i++) {
        if (scanf("%d", &numbers[i]) != 1) {
            break;
        }
        sum += numbers[i];
        count++;
    }

    for (int i = 0; i < count; i++) {
        if (numbers[i] < sum) {
            printf("%d ", numbers[i]);
        }
    }
    printf("\n");
}

void intersect_ranges() {
    double a, b, c, d;

    printf("Enter the initial range (a b): ");
    if (!read_and_swap(&a, &b)) return;

    printf("[%.6lf, %.6lf]\n", a, b);

    while (1) {
        printf("Enter the next range (c d): ");
        if (!read_and_swap(&c, &d)) break;

        if (b < c || d < a) break;

        if (c > a) a = c;
        if (d < b) b = d;

        printf("[%.6lf, %.6lf]\n", a, b);
    }

    for (int i = (int)a; i <= (int)b; i++) {
        if (i >= a && i <= b) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

double read_and_swap(double *a, double *b) {
    if (scanf("%lf %lf", a, b) != 2) {
        printf("Invalid input.\n");
        return 0;
    }
    if (*a > *b) {
        double temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*a == *b) {
        printf("Invalid range.\n");
        return 0;
    }
    return 1;
}
