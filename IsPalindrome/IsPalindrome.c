#include <stdio.h>

typedef enum boolean
{
    FALSE,
    TRUE
} BOOL;

BOOL isPalindrome(int num);

int main()
{
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    
    isPalindrome(num) ? printf("The number is a palindrome!\n") : 
                        printf("The number IS NOT a palindrome.\n");
    return 0;
}

BOOL isPalindrome(int num)
{
    int copy = num;
    int reverse = 0;
    
    while(num)
    {
        reverse = 10 * reverse + (num % 10);
        num /= 10;
    }
    
    return copy == reverse ? TRUE : FALSE;
}

