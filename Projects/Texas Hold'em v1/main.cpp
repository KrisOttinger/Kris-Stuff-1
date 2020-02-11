//Kris Ottinger
//Texas Hold'em
//01/23/2020 8:20 PM

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
    short int plyr1=1,plyr2=2,plyr3=3,plyr4=4,plyr5=5,rndNum=1;
    short int hand1,suite1,plyrVal1=1,plyrVal2=1; //Random number generator value determiner hand/suite
    char plyr1H1=0,plyr2H1=0,plyr3H1,plyr4H1,plyr5H1; //Players hand 1
    char plyr1H2,plyr2H2,plyr3H2,plyr4H2,plyr5H2; //Players hand 2
    char plyr1S1=0,plyr2S1=0,plyr3S1,plyr4S1,plyr5S1; //Players hand 1 suite
    char plyr1S2,plyr2S2,plyr3S2,plyr4S2,plyr5S2; //Players hand 2 suite
    char handSuit, handVal; //hand card generator variables
    char tblS1,tblS2,tblS3,tblS4,tblS5,tblH1,tblH2,tblH3,tblH4,tblH5; //Table cards shown
    string pName, smB, bgB,pl1, pl2, pl3, pl4, pl5;
    unsigned int plyr1M=500,plyr2M=500,plyr3M=500,plyr4M=500,plyr5M=500,potM=0;
    unsigned int numPlyr=0,op,sBbB=1;

    srand(static_cast<int>(time(0)));


        cout<<"***** ****  *   * *****   *  *  ***  *    ***     **** **   **  \n";
        cout<<"  *   *      * *    *     *  * *   * *    *  *    *    * * * *  \n";
        cout<<"  *   ***     *     *     **** *   * *    *   *   ***  *  *  *  \n";
        cout<<"  *   *      * *    *     *  * *   * *    *  *    *    *     *  \n";
        cout<<"  *   ****  *   *   *     *  *  ***  **** ***     **** *     *  \n";
        cout<<"...............................................................\n";
        cout<<""<<endl;
        cout<<"Please type your name: ";
        cin>>pName;
        cout<<"Alright "<<pName<<" lets play Texas Hold'em."<<endl;
        cout<<""<<endl;

        pl1=pName;
        pl2="bot-Erin";
        pl3="bot-Cindy";
        pl4="bot-Bob";
        pl5="bot-Nick";

      do{
        cout<<"Round "<<rndNum<<", get ready!"<<endl;
    Sleep(2600);

        for(int cnt1=0;cnt1<=14;cnt1++){      //Player card generator
            hand1=rand()%14+1;
            switch(hand1){
                case 1: handVal='2';break;
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
                default: handVal='5';
            }switch(plyrVal1){               //Card to hand assignment
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
                default:plyr1H1=handVal;
                }
            plyrVal1++;
        }
        for(int cnt2=0;cnt2<=14;cnt2++){      //Player suite generator
            suite1=rand()%5+1;
            switch(suite1){
                case 1: handSuit='S';break;
                case 2: handSuit='D';break;
                case 3: handSuit='H';break;
                case 4: handSuit='C';break;
                default:handSuit='S';
            }switch(plyrVal2){              //suite to card assignment
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
                default:plyr1S1=handSuit;
                }
            plyrVal2++;
        }

        cout<<""<<endl;
        cout<<pName<<" cards:   Money: $"<<plyr1M<<endl;
        cout<<" -----  -----"<<endl;
        cout<<"|  "<<plyr1H1<<"  ||  "
        <<plyr1H2<<"  |"<<endl;
        cout<<"|  "<<plyr1S1<<"  ||  "
        <<plyr1S2<<"  |"<<endl;
        cout<<"|     ||     |"<<endl;
        cout<<" -----  -----"<<endl;
        cout<<"......................."<<endl;
    Sleep(1800);
    switch(sBbB){
        case 1:smB=pl2;break;
        case 2:smB=pl3;break;
        case 3:smB=pl1;break;
        case 4:smB=pl4;break;
        case 5:smB=pl5;break;
        }
    switch(sBbB){
        case 1:bgB=pl3;break;
        case 2:bgB=pl1;break;
        case 3:bgB=pl4;break;
        case 4:bgB=pl5;break;
        case 5:bgB=pl2;break;
    }
    switch(sBbB){
        case 1:if(plyr2M>=20)potM+=20;break;
        case 2:if(plyr3M>=20)potM+=20;break;
        case 3:if(plyr1M>=20)potM+=20;break;
        case 4:if(plyr4M>=20)potM+=20;break;
        case 5:if(plyr5M>=20)potM+=20;break;
    }
    switch(sBbB){
        case 1:if(plyr3M>=40)potM+=40;break;
        case 2:if(plyr1M>=40)potM+=40;break;
        case 3:if(plyr4M>=40)potM+=40;break;
        case 4:if(plyr5M>=40)potM+=40;break;
        case 5:if(plyr2M>=40)potM+=40;break;
    }

            cout<<"Dealer flops!             The Pot: $"<<potM<<endl;
            cout<<"----- ----- ----- ----- -----"<<endl;
            cout<<"| "<<tblH1<<" | | "<<tblH2<<" | | "<<tblH3
            <<" | | "<<tblH4<<" | | "<<tblH5<<" |    SB: $20 = "<<smB<<endl;
            cout<<"| "<<tblS1<<" | | "<<tblS2<<" | | "<<tblS3
            <<" | | "<<tblS4<<" | | "<<tblS5<<" |    BB: $40 = "<<bgB<<endl;
            cout<<"----- ----- ----- ----- -----"<<endl;
            cin>>op;


        sBbB++;
        rndNum++;
        numPlyr=0;
        if(plyr1M>=1)numPlyr++;
        if(plyr2M>=1)numPlyr++;
        if(plyr3M>=1)numPlyr++;
        if(plyr4M>=1)numPlyr++;
        if(plyr5M>=1)numPlyr++;
        if(sBbB>=6)sBbB=1;
    }while(numPlyr>=2);

    return 0;
}
