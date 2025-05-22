#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

void binarytodec() {
    long long binary; 
    int decimal = 0, i = 0, remainder;

    printf("Type your binary number: ");
    scanf("%lld", &binary); 

    long long tempBinary = binary; 
    while (binary != 0) {
        remainder = binary % 10;
        if (remainder != 0 && remainder != 1) {
            printf("Error: Not a valid binary number.\n");
            return; 
        }
        binary /= 10;
        decimal += remainder * pow(2, i);
        ++i;
    }
    printf("%lld in binary = %d in decimal\n", tempBinary, decimal);
}


void dectobinary() {
    int decimal;
    long long binary = 0;
    int remainder, i = 1;

    printf("Type your decimal number: ");
    scanf("%d", &decimal);

    int tempDecimal = decimal; 

    if (decimal < 0) {
        printf("Error: Please enter a non-negative decimal number for this simple conversion.\n");
        return;
    }

    if (decimal == 0) {
        printf("%d in decimal = 0 in binary\n", tempDecimal);
        return;
    }

    while (decimal != 0) {
        remainder = decimal % 2;
        decimal /= 2;
        binary += (long long)remainder * i; 
        i *= 10;
    }
    printf("%d in decimal = %lld in binary\n", tempDecimal, binary);
}

int main() {
    int decision;
    printf("Which conversion do you want to do?\n"); 
    printf("\t1- Binary to Decimal\n");       
    printf("\t2- Decimal to Binary\n");        
    printf("Enter your choice (1 or 2): ");

    scanf("%d", &decision);

    if (decision == 1) { 
        binarytodec();    
    } else if (decision == 2) {
        dectobinary();
    } else {
        printf("Invalid choice. Please run the program again and select 1 or 2.\n");
    }

    return 0;
}