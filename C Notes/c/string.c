#include<stdio.h>
#include<string.h>
/*
Strings 
 
A string is a group of characters. 
A char array is used to represent a string 
in C. 
 
C allows processing of a char array like 
1) a group of characters 
2) a string. 
 
For processing like a group of characters 
treat it like an array and use loops and
logic within. 
 
For processing like a string we use numerous
features and functions provided by the C libraries.
 
LEARN MORE FORM EXAMPLES AND NOTES AHEAD. 
------------------------------------------------- 
 
 
 */ 

int slen(char s[])
{
    int x = 0;
    while(s[x] != '\0') //A scanned string has '\0' as end marker
        x++;
    
    return x;
}//slen

//recall that an array is passed by reference
void srev(char s[])
{
    int x, y;//2 indices
    char temp; //swapping
    
    x = 0;//left side index
    y = slen(s) -1; //right side index
    
    while(x < y)
    {
        temp = s[x];
        s[x] = s[y];
        s[y] = temp;
        x++;
        y--;
    }
}//srev


void scopy(char trgt[], char src[])
{
    int i;
    for(i =0; src[i] != '\0'; i++)
    {
        trgt[i] = src[i];
    }
    trgt[i] = '\0'; //mark end of trgt string
}//scopy


void scat(char s1[], char s2[])
{
    int x, y;
    
    x = slen(s1);
    y = 0;

    while(s2[y] != '\0')
    {
        s1[x] = s2[y];
        x++;
        y++;
    }
    s1[x] = '\0';
}//scat


int palinCheck(char str[])
{
    int x,y;
    
    x = 0;//left side boundary
    y = slen(str) -1; //right side boundary
    
    while(x < y)
    {
        if(str[x] != str[y])
            return 0; //false
        x++;
        y--;
    }//while
    return 1;//true
}

int scmp(char s1[], char s2[])
{
    int i, res;
    
    i =0 ;
    while(s1[i] != '\0' || s2[i] != '\0')
    {
        res = s1[i] - s2[i];
        if(res != 0)
            return res;//not equal
        i++;
    }//while
    return 0; //equal
}

void toggle(char str[])
{
    int i;
    for(i =0 ; str[i]!= '\0'; i++)
    {
        if(str[i] >=65 && str[i] <= 90)
        {//CAPITAL LETTER
            str[i] = str[i] + 32; //make it small
        }
        else if(str[i] >=97 && str[i] <= 122)
        {//SMALL LETTER
            str[i] = str[i] - 32; //make it capital
        }
    }//for
}

int main()
{
    //string operations
    char name[20];//declare a string
    
    //declare and initalize the string
    char str[20]= "PROGRAM";
    //or
    //char str[20] = {'P','R','O','G','R','A','M'};
    
    //In both case '\0' is auto appended to the string
    int q;

    
    //1) scanning
    printf("\n Enter your name ");
    scanf("%19s", name);//scan a string (char array) without a loop
    //%s to scan a string of unlimited length
    //%19s to scan a string of max 19 characters

    //2) display
    printf("\n HELLO %s", name);//display the string data (char array) without a loop
    
    //3) length
    //q = strlen(name);//ready made function that calculates and returns the length of the string
    //q = slen(name);//our function to calculate and return the length of the string
    //printf("\n Length : %d", q);    
    
    //4) reverse
    //strrev(name);//ready made function to reverse a string
    //srev(name);//our function to reverse a string
    //printf("\n REVERSED %s", name);//display the string data (char array) without a loop
    
    //5) copy
    //strcpy(str, name);//ready made function to copy 2nd param string into 1st param string, even \0 is copied.
    //scopy(str, name);//our function to copy 2nd param string into 1st param string, even \0 is copied.
    //printf("\n COPY : %s ", str);
    
    //6) concatenate 
    //strcat(name, str);//ready made function that concatenates 2nd param string to the 1st param string, 2nd param string is not modified.
    //scat(name, str);//our function to concatenate 2nd param string to the 1st param string, 2nd param string is not modified.
    //printf("\n name : %s ", name);
    //printf("\n str : %s ", str);

    //7) palindrome check
    //q = palinCheck(name);
    //if(q == 1)
    //    printf("\n PLAINDROME");
    //else if(q == 0)
    //    printf("\n NOT A PLAINDROME");
    
    //8) string compare
    //q = strcmp(name, str);//ready made function to compare 2 strings and return negative (smaller)/positive (greater) /zero (equal) result.
    //q = scmp(name, str);//our function to compare 2 strings and return negative (smaller)/positive (greater) /zero (equal) result.
    //if(q > 0)
    //    printf("\n %s is greater ", name);
    //else if(q < 0)
    //    printf("\n %s is greater ", str);
    //else if(q == 0)
    //    printf("\n Both strings are %s ", name);
   
    
    //9) Toggle Case of the string
    //ABcdEf becomes abCDeF
    toggle(name);
    printf("\n Hello %s ", name);
    return 0;
}