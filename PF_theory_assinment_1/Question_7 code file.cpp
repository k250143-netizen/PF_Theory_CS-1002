#include <stdio.h>

int main() {
    int value;

    printf("Please enter a value in the range 1...7: ");
    scanf("%d", &value);

    if (value == 1) {
        printf("You entered Monday\n");
    }
    else if (value == 2) {
        printf("You entered Tuesday\n");
    }
    else if (value == 3) {
        printf("You entered Wednesday\n");
    }
    else if (value == 4) {
        printf("You entered Thursday\n");
    }
    else if (value == 5) {
        printf("You entered Friday\n");
    }
    else if (value == 6) {
        printf("You entered Saturday\n");
    }
    else if (value == 7) {
        printf("You entered Sunday\n");
    }
    else {
        printf("You entered a value out of range\n");
    }

    return 0;
}
