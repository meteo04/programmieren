/*
Compile: make wages
Run: ./wages
*/
 
#include "base.h"
#include "string.h"

/*
Design a function that cut the String when its longer then 8
*/
 
typedef int s_length; // how long is the string

 
// Cut the String when it ist longer than 8
truncate_to_8;
 


//This is the function:
String truncate_to_8(String eingabe) {
    if (s_length(eingabe) <= 8) {//when the string smaller 8, then print the string
        return eingabe;
    } else {//when the string bigger 8, cut the string
        return s_sub(eingabe, 0, 8);
    }
}

void truncate_to_8_test() {// this is the testfunction
    check_expect_s(truncate_to_8("cumulus"), "cumulus"); //Exampel for String < 8
    check_expect_s(truncate_to_8("cumulusc"), "cumulusc"); //Exampel for String = 8
    check_expect_s(truncate_to_8("cumuluscumuluscumuluscumulus"), "cumulusc"); //Exampel for String > 8
}


int main(void) {
    truncate_to_8_test();
    return 0;
}