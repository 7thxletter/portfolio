// Name: Gerard Lawrence
// Program: C++
// The purpose of this code is to create a "Geometry Calculator" that will calculate the area of a cirle, triangle, and rectangle. Once it is finished, it will then quit.
// This code took a few weeks to work on because of schedule
// Due Date: 10/18/2018
// 10/8/2018 Rev A. Wrote out the outline; the directive and variables
// 10/8/2018 Rev B. Figured out the output in order for user to input their choices
// 10/10/2018 Rev C. Worked on output structure; making the sentences look neat
// 10/19/2018 Rev D. Finalized code

#include <iostream>
using namespace std;

int main()
{
    int choice;
    double radius, length, width, height, base, area, pi = 3.14;
    
    //Display input for user
    cout << "Geometry Calculator" << endl;
    cout << "1. Calculate the area of a Circle" << endl;
    cout << "2. Calculate the area of a Rectangle" << endl;
    cout << "3. Calculate the area of a Triangle" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): " << endl;
    cin >> choice;
    
    // Display area of shape
    switch (choice)
    {
        case 1: // Area of a circle
            cout << "Enter the circle's radius: " << endl;
            cin >> radius;
            
                if (radius < 0)
                    cout << "The radius can not be less than zero." << endl;
                else
                {
                    area = pi * radius * radius;
                    cout << "The area is " << area << endl;
                }
        break;
            
        case 2: // Area of a rectangle
            cout << "Enter the rectangle's length: " << endl;
            cin >> length;
            cout << "Enter the rectangle's width: " << endl;
            cin >> width;
            
                if (length < 0 || width < 0)
                    cout << "Only enter positive values for length and width." << endl;
                else
                {
                    area = length * width;
                    cout << "The area is " << area << endl;
                }
        break;
            
        case 3: // Area of a triangle
            cout << "Enter the length of the base: " << endl;
            cin >> base;
            cout << "Enter the triangle's height: " << endl;
            cin >> height;
            
                if (base < 0 || height < 0)
                    cout << "Positive values only for base and height." << endl;
                else
                {
                    area = base * height * 0.5;
                    cout << "The area is " << area << endl;
                }
        break;
            
        case 4:
            cout << "Have a nice day!" << endl;
        break;
            
        default:
            cout << "Please enter 1,2,3, or 4." << endl;
    }
    return 0;
}
