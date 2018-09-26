#include<stdio.h>

/*
 Command Line Arguments
 System allows passing parameters to the 
 main() function of C program.
 
 In such a case 
 1) The signature of main() of C program is 
    to be modified as follows:
        int main(int argc, char *argv[] )
        { ... }
    
 2) The C program has to be build and its
    executable file has to be created. 
 
 3) The C programs executable file has to be 
    executed and parameters are to be passed 
    from DOS/LINUX Shell.
 
 */

int main(int argc, char *argv[])
{
    int i;
    printf("\n COMMAND LINE ARGUMENTS DEMO");
    printf("\n-----------------------------");
    
    printf("\n Number of arguments : %d ", argc);
    
    printf("\n Values of arguments : ");
    for(i =0 ; i< argc; i++)
    {
        printf("\n %s", argv[i]);
    }
    
    return 0;
}
