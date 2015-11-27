/*
Compile: make Gewichtsumrechnung
Run: ./Gewichtsumrechnung
*/
 
#include "base.h"
#include "array.h"
#include "string.h"
#include "string_array.h"

/*
Gegeben ist ein String-Array mit Elementen verschiedenen Gewichts.
Im String-Array ist abwechselnd eine Zahl (als String) und eine Einheit (kg, g oder t) gespeichert. 
Ein Beispiel wäre: ["10", "kg", "500", "g", "0.5", "t"]. 
Ihre Aufgabe besteht darin, das Gesamtgewicht aller Elemente in Kilogramm zu berechnen. 
Beachten Sie dabei, dass Sie zunächst die verschiedenen Gewichte auf Kilogramm umrechnen müssen. 
Gewichte unbekannter Einheit können Sie ignorieren.
*/

/*
A:
Array(String) -> float 
Soll das zusammengesetzte Gewicht aller Massen im array wieder geben.
*/


/*
B:
*/
Array total_weight_kg(String); 

const double epsilon = 0.000000000000001;


/*
D:
Test-Arrays
*/
static void total_weight_kg_test(void) {
    check_within_d(total_weight_kg(sa_of_string("10, kg, 500, g, 0.5, t")), 10 + 0.5 + 500, epsilon); //Vorgegebenes Bsp.
	check_within_d(total_weight_kg(sa_of_string("8000, g, 20, kg, 0.04, t")), 8 + 20 + 40, epsilon); //Bsp:1
	check_within_d(total_weight_kg(sa_of_string("5, t, 0.4, t, 23000, g")), 5000 + 400 + 23, epsilon); //Bsp:2
	check_within_d(total_weight_kg(sa_of_string("500, g, 800, g, 0.9, kg")), 0.5 + 0.8 + 0.9, epsilon); //Bsp:3

}


/*
E:

Schritt 1: Auslesen und Umrechnen.
*/

double make_kg(String mass,String unit){
	if(s_equals(unit, "kg")) {
	return d_of_s(mass);
	}
	if(s_equals(unit, "g")) {
	return d_of_s(mass)/1000;
	}
	if(s_equals(unit, "t")) {
	return d_of_s(mass)*1000;
	}
}


/*
E:
Schritt 2: Elemente im String entnehmen und Elementen zusammenrechnen.
Bemerkung: Noch nicht ganz klar!
*/
double total_weight_kg(Array a) { 
	
	int n = a_length(a);
	double all = 0;
	
	for(int x = 0; x < n; x = x + 2) {
		
	String mass = sa_get (a,x);
		
	String unit = sa_get (a,x + 1);
		
	all = all + make_kg (mass, unit);
	}
	return all;
}



int main(void) {
    total_weight_kg_test();
    return 0;
}
