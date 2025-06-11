

#ifndef LINKS_H
#define LINKS_H

#include<iostream>
#include<cmath>
#include "materials.h"
#include "motors.h"

using namespace std;

class links{
private:

materials used_material;
motors m1;
const double PI = 22/7.0;
const double g = 9.81;
int type;
double base;
double height;
double radius;
double length;
double payload_mass;
double max_angular_acc;
double required_omega;

double link_mass;
double bending_moment;
double moment_of_inertia;
double max_stress;
int x;
int z;
double percent;
double new_height;
double new_base;
double new_radius;
double new_max_stress;

public:
void handling_invalid_inputs();

links();
void link_cross_section();
void read_remaining_inputs();
void calc_mass_link();
void calc_bending_moment();
void calc_moment_of_inertia();
void calc_max_stress();
void calc_all_data();
void take_all_inputs();
void comparison ();
void dim_print();
void comparison_with_another_percent ();
void dim_print_with_percent();

double get_length() const;
double get_payload_mass() const;
double get_max_angular_acc() const;
double get_link_mass() const;
double get_required_omega() const;

};


#endif // LINKS_H

