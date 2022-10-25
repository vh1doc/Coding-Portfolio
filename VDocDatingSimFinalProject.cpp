//Amber Dougherty, Data Structures 3700

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int SIZE = 6;
void setMatrix(int[][SIZE]);
int getIndex(vector <string>, string);
void setAdjacency(int [][SIZE], int, int);
void printAdjacency(int [][SIZE], vector <string>);

int interestCalc(string [], string[]);
void comparelogic(vector <string> v, int, int e[][SIZE], string first[], string second[], string third[], string fourth[], string fifth[], string sixth[]);



int main()
{
    system("Color 56");

    cout<< "Written by Vincenzo Dougherty for CSIS 3700\n";
    cout<< "Dating App Sim Project for Final Project.\n\n";

    //users
     vector <string> vertex = {"User 1", "User 2", "User 3", "User 4", "User 5", "User 6"};

     //user interests
     string user1[] = {"Dogs", "Weed", "Cooking", "Yoga", "Tea"};
     string user2[] = {"Robots", "Dogs", "Weed", "Hiking", "Coffee"};
     string user3[] = {"Sports", "Dinosaurs", "Cats", "Working Out", "Vegan"};
     string user4[] = {"Video Games", "Art", "Robots", "Tattoos", "3D Printers"};
     string user5[] = {"Video Games", "Cats", "Writing", "Religious", "Shopping"};
     string user6[] = {"Writing", "Movies", "Dinosaurs", "Yoga", "Coffee"};

    int edge[SIZE][SIZE];
    setMatrix(edge);
    int position;

    cout<< "User 1's interests are: \n";
    for(int i =0; i < 5; i++)
    {
        cout<< user1[i];
        cout<< endl;
    }
    cout<< endl;

    cout<< "User 2's interests are: \n";
    for(int i =0; i < 5; i++)
    {
        cout<< user2[i];
        cout<< endl;
    }
    cout<< endl;

    cout<< "User 3's interests are: \n";
    for(int i =0; i < 5; i++)
    {
        cout<< user3[i];
        cout<< endl;
    }
    cout<< endl;

    cout<< "User 4's interests are: \n";
    for(int i =0; i < 5; i++)
    {
        cout<< user4[i];
        cout<< endl;
    }
    cout<< endl;

    cout<< "User 5's interests are: \n";
    for(int i =0; i < 5; i++)
    {
        cout<< user5[i];
        cout<< endl;
    }
    cout<< endl;

    cout<< "User 6's interests are: \n";
    for(int i =0; i < 5; i++)
    {
        cout<< user6[i];
        cout<< endl;
    }
    cout<< endl;
    cout<< endl;

    cout<< "The Potential Match List: \n\n";

    position = 0;
    comparelogic(vertex, position, edge, user1, user2, user3, user4, user5, user6);
    position = 1;
    comparelogic(vertex, position, edge, user2, user1, user3, user4, user5, user6);
    position = 2;
    comparelogic(vertex, position, edge, user3, user2, user1, user4, user5, user6);
    position = 3;
    comparelogic(vertex, position, edge, user4, user2, user3, user1, user5, user6);
    position = 4;
    comparelogic(vertex, position, edge, user5, user2, user3, user4, user1, user6);
    position = 5;
    comparelogic(vertex, position, edge, user6, user2, user3, user4, user5, user1);


    printAdjacency(edge, vertex);




    return 0;
}

void comparelogic(vector <string> v, int position, int e[][SIZE], string first[], string second[], string third[], string fourth[], string fifth[], string sixth[])
{
    int compare = interestCalc(first, second);
    if(compare >= 20)
    {
        setAdjacency(e, getIndex(v, v[position]), getIndex(v, v[1]));
    }

    compare = interestCalc(first, third);
    if(compare >= 20)
    {
        setAdjacency(e, getIndex(v, v[position]), getIndex(v, v[2]));
    }

    compare = interestCalc(first, fourth);
    if(compare >= 20)
    {
        setAdjacency(e, getIndex(v, v[position]), getIndex(v, v[3]));
    }

    compare = interestCalc(first, fifth);
    if(compare >= 20)
    {
        setAdjacency(e, getIndex(v, v[position]), getIndex(v, v[4]));
    }

    compare = interestCalc(first, sixth);
    if(compare >= 20)
    {
        setAdjacency(e, getIndex(v, v[position]), getIndex(v, v[5]));
    }
}

int interestCalc(string first[], string second[])
{
    int level = 0;

    for(int i =0; i < 5; i++)
    {
        if(first[i]== second[0])
        {
            level = level +20;
        }

        if(first[i]== second[1])
        {
            level = level +10;
        }

        if(first[i]== second[2])
        {
            level = level +10;
        }

        if(first[i]== second[3])
        {
            level = level +10;
        }

        if(first[i]== second[4])
        {
            level = level +10;
        }
    }


    return level;

}



void setMatrix(int e[][SIZE])
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            e[i][j] = 0;
        }
    }
}

//this is cool. take note of this
int getIndex(vector <string> v, string s)
{
    auto i = find(v.begin(), v.end(),s);

    return (i - v.begin());
}

void setAdjacency(int e[][SIZE], int f, int l)//f for first, l for last
{
    e[f][l] = 1;
    e[l][f] = 1;
}

void printAdjacency(int e[][SIZE], vector <string> v)
{
    for(int i = 0; i < SIZE; i++)
    {
        cout<< v[i] << " has a potential match with: ";
        for(int j = 0; j < SIZE; j++)
        {
            if(e[i][j] == 1)
            {
                cout<< v[j] << ", ";
            }
        }
        cout<< endl;
        cout<< endl;
    }

}
