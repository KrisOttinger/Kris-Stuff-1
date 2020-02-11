/*
 * File:
 * Author: Kris Ottinger
 * Created on 01/28/2020 10:22 AM
 * Purpose:  Whole sale and Mark up
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables

//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
const float CNVFACT=100.0f; //Conversion to percentage
//Function Prototypes
float calulateRetail(float, float); //Calculate Retail markup

//Execution Begins Here
float calculateRetail(float w, float m){
    float tot;
    tot=(w*m)+w;
    return tot;
}
int main(int argc, char** argv) {
    //Set Random Number seed

    //Declare Variable Data Types and Constants
    float whlSal; //Whole sale cost
    float mrkPer; //Mark up percentage

    //Initialize Variables
    cout<<"Enter the wholesale cost:"<<endl;
    cin>>whlSal; //Whole sale input
    cout<<"Enter the markup percentage:"<<endl;
    cin>>mrkPer; //Markup percentage input

    //Process or map Inputs to Outputs
    mrkPer/=CNVFACT; //Convert input percent to percentage
    float temp = calculateRetail(whlSal, mrkPer);
    //Display Outputs
    cout<<"The retail price is $"<<setw(5)<<fixed<<showpoint<<setprecision(2)<<temp; //Coutput to user
    //Exit stage right!
    return 0;
}
