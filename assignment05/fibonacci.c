/*
Compile: make fibonacci
Run: ./fibonacci
*/

#include "base.h"



int Number;

static void fibonacci_recursive_test();

int Fibonaccinumber fibonacci_recursive(int Number n);

//Aufgabe a)

static void fibonacci_recursive_test(){
    check_expect_i(fibonacci_recursiv(0), 0);
    check_expect_i(fibonacci_recursiv(1), 1);
    check_expect_i(fibonacci_recursiv(2), 1);
	check_expect_i(fibonacci_recursiv(3), 2);
	check_expect_i(fibonacci_recursiv(4), 3);
	check_expect_i(fibonacci_recursiv(5), 5);

}





	
//Aufgabe b)

int Fibonaccinumber fibonacci_recursive(int Number n){ 
	if (n == 0){
		return 0;
	} else { 
	
		if (n == 1){
			
				return 1;
	
		} else {
		
				if (n>= 2){
				
					return (n - 1) - (n - 2); 
				}
		}
		
		
	}
}




//int fibonacci_iterative(int n) {
	// c)
//	return 0;
//}

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
    fibonacci_recursive_testh();
 //   fibonacci_iterative_test();
 //   timing();
 return 0;
}
