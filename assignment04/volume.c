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
    TVolumenQuarderEuclid, // 
    TVolumenKugelPolar,   // 
	TVolumenZylinderPolar // 
};

struct VolumenQuarderEuclid {
    double x;
    double y;
	double z;
};

struct VolumenKugelPolar {
<<<<<<< HEAD
=======
    double PhiKugel;   //man braucht keine winkel um das volumen einer kugel zu berechnen. radius reicht
>>>>>>> 5e86382700d52a129efd68fb5608f88fb2becae2
    double RadiusKugel;
};

struct VolumenZylinderPolar {
<<<<<<< HEAD
=======
    double PhiZylinder;    //siehe kugel
>>>>>>> 5e86382700d52a129efd68fb5608f88fb2becae2
    double RadiusZylinder;
	double HoeheZylinder;
};

struct Volumen {
    enum Volumenversch tag;                // 
    union {
		struct VolumenQuarderEuclid euclid; // Euclidean variant
		struct VolumenKugelPolar polar;      // polar variant
		struct VolumenZylinderPolar polare;
    };
};

// constructor für VolumenQuader
struct Volumen make_VolumenQuarder_euclid(double x, double y, double z) {
    struct Volumen p;
    p.tag = TVolumenQuarderEuclid;
    p.euclid.x = x;
    p.euclid.y = y;
	p.euclid.z = z;
    return p;
}

// constructor für VolumenKugel
struct Volumen make_VolumenKugel_polar(double rku) {
    struct Volumen p;
    p.tag = TVolumenKugelPolar;
    p.polar.RadiusKugel = rku;
    return p;
}

// constructor für VolumenZylinder
struct Volumen make_VolumenZylinder_polare(double r, double h) {
    struct Volumen p;
    p.tag = TVolumenKugelPolar;
    p.polare.RadiusZylinder = r;
	p.polare.HoeheZylinder = h;
    return p;
}


// 
double volume(struct Volumen p);
<<<<<<< HEAD


=======
//die tests für kugel und zylinder werden wahrscheinlich nicht bestanden,
//weil EPSILON=0.0000001(glaub ich, vielleicht eine null mehr oder weniger)
//aber pi ist nur auf zwei nachkommastellen genau in dem programm
//entweder im test explizit mit sachen wie pi*1*1*3 vergleichen, oder pi genauer festlegen
>>>>>>> 5e86382700d52a129efd68fb5608f88fb2becae2
static void volume_test() {
    // test für die Kugel (Radius)
    check_within_d(
        volume(make_VolumenKugel_polar(0.0)), 
        0.0, EPSILON);
    check_within_d(
         volume(make_VolumenKugel_polar(1.0)), 
        3.14, EPSILON);
    check_within_d(
        volume(make_VolumenKugel_polar(2.0)), 
        25.12, EPSILON);

    // test für den Quarder (x, y, z)
    check_within_d(
        volume(make_VolumenQuarder_euclid(0.0, -2.0, 2.0)), 
        0.0, EPSILON);
    check_within_d( 
<<<<<<< HEAD
        volume(make_VolumenQuarder_euclid(2.0, -2.0, 2.0)), 
=======
        volume(make_Volumen_euclid(-2.0, 2.0)), //der quader hat 3 variablen, nicht zwei, daher gibts nen fehler
>>>>>>> 5e86382700d52a129efd68fb5608f88fb2becae2
        8.0, EPSILON);
    check_within_d( 
        volume(make_VolumenQuarder_euclid(1.0, 1.0, 1.0)), 
        1.0, EPSILON); 
	
	
	// test für den Zylinder (Radius, Hoehe)	
	check_within_d(
        volume(make_VolumenZylinder_polare(3.0, 2.0)), 
        56.52, EPSILON);
    check_within_d(
<<<<<<< HEAD
         volume(make_VolumenZylinder_polare(1.0, 2.0)), 
=======
         volume(make_VolumenZylinder_polare(0.0, 1.0, 2.0)), //hier ist ein argument zu viel, wahrscheinlich hast dus verwechselt
>>>>>>> 5e86382700d52a129efd68fb5608f88fb2becae2
        6.28, EPSILON);
    check_within_d(
        volume(make_VolumenZylinder_polare(0.5, 2.0)), 
        1.57, EPSILON);	
}



// Berechnet das Volumen der einzelnen Körper
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
<<<<<<< HEAD
       vol = (4/3)*p.polar.RadiusKugel*p.polar.RadiusKugel*p.polar.RadiusKugel* pi;
	   if (vol < 0){
		   return vol * (-1);
	   } else {
		   return vol;
	   }
=======
       return (4/3)*p.polar.RadiusKugel*p.polar.RadiusKugel* pi; //die formel ist 4/3 pi r^3(nicht 2)
>>>>>>> 5e86382700d52a129efd68fb5608f88fb2becae2
    }
	
	if (p.tag==TVolumenZylinderPolar){
		vol = p.polare.RadiusZylinder * p.polare.RadiusZylinder * p.polare.HoeheZylinder * pi;
		if (vol < 0){
			return vol * (-1);
		} else {
			return vol;
		}
	}
    return 0;
	
	
}

int main(void) {
    volume_test();
    return 0;
}
