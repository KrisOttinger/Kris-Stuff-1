

/*
 * File:   main.cpp
 * Author: Kris Ottinger
 * Purpose:
 * Created on January 25, 2020, 11:50 AM
 */
//System Libraries

#include <iostream>  //I/O library
#include <ctime>     //Time
#include <cstdlib>   //C standard library
#include <windows.h> //Sleep function use
#include <iomanip>   //I/O manipulation
using namespace std;

//User Libraries

//Global Constants - No Global Variable

//Only Universal Constant, Math, Physics, Conversions

//Function Prototypes
int pointSystem1(int,int,int,int,int,int,int,int,int,int,int,int,int);
int winnerSystem(int,int,int,int,int);
//Execution Begins Here

int main() {

    //Set Random Number Seed
    srand(static_cast<int>(time(0))); //Random number generator

    //Declare Variable Data types and Constants

    short int hand1,suite1,plyrVal1=1,plyrVal2=1,rndNum=1; //Random number generator value determiner hand/suite
    char plyr1H1,plyr2H1=0,plyr3H1,plyr4H1,plyr5H1; //Players hand 1 face values
    char plyr1H2,plyr2H2,plyr3H2,plyr4H2,plyr5H2; //Players hand 2 face values
    char plyr1S1=0,plyr2S1=0,plyr3S1,plyr4S1,plyr5S1; //Players hand 1 suite values
    char plyr1S2,plyr2S2,plyr3S2,plyr4S2,plyr5S2; //Players hand 2 suite values
    char handSuit, handVal; //hand card generator variables
    char tblS1,tblS2,tblS3,tblS4,tblS5,tblH1,tblH2,tblH3,tblH4,tblH5; //Table cards shown
    char dsply1,dsply2,dsply3,dsply4; //Table cards #4 and #5 face value and suite to be delayed shown
    string pName, smB, bgB,pl1, pl2, pl3, pl4, pl5;//PLayer Name, Small BLind, Big Blind, SB&BB player choice 1-5
    string rndWin,totWin;
    unsigned int plyr1M=500,plyr2M=500,plyr3M=500,plyr4M=500,plyr5M=500,potM=0,betHld=0,potAd=0; //Players/Pot Money, Bet holder, Pot Adder
    unsigned int numPlyr=0,sBbB=1,plyrT=1,cnt1=1,cnt2=1; //Number of players left, Small/Big blind selector, Player turn
    int p1A=0,p1B=0,p2A=0,p2B=0,p3A=0,p3B=0,p4A=0,p4B=0,p5A=0,p5B=0,next=0; //Player points each hand, advance to next round
    int p1=0,p2=0,p3=0,p4=0,p5=0;
    float op=0,botM; //User choice on turn, Bots Move on turn
    bool nextR=true;

    //Initialize Variables
            cout<<"##### ####  #   # #####   #  #  ###  #    ###     #### ##   ## \n";
            cout<<"  #   #      # #    #     #  # #   # #    #  #    #    # # # # \n";
            cout<<"  #   ###     #     #     #### #   # #    #   #   ###  #  #  # \n";
            cout<<"  #   #      # #    #     #  # #   # #    #  #    #    #     # \n";
            cout<<"  #   ####  #   #   #     #  #  ###  #### ###     #### #     # \n";
            cout<<"...............................................................\n";
            cout<<"Please type your name: ";
            cin>>pName;	//User input for there name
            cout<<""<<endl;
            cout<<"Alright "<<pName<<" lets play Texas Hold'em."<<endl;
            cout<<""<<endl;

        pl1=pName;  //User name assignment variable to uniform standard name
        pl2="bot 1-Erin";  //AI player 2 uniform standard name
        pl3="bot 2-Cindy"; //AI player 3 uniform standard name
        pl4="bot 4-Bob";   //AI player 4 uniform standard name
        pl5="bot 5-Nick";  //AI player 5 uniform standard name


    //Processes or map Inputs to Outputs
    do{ //Cycle main portion of the game

    Sleep(2400); //Delay next segment to user for 2.4 seconds


//**************************************Card Selection Start******************************************************
    cnt1=1; //Reset player card gen loop
    cnt2=1; //Reset player suit gen loop
    potM=0; //Reset Pot back to 0 for new game

        for(int cnt1=1;cnt1<=15;cnt1++){      //Player card generator section.
            hand1=rand()%13+1; 		      //Random number-gen to select a card face value.
            switch(hand1){
                case 1: handVal='2';break;    //Hand case values 1-13 = card face values.
                case 2: handVal='3';break;
                case 3: handVal='4';break;
                case 4: handVal='5';break;
                case 5: handVal='6';break;
                case 6: handVal='7';break;
                case 7: handVal='8';break;
                case 8: handVal='9';break;
                case 9: handVal='T';break;
                case 10: handVal='J';break;
                case 11: handVal='Q';break;
                case 12: handVal='K';break;
                case 13: handVal='A';break;
                default: handVal='6';
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
        }plyrVal1=1;
        for(int cnt2=1;cnt2<=15;cnt2++){    //Player suite generator.
            suite1=rand()%4+1;		    //Random  number-gen for selection of card suite value.
            switch(suite1){
                case 1: handSuit='S';break; //Suite case values 1-4 = card suite values.
                case 2: handSuit='D';break;
                case 3: handSuit='H';break;
                case 4: handSuit='C';break;
                default: handSuit='C';

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
        }plyrVal2=1;
//****************************************Card Selection END*********************************************************


//****************************************Small/Big Blind Selection Start********************************************

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
        case 1:if(plyr2M>=20)potM+=20;plyr2M-=20;break;
        case 2:if(plyr3M>=20)potM+=20;plyr3M-=20;break;
        case 3:if(plyr1M>=20)potM+=20;plyr1M-=20;break;
        case 4:if(plyr4M>=20)potM+=20;plyr4M-=20;break;
        case 5:if(plyr5M>=20)potM+=20;plyr5M-=20;break;
        default:potM+=20;
    }
    switch(sBbB){  //Incrementing values to have Big Blind place $40 dollars down.
        case 1:if(plyr3M>=40)potM+=40;plyr3M-=40;break;
        case 2:if(plyr1M>=40)potM+=40;plyr1M-=40;break;
        case 3:if(plyr4M>=40)potM+=40;plyr4M-=40;break;
        case 4:if(plyr5M>=40)potM+=40;plyr5M-=40;break;
        case 5:if(plyr2M>=40)potM+=40;plyr2M-=40;break;
        default:potM+=40;
    }
        dsply1='-';  //Default for table card face #4
        dsply2='-';  //Default for table card suite #4
        dsply3='-';  //Default for table card face #5
        dsply4='-';  //Default for table card suite #5
    do{
        if(rndNum>=2) dsply1=tblH4;
        if(rndNum>=2) dsply2=tblS4;
        if(rndNum>=3) dsply3=tblH5;
        if(rndNum>=3) dsply4=tblS5;
//*********************************************Small/Blind Selection END****************************************


//*********************************************Player & Table Card Display**************************************

            cout<<"Round "<<rndNum<<", get ready!"<<endl;       //Output the round number to user.
        Sleep(800); //Delay for .8 seconds

            cout<<""<<endl;
            cout<<pName<<" cards:   Money: $"<<plyr1M<<endl;    //Output Users name and Users money.
            cout<<" -----  -----"<<endl;                        //Display players cards.
            cout<<"|  "<<plyr1H1<<"  ||  "<<plyr1H2<<"  |"<<endl;
            cout<<"|  "<<plyr1S1<<"  ||  "<<plyr1S2<<"  |"<<endl;
            cout<<"|     ||     |"<<endl;
            cout<<" -----  -----"<<endl;
            cout<<"..............................."<<endl;
            cout<<""<<endl;

    Sleep(1700); //Delay next segment to user for 1.7 seconds


            cout<<"Dealer flops!      The Pot: $"<<potM<<endl;                   //Display Total bets summed.
            cout<<"----- ----- ----- ----- -----"<<endl;
            cout<<"| "<<tblH1<<" | | "<<tblH2<<" | | "<<tblH3                    //Display dealer cards to user.
            <<" | | "<<dsply1<<" | | "<<dsply3<<" |    SB: $20 = "<<smB<<endl;   //Display which player is SB.
            cout<<"| "<<tblS1<<" | | "<<tblS2<<" | | "<<tblS3
            <<" | | "<<dsply2<<" | | "<<dsply4<<" |    BB: $40 = "<<bgB<<endl;   //Display which player is BB.
            cout<<"----- ----- ----- ----- -----"<<endl;
            cout<<"...................................................."<<endl;

//*******************************************Player Betting********************************************
       plyrT=1;
       if(plyrT==1&&plyr1M>=1){     //User input for choice
                cout<<"CALL/CHECK: 1         BET: 2          FOLD: 3"<<endl;
                cout<<"Choice: ";
                cin>>op;        //User input for choice to bet, call/check, fold.
                cout<<""<<endl;

            while (op<=0||op>=4){   //User input valadation
                cout<<"Invalid choice! Choose options 1-3"<<endl;
                cout<<"CALL/CHECK: 1         BET: 2          FOLD: 3"<<endl;
                cin.clear();
                cin.ignore('\n');
                cin>>op;        //User input for choice to bet, call/check, fold.
                cout<<""<<endl;
        }   betHld=0;
            if(op==1&&plyr1M>=1){   //User option 1 = Call/Check
                if(rndNum==1)potM+=40,plyr1M+=-40;
                else cout<<"Check!"<<endl;
            }
            else if(op==2){         //User option 2 = Betting
                if(rndNum==1&&plyr1M>=1){
                  while(betHld<=40){
                        betHld=0;
                        cout<<"Enter bet more than Big Blind of $40, $";
                        cin>>betHld;
                        plyr1M-=betHld;
              }}
                else if(plyr1M>=1){  betHld=0;
                        cout<<"Enter bet $";
                        cin>>betHld;
                        plyr1M-=betHld;
                }
                else cout<<"Not Enough Money... Automatically Call."<<endl;
            }
            else if (op==3){rndNum=5;}   //User option 3 = Pass
        //if(betHld>=potAd)potAd=betHld; //Determines the highest bet so far for call/checking
            potM+=betHld;                //Mid term use - User bet added to Pot Money
        }
         rndNum++;      //Incrementing value to show how many cycles (rounds) have passed to the player.
    }while(rndNum<4);   //Number of rounds for User to Call/Bet/Fold
        cout<<"    "<<pl1<<"         "<<pl2<<"     "<<pl3<<"    "<<pl4<<"     "<<pl5<<endl;
        cout<<" -----  -----   -----  -----   -----  -----   -----  -----   -----  -----"<<endl;
        cout<<"|  "<<plyr1H1<<"  || "<<plyr1H2<<"   | |  "<<plyr2H1<<"  ||  "<<plyr2H2<<"  |  | "<<plyr3H1<<"  ||  "<<plyr3H2
                <<"  |  | "<<plyr4H1<<"  ||  "<<plyr4H2<<"  |  | "<<plyr5H1<<"  ||  "<<plyr5H2<<"  |"<<endl;
        cout<<"|  "<<plyr1S1<<"  || "<<plyr1S2<<"   | |  "<<plyr2S1<<"  ||  "<<plyr2S2<<"  |  | "<<plyr3S1<<"  ||  "<<plyr3S2
                <<"  |  | "<<plyr4S1<<"  ||  "<<plyr4S2<<"  |  | "<<plyr5S1<<"  ||  "<<plyr5S2<<"  |"<<endl;
        cout<<" -----  -----   -----  -----   -----  -----   -----  -----   -----  -----"<<endl;
    Sleep(1400);
//**********************************************BOT Point System****************************************
    plyrT++;
        if(plyrT==2&&plyr3M>=1){    //Bot 1 point system
            p2A=pointSystem1(plyr2H1,plyr2S1,plyr2S2,tblH1,tblH2,tblH3,tblH4,tblH5,tblS1,tblS2,tblS3,tblS4,tblS5); //Player hand 1 points
            p2B=pointSystem1(plyr2H2,plyr2S1,plyr2S2,tblH1,tblH2,tblH3,tblH4,tblH5,tblS1,tblS2,tblS3,tblS4,tblS5);
            if(p2A==1||p2B==1)p2=1;
            if(p2A==1&&p2B==1)p2=2;
            if(p2A==2||p2B==2)p2=2;
            if(plyr2H1==plyr2H2&&p2==2)p2=3;
            if(p2A==2&&p2B==2)p2=7;

        else if(p2A==7||p2B==7)p2=7;
        }plyrT++;
        if(plyrT==3&&plyr4M>=1){    //Bot 2 point system
            p3A=pointSystem1(plyr3H1,plyr3S1,plyr3S2,tblH1,tblH2,tblH3,tblH4,tblH5,tblS1,tblS2,tblS3,tblS4,tblS5); //Player hand 1 points
            p3B=pointSystem1(plyr3H2,plyr3S1,plyr3S2,tblH1,tblH2,tblH3,tblH4,tblH5,tblS1,tblS2,tblS3,tblS4,tblS5);
            if(p3A==1||p3B==1)p3=1;
            if(p3A==1&&p3B==1)p3=2;
            if(p3A==2||p3B==2)p3=2;
            if(plyr3H1==plyr3H2&&p3==2)p3=3;
            if(p3A==2&&p3B==2)p3=7;
        else if(p3A==7||p3B==7)p3=7;
        }plyrT++;
        if(plyrT==4&&plyr4M>=1){    //Bot 3 point system
            p4A=pointSystem1(plyr4H1,plyr4S1,plyr4S2,tblH1,tblH2,tblH3,tblH4,tblH5,tblS1,tblS2,tblS3,tblS4,tblS5); //Player hand 1 points
            p4B=pointSystem1(plyr4H2,plyr4S1,plyr4S2,tblH1,tblH2,tblH3,tblH4,tblH5,tblS1,tblS2,tblS3,tblS4,tblS5);
            if(p4A==1||p4B==1)p4=1;
            if(p4A==1&&p4B==1)p4=2;
            if(p4A==2||p4B==2)p4=2;
            if(plyr4H1==plyr4H2&&p4==2)p4=3;
            if(p4A==2&&p4B==2)p4=7;
        else if(p4A==7||p4B==7)p4=7;
        }plyrT++;
        if(plyrT==5&&plyr5M>=1){    //Bot 4 point system
            p5A=pointSystem1(plyr5H1,plyr5S1,plyr5S2,tblH1,tblH2,tblH3,tblH4,tblH5,tblS1,tblS2,tblS3,tblS4,tblS5); //Player hand 1 points
            p5B=pointSystem1(plyr5H2,plyr5S1,plyr5S2,tblH1,tblH2,tblH3,tblH4,tblH5,tblS1,tblS2,tblS3,tblS4,tblS5);
            if(p5A==1||p5B==1)p5=1;
            if(p5A==1&&p5B==1)p5=2;
            if(p5A==2||p5B==2)p5=2;
            if(plyr5H1==plyr5H2&&p5==2)p5=3;
            if(p5A==2&&p5B==2)p5=7;
        else if(p5A==7||p5B==7)p5=7;
        }plyrT++;



    //**************************Player point system*****************************************

    if(op==2||op==1){   //Allow player to get points as long as they don't fold
        p1A=pointSystem1(plyr1H1,plyr1S1,plyr1S2,tblH1,tblH2,tblH3,tblH4,tblH5,tblS1,tblS2,tblS3,tblS4,tblS5); //Player hand 1 points
        p1B=pointSystem1(plyr1H2,plyr1S2,plyr1S2,tblH1,tblH2,tblH3,tblH4,tblH5,tblS1,tblS2,tblS3,tblS4,tblS5); //Player hand 2 points
    }
        if(p1A==1||p1B==1)p1=1;
        if(p1A==1&&p1B==1)p1=2;
        if(p1A==2||p1B==2)p1=2;
        if(plyr1H1==plyr1H2&&p1==2)p1=3;
        if(p1A==2&&p1B==2)p1=7;
        else if(p1A==7||p1B==7)p1=7;
    //**************************Player point system END**************************************

    //**************************Win or Lose Round********************************************
        p1=0;
        if(p1>p2&&p1>p3&&p1>p4&&p1>p5){cout<<"You win this round!!"<<p1<<endl;plyr1M+=potM;}
        else if(p2>p1&&p2>p3&&p2>p4&&p2>p5)cout<<"Bot Erin wins!!"<<p1<<p2<<endl;
        else if(p3>p1&&p3>p2&&p3>p4&&p3>p5)cout<<"Bot Cindy wins!!"<<p1<<p3<<endl;
        else if(p4>p1&&p4>p3&&p4>p2&&p4>p5)cout<<"Bot Bob wins!!"<<p1<<p4<<endl;
        else if(p5>p1&&p5>p3&&p5>p2&&p5>p4)cout<<"Bot Nick wins!!"<<p1<<p5<<endl;
        else cout<<"Tie, sorry!"<<p1<<p2<<p3<<p4<<p5<<endl;
        cout<<""<<endl;
        cout<<"next round! ready? y/n :";
        cin>>next; //ADD BOOL HERE!!!! EXIT_FAILURE HERE

    //**************************Win orLose Round END*****************************************


        if(numPlyr>=0)numPlyr=0;//Default Number of Players to 0 so players with money is summed to determine is to cycle or end game.
        if(plyr1M>=1)numPlyr++; //START----If players have money they are added to sum.
        if(plyr2M>=1)numPlyr++;
        if(plyr3M>=1)numPlyr++;
        if(plyr4M>=1)numPlyr++;
        if(plyr5M>=1)numPlyr++; //END----If players have money they are added to sum.
        plyrT++;                //Starting player for betting
        sBbB++;                 //Incrementing value that is used to switch Small Blind and Big Blind assignment.
        if(rndNum>=3)rndNum=1;  //Restart player to new round with new cards
        if(sBbB>=5)sBbB=1;      //When Variable for incrementing Small Blind and Big Blind = 6, value is reset to 1.
    }while(plyr1M>=1);          //Midterm temporary use
    //}while(numPlyr>=2);  //If number of players with money is 2 or more then game cycles

    //win=winnerSystem(p1,p2,p3,p4,p5);

    //Display Outputs
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"The Winner is..."<<plyr1M<<endl;
    //Exit stage right
    return 0;
}
int pointSystem1(int hand,int suit1,int suit2,int tH1,int tH2,int tH3,//Scoring System.. scroll down at your own risk! its ugly!
        int tH4,int tH5,int S1,int S2,int S3,int S4,int S5){
    int p1=0,p,tw,tr,f,fl;
    p1=0;
    if(hand==tH1)p=1; //Pairs
    else if(hand==tH2)p=1;
    else if(hand==tH3)p=1;
    else if(hand==tH4)p=1;
    else if(hand==tH5)p=1;
    else p=0;

    tw=0;
    if(hand==tH1&&tH1==tH2)tw=2; //Two pair
    else if(hand==tH1&&tH1==tH3)tw=2;
    else if(hand==tH1&&tH1==tH4)tw=2;
    else if(hand==tH1&&tH1==tH5)tw=2;
    else if(hand==tH1&&tH2==tH3)tw=2;
    else if(hand==tH1&&tH2==tH4)tw=2;
    else if(hand==tH1&&tH2==tH5)tw=2;
    else if(hand==tH1&&tH3==tH4)tw=2;
    else if(hand==tH1&&tH3==tH5)tw=2;
    else if(hand==tH1&&tH4==tH5)tw=2;
    else if(hand==tH2&&tH1==tH2)tw=2; //Two pair
    else if(hand==tH2&&tH1==tH3)tw=2;
    else if(hand==tH2&&tH1==tH4)tw=2;
    else if(hand==tH2&&tH1==tH5)tw=2;
    else if(hand==tH2&&tH2==tH3)tw=2;
    else if(hand==tH2&&tH2==tH4)tw=2;
    else if(hand==tH2&&tH2==tH5)tw=2;
    else if(hand==tH2&&tH3==tH4)tw=2;
    else if(hand==tH2&&tH3==tH5)tw=2;
    else if(hand==tH2&&tH4==tH5)tw=2;
    else if(hand==tH3&&tH1==tH2)tw=2; //Two pair
    else if(hand==tH3&&tH1==tH3)tw=2;
    else if(hand==tH3&&tH1==tH4)tw=2;
    else if(hand==tH3&&tH1==tH5)tw=2;
    else if(hand==tH3&&tH2==tH3)tw=2;
    else if(hand==tH3&&tH2==tH4)tw=2;
    else if(hand==tH3&&tH2==tH5)tw=2;
    else if(hand==tH3&&tH3==tH4)tw=2;
    else if(hand==tH3&&tH3==tH5)tw=2;
    else if(hand==tH3&&tH4==tH5)tw=2;
    else if(hand==tH4&&tH1==tH2)tw=2; //Two pair
    else if(hand==tH4&&tH1==tH3)tw=2;
    else if(hand==tH4&&tH1==tH4)tw=2;
    else if(hand==tH4&&tH1==tH5)tw=2;
    else if(hand==tH4&&tH2==tH3)tw=2;
    else if(hand==tH4&&tH2==tH4)tw=2;
    else if(hand==tH4&&tH2==tH5)tw=2;
    else if(hand==tH4&&tH3==tH4)tw=2;
    else if(hand==tH4&&tH3==tH5)tw=2;
    else if(hand==tH4&&tH4==tH5)tw=2;
    else if(hand==tH5&&tH1==tH2)tw=2; //Two pair
    else if(hand==tH5&&tH1==tH3)tw=2;
    else if(hand==tH5&&tH1==tH4)tw=2;
    else if(hand==tH5&&tH1==tH5)tw=2;
    else if(hand==tH5&&tH2==tH3)tw=2;
    else if(hand==tH5&&tH2==tH4)tw=2;
    else if(hand==tH5&&tH2==tH5)tw=2;
    else if(hand==tH5&&tH3==tH4)tw=2;
    else if(hand==tH5&&tH3==tH5)tw=2;
    else if(hand==tH5&&tH4==tH5)tw=2;
    else tw=0;
/*
    if(hand==tH1&&hand==tH2)tr=3; //Three of a kind
    if(hand==tH1&&hand==tH3)tr=3;
    if(hand==tH1&&hand==tH4)tr=3;
    if(hand==tH1&&hand==tH5)tr=3;
    if(hand==tH2&&hand==tH3)tr=3;
    if(hand==tH2&&hand==tH4)tr=3;
    if(hand==tH2&&hand==tH5)tr=3;
    if(hand==tH3&&hand==tH4)tr=3;
    if(hand==tH3&&hand==tH5)tr=3;
    if(hand==tH4&&hand==tH5)tr=3;
    if(hand==tH4&&hand==tH5)tr=3;

    if(hand==tH1&&hand==tH2&&hand==tH3)f=7; //Four of a kind
    if(hand==tH1&&hand==tH2&&hand==tH4)f=7;
    if(hand==tH1&&hand==tH2&&hand==tH5)f=7;
    if(hand==tH1&&hand==tH3&&hand==tH4)f=7;
    if(hand==tH1&&hand==tH3&&hand==tH5)f=7;
    if(hand==tH1&&hand==tH4&&hand==tH5)f=7;

    if(suit1==S1&&suit1==S2&&suit1==S3&&suit1==S4)fl=5; //Flush
    if(suit1==S2&&suit1==S3&&suit1==S4&&suit1==S5)fl=5;
    if(suit1==S3&&suit1==S4&&suit1==S5&&suit1==S1)fl=5;
    if(suit1==S4&&suit1==S5&&suit1==S1&&suit1==S2)fl=5;
    if(suit1==S5&&suit1==S1&&suit1==S2&&suit1==S3)fl=5;

    if(suit1==suit2&&suit1==S1&&suit1==S2&&suit1==S3)fl=5; //Flush
    if(suit1==suit2&&suit1==S1&&suit1==S3&&suit1==S4)fl=5;
    if(suit1==suit2&&suit1==S1&&suit1==S4&&suit1==S5)fl=5;
    if(suit1==suit2&&suit1==S2&&suit1==S1&&suit1==S3)fl=5;
    if(suit1==suit2&&suit1==S2&&suit1==S3&&suit1==S4)fl=5;
    if(suit1==suit2&&suit1==S2&&suit1==S4&&suit1==S5)fl=5;
    if(suit1==suit2&&suit1==S2&&suit1==S5&&suit1==S1)fl+=5;

    if(suit1==suit2&&suit1==S3&&suit1==S1&&suit1==S2)fl=5;
    if(suit1==suit2&&suit1==S3&&suit1==S1&&suit1==S4)fl=5;
    if(suit1==suit2&&suit1==S3&&suit1==S1&&suit1==S5)fl=5;
    if(suit1==suit2&&suit1==S3&&suit1==S2&&suit1==S4)fl=5;
    if(suit1==suit2&&suit1==S3&&suit1==S2&&suit1==S5)fl=5;
    if(suit1==suit2&&suit1==S3&&suit1==S4&&suit1==S1)fl=5;

    if(suit1==suit2&&suit1==S4&&suit1==S1&&suit1==S2)fl=5;
    if(suit1==suit2&&suit1==S4&&suit1==S1&&suit1==S3)fl=5;
    if(suit1==suit2&&suit1==S4&&suit1==S1&&suit1==S5)fl=5;
    if(suit1==suit2&&suit1==S4&&suit1==S2&&suit1==S3)fl=5;
    if(suit1==suit2&&suit1==S4&&suit1==S2&&suit1==S5)fl=5;
    if(suit1==suit2&&suit1==S4&&suit1==S3&&suit1==S1)fl=5;

    if(suit1==suit2&&suit1==S5&&suit1==S1&&suit1==S2)fl=5;
    if(suit1==suit2&&suit1==S5&&suit1==S1&&suit1==S4)fl=5;
    if(suit1==suit2&&suit1==S5&&suit1==S1&&suit1==S3)fl=5;
    if(suit1==suit2&&suit1==S5&&suit1==S2&&suit1==S4)fl=5;
    if(suit1==suit2&&suit1==S5&&suit1==S2&&suit1==S3)fl=5;
    if(suit1==suit2&&suit1==S5&&suit1==S4&&suit1==S1)fl=5;
*/
//*****************************Which is larger and return*****************************************
    if(p>tw)p1=p;
    if(tw>p)p1=tw;
   /* else if(tr>tw&&tr>p&&tr>f&&tr>fl)p1=tr;
    else if(f>tw&&f>tr&&f>p&&f>fl)p1=f;
    else p=fl; */
        //p1=p;
    return p1;
}
