
#include<iostream>
#include "links.h"
#include "materials.h"
#include "motors.h"
#include<limits>
#include <cmath>


void links :: handling_invalid_inputs_types()
{
           while(cin.fail())
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

          cout << "Error!Please, enter a valid value: " << endl;

}
}

void links ::  link_cross_section()
{

    cout<<"\nPlease, Select the number of the type of your link cross section area: " << endl;
    cout << "1- Rectangle" << endl;
    cout << "2- Circle" << endl;
    cin >> type;

    if(cin.fail())
    {
        handling_invalid_inputs_types();
        link_cross_section();
    }
    else if (type != 1 && type != 2)
    {
        cout << "Error!Please, enter a valid number: " << endl;
        link_cross_section();
    }

    else if(type == 1)
    {
        cout << "Enter the base length: (in mm)" << endl;
        cin >> base;

        if(cin.fail())
        {
            handling_invalid_inputs_types();
            cin >> base;
        }
       else if(base <= 0)
       {
                while(base<=0)
        {
            cout << "error! Enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> base;


        }
       }

        cout << "Enter the height length: (in mm)" << endl;

        cin >> height;

        if(cin.fail())
        {
            handling_invalid_inputs_types();
            cin >> height;
        }
       else if(height <= 0)
       {
                while(height<=0)
        {
            cout << "error! Enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> height;


        }
       }

    }
    else if(type == 2)
    {
        cout << "Enter the radius length: (in mm)" << endl;
        cin >> radius;

                if(cin.fail())
        {
            handling_invalid_inputs_types();
            cin >> radius;
        }
       else if(radius <= 0)
       {
                while(radius<=0)
        {
            cout << "error! Enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> radius;
        }
       }
    }
}


void links :: read_remaining_inputs()
{
cout << "Enter the length of the link: (in mm)" << endl;
cin >> length;

        if(cin.fail())
        {
            handling_invalid_inputs_types();
            cin >> length;
        }
       else if(length <= 0)
       {
                while(length<=0)
        {
            cout << "error! Enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> length;
        }
       }

cout << "Enter the payload mass: (in gram)" << endl;
cin >> payload_mass;

        if(cin.fail())
        {
            handling_invalid_inputs_types();
            cin >> payload_mass;
        }
       else if(payload_mass <= 0)
       {
                while(payload_mass<=0)
        {
            cout << "error! Enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> payload_mass;
        }
       }

cout << "Enter the maximum angular acceleration: (in rad/s^2)" << endl;
cin >> max_angular_acc;

        if(cin.fail())
        {
            handling_invalid_inputs_types();
            cin >> max_angular_acc;
        }
       else if(max_angular_acc <= 0)
       {
                while(max_angular_acc<=0)
        {
            cout << "error! Enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> max_angular_acc;
        }
       }

cout << "Enter the required angular velocity: (in rad/s)" << endl;
cin >> required_omega;

        if(cin.fail())
        {
            handling_invalid_inputs_types();
            cin >> required_omega;
        }
       else if(required_omega <= 0)
       {
                while(required_omega<=0)
        {
            cout << "error! Enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> required_omega;


        }
       }

    used_material.print_table();
    used_material.select_material();
}

void links :: calc_mass_link()
    {
        if(type == 1)
        {
            link_mass = (base/1000)*(height/1000)*(length/1000)*(used_material.get_density_chosen()*1000);
        }
        else
            link_mass = PI*pow(radius/1000,2)*(length/1000)*(used_material.get_density_chosen()*1000);
    }

void links :: calc_bending_moment()
    {
        bending_moment = link_mass * g * (length/2000) + ((payload_mass/1000) * g * length/1000) +
        (((link_mass * pow(length/2000 , 2)) * max_angular_acc) + (payload_mass/1000 * pow(length/1000, 2) * max_angular_acc));
    }

void links :: calc_moment_of_inertia()
    {
        if(type == 1)
        {
            moment_of_inertia = (base/1000) * pow(height/1000 ,3) / 12;
        }
        else
            moment_of_inertia = PI * pow(radius/1000, 4) /4;
    }

