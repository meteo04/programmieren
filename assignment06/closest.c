/*
Compile: make closest
Run: ./closest
*/

// http://hci.uni-hannover.de/files/prog1lib/index.html
#include "base.h"
#include "array.h"
#include "int_array.h"
#include "double_array.h"

/*
Gegeben sind zwei Arrays a und b mit Elementen vom Typ double. Für jedes Element von a berechnet die Funktion den Index des ähnlichsten Elements in b. Ähnlichkeit ist hier definiert als kleinste absolute Differenz. Die Funktion gibt ein Array der entsprechenden Indizes zurück.
*/



//Aufgabe a

/*
 zwei double, Arrays --> int, Array																				
*/



//Aufgabe b

/*
Diese Funktion vergleich die einzelnen Einträge der Arrays miteinander. Dabei wird die Ähnlichkeit der Einträge verglichen und 
die Position der ähnlichen Einträge als neues Array ausgegeben.
*/


//Aufgabe c


Array closest(Array a, Array b);



//Aufgabe d


static void closest_test(void) {
	Array a,b,c ;
	
	a = da_of_string ("0.0,2.0,3.0");
	b = da_of_string ("0.1,2.9,0");
	c = ia_of_string ("0,2,0");
	check_expect_b(closest (a, b), c); 
	a_free(a);
	a_free(b);
	a_free(c);
	
	
	a = da_of_string ("1.5,2.8,0.0");
	b = da_of_string ("0.1,2.9,0.8");
	c = ia_of_string ("2,1,0");
	check_expect_b(closest (a,b),  c); 
	a_free(a);
	a_free(b);
	a_free(c);
	
	
	a = da_of_string ("0.0,2.0,3.0");
	b = da_of_string ("0.1,2.9,0");
	c = ia_of_string ("0,2,0");
	check_expect_b(closest (a, b), c); 
	a_free(a);
	a_free(b);
	a_free(c);
	
		
	a = da_of_string ("0.0,2.0,3.0");
	b = da_of_string ("0.1,2.9,0");
	c = ia_of_string ("0,2,0");
	check_expect_b(closest (a, b), c); 
	a_free(a);
	a_free(b);
	a_free(c);
	
	}

double fabs(double x) {
    return (x >= 0) ? x : -x;
}



//Aufgabe e



Array closest(Array a, Array b) { 

int n = a_length(a);
int m = a_length(b);
double y;
int j;



			for (int i = 0; i < n; ++i){
	
					double e = da_get(a,i);
	
						for (int j = 0; j < m; ++j){
		
							double f = da_get(b,j);
		
							double x = e - f;
		
							fabs(x);
		
		
									if (x<y) {
											x = y;
									}else
											x = x;
									
						}
 
			return ia_create(n,j);	
			}


}

int main(void) {
    closest_test();
    return 0;
}
