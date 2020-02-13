

/*
 * File:   main.cpp
 * Author: Kris Ottinger
 * Purpose:
 * Created on January 25, 2020, 11:50 AM
 */
//System Libraries

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;

//User Libraries

//Global Constants - No Global Variable

//Only Universal Constant, Math, Physics, Conversions

//Function Prototypes

//Execution Begins Here

int main() {

    //Set Random Number Seed
    srand(static_cast<int>(time(0))); //Random number generator

    //Declare Variable Data types and Constants
    short int plyr2=2,plyr3=3,plyr4=4,plyr5=5;
    short int hand1,suite1,plyrVal1=1,plyrVal2=1,rndNum=1; //Random number generator value determiner hand/suite
    char plyr1H1=0,plyr2H1=0,plyr3H1,plyr4H1,plyr5H1; //Players hand 1 face values
    char plyr1H2,plyr2H2,plyr3H2,plyr4H2,plyr5H2; //Players hand 2 face values
    char plyr1S1=0,plyr2S1=0,plyr3S1,plyr4S1,plyr5S1; //Players hand 1 suite values
    char plyr1S2,plyr2S2,plyr3S2,plyr4S2,plyr5S2; //Players hand 2 suite values
    char handSuit, handVal; //hand card generator variables
    char tblS1,tblS2,tblS3,tblS4,tblS5,tblH1,tblH2,tblH3,tblH4,tblH5; //Table cards shown
    char dsply1,dsply2,dsply3,dsply4; //Table cards #4 and #5 face value and suite to be delayed shown
    string pName, smB, bgB,pl1, pl2, pl3, pl4, pl5;//PLayer Name, Small BLind, Big Blind, SB&BB player choice 1-5
    string rndWin,totWin;
    unsigned int plyr1M=500,plyr2M=500,plyr3M=500,plyr4M=500,plyr5M=500,potM=0,betHld=0,potAd=0; //Players/Pot Money, Bet holder, Pot Adder
    unsigned int numPlyr=0,sBbB=1,plyrT=1; //Number of players left, Small/Big blind selector, Player turn
    float op=0,botM; //User choice on turn, Bots Move on turn


    //Initialize Variables
            cout<<"##### ####  #   # #####   #  #  ###  #    ###     #### ##   ## \n";
            cout<<"  #   #      # #    #     #  # #   # #    #  #    #    # # # # \n";
            cout<<"  #   ###     #     #     #### #   # #    #   #   ###  #  #  # \n";
            cout<<"  #   #      # #    #     #  # #   # #    #  #    #    #     # \n";
            cout<<"  #   ####  #   #   #     #  #  ###  #### ###     #### #     # \n";
            cout<<"...............................................................\n";
            cout<<""<<endl;
            cout<<"Please type your name: ";
            cin>>pName;	//User input for there name
            cout<<"Alright "<<pName<<" lets play Texas Hold'em."<<endl;
            cout<<""<<endl;

        pl1=pName;  //User name assignment variable to uniform standard name
        pl2="bot 1-Erin";  //AI player 2 uniform standard name
        pl3="bot 2-Cindy"; //AI player 3 uniform standard name
        pl4="bot 4-Bob";   //AI player 4 uniform standard name
        pl5="bot 5-Nick";  //AI player 5 uniform standard name
        dsply1='-';  //Default for table card face #4
        dsply2='-';  //Default for table card suite #4
        dsply3='-';  //Default for table card face #5
        dsply4='-';  //Default for table card suite #5

    //Processes or map Inputs to Outputs
    do{ //Cycle main portion of the game

    Sleep(2400); //Delay next segment to user for 2.4 seconds

        for(int cnt1=1;cnt1<=15;cnt1++){      //Player card generator section.
            hand1=rand()%14+1; 		      //Random number-gen to select a card face value.
            switch(hand1){
                case 1: handVal='2';break;    //Hand case values 1-13 = card face values.
                case 2: handVal='3';break;
                case 3: handVal='4';break;
                case 4: handVal='5';break;
                case 5: handVal='6';break;
                case 6: handVal='7';break;
                case 7: handVal='8';break;
                case 8: handVal='9';break;
                case 9: handVal='10';break;
                case 10: handVal='J';break;
                case 11: handVal='Q';break;
                case 12: handVal='K';break;
                case 13: handVal='A';break;
            }
             switch(plyrVal1){      //Card to player hand assignment.
                case 1:plyr1H1=handVal;break;
                case 2:plyr2H1=handVal;break;
                case 3:plyr3H1=handVal;break;
                case 4:plyr4H1=handVal;break;
                case 5:plyr5H1=handVal;break;
                case 6:plyr1H2=handVal;break;
                case 7:plyr2H2=handVal;break;
                case 8:plyr3H2=handVal;break;
                case 9:plyr4H2=handVal;break;
                case 10:plyr5H2=handVal;break;
                case 11:tblH1=handVal;break;
                case 12:tblH2=handVal;break;
                case 13:tblH3=handVal;break;
                case 14:tblH4=handVal;break;
                case 15:tblH5=handVal;break;
            }
            plyrVal1++;	//Incrementing variable to select next players hand to deposit random hand value in.
        }
        for(int cnt2=1;cnt2<=15;cnt2++){    //Player suite generator.
            suite1=rand()%5+1;		    //Random  number-gen for selection of card suite value.
            switch(suite1){
                case 1: handSuit='S';break; //Suite case values 1-4 = card suite values.
                case 2: handSuit='D';break;
                case 3: handSuit='H';break;
                case 4: handSuit='C';break;

            }switch(plyrVal2){   //suite to card assignments.
                case 1:plyr1S1=handSuit;break;
                case 2:plyr2S1=handSuit;break;
                case 3:plyr3S1=handSuit;break;
                case 4:plyr4S1=handSuit;break;
                case 5:plyr5S1=handSuit;break;
                case 6:plyr1S2=handSuit;break;
                case 7:plyr2S2=handSuit;break;
                case 8:plyr3S2=handSuit;break;
                case 9:plyr4S2=handSuit;break;
                case 10:plyr5S2=handSuit;break;
                case 11:tblS1=handSuit;break;
                case 12:tblS2=handSuit;break;
                case 13:tblS3=handSuit;break;
                case 14:tblS4=handSuit;break;
                case 15:tblS5=handSuit;break;

                }
            plyrVal2++; //Incrementing value to select next players hand to deposit random suite value in.
        }
    switch(sBbB){  //Incrementing values to assign the Small Blind to a player.
        case 1:smB=pl2;break;
        case 2:smB=pl3;break;
        case 3:smB=pl1;break;
        case 4:smB=pl4;break;
        case 5:smB=pl5;break;
        }
    switch(sBbB){  //Incrementing values to assign the Big Blind to the player after Small Blind.
        case 1:bgB=pl3;break;
        case 2:bgB=pl1;break;
        case 3:bgB=pl4;break;
        case 4:bgB=pl5;break;
        case 5:bgB=pl2;break;
    }
    switch(sBbB){  //Incrementing values to have Small Blind place $20 dollars down.
        case 1:if(plyr2M>=20)potM+=20;break;
        case 2:if(plyr3M>=20)potM+=20;break;
        case 3:if(plyr1M>=20)potM+=20;break;
        case 4:if(plyr4M>=20)potM+=20;break;
        case 5:if(plyr5M>=20)potM+=20;break;
    }
    switch(sBbB){  //Incrementing values to have Big Blind place $40 dollars down.
        case 1:if(plyr3M>=40)potM+=40;break;
        case 2:if(plyr1M>=40)potM+=40;break;
        case 3:if(plyr4M>=40)potM+=40;break;
        case 4:if(plyr5M>=40)potM+=40;break;
        case 5:if(plyr2M>=40)potM+=40;break;
    }
    do{
    if(rndNum>=2) dsply1=tblH4;
    if(rndNum>=2) dsply2=tblS4;
    if(rndNum>=3) dsply3=tblH5;
    if(rndNum>=3) dsply4=tblS5;
            cout<<"Round "<<rndNum<<", get ready!"<<endl; //Output the round number to user.
        Sleep(800); //Delay for .8 seconds

            cout<<""<<endl;
            cout<<pName<<" cards:   Money: $"<<plyr1M<<endl; //Output Users name and Users money.
            cout<<" -----  -----"<<endl; 			 //Display players cards.
            cout<<"|  "<<plyr1H1<<"  ||  "
            <<plyr1H2<<"  |"<<endl;
            cout<<"|  "<<plyr1S1<<"  ||  "
            <<plyr1S2<<"  |"<<endl;
            cout<<"|     ||     |"<<endl;
            cout<<" -----  -----"<<endl;
            cout<<"..............................."<<endl;
            cout<<""<<endl;

    Sleep(1700); //Delay next segment to user for 1.7 seconds


            cout<<"Dealer flops!      The Pot: $"<<potM<<endl;  //Display Total bets summed.
            cout<<"----- ----- ----- ----- -----"<<endl;
            cout<<"| "<<tblH1<<" | | "<<tblH2<<" | | "<<tblH3	       //Display dealer cards to user.
            <<" | | "<<dsply1<<" | | "<<dsply3<<" |    SB: $20 = "<<smB<<endl;  //Display which player is SB.
            cout<<"| "<<tblS1<<" | | "<<tblS2<<" | | "<<tblS3
            <<" | | "<<dsply2<<" | | "<<dsply4<<" |    BB: $40 = "<<bgB<<endl;  //Display which player is BB.
            cout<<"----- ----- ----- ----- -----"<<endl;
            cout<<"...................................................."<<endl;


       if(plyrT==1&&plyr1M>=1){
                cout<<"CALL/CHECK: 1         BET: 2          FOLD: 3"<<endl;
                cout<<"Choice: ";
                cin>>op;    //User input for choice to bet, call/check, fold.
                cout<<""<<endl;

            while (op<=0||op>=4){
                cout<<"Invalid choice! Choose options 1-3"<<endl;
                cout<<"CALL/CHECK: 1         BET: 2          FOLD: 3"<<endl;
                cin.clear();
                cin.ignore('\n');
                cin>>op;  //User input for choice to bet, call/check, fold.
                cout<<""<<endl;
        }
            if(op==1&&plyr2M>=1){
                if(rndNum==1)potM+=40,plyr1M+=-40;
            }
            else if(op==2){
                if(rndNum==1){
                  while(betHld<=40){
                        betHld=0;
                        cout<<"Enter bet more than Big Blind:";
                        cin>>betHld;
              }}
                else {  betHld=0;
                        cout<<"Enter bet in $10 increments";
                        cin>>betHld;
                }
            }
            else {}
        if(betHld>=potAd)potAd=betHld; //Determines the highest bet so far for call/checking

        }plyrT++;
        if(plyrT==2&&plyr3M>=1){
            botM=rand()%101+1;
            if(botM>=0||botM<=16){ }
            else if(botM>=17||botM<=78){ }
            else if(botM>=79||botM<=100){}
        }plyrT++;
        if(plyrT==3&&plyr4M>=1){
            botM=rand()%101+1;
            if(botM>=0||botM<=16){ }
            else if(botM>=17||botM<=78){ }
            else if(botM>=79||botM<=100){}
        }plyrT++;
        if(plyrT==4&&plyr4M>=1){
            botM=rand()%101+1;
            if(botM>=0||botM<=16){ }
            else if(botM>=17||botM<=78){ }
            else if(botM>=79||botM<=100){}
        }plyrT++;
        if(plyrT==5&&plyr5M>=1){
            botM=rand()%101+1;
            if(botM>=0||botM<=16){ }
            else if(botM>=17||botM<=78){ }
            else if(botM>=79||botM<=100){}
        }if(plyrT>=5)plyrT=1;


        rndNum++;  //Incrementing value to show how many cycles (rounds) have passed to the player.
    }while(rndNum<=4);

        if(numPlyr>=0)numPlyr=0;  //Default Number of Players to 0 so players with money is summed to determine is to cycle or end game.
        if(plyr1M>=1)numPlyr++;  //START----If players have money they are added to sum.
        if(plyr2M>=1)numPlyr++;
        if(plyr3M>=1)numPlyr++;
        if(plyr4M>=1)numPlyr++;
        if(plyr5M>=1)numPlyr++;  //END----If players have money they are added to sum.
        plyrT++;  //Starting player for betting
        sBbB++;   //Incrementing value that is used to switch Small Blind and Big Blind assignment.
        if(rndNum>=4)rndNum=1;
        if(sBbB>=6)sBbB=1;  //When Variable for incrementing Small Blind and Big Blind = 6, value is reset to 1.
    }while(numPlyr>=2);  //If number of players with money is 2 or more then game cycles


    //Display Outputs
    cout<<"The Winner is..."<<endl;
    //Exit stage right
    return 0;
}

