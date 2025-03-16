#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
    #include <windows.h>
    #define SLEEP(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define SLEEP(ms) sleep(ms / 1000)
#endif

int main()
{
    char name[10];
    double num1, num2;
    char operator;

    printf("Enter first number: ");
    while (scanf("%lf", &num1) != 1) {
        printf("Invalid input. Please enter a valid number: ");
        while (getchar() != '\n'); // clean buffer
    }

    printf("Enter an operator (+, -, *, /): ");
    while (scanf(" %c", &operator) != 1 || (operator != '+' && operator != '-' && operator != '*' && operator != '/')) {
        printf("Invalid operator. Please enter +, -, * or /: ");
        while (getchar() != '\n');
    }

    printf("Enter second number: ");
    while (scanf("%lf", &num2) != 1) {
        printf("Invalid input. Please enter a valid number: ");
        while (getchar() != '\n');
    }

    switch (operator) {
        case '+':
            printf("Answer: %f\n", num1 + num2);
            break;
        case '-':
            printf("Answer: %f\n", num1 - num2);
            break;
        case '*':
            printf("Answer: %f\n", num1 * num2);
            break;
        case '/':
            if (num2 != 0)
                printf("Answer: %f\n", num1 / num2);
            else
                printf("Are you dumb?\n");
            break;
    }

    SLEEP(2000);
    printf("Thanks for using me :D\n");

    return 0;
}
