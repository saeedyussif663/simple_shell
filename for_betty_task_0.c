#include <stdio.h>

/**
 * add_numbers - Adds two digits
 * @a: The 1st
 * @b: The 2cond
 *
 * Return: success
 */
int add_numbers(int a, int b)
{
return (a + b);
}

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int num1 = 5;
int num2 = 10;
int result;

printf("Hello, Betty!\n");

result = add_numbers(num1, num2);

printf("The sum of %d and %d is: %d\n", num1, num2, result);

return (0);
}
