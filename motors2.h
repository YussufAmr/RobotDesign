
#include<iostream>
#include<vector>
using namespace std;

class motors{
private:

double torque;
double rpm;
double mass;
double diameter;
double width;
double effeciency;
int adding_choice;
double gear_ratio;
double max_gear_eff;
double gear_mass;
double gear_diameter;
double gear_width;
int gear_adding_choice;


vector<double> torques;
vector<double> rpms;
vector<double> masses;
vector<double> diameters ;
vector<double> widths;
vector<double> effecencies;

vector<double> gear_ratios;
vector<double> max_gear_effs;
vector<double> gear_masses;
vector<double> gear_diameters;
vector<double> gear_widths;


public:

motors();


void  print_motors();
void  add_motor();
void  print_gears();
void  add_gear();




};


