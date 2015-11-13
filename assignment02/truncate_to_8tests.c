/*
Compile: Bitte einmal angucken ob das so akzeptabel ist. Es macht auch irgendwie keinen sinn String in string umzubenennen.
Run: ./
*/
 
#include "base.h"
#include "string.h"

/*
Design a function that truncates the string lenght to 8 characters 
*/
 
typedef String string; // represents the string

// string lenght <=8 char
string truncate_string_length (string Word); // Word=Variable  

 
void truncate_string_length_test() {
    check_expect_s(truncate_string_length(Hallo), Hallo);//string-lenght<8 char
	check_expect_s(truncate_string_lengthSegelschiff), Segelsch);//string-lenght>8 char
	check_expect_s(truncate_string_length(Nachbarn), Nachbarn);//string-lenght=8 char
    
}
 
/ 
String truncate_string_length(String Word) {
    if (int s_length(Word)<= 8) {
        return Word;
    } else {
        return s_sub(Word,0,8);
    }
}
 
int main(void) {
    truncate_string_length();
    return 0;
}
