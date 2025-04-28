#include<iostream>
#include<string>
#include<vector>
#include "materials.h"
#include "links.h"

using namespace std;



int main()
{
    links link1;
    materials used_material;

    link1.take_all_inputs();
    link1.calc_all_data();
    link1.optimize_dimensions();

    return 0;
}
