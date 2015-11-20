/*
Compile: make fibonacci
Run: ./fibonacci
*/

#include "base.h"


void fibonacci_recursive_test();

void fibonacci_recursive_test();

int fibonacci_recursive(int n);

//Aufgabe a)

void fibonacci_recursive_test(){
    check_expect_i(fibonacci_recursive(0), 0);
    check_expect_i(fibonacci_recursive(1), 1);
    check_expect_i(fibonacci_recursive(2), 1);
	check_expect_i(fibonacci_recursive(3), 2);
	check_expect_i(fibonacci_recursive(4), 3);
	check_expect_i(fibonacci_recursive(5), 5);

}



void fibonacci_iterative_test(){
    check_expect_i(fibonacci_recursive(0), 0);
    check_expect_i(fibonacci_recursive(1), 1);
    check_expect_i(fibonacci_recursive(2), 1);
	check_expect_i(fibonacci_recursive(3), 2);
	check_expect_i(fibonacci_recursive(4), 3);
	check_expect_i(fibonacci_recursive(5), 5);

}

	
//Aufgabe b)

int fibonacci_recursive(int n){ 
	if (n == 0){
		return 0;
	} 
	
	if (n == 1){
			
	return 1;
	
	} 
		
	if (n >= 2){
				
	return fibonacci_recursive (n-1) + fibonacci_recursive (n-2); 
	}
		
			
return 0;	
}


//Aufgabe c

int fibonacci_iterative(int n) {
int k;
for(k==0; k<=n; ++k){
		int w;
		return w = n + k;	
		k + 1;

}
		
return 0;
}

//void timing(void) {
	// d)
//}
/*
d)
i   fib(i)  time_iter [ms]  time_rek [ms]
0...
5...
...
45...
*/

int main(void) {
    fibonacci_recursive_test();
 //   fibonacci_iterative_test();
 //   timing();
 return 0;
}
