#include<iostream>
#include<string>
#include<vector>

using namespace std;

class materials{

public:
vector<string> name ;
vector<double> yield_strength ;
vector<double> density ;

string new_material_name;
double new_material_yield_strength;
double new_material_density;

int number_of_material_chosen;
double yield_strength_chosen;
double density_chosen;

materials(){

    string new_material_name = "";
double new_material_yield_strength = 0;
double new_material_density = 0;

int number_of_material_chosen;
double yield_strength_chosen = 0;
double density_chosen = 0;

};

materials(double density_chosen2,double yield_strength_chosen2)
{
  density_chosen2 = density_chosen;
  yield_strength_chosen2 = yield_strength_chosen;
};

void print_table()
{
    for(int i=0; i<=8; i++)
    {
vector<string> name = {"Cast iron", "Copper nickel", "Brass", "Aluminum", "Steel", "Acrylic", "Copper", "Stainless steel", "Tungesten" };
vector<double> yield_strength = {130, 130, 200, 241, 247, 72, 70, 275, 941};
vector<double> density = {7.3, 8.94, 8.73, 2.7, 7.58, 1.16, 8.92, 7.86, 19.25};

if(i==1 || i==7)
{
        cout << i+1 << "- " << name.at(i) << "\t";
        cout <<  yield_strength.at(i) << "\t\t";
}

else{
        cout << i+1 << "- " << name.at(i) << "\t\t";
        cout <<  yield_strength.at(i) << "\t\t";
}
        cout << density.at(i) ;
        cout << endl;

    }
}

void add_new_material()
{
    cout << "please, enter the name of the material: " << endl;
    cin >> new_material_name;
    name.push_back(new_material_name);

        cout << "please, enter the yield strength of the material: " << endl;
    cin >> new_material_yield_strength;
    yield_strength.push_back(new_material_yield_strength);
    yield_strength_chosen = new_material_yield_strength;

        cout << "please, enter the density of the material: " << endl;
    cin >> new_material_density;
    density.push_back(new_material_density);
    density_chosen = new_material_density;

}

void select_material()
{
    cout << "Please, enter the number of the material you want to use: " << endl;
    cout << "Enter \"11\" for adding a new material: " << endl;
    cin >> number_of_material_chosen;

    if( number_of_material_chosen == 11  )
    {
        add_new_material();
    }

    else if((number_of_material_chosen >= 0) && (number_of_material_chosen<= 8))
    {
        yield_strength_chosen = (number_of_material_chosen);
        density_chosen = (number_of_material_chosen);
    }
    else
    {
        cout << "Error, please enter a valid number" << endl;
         select_material();
    }

}


};

class links{
public:

materials material_chosen;
const double PI = 22/7.0;
int type;
double base;
double height;
double radius;
double length;
double mass_of_link;
double pay_load_mass;
double max_angular_acc;

links(){

int type;
double base = 0;
double height = 0;
double radius = 0;
double mass_of_link = 0;
double pay_load_mass=  0;
double max_angular_acc= 0;

};

void link_cross_section()
{

    cout << "Please, Select the number of the type of your link cross section area: " << endl;
    cout << "1- Rectangle" << endl;
    cout << "2- Circle" << endl;
    cin >> type;

    if(type == 1)
    {
        cout << "Enter the base length: " << endl;
        cin >> base;
        cout << "Enter the height length: " << endl;
        cin >> height;

    }
    else if(type == 2)
    {
        cout << "Enter the radius length: " << endl;
        cin >> radius;
    }
    else
    {
        cout << "Error!Please, enter a valid number: " << endl;
        link_cross_section();
    }

}

void read_remaining_inputs(){
cout << "Enter the length of the link: " << endl;
cin >> length;

cout << "Enter the payload mass: " << endl;
cin >> pay_load_mass;

cout << "Enter the maximum angular acceleration: " << endl;
cin >> max_angular_acc;


    material_chosen.print_table();
    material_chosen.select_material();
    materials(material_chosen.density_chosen, material_chosen.yield_strength_chosen);
}




void calc_mass_link()
{


    if(type == 1)
    {
        mass_of_link = base*height*length*material_chosen.density_chosen;
    }
    else
        mass_of_link = PI*radius*radius*length*material_chosen.density_chosen;

    cout << "The mass of link = " << mass_of_link << endl;

}



};

int main()
{
links link1;
materials material_chosen;

link1.link_cross_section();
link1.read_remaining_inputs();
link1.calc_mass_link();


    return 0;
}