void links :: calc_max_stress()
    {
        if(type == 1)
        {
            max_stress = ( bending_moment * (height/1000) ) / (( 2 * moment_of_inertia )*(pow(10,6)));
        }
        else
            max_stress = ( bending_moment * (radius/1000) ) / (moment_of_inertia*(pow(10,6)));
    }

void links :: comparison ()//checking stress & optimizing dimensions
    {
        if(max_stress > used_material.get_yield_strength_chosen())
          {
            x=1;
            while(max_stress > used_material.get_yield_strength_chosen())
            {
                if (type==1)//rectangle
                {
                    height*=1.01;//increasing base and height by one percentage
                    base*=1.01;
                }
                else//circle
                {
                    radius*=1.01;//increasing radius by one percentage
                }
                calc_mass_link();//recalculate
                calc_bending_moment();
                calc_moment_of_inertia();
                calc_max_stress();
            }

            cout<<"\nThe applied stress was greater than the yield strength of the material\nso,"<<
             "we modified the dimensions to make the applied stress less than\nthe yield strength by 1%\nThe new dimension:\n";
            dim_print();
            return;
          }

        if(max_stress < used_material.get_yield_strength_chosen())
        {
            new_height=height;
            new_base=base;
            new_radius=radius;
            x=2;
            new_max_stress=max_stress;
            while(max_stress < used_material.get_yield_strength_chosen())

            {
                if (type==1)//rectangle
                {
                    height/=1.01;//decreasing base and height by one percentage
                    base/=1.01;
                }
                else//circle
                {
                    radius/=1.01;//decreasing radius by one percentage
                }
                calc_mass_link();//recalculate
                calc_bending_moment();
                calc_moment_of_inertia();
                calc_max_stress();
            }
            if (type==1)//rectangle
                {
                    height*=1.01;//increasing base and height by one percentage
                    base*=1.01;
                }
                else//circle
                {
                    radius*=1.01;//increasing radius by one percentage
                }
                calc_mass_link();//recalculate
                calc_bending_moment();
                calc_moment_of_inertia();
                calc_max_stress();
                cout<<"\nWe decreased dimension by 1% in iteration\nThe new dimension:"<<endl;
                dim_print();
        }

    }
void links :: comparison_with_another_percent ()//checking stress & optimizing dimensions
    {
        if(x==2)
        {
            cout<<"\nIf you to accept percent Enter 0 \nIf you want to change percent Enter 1 "<<endl;
            cin>>z;
                    if(cin.fail())
        {
            handling_invalid_inputs_types();
            cin >> z;
        }
        else if(z != 1 && z!= 0 )
        {
            while(z!=1 && z!= 0)
            {
                cout << "error! Please Enter a valid input: 0 or 1" << endl;
                cin >> z;
            }
        }

       }
        if(z==1)
        {
            cout <<"Enter percent in %"<<endl;
            cin>>percent;

                    if(cin.fail())
        {
            handling_invalid_inputs_types();
            cin >> percent;
        }

       else if(percent <= 0)
       {
                while(percent<=0)
        {
            cout << "error! Enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> percent;
        }
       }
        }


        if(z==1)
        {
            percent/=100;
            cout<<"\nWe increased dimension by "<<(percent*100)<<"% in iteration\nThe new dimension:"<<endl;
            while(new_max_stress < used_material.get_yield_strength_chosen() /*||z==1*/ )

            {
                if (type==1)//rectangle
                {
                    height=new_height/(1.0+percent);//decreasing base and height by user percent percentage
                    new_height=height;
                    base=new_base/(1.0+percent);
                    new_base=base;
                }
                else//circle
                {
                    radius=new_radius/(1.0+percent);//decreasing radius by user percent percentage
                    new_radius=radius;
                }
                calc_mass_link();//recalculate
                calc_bending_moment();
                calc_moment_of_inertia();
                calc_max_stress();
                new_max_stress=max_stress;


            }
            if (type==1)//rectangle
                {
                    height*=(1.0+percent);//increasing base and height by one percentage
                    base*=(1.0+percent);
                }
                else//circle
                {
                    radius*=(1.0+percent);//increasing radius by one percentage
                }
                calc_mass_link();//recalculate
                calc_bending_moment();
                calc_moment_of_inertia();
                calc_max_stress();

        }
    }
