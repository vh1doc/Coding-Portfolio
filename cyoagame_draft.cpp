//This is a program that codes for a "choose your own adventure" type game
//Written by Vincenzo Dougherty

#include <iostream>
#include <string>

using namespace std;

void routeone();
void routetwo();
void routethree();

void gameintro()
{
    cout<< "game intro\n";
    cout<< "what would you like to do?\n";
    cout<< "1. route 1 \n2. route 2 \n3. route 3\n";
    int routedecision;
    cin>> routedecision;

    switch (routedecision)//nest the functions for the gameplay in this portion
    {
    case 1:
        routeone();
        break;
    case 2:
        routetwo();
        break;
    case 3:
        routethree();
        break;
    }
}

void routeone()
{
    cout<< "The continuation of route 1\n";
    cout<< "What would you like to do?\n";
    cout<< "1. route1a \n2. route1b \n3. route1c\n";
    int routedecision;
    cin>> routedecision;

    switch (routedecision)
    {
    case 1:
        cout<< "route 1a\n";
        break;
    case 2:
        cout<< "route 1b\n";
        break;
    case 3:
        cout<< "route 1c\n";
        break;
    }
}

void routetwo()
{
    cout<< "The continuation of route 2\n";
    cout<< "What would you like to do?\n";
    cout<< "1. route2a \n2. route2b \n3. route2c\n";
    int routedecision;
    cin>> routedecision;

    switch (routedecision)
    {
    case 1:
        cout<< "route 2a\n";
        break;
    case 2:
        cout<< "route 2b\n";
        break;
    case 3:
        cout<< "route 2c\n";
        break;
    }
}

void routethree()
{
    cout<< "The continuation of route 3\n";
    cout<< "What would you like to do?\n";
    cout<< "1. route3a \n2. route3b \n3. route3c\n";
    int routedecision;
    cin>> routedecision;

    switch (routedecision)
    {
    case 1:
        cout<< "route 3a\n";
        break;
    case 2:
        cout<< "route 3b\n";
        break;
    case 3:
        cout<< "route 3c\n";
        break;
    }
}

int main()
{

   int choice;

   do
   {
       cout<< "1. Quit \n2. Play Game\n";
       cin>> choice;

      switch(choice)
   {
       case 1:
            cout<< "Bye, see ya later\n";
            return 0;
       case 2:

            gameintro();//function for the game here
   }

   }
   while(choice !=0);//after game is done playing, it should return to the starting menu




}
