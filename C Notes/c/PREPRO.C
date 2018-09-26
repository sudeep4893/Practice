#include<stdio.h>
#define PI 3.14
#define GRTR(A,B) (A>B)?A:B

/*
preprocessors

#, when used as first letter
of a statement, represents the
preprocessor.

C provides a set of preprocessor
directives (commands).
All are executed at program compile time.

#include : This directive tells
the system to include all the
code of the specified header file 
into the current C program.

#define : This directive is used
to define a "macro".
A macro is a token replacement mechanism.
  
At program compile time all the
occurrences of the macro (macro calls) 
are substituted by the macro definition.

#undef : to undefine a macro

#ifdef : to check if a macro is defined.
#if : to compare value of a macro
#elif : an else if to #if
#else : an else to #if or #ifdef or #elif
#endif : an end to #if or #ifdef

*/
int main()
{
    float r, a;
    int q ;
    printf("\n enter value of q ");
    scanf("%d", &q);
    
    r = GRTR(q, 10);
    //defn of GRTR is substituted against macro call
    //r = (q>10)?q:10
    printf("\n PI is %f ", PI);
//#undef PI

#ifdef PI
//compile this code only when PI is defined    
    //#if PI < 3.14
    //    printf("\n PI < 3.14");
    //#elif PI > 3.14    
    //    printf("\n PI > 3.14");
    //#else    
        
        a = PI * r *r;
        printf("\n Area : %f", a);
    //#endif
#else
    //compile this code only when PI is not defined    
    printf("\n SORRY PI IS NOT AVAILABLE FOR USE");
    
#endif    
    return 0;

}
/*
	Explain difference between a
	fn and a macro?

	Macro calls are resolved at
	prg compile time
	Fn calls are resolved at prg
	run time.

	Macro call is substituted by
	macro definition (inline expansion)
	Fn call transfers prg ctrl to
	the fns defn and after complete
	exeution of fns code the prg
	ctrl returns to the line following
	the call.

	Tip: For smaller defn define
	macros and for larger set of
	instructions defn fns.

	Macros cannot be recursive.
	Fns can be recursive.

	Macro parameters have no specific
	datatype.
	Function parameters have specific
	datatype.
*/