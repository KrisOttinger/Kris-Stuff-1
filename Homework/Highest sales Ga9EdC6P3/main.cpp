/*
 * File:
 * Author: Kris Ottinger
 * Created on 01/30/2020 1:36 PM
 * Purpose:  Which company section had the highest sales
 */

//System Libraries
#include <iostream> //I/O library
#include <iomanip> //I/O manipulation
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
float getSales(float); //Function used for valadating sales above $0
void findHighest(float,float,float,float); //Function to find and output highest sales and division
//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed

    //Declare Variable Data Types and Constants
    float nrthED,sthED,nrthWD,sthWD,monI=0; //User input vaiables stored after valadation, valdation input temp holder

    //Initialize Variables
    cout<<"Enter the sales for Northeast division:$\n";
    cin>>monI; //User input
    nrthED=getSales(monI); //Calling valadation function and storing into vairable after
    monI=0; //Reset temp value to 0 for next use

    cout<<"Enter the sales for Southeast division:$\n";
    cin>>monI; //User input
    sthED=getSales(monI); //Calling valadation function and storing into vairable after
    monI=0; //Reset temp value to 0 for next use

    cout<<"Enter the sales for Northwest division:$\n";
    cin>>monI; //User input
    nrthWD=getSales(monI); //Calling valadation function and storing into vairable after
    monI=0; //Reset temp value to 0 for next use

    cout<<"Enter the sales for Southwest division:$\n";
    cin>>monI; //User input
    sthWD=getSales(monI); //Calling valadation function and storing into vairable after
    monI=0; //Reset temp value to 0 for next use

    //Process or map Inputs to Outputs
    findHighest(nrthED,sthED,nrthWD,sthWD);
    //Display Outputs

    //Exit stage right!
    return 0;
}
float getSales(float num){ //Valadation function for user input
    if(num>0) return num; //Valadation that user input is above 0
}
void findHighest(float n1,float n2,float n3,float n4){ //Function that determinds highest sales and division
    cout<<fixed<<showpoint<<setprecision(2);
        if(n1>n2&&n1>n3&&n1>n4) cout<<"The Northeast division had the highest sales of $"<<n1;
        else if(n2>n1&&n2>n3&&n2>n4) cout<<"The Southeast division had the highest sales of $"<<n2;
        else if(n3>n1&&n3>n2&&n3>n4) cout<<"The Northwest division had the highest sales of $"<<n3;
        else cout<<"The Southwest division had the highest sales of $"<<n4;
}
