/*
Compile: make volume
Run: ./volume
*/

#include "base.h"

/*
In einem Programm sollen verschiedene Formen von geometrischen Körpern, nämlich Zylinder, Kugel und Quader, repräsentiert werden. Entwickeln Sie eine Funktion, die diese geometrischen Körper vararbeiten kann (Parametertyp: Shape) und das zugehörige Volumen berechnet.
*/

const double pi = 3.14; // Die Zahl PI welche für die Berechnung des Kreises wichtig ist

double vol; // hilfsvariable, wenn das volumen negativ

enum Volumenversch {
    TVolumenQuarderEuclid, // tag for a Volumen in Euclidean coordinates
    TVolumenKugelPolar,   // tag for a Volumen in polar coordinates
	TVolumenZylinderPolar // 
};

struct VolumenQuarderEuclid {
    double x;
    double y;
	double z;
};

struct VolumenKugelPolar {
    double PhiKugel;   //man braucht keine winkel um das volumen einer kugel zu berechnen. radius reicht
    double RadiusKugel;
};

struct VolumenZylinderPolar {
    double PhiZylinder;    //siehe kugel
    double RadiusZylinder;
	double HoeheZylinder;
};

struct Volumen {
    enum Volumenversch tag;                // indicate which variant follows
    union {
		struct VolumenQuarderEuclid euclid; // Euclidean variant
		struct VolumenKugelPolar polar;      // polar variant
		struct VolumenZylinderPolar polare;
    };
};

// constructor for VolumenEuclid
struct Volumen make_Volumen_euclid(double x, double y, double z) {
    struct Volumen p;
    p.tag = TVolumenQuarderEuclid;
    p.euclid.x = x;
    p.euclid.y = y;
	p.euclid.z = z;
    return p;
}

// constructor for VolumenPolar
struct Volumen make_VolumenKugel_polar(double rku) {
    struct Volumen p;
    p.tag = TVolumenKugelPolar;
    p.polar.RadiusKugel = rku;
    return p;
}

// constructor for VolumenPolar
struct Volumen make_VolumenZylinder_polare(double rzy, double hzy) {
    struct Volumen p;
    p.tag = TVolumenKugelPolar;
    p.polare.RadiusZylinder = rzy;
	p.polare.HoeheZylinder = hzy;
    return p;
}


// struct Volumen -> double
// Computes the distance from the given Volumen
// to the origin of the coordinate system.
double volume(struct Volumen p);
//die tests für kugel und zylinder werden wahrscheinlich nicht bestanden,
//weil EPSILON=0.0000001(glaub ich, vielleicht eine null mehr oder weniger)
//aber pi ist nur auf zwei nachkommastellen genau in dem programm
//entweder im test explizit mit sachen wie pi*1*1*3 vergleichen, oder pi genauer festlegen
static void volume_test() {
    // test cases for polar variant
    check_within_d(
        volume(make_VolumenKugel_polar(0.0)), 
        0.0, EPSILON);
    check_within_d(
         volume(make_VolumenKugel_polar(1.0)), 
        3.14, EPSILON);
    check_within_d(
        volume(make_VolumenKugel_polar(2.0)), 
        12.56, EPSILON);

    // test cases for Euclidean variant
    check_within_d(
        volume(make_Volumen_euclid(-2.0, 2.0)), 
        0.0, EPSILON);
    check_within_d( 
        volume(make_Volumen_euclid(-2.0, 2.0)), //der quader hat 3 variablen, nicht zwei, daher gibts nen fehler
        8.0, EPSILON);
    check_within_d( 
        volume(make_Volumen_euclid(1.0, 1.0)), 
        1.0, EPSILON); // square root
	
	
	// test für den Zylinder	
	check_within_d(
        volume(make_VolumenZylinder_polare(0.0, 1.0, 2.0)), 
        6.28, EPSILON);
    check_within_d(
         volume(make_VolumenZylinder_polare(0.0, 1.0, 2.0)), //hier ist ein argument zu viel, wahrscheinlich hast dus verwechselt
        6.28, EPSILON);
    check_within_d(
        volume(make_VolumenZylinder_polare(2.0, 2.0, 2.0)), 
        25.12, EPSILON);	
}

// Computes the distance from the given Volumen
// to the origin of the coordinate system.
double volume(struct Volumen p) {
    if (p.tag==TVolumenQuarderEuclid) {
        vol = p.euclid.x * p.euclid.y * p.euclid.z;//bin mir nicht sicher, ob es nicht double vol sein muss(hast die variable vorher initialisiert, kann also auch sein, dass es klappt, kenn die syntax da nicht genau)
		if (vol < 0) {
			return vol * (-1);
		} else {
			return vol;
		}
	}	
	//für quader berücksichtigst du negative volumina, bei den anderen beiden aber nicht, das sollte man konsistent machen (man könnte es auch bei allen weglassen, haben wir zumindest so)
	if (p.tag==TVolumenKugelPolar){
       return (4/3)*p.polar.RadiusKugel*p.polar.RadiusKugel* pi; //die formel ist 4/3 pi r^3(nicht 2)
    }
	
	if (p.tag==TVolumenZylinderPolar){
		return p.polare.RadiusZylinder * p.polare.RadiusZylinder * pi * p.polare.HoeheZylinder;
	}
    return 0;
	
	
}

int main(void) {
    volume_test();
    return 0;
}
