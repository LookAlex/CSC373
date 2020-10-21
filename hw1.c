/* CSC 373 Winter 2020 Prof Lytinen
   Homework 1 due as specified on D2L
*/
#include <stdio.h>
#include <math.h>

//1
void scan_ints(int *x, int *y) {
	scanf("%d %d", x, y);
}

void print_ints(int x, int y) {
	printf("%d %d", x, y);
}

//2
int pow_xy(int *xptr, int y) {
	*xptr=pow(*xptr,y);
	return *xptr;
}

//3
void convert_temp(int degree, char scale, int *other_degree, char *other_scale) {
	//check scale being passeed in
	//if celcius convert the degree passed in and store it in the other degree and sotre the changed scale in other scale 
	//C to F (10x9/5)+32=50F
	//F to C (32-32)X5/9=0C
	int m;
	if(scale=='C'){
		m=(degree* 9/5)+32;
		*other_degree=m;
		*other_scale='F';
	}
	else {
		m=(degree-32)*5/9;
		*other_degree=m;
		*other_scale='C';
	}
}

//4
int init_array(int array[ ], int len, int start_value) {
	int k; 
	for(k=0;k<len;k++){
		array[k]=start_value*k;
	}
	return k;
}

//5
void reverse_numbers(int nums[], int len) {
	int a, p, temp; 
	p=len-1;
	while(a<p){
		temp=nums[a];
		nums[a]=nums[p];
		nums[p]=temp;
		a++;
		p--;
	}
}
