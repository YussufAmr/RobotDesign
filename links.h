#ifndef LINKS_H
#define LINKS_H

#include<iostream>
#include<cmath>
#include "materials.h"

using namespace std;

class links{
private:

materials used_material;
const double PI = 22/7.0;
const double g = 9.81;
int type;
double base;
double height;
double radius;
double length;
double payload_mass;
double max_angular_acc;

double link_mass;
double bending_moment;
double moment_of_inertia;
double max_stress;

double required_torque;

public:
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
void print_all_data();
void optimize_dimensions();
};


#endif // LINKS_H
