#include <stdio.h>

/* CSC 373 Spring 2019 -- Lytinen
   Homework 4:  Restricted C 

   This is a (hopefully) short programming assignment,
   intended to get you used to aspects of the programming style
   of assembly language.  It will be graded on a scale 
   of 0-10.  There are 5 problems, worth 2 points each.
   
   In this homework, your job is to rewrite each of the 5
   functions below, but only using a limited form of C.
   The limitations are:

   1.  Array syntax [ ] is not allowed   
   2.  You may not use the keywords "for", "while", or "do".
       Instead, you will use "goto" (see below)
   3.  The body of an "if" statement must consist of only a 
       single "goto" statement
   4.  No "else" statements are allowed
   5.  You may not use the modulus operator %.  All other arithmetic
       operators are allowed.
 
   Use of the assignment operator is permitted.
   Use of bitwise and shift operators is encouraged.
   
   ----------------
   
   goto statements
   
   Many of you have probably never used a goto statement,
   although it is part of the C language.  The syntax is:
   
   goto <label>;
   
   Statements in C may be labeled.  The label is an identifier
   followed by a ":", preceding the statememnt. 
   For example:
   
   L1:  x = 0;
   
   Below is an example of a function which is written to conform
   to these specifications.
   
int factorial(int x) {
  int answer = 1;
  int i = 2;
 L1: if (i > x) goto L2;
  answer *= i;
  i += 1;
  goto L1;
 L2:  return answer;

---------------------

*/
// Problem 1.
// reverse the order of the integers in x

void reverse(int x[], int len) {
	int *begin=x;
	int *end=x+len-1;
	int temp;
	L1: if(begin>end) goto L2;
	temp=*begin;
	*begin=*end;
	*end=temp;
	begin+=1;
	end-=1;
	goto L1;
	L2: return;
}

// Problem 2.
// return the maximum integer in x
int max(int x[], int len) { 
  int answer;
  L1: answer=*x;
  goto L4;
  L3: if(answer<*x) goto L1;
  L4: x+=1;
  len-=1;
  if(len>0) 
  goto L3;
  L2: return answer;
  }

// Problem 3.
// emulate string library's strcpy function
void strcpy373(char dest[], char src[]) { 
	L1: if(*src=='\0') goto L2;
	*dest=*src;
	dest+=1;
	src+=1;
	goto L1;
	L2: return;
}
// Problem 4.
// return the number of odd numbers in x
int count_odds(int x[ ], int len) { 
  int answer = 0;
  L1: if((*x&1)==1) answer+=1;
  x+=1;
  len-=1;
  L2: if(len>0) goto L1;
  return answer;
}

// Problem 5.
// compute x to the y power
int power(int x, int y) {
    int answer = 1;
    int i=0;
	L1: if(i>=y) goto L2;
    answer*=x;
    i+=1;
    goto L1;
    L2: return answer;
}


