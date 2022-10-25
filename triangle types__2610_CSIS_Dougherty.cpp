//this program will identify if 3 numbers correspond to the side length criteria of an equilateral triangle, an isosceles triangle, a right
//triangle or none of the above
//this program was written by Amber Dougherty for CSIS 2616 Assignment 2
#include <iostream>

using namespace std;

int main()
{
    double sideA, sideB, sideC;

    cout << "This program will identify if 3 given numbers correspond with the side lengths of three different types of triangles. \n";
    cout << "It will identify whether or not it would be an equilateral triangle, an isosceles triangle, or a right triangle. \n";
    cout << "This program was written by Amber Dougherty for CSIS Assignment 2. \n";
    cout << "   \n";

    //input the values for the side lengths
    cout << "Please input a value for the first side length. Then hit ENTER. \n";
    cin >> sideA;
    cout << " \n";

    cout << "Please input a value for the second side length. Then hit ENTER. \n";
    cin >> sideB;
    cout << " \n";

    cout << "Please input a value for the third side length. Then hit ENTER. \n";
    cin >> sideC;
    cout << " \n";

    if (sideA == sideB && sideB == sideC)
    {
        cout << "This is an equilateral triangle. \n";
    }
    else if (sideA == sideB && sideA != sideC && sideB != sideC || sideA == sideC && sideA != sideB && sideC != sideB || sideB == sideC && sideB != sideA)
    {
        cout << "This is an isosceles triangle. \n";
    }
    else if (sideC > sideA && sideC > sideB && sideA*sideA + sideB*sideB == sideC*sideC || sideB > sideA && sideB > sideC && sideA*sideA + sideC*sideC == sideB*sideB || sideA > sideB && sideA > sideC && sideB*sideB + sideC*sideC == sideA*sideA)
    {
        cout << "This is a right triangle. \n";
    }
    else
    {
        cout << "This is not an equilateral, isosceles, or a right triangle. \n";
        cout << "It is none of the above. \n";
    }



    return 0;
}
