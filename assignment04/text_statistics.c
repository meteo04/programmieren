/*
Compile: make text_statistics
Run: ./text_statistics
*/

#include "base.h"
#include "string.h"

/*
Entwickeln Sie eine Funktion zur Erstellung einer Text-Statistik. Eingabe der Funktion ist ein String beliebiger Länge. Ausgabe ist eine statistische Zusammenfassung des Strings, die folgende Komponenten enthält: Anzahl Zeichen insgesamt (inkl. Whitespace), Anzahl Buchstaben, Anzahl Wörter, Anzahl Sätze, Anzahl Zeilen. Whitespace (Leerraum) ist definiert als die Menge der Steuerzeichen Leerzeichen (' '), Tabulator ('\t'), Zeilenvorschub ('\n') und Wagenrücklauf ('\r'). Die Menge der im Eingabetext erlaubten Zeichen sind diejenigen mit einem ASCII-Code zwischen 32 (Leerzeichen) und 126 (Tilde) sowie Whitespace (also insbesondere sind keine Umlaute erlaubt). 
*/
/* idee von eduard 
für jedes '\n' -> neue zeile
für jedes '.' -> neuer satz
für jedes ' ' -> neues wort
für jedes zeichen im string muss man die anzahl der jeweiligen charactere
zählen. iteriere also über den string
*/
double text_statistics(String);

static void text_statistics_test() {
 
}

double text_statistics(struct Point p) {
    return 0
}

int main(void) {
    text_statistics_test();
    return 0;
}
