#include <iostream>
#include "motors.h"
#include "links.h"
#include<limits>

using namespace std;



motors :: motors()
    {
    double torque = 0;
    double rpm = 0 ;
    double mass = 0;
    double diameter = 0;
    double width = 0;
    double effeciency = 0;
    int adding_choice = 0;
    int x=0;


 torques = {1.33, 3.6, 4.12, 4.53, 5.05, 5.09, 5.45, 6, 6.31, 6.9};
 rpms = {4980, 2430, 5770, 3400, 5450, 4590, 3530, 4510, 3550, 7380};
 masses = {34, 34, 26, 119, 42, 119, 26, 54, 54, 54};
 diameters = {19, 19, 14, 26, 16, 26, 16, 22, 22, 22};
 widths = {28.9, 28.9, 35.6, 44.7, 40.4, 44.7, 26.5, 31.9, 31.9, 31.9};
 effecencies = {0.72, 0.71, 0.76, 0.81, 0.82, 0.81, 0.76, 0.81, 0.81, 0.73};

    double gear_ratio=0;
    double max_gear_eff=0;
    double gear_mass=0;
    double gear_diameter=0;
    double gear_width=0;
    int gear_adding_choice=0;

gear_ratios = {6,6.4,7,9.1,10, 12, 13, 15, 18, 22};
max_gear_effs = {0.81,0.81,0.87,0.81,0.81, 0.81, 0.73, 0.73, 0.73, 0.73};
gear_masses = {55,6,113,14,55, 9, 7, 40, 60, 10};
gear_diameters = {38,12,45,16,38, 16, 12, 30, 38, 16};
gear_widths = {20.6,10,24.2,14.3,20.6, 11.8, 12, 23, 23.1, 12.8};

}


void motors :: handling_invalid_inputs_types_3()
{
           while(cin.fail())
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

          cout << "Error!Please, enter a valid value: " << endl;

}
}
void motors :: print_motors()
    {
        cout<<"\nLIST OF MOTORS"<<endl;
        cout << "M.No." << "\t" << "Torques(mN.m)\t" << "rpms\t" << "masses(g)\t" << "diameters(mm)\t" << "widths(mm)\t" << "effecencies" << endl;
        for(int i =0; i<torques.size(); i++)
        {
            cout << i+1 << "-\t" << torques.at(i) << "\t\t";
            cout << rpms.at(i) << "\t";
            cout << masses.at(i) << "\t\t";
            cout << diameters.at(i) << "\t\t";
            cout << widths.at(i) << "\t\t";
            cout << effecencies.at(i) << endl;

        }
            cout << endl;
            cout << endl;

            cout << "These are our list of available motors, if you want to add another motor, enter: 1, if not, enter: 0" << endl;
            cin >> adding_choice;

            if(adding_choice == 1)
                add_motor();

                                       else  if(cin.fail())
        {
            handling_invalid_inputs_types_3();
            cin >> adding_choice;
        }
       else if(adding_choice != 0 && adding_choice != 1)
       {
                while(adding_choice<0)
        {
            cout << "error! Enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> adding_choice;


        }
       }
       else if(adding_choice == 0)
        print_gears();
    }

