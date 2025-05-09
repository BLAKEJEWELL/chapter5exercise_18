/*
File name: chapter5exercise_18.cpp
Programmer: Blake Jewell
Date: 05/25
Requirements: Write a program that produces a bar chart showing the population growth of Prairieville,
a small town in the Midwest, at 20-year intervals during the past 100 years. The program should read in
the population figures (rounded to the nearest 1,000 people) for 1900, 1920, 1940, 1960, 1980, and 2000
from a file. For each year, it should display the date and a bar consisting of one asterisk for each 1,000 people.
*/

using namespace std;

#include <iostream>
#include <fstream>
#include<string>

void getnumbers(long int [],int, string);
void displayresults(long int[], int);
int choose();
string getfilename();
void getfilehandle(string);

const string location = R"(C:\Users\Blake Jewell\Downloads\)";

int main()
{
    int choice;
    do {
        const int peryear = 6;
        long int mainarray[peryear];
        string file = getfilename();
        string local = location + file;
        getfilehandle(local);
        getnumbers(mainarray, peryear, local);
        displayresults(mainarray, peryear);
        choice = choose();
    } while (choice == 1);
}
void getnumbers(long int array[], int num, string file) //puts the numbers from the file into an array
{
    ifstream inputfile;
    inputfile.open(file);
    for (int count = 0; count < num;count++)
    {
        inputfile >> array[count];
    }
    inputfile.close();
}
void displayresults(long int array[], int year) //translates the array numbers into "*" and displays them with the year they correspond to
{
    cout << "PRAIRIEVILLE POPULATION GROWTH " << endl;
    cout << "(each * represents 1,000 people)" << endl;
    int thousands;
    int time = 1900;
    for (int count = 0; count < year;count++)
    {
        cout << time + (count * 20);
        thousands = array[count] / 1000;
        for (int index = 0;index < thousands;index++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}
int choose() //make the program repeatable
{
    int choice;
    cout << "Would you like to run the program again? 1 for yes or 2 for no" << endl;
    cin >> choice;
    while (choice < 1 || choice >2)
    {
        cout << "Invalid selection. Please select either 1 or 2." << endl;
        cin >> choice;
    }
    return choice;
}
string getfilename() //allows the user to enter a file name
{
    string filename;
    cout << "please enter the full name of the file" << endl;
    
    cin >> filename;
    return filename;
}
void getfilehandle(string name) // checks to see if the file opened
{
    ifstream handle;
    handle.open(name);
    if (!handle.is_open())
        cout << "could not find the file" << endl;
}