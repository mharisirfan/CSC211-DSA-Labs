#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TASK1       /// Task 1 is telling whether a C string is a Palindrome or not
#define TASK2       /// Task 2 is finding the GCD

#ifdef TASK1
bool test_palindrome_itr(char * test_word);             /// Given Function
bool test_palindrome_rec(char * test_word, int size);   /// Complete This
#endif // TASK1


#ifdef TASK2

int GCD_rec(int x, int y);  /// Given function
int GCD_itr(int x, int y);  /// Complete this

#endif // TASK2

int main()
{
    #ifdef TASK1
        char my_word[21]; /// This will carry our input string.
        printf("This program tells whether an input word is a Palindrome or not.\n");
        printf("Enter a word (maximum 20 letters): ");
        fgets(my_word, 20,stdin);

        printf("\nIterative Output: ");
        if(test_palindrome_itr(my_word))
            printf("This word is a Palindrom!\n");
        else
            printf("This word is not a Palindrom!\n");

        printf("\nRecursive Output: ");
        if(test_palindrome_rec(my_word, strlen(my_word)-1))
            printf("This word is a Palindrom!\n");
        else
            printf("This word is not a Palindrom!\n");

    #endif // TASK1

    #ifdef TASK2

        int num1, num2, res;

        printf("\nEnter two numbers separated by a space: ");

        scanf("%d %d", &num1, &num2);

        res = GCD_rec(num1, num2);
        printf("\nRecursive Output: GCD of %d and %d = %d", num1, num2, res);

        res = GCD_itr(num1, num2);
        printf("\nRecursive Output: GCD of %d and %d = %d", num1, num2, res);

    #endif // TASK2
    return 0;
}


#ifdef TASK1
bool test_palindrome_itr(char * test_word)
{
    /// Get the length of the string.
    /// 'strlen()' returns total length including the NULL charachter
    int length = strlen(test_word)-1;

    int i;

    for(i = 0; i<=(length/2); i++)
    {
        /// Compare the 1st and the Last letters of the word
        if((*(test_word+i)) != (*(test_word+length-i-1)))
            break;
    }

    i--;    /// 'i' would have been one greater because of the 'i++' in the loop

    return(i==(length/2));
}

bool test_palindrome_rec(char * test_word, int size)
{
    /** Complete this function **/
    /// You may change the prototype of the function to include more arguments.
    return(false);
}
#endif // TASK1

#ifdef TASK2

int GCD_rec(int x, int y)
{

    int rem;

    rem = x%y;

    if(rem==0)
		return y;
	else

    return (GCD_rec(y, rem));
}

int GCD_itr(int x, int y)
{
    /** Complete this function **/
}

#endif