void motors :: add_motor()
    {
        motors new_motor;
        cout << "Please enter new motor specifications\nEnter the torque mN.m: " << endl;
        cin >> new_motor.torque;

                    if(cin.fail())
        {
            handling_invalid_inputs_types_3();
            cin >> new_motor.torque;
        }
       else if(new_motor.torque <= 0)
       {
                while(new_motor.torque<=0)
        {
            cout << "error! Enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> new_motor.torque;


        }
       }
        torques.push_back(new_motor.torque);

        cout << "Enter the rpm: " << endl;
        cin >> new_motor.rpm;

                            if(cin.fail())
        {
            handling_invalid_inputs_types_3();
            cin >> new_motor.rpm;
        }
       else if(new_motor.rpm <= 0)
       {
                while(new_motor.rpm<=0)
        {
            cout << "error! Enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> new_motor.rpm;


        }
       }

        rpms.push_back(new_motor.rpm);

        cout << "Enter the mass in g: " << endl;
        cin >> new_motor.mass;

                            if(cin.fail())
        {
            handling_invalid_inputs_types_3();
            cin >> new_motor.mass;
        }
       else if(new_motor.mass <= 0)
       {
                while(new_motor.mass<=0)
        {
            cout << "error! Enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> new_motor.mass;


        }
       }

        masses.push_back(new_motor.mass);

        cout << "Enter the diameter in mm: " << endl;
        cin >> new_motor.diameter;

                            if(cin.fail())
        {
            handling_invalid_inputs_types_3();
            cin >> new_motor.diameter;
        }
       else if(new_motor.diameter <= 0)
       {
                while(new_motor.diameter<=0)
        {
            cout << "error! Enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> new_motor.diameter;


        }
       }

        diameters.push_back(new_motor.diameter);

        cout << "Enter the width in mm: " << endl;
        cin >> new_motor.width;

                            if(cin.fail())
        {
            handling_invalid_inputs_types_3();
            cin >> new_motor.width;
        }
       else if(new_motor.width <= 0)
       {
                while(new_motor.width<=0)
        {
            cout << "error! Enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> new_motor.width;


        }
       }

        widths.push_back(new_motor.width);

        cout << "Enter the effeciency: " << endl;
        cin >> new_motor.effeciency;

                            if(cin.fail())
        {
            handling_invalid_inputs_types_3();
            cin >> new_motor.effeciency;
        }
       else if(new_motor.effeciency <= 0)
       {
                while(new_motor.effeciency<=0)
        {
            cout << "error! Enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> new_motor.effeciency;


        }
       }

        effecencies.push_back(new_motor.effeciency);

        print_motors();
    }

void motors :: print_gears()
    {
        cout<<"\nLIST OF GEARBOXES"<<endl;
        cout << "G.No." << "\t" << "Gear ratio\t" << "Max eff.\t" << "mass(g)\t" << "diameter(mm)\t" << "width(mm) "<< endl;
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
                                if(cin.fail())
        {
            handling_invalid_inputs_types_3();
            cin >> gear_adding_choice;
        }
       else if(gear_adding_choice < 0)
       {
                while(gear_adding_choice<0)
        {
            cout << "error! Enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> gear_adding_choice;


        }
       }

            if(gear_adding_choice == 1)
                add_gear();

    }


void motors :: add_gear()
    {

        motors new_gear;
        cout << "Please enter new gearbox specifications\nEnter gear ratio: " << endl;
        cin >> new_gear.gear_ratio;

                                    if(cin.fail())
        {
            handling_invalid_inputs_types_3();
            cin >> new_gear.gear_ratio;
        }
       else if(new_gear.gear_ratio <= 0)
       {
                while(new_gear.gear_ratio<=0)
        {
            cout << "error! Enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> new_gear.gear_ratio;


        }
       }

        gear_ratios.push_back(new_gear.gear_ratio);

        cout << "Enter the maximium gearbox efficiency: " << endl;
        cin >> new_gear.max_gear_eff;

                                            if(cin.fail())
        {
            handling_invalid_inputs_types_3();
            cin >> new_gear.max_gear_eff;
        }
       else if(new_gear.max_gear_eff <= 0)
       {
                while(new_gear.max_gear_eff<=0)
        {
            cout << "error! Enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> new_gear.max_gear_eff;


        }
       }

        max_gear_effs.push_back(new_gear.max_gear_eff);

        cout << "Enter the gearbox mass in grams: " << endl;
        cin >> new_gear.gear_mass;

                                            if(cin.fail())
        {
            handling_invalid_inputs_types_3();
            cin >> new_gear.gear_mass;
        }
       else if(new_gear.gear_mass <= 0)
       {
                while(new_gear.gear_mass<=0)
        {
            cout << "error! Enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> new_gear.gear_mass;


        }
       }

        gear_masses.push_back(new_gear.gear_mass);

        cout << "Enter the gearbox diameter in mm: " << endl;
        cin >> new_gear.gear_diameter;

                                            if(cin.fail())
        {
            handling_invalid_inputs_types_3();
            cin >> new_gear.gear_diameter;
        }
       else if(new_gear.gear_diameter <= 0)
       {
                while(new_gear.gear_diameter<=0)
        {
            cout << "error! Enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> new_gear.gear_diameter;


        }
       }

        gear_diameters.push_back(new_gear.gear_diameter);

        cout << "Enter the gearbox width in mm: " << endl;
        cin >> new_gear.gear_width;

                                            if(cin.fail())
        {
            handling_invalid_inputs_types_3();
            cin >> new_gear.gear_width;
        }
       else if(new_gear.gear_width <= 0)
       {
                while(new_gear.gear_width<=0)
        {
            cout << "error! Enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> new_gear.gear_width;


        }
       }

        gear_widths.push_back(new_gear.gear_width);

        print_gears();
    }


