//----------------------------------------------------------------------------
// EGR 126 ELI Fall 2017
//----------------------------------------------------------------------------
// Student Name : Rich MURPHY
// Assignment : Project #2
// Submission Date: 10/15/17
// Complier Info : MacOS, Xcode
// Purpose : This program outputs weather balloon altitude and velocity as
// a function of time based on some user inputs.

// Note: The system ("CLS") command doesn't work in Xcode. As a workaround I've
// created another function called clr_scrn() which simulates the system ("CLS")
// command by performing 10 "\n" commands.
//----------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

void clr_scrn() // See comment above regarding system ("CLS") command in Xcode.
{
    for (int i = 1; i < 11; i++)
        cout << "\n" << endl;
}

float myAltitude (float total_time, float WB) // This is our altitude function.
    {
    float W1A1=-.12, W1B1=12, W1C1=-380, W1D1=4100, W1E1=220;
    float W2A1=-.11, W2B1=10, W2C1=-235, W2D1=3850, W2E1=178;
    float W3A1=-.18, W3B1=14, W3C1=-401, W3D1=4860, W3E1=235;
    
        if (WB == 1)
          return pow(total_time,4)*W1A1 + pow(total_time,3)*W1B1 + pow(total_time,2)*W1C1 + total_time*W1D1 + W1E1;
    
            else if (WB == 2)
                return pow(total_time,4)*W2A1 + pow(total_time,3)*W2B1 + pow(total_time,2)*W2C1 + total_time*W2D1 + W2E1;
    
                else if (WB == 3)
                    return pow(total_time,4)*W3A1 + pow(total_time,3)*W3B1 + pow(total_time,2)*W3C1 + total_time*W3D1 + W3E1;
    
        return 0;
    }

float myVelocity (float total_time, float WB) // This is our velocity function.
    {
    float W1A2=0, W1B2=-.48, W1C2=36, W1D2=-760, W1E2=4100;
    float W2A2=0, W2B2=34, W2C2=34, W2D2=-564, W2E2=3450;
    float W3A2=0, W3B2=39, W3C2=39, W3D2=-843, W3E2=4300;
    
        if (WB == 1)
           return (pow(total_time,4)*W1A2 + pow(total_time,3)*W1B2 + pow(total_time,2)*W1C2 + total_time*W1D2 + W1E2)/3600;
    
            else if (WB == 2)
                return (pow(total_time,4)*W2A2 + pow(total_time,3)*W2B2 + pow(total_time,2)*W2C2 + total_time*W2D2 + W2E2)/3600;
    
                else if (WB == 3)
                    return (pow(total_time,4)*W3A2 + pow(total_time,3)*W3B2 + pow(total_time,2)*W3C2 + total_time*W3D2 + W3E2)/3600;
    
    return 0;
    }

void mymenu () // This is the menu which greets the user after they enter the simulation parameters.
{
    cout << "\t\tSELECT THE BALLOON FOR SIMULATION" << endl;
    cout << "\t1. Weather Balloon 1" << endl;
    cout << "\t2. Weather Balloon 2" << endl;
    cout << "\t3. Weather Balloon 3" << endl;
    cout << "\t4. Exit" << endl;
}

int main() // Our main program consists of two do-loops, one for the parameters and one for the main menu.
{
    float t_init,t_final,t_incr,total_time;
    float WB=0;
    
    cout << "----------------------------------------------------" << endl;
    cout << "\tRich MURPHY" << endl;
    cout << "\tSolution for Project #2" << endl;
    cout << "----------------------------------------------------" << endl;
    do
    {
    cout << endl;
    cout << "\t\tENTER THE SIMULATION PARAMETERS" << endl;
    cout << "\tEnter initial value of the time (in hrs): ";
    cin >> t_init;
    cout << "\tEnter increments between lines (in hrs): ";
    cin >> t_incr;
    cout << "\tEnter the final value of the observation (in hrs): ";
    cin >> t_final;
    if (t_final - t_init <5 || t_final - t_init >24) // This is the circuit breaker if the user enters in too short or too long a simulation.
        {
        cout << endl;
        cout << "NOT PROPER DURATION. Observation period must be between 5 and 24 hours." << endl;
        cout << "Enter the parameters again." << endl;
        }
    } while (t_final - t_init <5 || t_final - t_init >24);
    
    do // This do-loop controls the selection, reading, and writing of the data.
    {
        cout << endl;
        mymenu();
        cin >> WB;
        
    if (WB == 1)
        {
        ofstream data1("Murphy_WB1.txt");
        data1 << setprecision (2) << fixed; // We are rounding off at 2 decimal places like the example in the instructions.
        cout <<endl;
                for (total_time = t_init; total_time <= t_final; total_time += t_incr)
                    {
                    data1 << total_time << "\t" << setw(10) << myAltitude(total_time, WB)<< "\t" << setw(5)<< myVelocity(total_time, WB) << endl;
                    }
            clr_scrn();
            cout << "Weather balloon 1 data saved to Murphy_WB1.txt" << endl;
            cout << "Please make another selection" << endl;
            }
    
            else if (WB == 2)
                    {
                    ofstream data2("Murphy_WB2.txt");
                    data2 << setprecision (2) << fixed; // We are rounding off at 2 decimal places like the example in the instructions.

                    cout <<endl;
                            for (total_time = t_init; total_time <= t_final; total_time += t_incr)
                                {
                                    data2 << total_time << "\t" << setw(10) << myAltitude(total_time, WB)<< "\t" << setw(5)<< myVelocity(total_time, WB) << endl;
                                }
                        clr_scrn();
                        cout << "Weather balloon 2 data saved to Murphy_WB2.txt" << endl;
                        cout << "Please make another selection" << endl;
                    }
    
                    else if (WB == 3)
                            {
                            ofstream data3("Murphy_WB3.txt");
                            data3 << setprecision (2) << fixed; // We are rounding off at 2 decimal places like the example in the instructions.
                           
                            cout <<endl;
                                    for (total_time = t_init; total_time <= t_final; total_time += t_incr)
                                        {
                                        data3 << total_time << "\t" << setw(10) << myAltitude(total_time, WB)<< "\t" << setw(5)<<   myVelocity(total_time, WB) << endl;
                                        }
                                clr_scrn();
                                cout << "Weather balloon 3 data saved to Murphy_WB3.txt" << endl;
                                cout << "Please make another selection" << endl;
                            }
    
                            else if (WB == 4)
                                    {
                                    clr_scrn();
                                    cout << "--------------------------" <<endl;
                                    cout << "\tEnd of Project #2" <<endl;
                                    cout << "--------------------------" <<endl;
                                    exit(0);
                                    }
    
                                    else if (WB != 4)
                                        {
                                        cout << "Error, please select from only the menu items below." << endl;
                                        cout << endl;
                                        }
            } while (WB !=4); // Loop will run until user selects 4 to exit.
    
return 0;
    
}