void links :: dim_print()//print all outputs
{
    if(type == 1)
    {
        cout << "\nbase = " << base << " mm" << endl;
        cout << "height = " << height <<" mm" <<  endl;
        cout << "Link Mass = " << link_mass*1000 <<" gram" <<  endl;
        cout << "The Bending Moment = " << bending_moment <<" N.m" <<  endl;
        cout << "Moment of Inertia = " << moment_of_inertia*pow(10,12) << " mm^4" << endl;
        cout << "Maximum Stress = " << max_stress <<" MPa" <<  endl;
    }
    else
    {
        cout << "\nradius = " << radius <<" mm" <<  endl;
        cout << "Link Mass = " << link_mass*1000 <<" gram" <<  endl;
        cout << "The Bending Moment = " << bending_moment <<" N.m" <<  endl;
        cout << "Moment of Inertia = " << moment_of_inertia*pow(10,12) <<" mm^4" <<  endl;
        cout << "Maximum Stress = " << max_stress <<" MPa" <<  endl;
    }
}
void links :: dim_print_with_percent()//print all outputs with user percent
{
    if(z==1)
    {
        if(type == 1)
        {
            cout << "\nbase = " << base << " mm" << endl;
            cout << "height = " << height <<" mm" <<  endl;
            cout << "Link Mass = " << link_mass*1000 <<" gram" <<  endl;
            cout << "The Bending Moment = " << bending_moment <<" N.m" <<  endl;
            cout << "Moment of Inertia = " << moment_of_inertia*pow(10,12) << " mm^4" << endl;
            cout << "Maximum Stress = " << max_stress <<" MPa" <<  endl;
        }
        else
        {
            cout << "\nradius = " << radius <<" mm" <<  endl;
            cout << "Link Mass = " << link_mass*1000 <<" gram" <<  endl;
            cout << "The Bending Moment = " << bending_moment <<" N.m" <<  endl;
            cout << "Moment of Inertia = " << moment_of_inertia*pow(10,12) <<" mm^4" <<  endl;
            cout << "Maximum Stress = " << max_stress <<" MPa" <<  endl;
        }
    }
}

void links :: calc_all_data()
{
    calc_mass_link();
    calc_bending_moment();
    calc_moment_of_inertia();
    calc_max_stress();
    cout<<"\nBy using the given dimensions:"<<endl;
    dim_print();
    comparison ();
    comparison_with_another_percent ();
    dim_print_with_percent();
}


void links :: take_all_inputs()
{
link_cross_section();
read_remaining_inputs();
}
void links :: project()
{
    int x;
    do
    {
    cout << "\t\t --Welcome to Single-Link Robot Design and Optimization Program--\n"<<endl;
    links link1;
    materials used_materials;
    motors m1;

    link1.take_all_inputs();
    link1.calc_all_data();

    m1.print_motors();
    m1.calc_required_torque(link1);
    m1.print_required_torque();
    m1.initialize_combinations(link1);
    m1.print_combinations(m1.get_comb());
    m1.optimization_selection();
    cout<<"\n\nIf you want to make another trial, press 1 if not press any other number\n"<<endl;
    cin>>x;
            if(cin.fail())
        {
            handling_invalid_inputs_types();
            cin >> x;
        }
       else if(x <= 0)
       {
                while(x<=0)
        {
            cout << "error! Enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> x;


        }
       }
    }
    while (x==1);
}


double links :: get_length() const
{
    return length;
}

double links :: get_max_angular_acc() const
{
    return max_angular_acc;
}


double links :: get_payload_mass() const
{
    return payload_mass;
}


double links :: get_link_mass() const
{
    return link_mass;
}
double links :: get_required_omega() const
{
    return required_omega;
}

