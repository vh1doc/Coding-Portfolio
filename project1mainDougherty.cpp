//For Data Structures
//Written by Amber Dougherty

#include <iostream>
#include "NumberList.h"

using namespace std;

int main()
{
    NumberList empId;
    NumberList hours;
    NumberList wages;


    //Main menu setup
    //This'll run after each function until the user chooses 4
    double searchID;
    int choice;

    int Idnum;
    int hournum;
    double payrate;

    do
    {
        cout<< "\nWhat would you like to do? you can: \n";
        cout<< " 1. Insert a new employee\n 2. Search for an employee\n 3. Delete an employee\n 4. Nothing, I want to quit.\n";
        cin>> choice;

        switch (choice)
        {
        case 1:


            cout<< "\nTo insert a new employee, please insert their employee ID first: \n";
            cin>> Idnum;

            cout<< "\nHow many hours they worked?: \n";
            cin>> hournum;

            cout<< "\nAnd what is their pay rate?: \n";
            cin>> payrate;

             empId.appendNode(Idnum);
             hours.appendNode(hournum);
             wages.appendNode(payrate);

             cout<< "\n\nOkay! The employee with ID#: " << Idnum << " has been added!\n";

            break;
        case 2:
        {
            cout<< "Enter the ID# of the employee you want to search: \n";
            cin>> searchID;

            int x = empId.search(searchID);
            if (x != -1)
            {
                cout<< "\nEmployee ID#: " << empId.displayNode(x);
                cout<< "\nHours worked: " << hours.displayNode(x);
                cout<< "\nTheir pay rate: " << wages.displayNode(x);
                cout<< "\nGross wage: " << wages.displayNode(x) * hours.displayNode(x)<< "\n";

            }else
            {
                cout<< "\n\nThat employee does not exist. Please enter a valid ID#\n";
            }
            break;
        }
        case 3:
        {
            cout<< "\nEnter the ID# of the employee you would like to remove: \n";
            cin>> searchID;

            int y = empId.search(searchID);
            if (y != -1)
            {
                empId.deleteNode(y);
                hours.deleteNode(y);
                wages.deleteNode(y);

                cout<< "\nOkay, employee with ID# " <<searchID << " has been deleted. \n";
            }else
            {
                cout<< "\n\nThat employee does not exist. Please enter a valid ID#\n";
            }

            break;
        }
        case 4:
            cout<< "\nOkay! See you later!\n";
            return 0;
        }
    }while(choice != 0);



}

