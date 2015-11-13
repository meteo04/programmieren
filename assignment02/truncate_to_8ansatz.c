#include "base.h"
#include "string.h"



// 

//This is the function:
String truncate_to_8(String eingabe) {
    if (s_length(eingabe) <= 8) {//when the string smaller 8, then print the string
        return eingabe;
    } else {//when the string bigger 8, cut the string
        return s_sub(eingabe, 0, 8);
    }
}

void truncate_to_8_test() {// this is the testfunction
    check_expect_s(truncate_to_8("cumulus"), "cumulus");
    check_expect_s(truncate_to_8("cumulusc"), "cumulusc");
    check_expect_s(truncate_to_8("cumuluscumuluscumuluscumulus"), "cumulusc");
}

//im main programm nur die testfkt aufrufen, in der kommandozeile bekommt man als ausgabe das ergebnis
//der tests, also ob truncate_to_8 funktioniert

int main(void) {
    truncate_to_8_test();
    return 0;
}