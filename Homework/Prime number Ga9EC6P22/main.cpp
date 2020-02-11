/*
 * File:
 * Author: Kris Ottinger
 * Created on 01/29/2020 12:02PM
 * Purpose: Prime number
 */

//System Libraries
#include <iostream> //I/O library
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
string isPrime(int); //Function to determine if prime or not
//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed

    //Declare Variable Data Types and Constants
    short int num; //User input Variable


    //Initialize Variables
    cout<<"Enter a number:"<<endl;
    cin>>num; //User input to variable

    //Process or map Inputs to Outputs

    //Display Outputs
    cout<<num<<isPrime(num); //Output to user

    //Exit stage right!
    return 0;
}
    string isPrime(int num){ //Function used to determine if prime or not
        int i; //Variables used to determine and store if prime variables
        bool isPrime=true;
        for(i=2;i<=num/2;++i){
            if(num%i==0) isPrime=false;break;  //If difference between number and divisor leave a number the isPrim is false
        }
            if (isPrime) return " is a prime number."; //Print out if prime
            else  return " is not a prime number."; //Print out if not prime
    }
