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

motors motors () {

double torque = 0;
double rpm = 0 ;
double mass = 0;
double diameter = 0;
double width = 0;
double effeciency = 0;
int adding_choice = 0;

};

vector<double> torques = {1.33, 3.6, 4.12, 4.53, 5.05};
vector<double> rpms = {4980, 2430, 5770, 3400, 5450};
vector<double> masses = {34, 34, 26, 119, 42};
vector<double> diameters = {19, 19, 14, 26, 16};
vector<double> widths = {28.9, 28.9, 35.6, 44.7, 40.4};
vector<double> effecencies = {72, 71, 76, 81, 82};

void print_motors()
{
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
}
void add_motor()
{
    motors new_motor;
    cout << "Enter the torque: " << endl;
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


};




int main()
{

motors m1;
m1.print_motors();


    return 0;
}
