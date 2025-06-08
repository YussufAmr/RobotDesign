#include "links.h"
#include "materials.h"


links :: links(){

int type;
double base = 0;
double height = 0;
double radius = 0;
double link_mass = 0;
double pay_load_mass=  0;
double max_angular_acc= 0;

}

void links ::  link_cross_section()
{

    cout << "Please, Select the number of the type of your link cross section area: " << endl;
    cout << "1- Rectangle" << endl;
    cout << "2- Circle" << endl;
    cin >> type;

    if(type == 1)
    {
        cout << "\nEnter the base length: " << endl;
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


void links :: read_remaining_inputs(){
cout << "Enter the length of the link: " << endl;
cin >> length;

cout << "Enter the payload mass: " << endl;
cin >> payload_mass;

cout << "Enter the maximum angular acceleration: " << endl;
cin >> max_angular_acc;


    used_material.print_table();
    used_material.select_material();
}


void links :: take_all_inputs()
{
link_cross_section();
read_remaining_inputs();
}


void links :: calc_mass_link()//calculate mass link
    {
        if(type == 1)
        {
            link_mass = base*height*length*used_material.get_density_chosen();
        }
        else
            link_mass = PI*radius*radius*length*used_material.get_density_chosen();
    }

void links :: calc_bending_moment()//calculate bending moment
    {
        bending_moment = link_mass * g * (length/2) + (payload_mass * g * length) +
        (link_mass * pow(length/2 , 2) * max_angular_acc + payload_mass * pow(length, 2) * max_angular_acc);
    }

void links :: calc_moment_of_inertia()//calculate moment of inertia
    {
        if(type == 1)
        {
            moment_of_inertia = base * pow(height ,3) / 12;
        }
        else
            moment_of_inertia = PI * pow(radius, 4) /4;
    }

void links :: calc_max_stress()//calculate max stress
    {
        if(type == 1)
        {
            max_stress = ( bending_moment * height ) / ( 2 * moment_of_inertia );
        }
        else
            max_stress = ( bending_moment * radius ) / moment_of_inertia;
    }



void links :: comparison ()//checking stress & optimizing dimensions
    {
        while(max_stress > used_material.get_yield_strength_chosen() )
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
            //recalculate
            calc_mass_link();
            calc_bending_moment();
            calc_moment_of_inertia();
            calc_max_stress();

        }
        while(max_stress < used_material.get_yield_strength_chosen() )
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
            //recalculate
            calc_mass_link();
            calc_bending_moment();
            calc_moment_of_inertia();
            calc_max_stress();
        }
        max_stress/=1.01;
    }


void links :: print_all_data()//print all outputs
{
    if(type == 1)
    {
        cout << "Base = " << base << endl;
        cout << "Height = " << height << endl;
        cout << "Link Mass = " << link_mass << endl;
        cout << "The Bending Moment = " << bending_moment << endl;
        cout << "Moment of Inertia = " << moment_of_inertia << endl;
        cout << "Maximum Stress = " << max_stress <<"\n"<< endl;
    }
    else if (type == 2){
    cout << "Radius = " << radius << endl;
    cout << "Link Mass = " << link_mass << endl;
    cout << "The Bending Moment = " << bending_moment << endl;
    cout << "Moment of Inertia = " << moment_of_inertia << endl;
    cout << "Maximum Stress = " << max_stress <<"\n"<<  endl;
    }
}


void links :: calc_all_data()
{
    calc_mass_link();
    calc_bending_moment();
    calc_moment_of_inertia();
    calc_max_stress();

}

void links :: optimize_dimensions()
{
    cout<<"\nBefore Optimization: " << endl;
    print_all_data();
    comparison ();
    cout<<"\nAfter Optimization: " << endl;
    print_all_data();
}
