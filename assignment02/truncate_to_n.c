/*
Compile: make wages
Run: ./wages
*/
 
#include "base.h"
#include "string.h"

/*
Design a function that computes weekly wages with overtime from hours worked. The hourly rate is 10 €/hour. Regular working time is 40 hours/week. Overtime is paid 150% of the normal rate of pay.
*/
 
typedef int n; // this is the variable about the length from string
typedef int s_length; // how long is the string
 
 const int n = 14 // it defines how long must be the string
 
 
 
// cut the String when it longer then n
truncate_to_n;
 
void truncate_to_8_test() {// this is the testfunction
    check_expect_s(truncate_to_n("cumulus"), "cumulus"); //Exampel for String < n ,  with n = 14
    check_expect_s(truncate_to_n("cumuluscumulus"), "cumuluscumulus"); //Exampel for String = n ,  with n = 14
    check_expect_s(truncate_to_n("cumuluscumuluscumuluscumulus"), "cumuluscumulus"); //Exampel for String > n, with n = 14
 
// Compute the wage in cents given the number of hours worked.
//This is the function:
String truncate_to_n(string input) {
    if (s_length(input) <= n) {//when the string smaller n, then print the string
        return input;
    } else {//when the string bigger n, cut the string
        return s_sub(input, 0, n);
    }
}


int main(void) {
    truncate_to_8_test();
    return 0;
}
int main(void) {
    hours_to_wages_test();
    return 0;
}
