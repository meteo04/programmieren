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
	c = ia_of_string ("0,2,0");//die erwartete ausgabe waere wohl eher [2, 1, 1]
	check_expect_b(closest (a, b), c); //du solltst wie in der aufgabe steht ia_check_expect benutzen
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
	c = ia_of_string ("0,2,0");//s. o.
	check_expect_b(closest (a, b), c); 
	a_free(a);
	a_free(b);
	a_free(c);
	
		
	a = da_of_string ("0.0,2.0,3.0");
	b = da_of_string ("0.1,2.9,0");
	c = ia_of_string ("0,2,0");//s. o.
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
double y;//du weist y in der funktion nirgends einen wert zu.
int j;//ueberfluessig, wird schon in der for schleife initialisiert
//du solltest noch ein rueckgabe array initialisieren.
//wenn du erstmal von dem ersten element ausgehst (index 0) waere das
//Array indizes=ia_create(n,0)
//also n mal(das rueckgabearray muss genau so lang wie a sein) die 0(also der erste index)

			for (int i = 0; i < n; ++i){
	
					double e = da_get(a,i);
                    //ich vermute hier wolltest du y die differenz zum ersten element aus b zuweisen. Also y=fabs(e-da_get(b,0));
                    
	
						for (int j = 0; j < m; ++j){
		
							double f = da_get(b,j);
		
							double x = e - f;
		
							fabs(x);//den wert solltest du schon zwischenspeichern. fabs gibt den betrag zurueck, aendert aber nichts an x. hier also eher z=fabs(x);
		
		
									if (x<y) {
											x = y;//wohl eher y=x, du moechtest ja die kleinere differenz uebernehmen
                                            //in dem fall muss auch indizes aktualisiert werden(du hast ja einen besseren wert gefunden)
                                            //ia_set(indizes,i,j);
									}else//klammern fehlen
											x = x;//ueberfluessig
									
						}
 
			return ia_create(n,j);//ia_create erstellt einen neuen array, der mit j mal n gefuellt ist. ich glaube nicht, dass du das da wolltest.
                                  //ausserdem sollte de rueckgabe NACH der schleife stattfinden, nicht mittendrin
                                  //die fehlermeldung hast du vermutlich bekommen, weil du hier keine vernuenftige rueckgabe hattest
			}

//stattdessen jetzt indizes zurueckgeben
//return indizes;    
}

int main(void) {
    closest_test();
    return 0;
}
