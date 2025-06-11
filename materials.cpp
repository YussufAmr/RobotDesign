
#include "materials.h"



#include "materials.h"
#include<limits>



materials :: materials(){

name = {"Cast iron", "Copper nickel", "Brass", "Aluminum", "Steel", "Acrylic", "Copper", "Stainless steel", "Tungsten" };
yield_strength = {130, 130, 200, 241, 247, 72, 70, 275, 941};
density = {7.3, 8.94, 8.73, 2.7, 7.58, 1.16, 8.92, 7.86, 19.25};

string new_material_name = "";
double new_material_yield_strength = 0;
double new_material_density = 0;
int number_of_material_chosen=0;
double yield_strength_chosen = 0;
double density_chosen = 0;

}

void materials :: handling_invalid_inputs_2()
{
           while(cin.fail())
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

          cout << "Error!Please, enter a valid value: " << endl;

}
}


void materials :: print_table()
{

    cout << "\nMaterial name \t Yield strength (MPa)  density (g/cm^3) \n" ; //alway: to know what is the data given in table and unit
    for(int i=0; i<=8; i++)
    {


if(i==1 || i==7)
{
        cout << i+1 << "- " << name.at(i) << "\t";
        cout <<  yield_strength.at(i) << "   \t\t    ";
}

else{
        cout << i+1 << "- " << name.at(i) << "\t\t";
        cout <<  yield_strength.at(i) << "   \t\t    ";
}
        cout << density.at(i) ;
        cout << endl;

    }
}

void materials ::  add_new_material()
{


    cout << "please, enter the name of the material: " << endl;
    cin >> new_material_name;
    name.push_back(new_material_name);

        cout << "please, enter the yield strength of the material: " << endl;
    cin >> new_material_yield_strength;

            if(cin.fail())
        {
            handling_invalid_inputs_2();
            cin >> new_material_yield_strength;
        }
       else if(new_material_yield_strength <= 0)
       {
                while(new_material_yield_strength<=0)
        {
            cout << "error! Enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> new_material_yield_strength;


        }
       }
    yield_strength.push_back(new_material_yield_strength);
    yield_strength_chosen = new_material_yield_strength;

        cout << "please, enter the density of the material: " << endl;
    cin >> new_material_density;

            if(cin.fail())
        {
            handling_invalid_inputs_2();
            cin >> new_material_density;
        }
       else if(new_material_density <= 0)
       {
                while(new_material_density<=0)
        {
            cout << "error! Enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> new_material_density;


        }
       }

    density.push_back(new_material_density);
    density_chosen = new_material_density;

}

void materials :: select_material()
{

    cout << "\nPlease, enter the number of the material you want to use: " << endl;
    cout << "Enter \"10\" for adding a new material: " << endl;
    cin >> number_of_material_chosen;

            if(cin.fail())
        {
            handling_invalid_inputs_2();
            cin >> number_of_material_chosen;
        }
       else if(number_of_material_chosen <= 0)
       {
                while(number_of_material_chosen<=0)
        {
            cout << "Error! Please Enter a valid number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> number_of_material_chosen;


        }
       }

    if( number_of_material_chosen == 10  )
    {
        add_new_material();
    }



    else if((number_of_material_chosen >= 1) && (number_of_material_chosen<= 9 ))
    {
        yield_strength_chosen = yield_strength.at(number_of_material_chosen-1);
        density_chosen = density.at(number_of_material_chosen -1);
    }
    else
    {
        cout << "Error! please enter a valid number" << endl;
         select_material();
    }

}


double materials :: get_density_chosen()
{
    return density_chosen;
}

double materials :: get_yield_strength_chosen()
{
    return yield_strength_chosen;
}

void materials :: set_density_chosen(double new_density_chosen)
{
    density_chosen = new_density_chosen;
}

void materials :: set_yield_strength_chosen(double new_yield_strength_chosen)
{
    yield_strength_chosen = new_yield_strength_chosen;
}

