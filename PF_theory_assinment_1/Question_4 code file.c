#include <stdio.h>
int main()
{
    int a, b, c, d, e;

    printf("This program takes 5 card ranks as input and determines the type of poker hand.\n");
    printf("Enter the ranks of cards (1-13)\n1 represents Ace,\n2-10 represent cards numbered 2 through 10,\n11 represents Jack,\n12 represents Queen,\n13 represents King.\n");

    printf("Enter a = ");
    scanf("%d", &a);
    printf("Enter b = ");
    scanf("%d", &b);
    printf("Enter c = ");
    scanf("%d", &c);
    printf("Enter d = ");
    scanf("%d", &d);
    printf("Enter e = ");
    scanf("%d", &e);

    if (a == b && b == c && d == e && d != a)
    {
        printf("The hand is a Full House(%d, %d, %d, %d, %d).\n", a, b, c, d, e);
        return 0;
    }
    else if (a == b && b == d && c == e && c != a)
    {
        printf("The hand is a Full House(%d, %d, %d, %d, %d).\n", a, b, c, d, e);
        return 0;
    }
    else if (a == b && b == e && c == d && c != a)
    {
        printf("The hand is a Full House(%d, %d, %d, %d, %d).\n", a, b, c, d, e);
        return 0;
    }
    else if (a == c && c == d && b == e && b != a)
    {
        printf("The hand is a Full House(%d, %d, %d, %d, %d).\n", a, b, c, d, e);
        return 0;
    }
    else if (a == c && c == e && b == d && b != a)
    {
        printf("The hand is a Full House(%d, %d, %d, %d, %d).\n", a, b, c, d, e);
        return 0;
    }
    else if (a == d && d == e && b == c && b != a)
    {
        printf("The hand is a Full House(%d, %d, %d, %d, %d).\n", a, b, c, d, e);
        return 0;
    }
    else if (b == c && c == d && a == e && a != b)
    {
        printf("The hand is a Full House(%d, %d, %d, %d, %d).\n", a, b, c, d, e);
        return 0;
    }
    else if (b == c && c == e && a == d && a != b)
    {
        printf("The hand is a Full House(%d, %d, %d, %d, %d).\n", a, b, c, d, e);
        return 0;
    }
    else if(b == d && d == e && a == c && a != b)
    {
        printf("The hand is a Full House(%d, %d, %d, %d, %d).\n", a, b, c, d, e);
        return 0;
    }
    else if (c == d && d == e && a == b && a != c)
    {
        printf("The hand is a Full House(%d, %d, %d, %d, %d).\n", a, b, c, d, e);
        return 0;
    }
    else
    {
        printf("The hand is not a Full House(%d, %d, %d, %d, %d).\n", a, b, c, d, e);
    }

    return 0;
}