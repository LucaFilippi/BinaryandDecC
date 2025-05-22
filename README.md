Binary-Decimal Converter in C
Hello! I've developed this C program from the ground up to allow for conversions between binary and decimal numbers. Here's a rundown of how I built it and the features I included.

Conception and Design
I started with the goal of creating a simple command-line tool for number system conversions. The core requirements were:

A user-friendly menu to select the conversion type (binary to decimal or decimal to binary).

Robust functions to handle each conversion accurately.

Basic error handling for invalid inputs.

Building the Converter: Step-by-Step
Here’s how I implemented the program and its features:

1. Structuring the Program (main() function)
I began by setting up the main() function to serve as the control center:

Menu Display: I designed a clear menu using printf that prompts the user to choose between:

Binary to Decimal conversion

Decimal to Binary conversion
I used \n (newline) and \t (tab) characters to ensure the menu is well-formatted and easy to read.

User Input: I used scanf("%d", &decision); to capture the user's choice.

Conditional Logic: Based on the user's decision:

If 1, I call the binarytodec() function.

If 2, I call the dectobinary() function.

For any other input, I included an else block to display an error message guiding the user to make a valid selection.

Return Value: I ensured main() returns 0 upon successful completion, which is a standard C practice.

2. Implementing binarytodec() (Binary to Decimal Conversion)
I created this function to handle the conversion from a binary representation to its decimal equivalent.

Input:

The function prompts the user: "Type your binary number: ".

I used scanf("%lld", &binary); to read the input. I chose long long for the binary variable to accommodate larger binary numbers that might exceed the capacity of a standard int.

Conversion Logic:

I initialized decimal = 0 and i = 0 (where i is the power of 2).

I implemented a while loop that iterates as long as binary != 0. In each step:

remainder = binary % 10; extracts the rightmost digit of the binary number.

Error Checking: I added a crucial validation: if (remainder != 0 && remainder != 1). If a digit is not 0 or 1, it's an invalid binary number. In this case, an error message is printed, and the function returns.

decimal += remainder * pow(2, i); performs the core conversion. The current binary digit (remainder) is multiplied by 2 raised to the power of its position (i), and the result is added to decimal.

binary /= 10; effectively removes the processed digit.

++i; increments the position for the next digit.

Output: After the loop, the function prints the original binary input and its calculated decimal value.

Required Header: The pow() function requires #include <math.h>, so I added this at the top of the source file.

3. Implementing dectobinary() (Decimal to Binary Conversion)
Next, I developed the dectobinary() function.

Input:

It prompts: "Type your decimal number: ".

scanf("%d", &decimal); reads the integer.

Conversion Logic:

I initialized binary = 0 (as long long to store potentially long binary strings) and i = 1 (as a multiplier to position binary digits correctly).

Edge Case (0): I specifically handled the input 0, directly printing "0 in decimal = 0 in binary".

Negative Input Check: I added a check for negative decimal inputs, as this algorithm is designed for non-negative integers. An error message is shown if a negative number is entered.

For positive decimals, a while loop runs as long as decimal != 0:

remainder = decimal % 2; calculates the binary digit (0 or 1).

decimal /= 2; updates the decimal value for the next iteration.

binary += (long long)remainder * i; constructs the binary number. i acts as a positional multiplier (1, 10, 100,...), placing the remainder in the correct spot. I cast remainder to (long long) to prevent overflow during multiplication.

i *= 10; updates the positional multiplier.

Output: The function displays the original decimal number and its computed binary equivalent.

4. General Code Practices and Refinements
Throughout the development, I focused on:

Clarity: Adding comments where necessary to explain complex parts of the logic.

Data Types: Using appropriate data types (int for smaller numbers or loop counters, long long for numbers that could grow large like binary representations) to ensure correctness and prevent overflow.

User Experience: Providing clear prompts and informative output messages.

Error Handling: Implementing basic checks for invalid inputs to make the program more robust.

That's the complete process of how I built this binary-decimal converter. It should now reliably perform both types of conversions based on what the user selects.