void motors :: calc_required_torque(const links& link1)
{
    double link_mass = link1.get_link_mass();
    double payload_mass = link1.get_payload_mass();
    double length = link1.get_length();
    double max_acc = link1.get_max_angular_acc();

    torque_required =

        (link_mass * g * (length / 2000)) +
        ((payload_mass/1000) * g * (length / 1000)) +
        (link_mass * pow((length / 2000), 2) * max_acc) +
        ((payload_mass/1000) * pow((length / 1000), 2) * max_acc);

}

void motors :: print_required_torque()
{
    cout << "The Calculated Required Torque = " << torque_required << "\n" << endl;
}





void motors :: initialize_combinations(const links& link1)
{
    comb = vector<vector<vector<double>>> (torques.size(), vector<vector<double>>(gear_ratios.size()));

    cout << "The Required Angular Velocity = " << link1.get_required_omega() << "\n" <<endl;

    cout << "     ------------------ Checking valid combinations process  ------------------ \n"<< endl;


    valid_combinations = 0;

    for (int i = 0; i < torques.size(); i++) {
        for (int j = 0; j < gear_ratios.size(); j++) {
            omega_motor = (2 * 3.14 * rpms[i]) / 60.0;
            torque_output = torques[i] * gear_ratios[j] * max_gear_effs[j] /1000.0;
            omega_output = omega_motor / gear_ratios[j];



            if( torque_output>= torque_required && omega_output >= link1.get_required_omega()){


                total_masses = masses [i] + gear_masses [j];
                total_diameter = diameters [i] + gear_diameters [j];
                total_width = widths [i] + gear_widths [j];

                comb[i][j].push_back(torque_output);                                              // [0]
                comb[i][j].push_back(omega_output);                                               // [1]
                comb[i][j].push_back(i);                                                          // [2] motor index
                comb[i][j].push_back(total_masses);                                               // [3]
                comb[i][j].push_back(total_diameter);                                             // [4]
                comb[i][j].push_back(total_width);                                                // [5]
                comb[i][j].push_back(j);                                                          // [6] gear index
                comb[i][j].push_back(total_masses + (total_diameter /100) + (total_width /100));  // [7]

                valid_combinations++;
                cout << "Valid combination found: Motor " << i+1 << " with Gear " << j+1 << endl;

            }


        }
    }

    if(valid_combinations == 0) {

        cout << "No combinations meet the requirements, Consider:" << endl;
        cout << "1. Lowering the required angular velocity" << endl;
        cout << "2. Adding motors with higher RPM" << endl;
        cout << "3. Adding gearboxes with lower gear ratios" << endl;

    } else {
        cout << "\nTotal valid combinations found: " << valid_combinations << endl;
        cout << "\n   ------------------------------------------------------ \n"<< endl;
    }
}


void motors :: print_combinations(const vector<vector<vector<double>>>& comb)
{
    int printed_count = 0;

    for (int i = 0; i < comb.size(); i++) {
        for (int j = 0; j < comb[i].size(); j++) {
            if(!comb[i][j].empty()) {

                cout << "Motor " << i+1 << ", Gear " << j+1 << ":\n";
                cout << "  Output Torque: " << comb[i][j][0] << " N.m\n";
                cout << "  Output Omega: " << comb[i][j][1] << " rad/s\n";
                cout << "  Motor Index: " << (comb[i][j][2])+1 << "\n";
                cout << "  Combination Mass: " << comb[i][j][3] << " g\n";
                cout << "  Combination Diameter: " << comb[i][j][4] << " mm\n";
                cout << "  Combination Width: " << comb[i][j][5] << " mm\n";
                cout << "  Gear Index: " << (comb[i][j][6])+1 << "\n";
                cout << "  cost : " << comb[i][j][7] << " $\n";

                cout << "----------------------------------\n";

                printed_count++;
            }
        }
    }

    if (printed_count == 0) {
        cout << "\nNo valid combinations to display." << endl;
    } else {
        cout << "\nTotal combinations displayed: " << printed_count << endl;

    }
}

