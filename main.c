#include <stdio.h>
#include <stdlib.h>
#define MAX 40

// Function to read a sentence character by character
void readSentence(char sentence[MAX])
{
    int i=0;
    scanf("%c",&sentence[i]);

    while(sentence[i]!='\n')
    {
        i++;
        scanf("%c",&sentence[i]);
    }
    sentence[i]='\0';
}

// Function to return the length of a string
int stringLength(char sentence[MAX])
{
   int i;

   for(i=0;sentence[i]!='\0';i++);

   return i;
}

// Function to remove spaces from a string
void removeSpaces(char sentence[MAX])
{
    int i,j=0;
    for(i=0;sentence[i]!='\0';i++)
    {
        if(sentence[i]!=' ')
        {
            sentence[j]=sentence[i];
            j++;
        }
    }
    sentence[j]='\0';
    printf("After removing spaces:%s\n",sentence);
}

// Function to reverse a string
void reverseString(char sentence[MAX],char reversed[MAX])
{
    int i;
    int j=stringLength(sentence)-1;

    for(i=0;sentence[i]!='\0';i++)
    {
        reversed[i]=sentence[j];
        j--;
    }
    reversed[i]='\0';
    printf("Reversed string:%s\n",reversed);
}

// Function to check if a string is a palindrome
int isPalindrome(char text[MAX])
{
    char reversed[MAX];
   int length,i;

   removeSpaces(text);

   length=stringLength(text);

   reverseString(text,reversed);

   for(i=0;i<length;i++)
   {
       if(reversed[i]==text[i])
       {
          return 0;
       }
   }
   return 1;
}

int main()
{
    int result;
    char sentence[MAX],reversed[MAX];
    printf("Enter a word or sentence: ");
    readSentence(sentence);

    result=isPalindrome(sentence);
    if(result==1)
    {
        printf("This is a palindrome.");
    }
    else
    {
       printf("This is not a palindrome.");
    }

    return 0;
}
