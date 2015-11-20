/*
Compile: make fibonacci
Run: ./fibonacci
*/

#include "base.h"



int nummber;

int fibonacci_recursive_test()

int fibonacci_recursiv(int nummber) 

//Aufgabe a)

fibonacci_recursive_test{
    check_expect_fibonacci(fibonacci_recursiv(0), 0);
    check_expect_fibonacci(fibonacci_recursiv(1), 1);
    check_expect_fibonacci(fibonacci_recursiv(2), 1);
	check_expect_fibonacci(fibonacci_recursiv(3), 2);
	check_expect_fibonacci(fibonacci_recursiv(4), 3);
	check_expect_fibonacci(fibonacci_recursiv(5), 5);
}





	
//Aufgabe b)

int fibonacci_recursive (int nummber){ 
	if (nummber = 0){
		return 0;
	} else { 
	
		if (nummber = 1){
			
				return 1;
	
		} else {
		
				if (nummber >= 2){
				
					return (nummber - 1) - (nummber - 2); 
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
    fibonacci_recursive_test();
 //   fibonacci_iterative_test();
 //   timing();
 return 0;
}