void motors :: mass_optimization (const vector<vector<vector<double>>>& comb)
{

    best_cost = INT_MAX;

     for (int i = 0; i < torques.size(); i++) {
            for (int j = 0; j < gear_ratios.size(); j++)
                {
                     if(!comb[i][j].empty())
                     {
                      cost = comb [i][j][3] ;
                     if (cost <= best_cost ) {  best_cost = cost ; opt_motor = i ;  opt_gear = j  ;}
                     }
                }
     }
}

void motors :: cost_optimization (const vector<vector<vector<double>>>& comb)
{

    best_cost= INT_MAX;

    for (int i = 0; i < torques.size(); i++)
        {
            for (int j = 0; j < gear_ratios.size(); j++)
            {
                 if(!comb[i][j].empty())
                 {
                    cost = comb [i][j][3] + (comb [i][j][4] /100) + (comb [i][j][5] /100);
                 if (cost <= best_cost ) {  best_cost = cost ;    opt_motor = i  ;  opt_gear = j  ;}
                 }
            }
        }

}

void motors :: optimization_selection()
{
    if(valid_combinations == 0 || valid_combinations == 1)
    {
        return;
    }
    int choice;
    cout << "\t \t \t OPTIMIZATION \n Enter \" 1 \" to optimize based on mass \n Enter \" 2 \" to optimize based on cost \n \t";
    cin >> choice ;
    if (choice == 1 ) {
            mass_optimization ( comb);
            cout << "combination of least mass = " << best_cost <<" g"<<endl;
            cout << "Motor " << opt_motor+1 << ", Gear " << opt_gear+1 << ":\n";
            cout << "  Output Torque: " << comb[opt_motor][opt_gear][0] << " N.m\n";
            cout << "  Output Omega: " << comb[opt_motor][opt_gear][1] << " rad/s\n";
            cout << "  Motor Index: " << (comb[opt_motor][opt_gear][2])+1 << "\n";
            cout << "  Combination Mass: " << comb[opt_motor][opt_gear][3] << " g\n";
            cout << "  Combination Diameter: " << comb[opt_motor][opt_gear][4] << " mm\n";
            cout << "  Combination Width: " << comb[opt_motor][opt_gear][5] << " mm\n";
            cout << "  Gear Index: " << (comb[opt_motor][opt_gear][6])+1 << "\n";
            cout << "  cost : " << comb[opt_motor][opt_gear][7] << " $"<<"\n";
    }
     if (choice == 2 ) {
            cost_optimization (comb);
            cout << "combination of least cost = " <<  best_cost <<" $"<<endl;
            cout << "Motor " << opt_motor+1 << ", Gear " << opt_gear+1 << ":\n";
            cout << "  Output Torque: " << comb[opt_motor][opt_gear][0] << " N.m\n";
            cout << "  Output Omega: " << comb[opt_motor][opt_gear][1] << " rad/s\n";
            cout << "  Motor Index: " << (comb[opt_motor][opt_gear][2])+1 << "\n";
            cout << "  Combination Mass: " << comb[opt_motor][opt_gear][3] << " g\n";
            cout << "  Combination Diameter: " << comb[opt_motor][opt_gear][4] << " mm\n";
            cout << "  Combination Width: " << comb[opt_motor][opt_gear][5] << " mm\n";
            cout << "  Gear Index: " << (comb[opt_motor][opt_gear][6])+1 << "\n";
            cout << "  cost : " << comb[opt_motor][opt_gear][7] <<" $"<< "\n";
    }
}



vector<vector<vector<double>>> motors :: get_comb()
{
    return comb;
}

