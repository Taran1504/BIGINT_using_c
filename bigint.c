#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>


// Define a structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to reverse a linked list
struct Node* reverseLinkedList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Function to add two big numbers represented as linked lists
struct Node* addBigNumbers(struct Node* num1, struct Node* num2) {
    struct Node* result = NULL;
    struct Node* temp;
    int carry = 0;

    while (num1 != NULL || num2 != NULL || carry != 0) {
        int sum = carry;
        if (num1 != NULL) {
            sum += num1->data;
            num1 = num1->next;
        }
        if (num2 != NULL) {
            sum += num2->data;
            num2 = num2->next;
        }

        carry = sum / 10;
        sum %= 10;

        struct Node* newNode = createNode(sum);
        if (result == NULL) {
            result = newNode;
            temp = result;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    return result;
}

// Function to subtract two big numbers represented as linked lists
struct Node* subtractBigNumbers(struct Node* num1, struct Node* num2) {
    struct Node* result = NULL;
    struct Node* temp;
    int borrow = 0;

    while (num1 != NULL || num2 != NULL) {
        int diff = borrow;
        if (num1 != NULL) {
            diff += num1->data;
            num1 = num1->next;
        }
        if (num2 != NULL) {
            diff -= num2->data;
            num2 = num2->next;
        }

        if (diff < 0) {
            diff += 10;
            borrow = -1;
        } else {
            borrow = 0;
        }

        struct Node* newNode = createNode(diff);
        if (result == NULL) {
            result = newNode;
            temp = result;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    return result;
}

// Function to multiply two big numbers represented as linked lists
struct Node* multiplyBigNumbers(struct Node* num1, struct Node* num2) {
    struct Node* result = createNode(0);
    struct Node* tempResult = result;

    while (num2 != NULL) {
        int carry = 0;
        struct Node* tempNum1 = num1;
        result = tempResult;

        while (tempNum1 != NULL) {
            int product = (num2->data * tempNum1->data) + carry;

            if (result == NULL) {
                result = createNode(product % 10);
                tempResult = result;
            } else {
                while (result->next != NULL) {
                    result = result->next;
                }
                result->next = createNode(product % 10);
            }

            carry = product / 10;
            tempNum1 = tempNum1->next;
        }

        if (carry > 0) {
            while (result->next != NULL) {
                result = result->next;
            }
            result->next = createNode(carry);
        }

        num2 = num2->next;
        tempResult = addBigNumbers(tempResult, createNode(0));
    }

    return tempResult;
}
// Function to check if num1 is greater than or equal to num2
int isGreaterOrEqual(struct Node* num1, struct Node* num2) {
    if (num1 == NULL) {
        return 0;
    }
    if (num2 == NULL) {
        return 1;
    }

    num1 = reverseLinkedList(num1);
    num2 = reverseLinkedList(num2);

    while (num1 != NULL && num2 != NULL) {
        if (num1->data > num2->data) {
            return 1;
        } else if (num1->data < num2->data) {
            return 0;
        }
        num1 = num1->next;
        num2 = num2->next;
    }

    return 1;
}
// Function to divide two big numbers represented as linked lists
struct Node* divideBigNumbers(struct Node* num1, struct Node* num2) {
    struct Node* result = NULL;

    // Ensure num2 is not zero
    while (num2 != NULL) {
        if (num2->data != 0) {
            break;
        }
        num2 = num2->next;
    }

    if (num2 == NULL) {
        fprintf(stderr, "Division by zero is not allowed.\n");
        exit(1);
    }

    while (num1 != NULL) {
        int quotient = 0;
        struct Node* tempNum1 = num1;

        while (tempNum1 != NULL && isGreaterOrEqual(tempNum1, num2)) {
            tempNum1 = subtractBigNumbers(tempNum1, num2);
            quotient++;
        }

        if (result == NULL) {
            result = createNode(quotient);
        } else {
            struct Node* tempResult = result;
            while (tempResult->next != NULL) {
                tempResult = tempResult->next;
            }
            tempResult->next = createNode(quotient);
        }

        num1 = num1->next;
    }

    return result;
}



// Function to print a linked list representing a big number
void printBigNumber(struct Node* num) {
    if (num == NULL) {
        printf("0");
        return;
    }

    num = reverseLinkedList(num);

    while (num != NULL) {
        printf("%d", num->data);
        num = num->next;
    }
    printf("\n");
}

// Function to input a big number from the user and create a linked list
struct Node* inputBigNumber() {
    struct Node* num = NULL;
    char ch;

    printf("Enter a big number (terminate with Enter or a non-digit character):\n");

    while (1) {
        ch = getchar();
        if (ch == '\n' || !isdigit(ch)) {
            break;
        }

        int digit = ch - '0';
        struct Node* newNode = createNode(digit);

        if (num == NULL) {
            num = newNode;
        } else {
            newNode->next = num;
            num = newNode;
        }
    }

    return num;
}

