# BIGINT Library in C

The **BIGINT** library is a C implementation designed to perform arithmetic operations—addition, subtraction, multiplication, and division—on integers larger than those typically handled by standard data types. This is achieved by using singly linked lists to represent large integers.

---

## Features

- **Arbitrary Precision Arithmetic**: Handles integers beyond the size limitations of standard data types.
- **Dynamic Memory Allocation**: Efficient storage using singly linked lists.
- **Basic Operations**: Supports addition, subtraction, multiplication, and division.

---

## Getting Started

### Prerequisites

To use the BIGINT library, you need a C compiler (e.g., GCC).

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/Taran1504/BIGINT_using_c.git
   cd BIGINT_using_c
   ```

2. Include the `BIGINT.h` header in your project:

   ```c
   #include "BIGINT.h"
   ```

3. Compile your program along with `bigint.c`:

   ```bash
   gcc -o your_program your_source.c bigint.c
   ```

---

## Usage Example

Here is an example demonstrating basic operations using the BIGINT library:

```c
#include "BIGINT.h"
#include <stdio.h>

int main() {
    // Initialize big integers
    BIGINT num1, num2, result;
    BIGINT_init(&num1);
    BIGINT_init(&num2);
    BIGINT_init(&result);

    // Assign values to num1 and num2
    BIGINT_assign(&num1, 1234567890123456789);
    BIGINT_assign(&num2, 9876543210987654321);

    // Perform addition
    BIGINT_add(&result, &num1, &num2);
    printf("Sum: ");
    BIGINT_print(&result);

    // Perform subtraction
    BIGINT_subtract(&result, &num1, &num2);
    printf("Difference: ");
    BIGINT_print(&result);

    // Perform multiplication
    BIGINT_multiply(&result, &num1, &num2);
    printf("Product: ");
    BIGINT_print(&result);

    // Perform division
    BIGINT_divide(&result, &num1, &num2);
    printf("Quotient: ");
    BIGINT_print(&result);

    // Free allocated memory
    BIGINT_free(&num1);
    BIGINT_free(&num2);
    BIGINT_free(&result);

    return 0;
}
```

---
## Contributing

Contributions are welcome! If you have suggestions or improvements, fork the repository and submit a pull request.

---

## Acknowledgments

This library was developed to provide a solution for handling large integers in C, especially for applications requiring arbitrary precision arithmetic.
