/*
 * File:
 * Author: Kris Ottinger
 * Created on 01/29/2020 12:06 AM
 * Purpose:  Kinetic Energy
 */

//System Libraries
#include <iostream> //I/O library
#include <iomanip> //I/O manipulation
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
float kineticEnergy(float,float); //Calculate kinetic Energy

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed

    //Declare Variable Data Types and Constants
    float mass, velocy; //User input vaiables mass, velocy

    //Initialize Variables
    cout<<"Enter the object's mass:"<<endl;
    cin>>mass; //User input for mass
    cout<<"Enter the object's velocity:"<<endl;
    cin>>velocy; //User input for velocy

    //Process or map Inputs to Outputs

    //Display Outputs
    cout<<"The object has "<<fixed<<showpoint<<setprecision(1)<<kineticEnergy(mass,velocy)<<" Joules of energy."; //Output to user

    //Exit stage right!
    return 0;
}
    float kineticEnergy(float m,float v){ //Function used to determine kinetic Energy
        return .5*m*(v*v); //kinetic Energy formula
    }
