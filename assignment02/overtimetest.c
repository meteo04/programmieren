/*
Compile: make wages
Run: ./wages
*/
 
#include "base.h"
 
/*
Design a function that computes weekly wages with overtime from hours worked. The hourly rate is 10 €/hour. Regular working time is 40 hours/week. Overtime is paid 150% of the normal rate of pay.
*/
 
typedef int Hours; // represents hours worked
typedef int Cents; // represents wage in cents
const int waz=40;// wochenarbeitszeit
 
// Hours -> Cents
Cents hours_to_wages(Hours hours);
 
void hours_to_wages_test() {      
    check_expect_i(hours_to_wages(20), 0); // line 21
    check_expect_i(hours_to_wages(40), 0); // line 23
    check_expect_i(hours_to_wages(45), 5);
}
 
// Compute the wage in cents given the number of hours worked.
Cents hours_to_wages(Hours hours) {
    if (hours <= waz) {
        return 0;
    } else {
        return (hours-waz);
    }
}
 
int main(void) {
    hours_to_wages_test();
    return 0;
}
