
#ifndef MOTORS_H
#define MOTORS_H


#include<iostream>
#include<vector>
using namespace std;


class links;


class motors{
private:

const double g = 9.81;

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


vector<vector<vector<double>>> comb;

double torque_required;
double omega_motor;
double torque_output;
double omega_output;
double omega_required;

vector<double> omega;


double total_masses;
double total_width;
double total_diameter;

double cost;
double best_cost;
int opt_motor;
int opt_gear;
int valid_combinations;

public:

motors();


void  print_motors();
void  add_motor();
void  print_gears();
void  add_gear();
void  handling_invalid_inputs_types_3();

void  print_combinations(const vector<vector<vector<double>>>& comb);
void  calc_required_torque(const links& link1);
void  print_required_torque();

void  initialize_combinations(const links& link1);


void mass_optimization (const vector<vector<vector<double>>>& comb);
void cost_optimization (const vector<vector<vector<double>>>& comb);
void optimization_selection();

vector<vector<vector<double>>> get_comb();
void set_omega_required(double new_omega_required);
};

#endif // MOTORS_H
