//Gerard Lawrence
//Program: C++
//This code finds the diameter of a whole pizza

#include <iostream> 
#include <string>
#include <iomanip>

using namespace std;

int main()

{
//declaring variables 
double pizza_diameter, pizza_slices, slice_area, pizza_area, pizza_radius, pi;
    
    pi = 3.14159;
    slice_area = 14.125;

//asks for UI
cout << "What is the diameter of the pizza in inches?: ";
//UI into inches
cin >> pizza_diameter;

//calculates number of slices
pizza_radius = pizza_diameter / 2.0;
pizza_area = pi * (pizza_radius * pizza_radius);
pizza_slices = pizza_area / slice_area;


//displays the number of slices available to fixed point
cout << "the number of slices available are: " << setprecision(2) << fixed << pizza_slices << endl;

return 0;

}

