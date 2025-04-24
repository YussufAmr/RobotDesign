
#ifndef MATERIALS_H
#define MATERIALS_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;



class materials{

private:
vector<string> name ;
vector<double> yield_strength ;
vector<double> density ;

string new_material_name;
double new_material_yield_strength;
double new_material_density;

int number_of_material_chosen;
double yield_strength_chosen;
double density_chosen;


public:

materials();
//void initialize_table_materials();
void print_table();
void add_new_material();
void select_material();
double get_density_chosen();
double get_yield_strength_chosen();
void set_density_chosen(double new_density_chosen);
void set_yield_strength_chosen(double new_yield_strength_chosen);

};



#endif // MATERIALS_H
