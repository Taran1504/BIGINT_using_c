#include<stdio.h>
#include<stdlib.h>
#include"BIGINT.h"
int main()
{
	struct Node* num1 = inputBigNumber();
    struct Node* num2 = inputBigNumber();

    // Add the big numbers
    struct Node* sum = addBigNumbers(num1, num2);

    // Subtract the big numbers
    struct Node* difference = subtractBigNumbers(num1, num2);

    // Multiply the big numbers
    struct Node* product = multiplyBigNumbers(num1, num2);

    // Divide the big numbers
    struct Node* division = divideBigNumbers(num1, num2);

    // Print the results
    printf("Number 1: ");
    printBigNumber(num1);
    printf("Number 2: ");
    printBigNumber(num2);
    printf("Sum: ");
    printBigNumber(sum);
    printf("Difference: ");
    printBigNumber(difference);
    printf("Product: ");
    printBigNumber(product);
    printf("Division: ");
    printBigNumber(division);

    // Free memory
    free(num1);
    free(num2);
    free(sum);
    free(difference);
    free(product);
    free(division);

    return 0;
}
