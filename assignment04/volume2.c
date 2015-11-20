/*
Compile: make volume
Run: ./volume
*/

#include "base.h"

/*
In einem Programm sollen verschiedene Formen von geometrischen Körpern, nämlich Zylinder, Kugel und Quader, repräsentiert werden. Entwickeln Sie eine Funktion, die diese geometrischen Körper vararbeiten kann (Parametertyp: Shape) und das zugehörige Volumen berechnet.
*/

const double pi = 3.14; // Die Zahl PI welche für die Berechnung des Kreises wichtig ist


enum Volumenversch {
    TVolumenEuclid, // tag for a Volumen in Euclidean coordinates
    TVolumenKugelPolar   // tag for a Volumen in polar coordinates
};

struct VolumenQuarderEuclid {
    double x;
    double y;
	double z;
};

struct VolumenKugelPolar {
    double theta;
    double magnitude;
};

struct Volumen {
    enum Volumenversch tag;                // indicate which variant follows
    union {
		struct VolumenQuarderEuclid euclid; // Euclidean variant
		struct VolumenKugelPolar polar;      // polar variant
    };
};

// constructor for VolumenEuclid
struct Volumen make_Volumen_euclid(double x, double y, double z) {
    struct Volumen p;
    p.tag = TVolumenEuclid;
    p.euclid.x = x;
    p.euclid.y = y;
	p.euclid.z = z;
    return p;
}

// constructor for VolumenPolar
struct Volumen make_Volumen_polar(double t, double m) {
    struct Volumen p;
    p.tag = TVolumenKugelPolar;
    p.polar.theta = t;
    p.polar.magnitude = m;
    return p;
}

// struct Volumen -> double
// Computes the distance from the given Volumen
// to the origin of the coordinate system.
double volume(struct Volumen p);

static void volume_test() {
    // test cases for polar variant
    check_within_d(
        volume(make_Volumen_polar(0.0, 0.0)), 
        0.0, EPSILON);
    check_within_d(
         volume(make_Volumen_polar(0.0, 1.0)), 
        3.14, EPSILON);
    check_within_d(
        volume(make_Volumen_polar(2.3, 2.0)), 
        12.56, EPSILON);

    // test cases for Euclidean variant
    check_within_d(
        volume(make_Volumen_euclid(0.0, -2.0, 2.0)), 
        0.0, EPSILON);
    check_within_d( 
        volume(make_Volumen_euclid(2.0, -2.0, 2.0)), 
        8.0, EPSILON);
    check_within_d( 
        volume(make_Volumen_euclid(1.0, 1.0, 1.0)), 
        1.0, EPSILON); // square root
}

// Computes the distance from the given Volumen
// to the origin of the coordinate system.
double volume(struct Volumen p) {
    if (p.tag==TVolumenEuclid) {
       return p.euclid.x * p.euclid.y * p.euclid.z; 
	}	
	
	if (p.tag==TVolumenKugelPolar){
       return (4/3)*p.polar.magnitude*p.polar.magnitude* pi;
    }
    return 0;
}

int main(void) {
    volume_test();
    return 0;
}
