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
    double PhiKugel;
    double RadiusKugel;
};

struct VolumenZylinderPolar {
    double PhiZylinder;
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
        volume(make_Volumen_euclid(-2.0, 2.0)), 
        8.0, EPSILON);
    check_within_d( 
        volume(make_Volumen_euclid(1.0, 1.0)), 
        1.0, EPSILON); // square root
	
	
	// test für den Zylinder	
	check_within_d(
        volume(make_VolumenZylinder_polare(0.0, 1.0, 2.0)), 
        6.28, EPSILON);
    check_within_d(
         volume(make_VolumenZylinder_polare(0.0, 1.0, 2.0)), 
        6.28, EPSILON);
    check_within_d(
        volume(make_VolumenZylinder_polare(2.0, 2.0, 2.0)), 
        25.12, EPSILON);	
}

// Computes the distance from the given Volumen
// to the origin of the coordinate system.
double volume(struct Volumen p) {
    if (p.tag==TVolumenQuarderEuclid) {
        vol = p.euclid.x * p.euclid.y * p.euclid.z;
		if (vol < 0) {
			return vol * (-1);
		} else {
			return vol;
		}
	}	
	
	if (p.tag==TVolumenKugelPolar){
       return (4/3)*p.polar.RadiusKugel*p.polar.RadiusKugel* pi;
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
