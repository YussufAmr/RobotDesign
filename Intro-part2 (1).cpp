#include <iostream>
#include<vector>
using namespace std;



class motors{
public:

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

motors Motor()
    {
    double torque = 0;
    double rpm = 0 ;
    double mass = 0;
    double diameter = 0;
    double width = 0;
    double effeciency = 0;
    int adding_choice = 0;
    };

motors Gearbox()
    {
    double gear_ratio=0;
    double max_gear_eff=0;
    double gear_mass=0;
    double gear_diameter=0;
    double gear_width=0;
    int gear_adding_choice=0;
    };

vector<double> torques = {1.33, 3.6, 4.12, 4.53, 5.05};
vector<double> rpms = {4980, 2430, 5770, 3400, 5450};
vector<double> masses = {34, 34, 26, 119, 42};
vector<double> diameters = {19, 19, 14, 26, 16};
vector<double> widths = {28.9, 28.9, 35.6, 44.7, 40.4};
vector<double> effecencies = {0.72, 0.71, 0.76, 0.81, 0.82};

vector<double> gear_ratios = {6,6.4,7,9.1,10};
vector<double> max_gear_effs = {0.81,0.81,0.87,0.81,0.81};
vector<double> gear_masses = {55,6,113,14,55};
vector<double> gear_diameters = {38,12,45,16,38};
vector<double> gear_widths = {20.6,10,24.2,14.3,20.6};

void print_motors()
    {
        cout<<"\nLIST OF MOTORS"<<endl;
        cout << "M.No." << "\t" << "Torques\t" << "rpms\t" << "masses\t" << "diameters\t" << "widths\t" << "effecencies" << endl;
        for(int i =0; i<torques.size(); i++)
        {
            cout << i+1 << "-\t" << torques.at(i) << "\t";
            cout << rpms.at(i) << "\t";
            cout << masses.at(i) << "\t";
            cout << diameters.at(i) << "\t\t";
            cout << widths.at(i) << "\t";
            cout << effecencies.at(i) << endl;

        }
            cout << endl;
            cout << endl;

            cout << "These are our list of available motors, if you want to add another motor, enter: 1, if not, enter: 0" << endl;
            cin >> adding_choice;

            if(adding_choice == 1)
                add_motor();
            else
                print_gears();
    }

void add_motor()
    {
        motors new_motor;
        cout << "Please enter new motor specifications\nEnter the torque: " << endl;
        cin >> new_motor.torque;
        torques.push_back(new_motor.torque);

        cout << "Enter the rpm: " << endl;
        cin >> new_motor.rpm;
        rpms.push_back(new_motor.rpm);

        cout << "Enter the mass: " << endl;
        cin >> new_motor.mass;
        masses.push_back(new_motor.mass);

        cout << "Enter the diameter: " << endl;
        cin >> new_motor.diameter;
        diameters.push_back(new_motor.diameter);

        cout << "Enter the width: " << endl;
        cin >> new_motor.width;
        widths.push_back(new_motor.width);

        cout << "Enter the effeciency: " << endl;
        cin >> new_motor.effeciency;
        effecencies.push_back(new_motor.effeciency);

        print_motors();
    }

void print_gears()
    {
        cout<<"\nLIST OF GEARBOXES"<<endl;
        cout << "G.No." << "\t" << "Gear ratio\t" << "Max eff.\t" << "mass\t" << "diameter\t" << "width "<< endl;
        for(int i =0; i<gear_ratios.size(); i++)
        {
            cout << i+1 << "-\t" << gear_ratios.at(i) << "\t\t";
            cout << max_gear_effs.at(i) << "\t\t";
            cout << gear_masses.at(i) << "\t";
            cout << gear_diameters.at(i) << "\t\t";
            cout << gear_widths.at(i) << endl;

        }
            cout << endl;
            cout << endl;

            cout << "These are our list of available gearboxes, if you want to add another gearbox, enter: 1, if not, enter: 0" << endl;
            cin >> gear_adding_choice;

            if(gear_adding_choice == 1)
                add_gear();

    }

void add_gear()
    {

        motors new_gear;
        cout << "Please enter new gearbox specifications\nEnter gear ratio: " << endl;
        cin >> new_gear.gear_ratio;
        gear_ratios.push_back(new_gear.gear_ratio);

        cout << "Enter the maximium gearbox efficiency: " << endl;
        cin >> new_gear.max_gear_eff;
        max_gear_effs.push_back(new_gear.max_gear_eff);

        cout << "Enter the gearbox mass: " << endl;
        cin >> new_gear.gear_mass;
        gear_masses.push_back(new_gear.gear_mass);

        cout << "Enter the gearbox diameter: " << endl;
        cin >> new_gear.gear_diameter;
        gear_diameters.push_back(new_gear.gear_diameter);

        cout << "Enter the gearbox width: " << endl;
        cin >> new_gear.gear_width;
        gear_widths.push_back(new_gear.gear_width);

        print_gears();
    }
};




int main()
{

motors m1;
m1.print_motors();


    return 0;
}
