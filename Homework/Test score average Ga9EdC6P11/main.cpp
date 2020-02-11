/*
 * File:
 * Author: Kris Ottinger
 * Created on 01/30/2020 2:20 PM
 * Purpose:  Test score average
 */

//System Libraries
#include <iostream> //I/O library
#include <iomanip> //I/O manipulation
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void calcAverage(float,float,float,float,float,float); //Function used to  calculate the average of the scores

void getScore(float); //Function used to valadate user input is above 0

int findLowest(int,int,int,int,int); //Function used to determind the lowest inputed score

//Execution Begins Here
int main(int argc, char** argv){
    //Set Random Number seed

    //Declare Variable Data Types and Constants
    float t1,t2,t3,t4,t5,lowest=0;

    //Initialize Variables
    cout<<"Enter a test score:"<<endl;
    cin>>t1; //User input to variable
    getScore(t1); //Calls to valadate input is above 0

    cout<<"Enter a test score:"<<endl;
    cin>>t2; //User input to variable
    getScore(t2); //Calls to valadate input is above 0

    cout<<"Enter a test score:"<<endl;
    cin>>t3; //User input to variable
    getScore(t3); //Calls to valadate input is above 0

    cout<<"Enter a test score:"<<endl;
    cin>>t4; //User input to variable
    getScore(t4); //Calls to valadate input is above 0

    cout<<"Enter a test score:"<<endl;
    cin>>t5; //User input to variable
    getScore(t5); //Calls to valadate input is above 0

    //Process or map Inputs to Outputs
    lowest+=-findLowest(t1,t2,t3,t4,t5); //Lowest score is stored in variable

    //Display Outputs

    calcAverage(t1,t2,t3,t4,t5,lowest); //Function used to calculate average and output results

    //Exit stage right!
    return 0;
}
    int findLowest(int t1,int t2,int t3,int t4,int t5){ //Function finds lowest score and returns it
        if(t1<t2&&t1<t3&&t1<t4&&t1<t5) return t1;
            else if(t2<t1&&t2<t3&&t2<t4&&t2<t5) return t2;
            else if(t3<t1&&t3<t2&&t3<t4&&t3<t5) return t3;
            else if(t4<t1&&t4<t2&&t4<t3&&t4<t5) return t4;
            else return t5;

    }
    void getScore(float num){ //Function to valadate user input is above 0
        if(num<=0) cout<<"Invlaid"<<endl;
    }
    void calcAverage(float ts1,float ts2, float ts3, float ts4,float ts5,float lowest){ //Function used to calculate average and output results
        float ave;
        ave=(ts1+ts2+ts3+ts4+ts5+lowest)/4;
        cout<<"The average is "<<ave;
    }
