
#include "links.h"


int main()
{
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

    return 0;
}
