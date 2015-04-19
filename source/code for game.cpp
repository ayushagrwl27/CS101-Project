#include<simplecpp>
#include<ctime>
#include<string>
#include<fstream>
#include<iostream>
#include"adavancd.h"

using namespace std;

string company(int i)
{
    if(i==0)
        return "HIND LEVER  ";
    else if (i==1)
        return "ITC         ";
    else if (i==2)
        return "TISCO       ";
    else if (i==3)
        return "MARUTI      ";
    else if (i==4)
        return "SBI         ";
    else if (i==5)
        return "RELIANCE    ";
}
//assigned a number to each company.
class p
{
public:
    char name[100];
    int company_name;


    long double array[6][12]= {{-1,-0.5,0.5,1,-1,-0.5,0.5,1,-1,-0.5,0.5,1},{-1.5,-1,-0.5,0.5,1,1.5,-1.5,-1,-0.5,0.5,1,1.5},{-1.5,-1,-0.5,0.5,1,1.5,-1.5,-1,-0.5,0.5,1,1.5},{-2,-1.5,-1,-0.5,0.5,1,1.5,2,-2,-1,1,2},{-2.5,-2,-1.5,-1,-0.5,0.5,1,1.5,2,2.5,-2,2},{-3,-2.5,-2,-1.5,-1,-0.5,0.5,1,1.5,2,2.5,3}}; //2-D array containing price fluctuations a particular company can have.

    int random_row, random_column;//for above 2-D array.
    double array2[10];//will contain the fluctuation value of the ten cards distributed to player 2.
    double net_fluctuation[6];
    int array_company[10];//will contain knowledge of the name of company the corresponding fluctuation in price is.


    unsigned int shares[6];//will contain number of shares player1 has of each company.
    int max_shares[6];
    int max_shares_inHun[6];
    unsigned int cash;
    unsigned long int ShareProperty;
    unsigned long int NetProperty;
    int amount;
    p()
    {


        shares[6]= {0};
        cash=6000;
        ShareProperty=0;


    }
    void WhichCompany()
    {
        cout<<"\nWhich company?"<<endl<<endl;

        for (int i=0; i<6; i++)
        {
            cout<<"For "<<company(i)<<" press "<<i<<endl;
        }


        b:cin>>company_name;
        if(company_name>=0 && company_name<6) ;
        else
        {
            cout<<"INVALID INPUT.  Please enter again  "<<endl;
            goto b;
        }
    }
    void amountf()
    {
        cout<<"\nHow much?  (Maximum you can buy is: "<<max_shares_inHun[company_name]<<" )"<<endl;
        cin>>amount;

    }
    void amountf1()
    {
        cout<<"\nHow much?  (Maximum you can sell is: "<<shares[company_name]<<" )"<<endl;
        cin>>amount;

    }

    void calc_NetProperty()
    {
        NetProperty= cash+ShareProperty;


    }

    void getName()
    {
        cout<<"\n Enter your name : ";
        gets(name);

    }

};
p player[2];
//p[0]&p[1] all info;
int char_int(char a[])
    {int n=0;
      for(int i=0;i<strlen(a);i++)

         n=n*10+a[i]-48;


     return n;



    }



main_program
{

    initCanvas("Stock Exchange Xtravaganza",1400,700);

    Rectangle ra(685,350,1300,650);
    ra.setColor(COLOR("red"));

    Rectangle rb(685,350,1325,675);
    rb.setColor(COLOR("red"));

    Text t1(700,100,"Stock Exchange Xtravaganza");
    t1.setColor(COLOR("blue"));

    Text t2(700,250,"Saved Game");
    t2.setColor(COLOR("blue"));

    Rectangle r2(700,250,150,50);
    r2.setColor(COLOR("red"));

    Text t3(700,325,"New Game");
    t3.setColor(COLOR("blue"));

    Rectangle r3(700,325,150,50);
    r3.setColor(COLOR("red"));

    Text t4(700,400,"Instructions");
    t4.setColor(COLOR("blue"));

    Rectangle r4(700,400,150,50);
    r4.setColor(COLOR("red"));

    Text t5(700,475,"High Scores");
    t5.setColor(COLOR("blue"));

    Rectangle r5(700,475,150,50);
    r5.setColor(COLOR("red"));

    Text t6(700,550,"Exit");
    t6.setColor(COLOR("blue"));

    Rectangle r6(700,550,150,50);
    r6.setColor(COLOR("red"));
    x:
    int x,y;
    int f=getClick();
    //Canvas();
    x=f/65536;
    y=f%65536;

    if (x<=775 && x>=625 && y<=275 && y>=225)
    {
        t1.hide();
        ra.hide();
        rb.hide();
        t2.hide();
        t3.hide();
        t4.hide();
        t5.hide();
        t6.hide();
        r2.hide();
        r3.hide();
        r4.hide();
        r5.hide();
        r6.hide();//further options
    }
    else if (x<=775 && x>=625 && y<=350 && y>=300)
    {
        t1.hide();
        ra.hide();
        rb.hide();
        t2.hide();
        t3.hide();
        t4.hide();
        t5.hide();
        t6.hide();
        r2.hide();
        r3.hide();
        r4.hide();
        r5.hide();
        r6.hide();//further options

    Text basicversion(350,350," Basic Version ");

    Rectangle roundR(350,350,300,30);

    Text advancedversion(950,350," Advanced Version ");

    Rectangle roundR2(950,350,300,30);

b:
    int ClickPos=getClick();
    int x=ClickPos/65536,y=ClickPos%65536;
    if(x>=200 && x<=500 && y>=335&& y<=365)
    {
    basicversion.hide();
    roundR.hide();
    advancedversion.hide();
    roundR2.hide();
    }
    else if(x>=800 && x<=1100 && y>=335 && y<=365)
    {

    basicversion.hide();
    roundR.hide();
    advancedversion.hide();
    roundR2.hide();
    advanced();
    }
    else goto b;
    }
    else if (x<=775 && x>=625 && y<=425 && y>=375)
    {
        t1.hide();
        ra.hide();
        rb.hide();
        t2.hide();
        t3.hide();
        t4.hide();
        t5.hide();
        t6.hide();
        r2.hide();
        r3.hide();
        r4.hide();
        r5.hide();
        r6.hide();

        Text instruct(65,10,"Rules of the game:");

        Text instruct1(673,30,"To become rich. Decide in advance number of bargain rounds to be played. One bargain round will have three transactions per player. The winner is one who has maximum net property at the end of the game.");

        Text instruct2(60,70,"To begin with:");
        Text instruct3(673,90,"Each player is given Rs.6000 as cash and 10 cards. During every bargain round, each player should start a bargain round, because the person who transacts last during a bargain round has an advantage of");
        Text ins23(150,110,"seeing how all the other players traded.");
        Text ins4(30,150,"Start:");
        Text ins5(450,170,"The cards given display price fluctuation for each of six companies. Some denote fluctuation in rupee value while some are windfall cards. ");

        Text ins6(70,210,"To purchase shares:");
        Text ins7(200,230,"When chance comes, select ‘b’ and answer the details asked.");

        Text ins8(60,270,"To sell shares:");
        Text ins9(200,290,"When chance comes, select ‘s’ and answer the details asked.");

        Text ins10(50,330,"Windfall cards:");
        Text ins11(640,350,"Share Suspended: Once all the cards have been revealed at the end of a bargain round, play this card to avoid making a big loss or prevent other player to make a big gain. CANNOT BE RETAINED.");
        Text ins12(420,370,"Loan Stock: Claim Rs.1000. This card is played as a transaction in the bargain round in which it is dealt. CANNOT BE RETAINED.");
        Text ins13(630,390,"Debenture: This card can be used if you have shares in company and that company goes bankrupt. It allows you to redeem shares at the opening price of those shares. CANNOT BE RETAINED.");

        wait(500);


    }
    else if (x<=775 && x>=625 && y<=500 && y>=450)
    {
        t1.hide();
        ra.hide();
        rb.hide();
        t2.hide();
        t3.hide();
        t4.hide();
        t5.hide();
        t6.hide();
        r2.hide();
        r3.hide();
        r4.hide();
        r5.hide();
        r6.hide();//further options
    }
    else if (x<=775 && x>=625 && y<=575 && y>=525)
    {
        t1.hide();
        ra.hide();
        rb.hide();
        t2.hide();
        t3.hide();
        t4.hide();
        t5.hide();
        t6.hide();
        r2.hide();
        r3.hide();
        r4.hide();
        r5.hide();
        r6.hide();//further options
    }
    else if(x>=550 && x<=850 && y>=200 && y<=300)
    {
        t1.hide();
        ra.hide();
        rb.hide();
        t2.hide();
        t3.hide();
        t4.hide();
        t5.hide();
        t6.hide();
        r2.hide();
        r3.hide();
        r4.hide();
        r5.hide();
        r6.hide();
        fstream file;
        file.open("save",ios::binary|ios::in|ios::out);
        for(int i=0; i<2; i++)
            file.read((char*)&player[i],sizeof(p));




    }
    else goto x;

    double price_per_share [6]={2,2.5,4,5.5,7.5,8};//value of shares of each company.

    long double array[6][12]={{-1,-0.5,0.5,1,-1,-0.5,0.5,1,-1,-0.5,0.5,1},{-1.5,-1,-0.5,0.5,1,1.5,-1.5,-1,-0.5,0.5,1,1.5},{-1.5,-1,-0.5,0.5,1,1.5,-1.5,-1,-0.5,0.5,1,1.5},{-2,-1.5,-1,-0.5,0.5,1,1.5,2,-2,-1,1,2},{-2.5,-2,-1.5,-1,-0.5,0.5,1,1.5,2,2.5,-2,2},{-3,-2.5,-2,-1.5,-1,-0.5,0.5,1,1.5,2,2.5,3}};//2-D array containing price fluctuations a particular company can have.
    srand(time(0));
    int j=0;//used for creating next round chart table.
    int number=1;//used for first round rotation.
    char c;//used against the output "Enter any key".

    //cout<<"\nEnter name of player 1: ";
    player[0].getName();//Defines the name of player1.

    //cout<<"\nEnter name of player 2: ";
    player[1].getName();//defines the name of player 2.
    int NumberOfRounds;
    char a[100];
    cout<<"\nHow many rounds do you want to play? (Maximum you can play is 10 rounds)"<<endl;
    cin>>a;//defines number of rounds to be played.
    NumberOfRounds=char_int(a);
    while(!(NumberOfRounds<=10&&NumberOfRounds>0))
    {
        cout<<"Invalid input.\nPlease enter again."<<endl;
        cin>>NumberOfRounds;

    }//checks that no. of rounds entered is valid.

    for(int round_number=0; round_number<NumberOfRounds; round_number++)
    {

        Text round(50,50," Round ");
        round.imprint();

        Rectangle roundR(50,50,100,textHeight()+5);
        roundR.imprint();

        for(int i=0; i<6; i++)
        {

            Text company_list(150+100*i,50,company(i));
            company_list.imprint();

            Rectangle companyR(150+100*i,50,100,textHeight()+5);
            companyR.imprint();
        }//displays each company's name in the table.

        for(int i=0; i<7; i++)
        {

            Rectangle r(50+100*(i),50+((textHeight()+5)*(j+1)),100,textHeight());
            r.imprint();

            Text round_no(50,50+((textHeight()+5)*(j+1)),j+1);
            round_no.imprint();
        }

        for(int i=0; i<6; i++)
        {

            Text round1(50+100*(i+1),50+((textHeight()+5)*(j+1)),price_per_share[i]);
            round1.imprint();
        }//creates table for a particular round.

        Line l(650,300,650,700);
        l.imprint();//line for separating display area of player 1 and player 2.

        Text Player1(350,650,player[0].name);
        Player1.imprint();

        Text Player2 (1050,650,player[1].name);
        Player2.imprint();

        Text Player(250,650,"Player 1: ");
        Player.imprint();

        Text Player_(950,650,"Player 2: ");
        Player_.imprint();//prints the name of the players.

        Text SharesYouHave(1200,300,"Shares  you have of: " );
        SharesYouHave.imprint();

        Text SharesYouHaveB(500,300,"Shares  you have of: " );
        SharesYouHaveB.imprint();

        for(int i=0; i<6; i++)
        {

            Text shares_company(1200,330+15*i,company(i));
            shares_company.imprint();

            Text shares_companyB(500,330+15*i,company(i));
            shares_companyB.imprint();
        }

        Text shares_value_0(1300,330+15*0,player[1].shares[0]);
        Text shares_value_1(1300,330+15*1,player[1].shares[1]);
        Text shares_value_2(1300,330+15*2,player[1].shares[2]);
        Text shares_value_3(1300,330+15*3,player[1].shares[3]);
        Text shares_value_4(1300,330+15*4,player[1].shares[4]);
        Text shares_value_5(1300,330+15*5,player[1].shares[5]);//displays shares player 2 has of each company.

        Text shares_value_0B(600,330+15*0,player[0].shares[0]);
        Text shares_value_1B(600,330+15*1,player[0].shares[1]);
        Text shares_value_2B(600,330+15*2,player[0].shares[2]);
        Text shares_value_3B(600,330+15*3,player[0].shares[3]);
        Text shares_value_4B(600,330+15*4,player[0].shares[4]);
        Text shares_value_5B(600,330+15*5,player[0].shares[5]);//displays shares player 1 has of each company.

        Text CashInHand(850,550,"Cash in Hand: ");
        CashInHand.imprint();

        Text CashInHandB(150,550,"Cash in Hand: ");
        CashInHandB.imprint();


        Text cash_value(850,570,player[1].cash);//displays cash in hand of player 2.
        Text cash_valueB(150,570,player[0].cash);
        Rectangle cashR(850,560,textWidth("  Cash in Hand:   "),((2*textHeight())+10));
        cashR.imprint();

        Rectangle cashRB(150,560,textWidth("  Cash in Hand:   "),((2*textHeight())+10));
        cashRB.imprint();

        Text NetProp(1050,550,"Net Property (in cash)");
        NetProp.imprint();

        Text NetPropB(350,550,"Net Property (in cash)");
        NetPropB.imprint();

        Rectangle NetPropR(1050,560,textWidth("  Net Property (in cash)  "),((2*textHeight())+10));
        NetPropR.imprint();

        Rectangle NetPropRB(350,560,textWidth("  Net Property (in cash)  "),((2*textHeight())+10));
        NetPropRB.imprint();

        player[1].calc_NetProperty();
        player[0].calc_NetProperty();
        Text Net_prop_value(1050,570,player[1].NetProperty);//displays net property of player 2.
        Text Net_prop_valueB(350,570,player[0].NetProperty);
        if(round_number==NumberOfRounds-1)
        {
            break;
        }//no trade is made with the prices of last round. it is only displayed to calculate final net property of both players.

        Text cards_display(800,300,"Your cards are displayed below: ");
        cards_display.imprint();

        Text cards_displayB(110,300,"Your cards are displayed below: ");
        cards_displayB.imprint();

        Text title(800,305+textHeight(),"  Company       Price Fluctuation ");
        title.imprint();

        Text titleB(100,305+textHeight(),"  Company       Price Fluctuation ");
        titleB.imprint();

        for(int i=0; i<10; i++)
        {
            for (int j=0; j<2; j++)
            {
                player[j].random_row=randuv(0,6);//selects a random company.
                player[j].random_column=randuv(0,12);//selects a random price fluctuation.



                player[j].array2[i]=array[player[j].random_row][player[j].random_column];
                player[j].array_company[i]=player[j].random_row;
            }
        }
        for(int j=0; j<6; j++)
        {
            for(int i=0; i<10; i++)
            {
                for(int k=0; k<2; k++)
                {
                    if(player[k].array_company[i]==j)
                    {
                        player[k].net_fluctuation[j]+=player[k].array2[i];
                    }
                }
            }
        }

        Text net(1000,300,"As per your cards ");
        net.imprint();

        Text netB(300,300,"As per your cards ");
        netB.imprint();

        Text net2(1000,330,"Net price fluctuation of: ");
        net2.imprint();

        Text net2B(300,330,"Net price fluctuation of: ");
        net2B.imprint();

        for(int i=0; i<6; i++)
        {

            Text netC(1000,345+15*i,company(i));
            netC.imprint();

            Text netCB(300,345+15*i,company(i));
            netCB.imprint();
        }//Name of the six companies displayed.

        for(int chance=1; chance<4; chance++)
        {

            if(number%2!=0)
            {
                break;
            }

            // int max_shares[6];//contains information of max shares that can be bought.
            //int max_sharesB[6];//take in class
            //int max_shares_inThou[6];
            //int max_shares_inThouB[6];//contains information of max shares (in multiples of thousands) that can be bought.

            for(int i=0; i<6; i++)
            {
                for(int j=0; j<2; j++)
                {
                    player[j].max_shares[i]=player[j].cash/price_per_share[i];//one more loop...........player[j].maxshares[i]
                    player[j].max_shares_inHun[i]=player[j].max_shares[i]-(player[j].max_shares[i]%100);
                }
                //max_sharesB[i]=cashB/price_per_share[i];
                // max_shares_inThouB[i]=max_sharesB[i]-(max_sharesB[i]%100);
            }

            Text card_0(750,325+15*1,company(player[1].array_company[0]));
            Text card_1(750,325+15*2,company(player[1].array_company[1]));
            Text card_2(750,325+15*3,company(player[1].array_company[2]));
            Text card_3(750,325+15*4,company(player[1].array_company[3]));
            Text card_4(750,325+15*5,company(player[1].array_company[4]));
            Text card_5(750,325+15*6,company(player[1].array_company[5]));
            Text card_6(750,325+15*7,company(player[1].array_company[6]));
            Text card_7(750,325+15*8,company(player[1].array_company[7]));
            Text card_8(750,325+15*9,company(player[1].array_company[8]));
            Text card_9(750,325+15*10,company(player[1].array_company[9]));//name of companies on the 10 cards displayed.

            Text p_0(810,325+15*1,player[1].array2[0]);
            Text p_1(810,325+15*2,player[1].array2[1]);
            Text p_2(810,325+15*3,player[1].array2[2]);
            Text p_3(810,325+15*4,player[1].array2[3]);
            Text p_4(810,325+15*5,player[1].array2[4]);
            Text p_5(810,325+15*6,player[1].array2[5]);
            Text p_6(810,325+15*7,player[1].array2[6]);
            Text p_7(810,325+15*8,player[1].array2[7]);
            Text p_8(810,325+15*9,player[1].array2[8]);
            Text p_9(810,325+15*10,player[1].array2[9]);//price fluctuations on the 10 cards displayed.

            Text netP_0(1060,345+15*0,player[1].net_fluctuation[0]);
            Text netP_1(1060,345+15*1,player[1].net_fluctuation[1]);
            Text netP_2(1060,345+15*2,player[1].net_fluctuation[2]);
            Text netP_3(1060,345+15*3,player[1].net_fluctuation[3]);
            Text netP_4(1060,345+15*4,player[1].net_fluctuation[4]);
            Text netP_5(1060,345+15*5,player[1].net_fluctuation[5]);//net fluctuation against each company displayed.

            card_0.show();
            card_1.show();
            card_2.show();
            card_3.show();
            card_4.show();
            card_5.show();
            card_6.show();
            card_7.show();
            card_8.show();
            card_9.show();

            p_0.show();
            p_1.show();
            p_2.show();
            p_3.show();
            p_4.show();
            p_5.show();
            p_6.show();
            p_7.show();
            p_8.show();
            p_9.show();

            netP_0.show();
            netP_1.show();
            netP_2.show();
            netP_3.show();
            netP_4.show();
            netP_5.show();

            char select;
            cout<<"\nChance "<<chance<<": "<<player[1].name<<", what do want to do: buy(b)/sell(s)/pass(p)?";
            cin>>select;

            while(select=='b' && price_per_share[0]*100>player[1].cash && price_per_share[1]*100>player[1].cash && price_per_share[2]*100>player[1].cash && price_per_share[3]*100>player[1].cash && price_per_share[4]*100>player[1].cash && price_per_share[5]*100>player[1].cash)
            {
                cout<<"\nYou do not have enough cash to buy any company";
                cout<<"\nChance "<<chance<<": "<<player[1].name<<", what do want to do: buy(b)/sell(s)/pass(p)?";//puts(p[1].name)
                cin>>select;
            }
            while(select=='s' && player[1].shares[0]==0 && player[1].shares[1]==0 && player[1].shares[2]==0 && player[1].shares[3]==0 && player[1].shares[4]==0 && player[1].shares[5]==0)
            {
                cout<<"You do not have any shares to sell!";
                cout<<"\nChance "<<chance<<": "<<player[1].name<<", what do want to do: buy(b)/sell(s)/pass(p)?";
                cin>>select;
            }
            if(select=='b')
            {
                player[1].WhichCompany();

                //  int WhichCompany;
                //cout<<"\nWhich company?"<<endl<<endl;

                //for (int i=0;i<6;i++){
                //  cout<<"For "<<company(i)<<" press "<<i<<endl;
                //  }

                //b:cin>>WhichCompany;
                //if(WhichCompany>=0 && WhichCompany<6)
                //return(WhichCompany);
                //else goto b;
                while(price_per_share[player[1].company_name]<=0 || price_per_share[player[1].company_name]*100>player[1].cash)
                {

                    if(price_per_share[player[1].company_name]<=0)
                    {

                        cout<<"\nYou cannot buy shares of a bankrupt company!";
                        //cout<<"\nEnter another company"<<endl;
                        player[1].WhichCompany();
                    }//checks that company to be bought is not bankrupt.

                    else if(price_per_share[player[1].company_name]*100>player[1].cash)
                    {
                        cout<<"\nYou do not have enough cash to buy this company !";
                        // cout<<"\nEnter another company"<<endl;
                        player[1].WhichCompany();
                    }
                }

                //  int amount;
                // cout<<"\nHow much?  (Maximum you can buy is: "<<max_shares_inThou[WhichCompany]<<" )"<<endl;//class
                //cin>>amount;
                player[1].amountf();
                while(player[1].amount*price_per_share[player[1].company_name]>player[1].cash || (player[1].amount+player[1].shares[player[1].company_name]+player[0].shares[player[1].company_name])>20000 || player[1].amount%100!=0 )
                {

                    if(player[1].amount*price_per_share[player[1].company_name]>player[1].cash)
                    {

                        cout<<"\nNot enough cash! Enter according to max. shares you can buy.";
                        //cout<<"\nHow much?  (Maximum you can buy is: "<<player[1].max_shares_inHun[player[1].company_name]<<" )"<<endl;
                        player[1].amountf();
                    }//checks that player has sufficient cash to buy required amount of shares.

                    else if(player[1].amount+player[1].shares[player[1].company_name]+player[0].shares[player[0].company_name]>20000)
                    {

                        cout<<"\nTotal shares for each company cannot exceed more than 20000";
                        // cout<<"\nEnter again."<<endl;
                        //cin>>amount;
                        player[1].amountf();
                    }

                    else if(player[1].amount%100!=0)
                    {
                        cout<<"\nPlease enter number of shares in multiples of hundred only.";
                        // cout<<"\nHow much?  (Maximum you can buy is: "<<player[1].max_shares_inHun[WhichCompany()]<<" )"<<endl;
                        //cin>>amount;
                        player[1].amountf();
                    }
                }

                player[1].shares[player[1].company_name]=player[1].shares[player[1].company_name]+player[1].amount;
                player[1].cash=player[1].cash-(player[1].amount*price_per_share[player[1].company_name]);

                cash_value.reset(850,570,player[1].cash);

                shares_value_0.reset(1300,330+15*0,player[1].shares[0]);
                shares_value_1.reset(1300,330+15*1,player[1].shares[1]);
                shares_value_2.reset(1300,330+15*2,player[1].shares[2]);
                shares_value_3.reset(1300,330+15*3,player[1].shares[3]);
                shares_value_4.reset(1300,330+15*4,player[1].shares[4]);
                shares_value_5.reset(1300,330+15*5,player[1].shares[5]);//updates the changed number of shares of each company that player has.
            }

            if(select=='s')
            {

                //int WhichCompany;
                //cout<<"\nWhich company?"<<endl<<endl;

                // for (int i=0;i<6;i++){
                //    cout<<"For "<<company(i)<<" press "<<i<<endl;
                //}

//                cin>>WhichCompany;
                player[1].WhichCompany();
                while(price_per_share[player[1].company_name]<=0 || player[1].shares[player[1].company_name]==0)
                {

                    if(price_per_share[player[1].company_name]<=0)
                    {

                        cout<<"\nYou cannot sell shares of a bankrupt company!";
                        //cout<<"\nEnter another company"<<endl;
                        //cin>>WhichCompany;
                        player[1].WhichCompany();
                    }
                    else if(player[1].shares[player[1].company_name]==0)
                    {
                        cout<<"\nYou do not have any shares of this company to sell!";
                        //       cout<<"\nEnter another company"<<endl;
                        //     cin>>WhichCompany;
                        player[1].WhichCompany();
                    }
                }
                //checks that company to be sold is not bankrupt.

                //int amount;
                // cout<<"\nHow much?  (Maximum you can sell is: "<<shares[WhichCompany]<<" )"<<endl;
                //cin>>amount;
                player[1].amountf1();
                while(player[1].amount>player[1].shares[ player[1].company_name] || player[1].amount%100!=0)
                {

                    if(player[1].amount>player[1].shares[player[1].company_name])
                    {
                        cout<<"You cannot sell more than what you own! Enter again according to max. shares you can sell.";
                        // cout<<"\nHow much?  (Maximum you can sell is: "<<shares[WhichCompany]<<" )"<<endl;
                        //cin>>amount;
                        player[1].amountf1();
                    }

                    else if(player[1].amount%100!=0)
                    {
                        //cout<<"\nPlease enter number of shares in multiples of hundred only.";
                        //cout<<"\nHow much?  (Maximum you can sell is: "<<shares[WhichCompany]<<" )"<<endl;
                        //cin>>amount;
                        player[1].amountf1();

                    }
                }

                player[1].shares[player[1].company_name]=player[1].shares[player[1].company_name]-player[1].amount;
                player[1].cash=player[1].cash+(player[1].amount*price_per_share[player[1].company_name]);

                cash_value.reset(850,570,player[1].cash);

                shares_value_0.reset(1300,330+15*0,player[1].shares[0]);
                shares_value_1.reset(1300,330+15*1,player[1].shares[1]);
                shares_value_2.reset(1300,330+15*2,player[1].shares[2]);
                shares_value_3.reset(1300,330+15*3,player[1].shares[3]);
                shares_value_4.reset(1300,330+15*4,player[1].shares[4]);
                shares_value_5.reset(1300,330+15*5,player[1].shares[5]);//updates the changed number of shares of each company that player owns.
            }

            card_0.hide();
            card_1.hide();
            card_2.hide();
            card_3.hide();
            card_4.hide();
            card_5.hide();
            card_6.hide();
            card_7.hide();
            card_8.hide();
            card_9.hide();

            p_0.hide();
            p_1.hide();
            p_2.hide();
            p_3.hide();
            p_4.hide();
            p_5.hide();
            p_6.hide();
            p_7.hide();
            p_8.hide();
            p_9.hide();

            netP_0.hide();
            netP_1.hide();
            netP_2.hide();
            netP_3.hide();
            netP_4.hide();
            netP_5.hide();

            cout<<"\nPass the computer to "<<player[0].name<<"\nPress any key"<<endl;
            cin>>c;

            Text card_0B(50,325+15*1,company(player[0].array_company[0]));
            Text card_1B(50,325+15*2,company(player[0].array_company[1]));
            Text card_2B(50,325+15*3,company(player[0].array_company[2]));
            Text card_3B(50,325+15*4,company(player[0].array_company[3]));
            Text card_4B(50,325+15*5,company(player[0].array_company[4]));
            Text card_5B(50,325+15*6,company(player[0].array_company[5]));
            Text card_6B(50,325+15*7,company(player[0].array_company[6]));
            Text card_7B(50,325+15*8,company(player[0].array_company[7]));
            Text card_8B(50,325+15*9,company(player[0].array_company[8]));
            Text card_9B(50,325+15*10,company(player[0].array_company[9]));//name of companies on the 10 cards displayed.

            Text p_0B(110,325+15*1,player[0].array2[0]);
            Text p_1B(110,325+15*2,player[0].array2[1]);
            Text p_2B(110,325+15*3,player[0].array2[2]);
            Text p_3B(110,325+15*4,player[0].array2[3]);
            Text p_4B(110,325+15*5,player[0].array2[4]);
            Text p_5B(110,325+15*6,player[0].array2[5]);
            Text p_6B(110,325+15*7,player[0].array2[6]);
            Text p_7B(110,325+15*8,player[0].array2[7]);
            Text p_8B(110,325+15*9,player[0].array2[8]);
            Text p_9B(110,325+15*10,player[0].array2[9]);//price fluctuations on the 10 cards displayed.

            Text netP_0B(360,345+15*0,player[0].net_fluctuation[0]);
            Text netP_1B(360,345+15*1,player[0].net_fluctuation[1]);
            Text netP_2B(360,345+15*2,player[0].net_fluctuation[2]);
            Text netP_3B(360,345+15*3,player[0].net_fluctuation[3]);
            Text netP_4B(360,345+15*4,player[0].net_fluctuation[4]);
            Text netP_5B(360,345+15*5,player[0].net_fluctuation[5]);

            card_0B.show();
            card_1B.show();
            card_2B.show();
            card_3B.show();
            card_4B.show();
            card_5B.show();
            card_6B.show();
            card_7B.show();
            card_8B.show();
            card_9B.show();

            p_0B.show();
            p_1B.show();
            p_2B.show();
            p_3B.show();
            p_4B.show();
            p_5B.show();
            p_6B.show();
            p_7B.show();
            p_8B.show();
            p_9B.show();

            netP_0B.show();
            netP_1B.show();
            netP_2B.show();
            netP_3B.show();
            netP_4B.show();
            netP_5B.show();


            cout<<"\nChance "<<chance<<": "<<player[0].name<<", what do want to do: buy(b)/sell(s)/pass(p)?";
            cin>>select;

            while(select=='b' && price_per_share[0]*100>player[0].cash && price_per_share[1]*100>player[0].cash && price_per_share[2]*100>player[0].cash && price_per_share[3]*100>player[0].cash && price_per_share[4]*100>player[0].cash && price_per_share[5]*100>player[0].cash)
            {
                cout<<"\nYou do not have enough cash to buy any company";
                cout<<"\nChance "<<chance<<": "<<player[0].name<<", what do want to do: buy(b)/sell(s)/pass(p)?";//puts(p[0].name)
                cin>>select;
            }
            while(select=='s' && player[0].shares[0]==0 && player[0].shares[1]==0 && player[0].shares[2]==0 && player[0].shares[3]==0 && player[0].shares[4]==0 && player[0].shares[5]==0)
            {
                cout<<"You do not have any shares to sell!";
                cout<<"\nChance "<<chance<<": "<<player[0].name<<", what do want to do: buy(b)/sell(s)/pass(p)?";
                cin>>select;
            }
            if(select=='b')
            {
                player[0].WhichCompany();

                //  int WhichCompany;
                //cout<<"\nWhich company?"<<endl<<endl;

                //for (int i=0;i<6;i++){
                //  cout<<"For "<<company(i)<<" press "<<i<<endl;
                //  }

                //b:cin>>WhichCompany;
                //if(WhichCompany>=0 && WhichCompany<6)
                //return(WhichCompany);
                //else goto b;
                while(price_per_share[player[0].company_name]<=0 || price_per_share[player[0].company_name]*100>player[0].cash)
                {

                    if(price_per_share[player[0].company_name]<=0)
                    {

                        cout<<"\nYou cannot buy shares of a bankrupt company!";
                        //cout<<"\nEnter another company"<<endl;
                        player[0].WhichCompany();
                    }//checks that company to be bought is not bankrupt.

                    else if(price_per_share[player[0].company_name]*100>player[0].cash)
                    {
                        cout<<"\nYou do not have enough cash to buy this company !";
                        // cout<<"\nEnter another company"<<endl;
                        player[0].WhichCompany();
                    }
                }

                //  int amount;
                // cout<<"\nHow much?  (Maximum you can buy is: "<<max_shares_inThou[WhichCompany]<<" )"<<endl;//class
                //cin>>amount;
                player[0].amountf();
                while(player[0].amount*price_per_share[player[0].company_name]>player[0].cash || (player[0].amount+player[0].shares[player[0].company_name]+player[1].shares[player[1].company_name])>20000 || player[0].amount%100!=0 )
                {

                    if(player[0].amount*price_per_share[player[0].company_name]>player[0].cash)
                    {

                        cout<<"\nNot enough cash! Enter according to max. shares you can buy.";
                        //cout<<"\nHow much?  (Maximum you can buy is: "<<player[0].max_shares_inHun[player[0].company_name]<<" )"<<endl;
                        player[0].amountf();
                    }//checks that player has sufficient cash to buy required amount of shares.

                    else if(player[0].amount+player[0].shares[player[0].company_name]+player[1].shares[player[1].company_name]>20000)
                    {

                        cout<<"\nTotal shares for each company cannot exceed more than 20000";
                        // cout<<"\nEnter again."<<endl;
                        //cin>>amount;
                        player[0].amountf();
                    }

                    else if(player[0].amount%100!=0)
                    {
                        cout<<"\nPlease enter number of shares in multiples of hundred only.";
                        // cout<<"\nHow much?  (Maximum you can buy is: "<<player[1].max_shares_inHun[WhichCompany()]<<" )"<<endl;
                        //cin>>amount;
                        player[0].amountf();
                    }
                }

                player[0].shares[player[0].company_name]=player[0].shares[player[0].company_name]+player[0].amount;
                player[0].cash=player[0].cash-(player[0].amount*price_per_share[player[0].company_name]);

                cash_valueB.reset(150,570,player[0].cash);

                shares_value_0B.reset(600,330+15*0,player[0].shares[0]);
                shares_value_1B.reset(600,330+15*1,player[0].shares[1]);
                shares_value_2B.reset(600,330+15*2,player[0].shares[2]);
                shares_value_3B.reset(600,330+15*3,player[0].shares[3]);
                shares_value_4B.reset(600,330+15*4,player[0].shares[4]);
                shares_value_5B.reset(600,330+15*5,player[0].shares[5]);//updates the changed number of shares of each company that player has.
            }

            if(select=='s')
            {

                //int WhichCompany;
                //cout<<"\nWhich company?"<<endl<<endl;

                // for (int i=0;i<6;i++){
                //    cout<<"For "<<company(i)<<" press "<<i<<endl;
                //}

//                cin>>WhichCompany;
                player[0].WhichCompany();
                while(price_per_share[player[0].company_name]<=0 || player[0].shares[player[0].company_name]==0)
                {

                    if(price_per_share[player[0].company_name]<=0)
                    {

                        cout<<"\nYou cannot sell shares of a bankrupt company!";
                        //cout<<"\nEnter another company"<<endl;
                        //cin>>WhichCompany;
                        player[0].WhichCompany();
                    }
                    else if(player[0].shares[player[0].company_name]==0)
                    {
                        cout<<"\nYou do not have any shares of this company to sell!";
                        //       cout<<"\nEnter another company"<<endl;
                        //     cin>>WhichCompany;
                        player[0].WhichCompany();
                    }
                }
                //checks that company to be sold is not bankrupt.

                //int amount;
                // cout<<"\nHow much?  (Maximum you can sell is: "<<shares[WhichCompany]<<" )"<<endl;
                //cin>>amount;
                player[0].amountf1();
                while(player[0].amount>player[0].shares[ player[0].company_name] || player[0].amount%100!=0)
                {

                    if(player[0].amount>player[0].shares[player[0].company_name])
                    {
                        cout<<"You cannot sell more than what you own! Enter again according to max. shares you can sell.";
                        // cout<<"\nHow much?  (Maximum you can sell is: "<<shares[WhichCompany]<<" )"<<endl;
                        //cin>>amount;
                        player[0].amountf1();
                    }

                    else if(player[0].amount%100!=0)
                    {
                        //cout<<"\nPlease enter number of shares in multiples of hundred only.";
                        //cout<<"\nHow much?  (Maximum you can sell is: "<<shares[WhichCompany]<<" )"<<endl;
                        //cin>>amount;
                        player[0].amountf1();

                    }
                }

                player[0].shares[player[0].company_name]=player[0].shares[player[0].company_name]-player[0].amount;
                player[0].cash=player[0].cash+(player[0].amount*price_per_share[player[0].company_name]);

                cash_valueB.reset(150,570,player[0].cash);

                shares_value_0B.reset(600,330+15*0,player[0].shares[0]);
                shares_value_1B.reset(600,330+15*1,player[0].shares[1]);
                shares_value_2B.reset(600,330+15*2,player[0].shares[2]);
                shares_value_3B.reset(600,330+15*3,player[0].shares[3]);
                shares_value_4B.reset(600,330+15*4,player[0].shares[4]);
                shares_value_5B.reset(600,330+15*5,player[0].shares[5]);//updates the changed number of shares of each company that player owns.
            }

            card_0B.hide();
            card_1B.hide();
            card_2B.hide();
            card_3B.hide();
            card_4B.hide();
            card_5B.hide();
            card_6B.hide();
            card_7B.hide();
            card_8B.hide();
            card_9B.hide();

            p_0B.hide();
            p_1B.hide();
            p_2B.hide();
            p_3B.hide();
            p_4B.hide();
            p_5B.hide();
            p_6B.hide();
            p_7B.hide();
            p_8B.hide();
            p_9B.hide();

            netP_0B.hide();
            netP_1B.hide();
            netP_2B.hide();
            netP_3B.hide();
            netP_4B.hide();
            netP_5B.hide();

            if(chance==3)
            {
                cout<<"\nKeep the computer with you";
            }

            else
            {
                cout<<"\nPass the computer to "<<player[1].name<<"\nPress any key"<<endl;
                cin>>c;
            }

        }

        for(int chance=1; chance<4; chance++)
        {

            if(number%2==0)
            {
                break;
            }
            for(int i=0; i<6; i++)
            {
                for(int j=0; j<2; j++)
                {
                    player[j].max_shares[i]=player[j].cash/price_per_share[i];
                    player[j].max_shares_inHun[i]=player[j].max_shares[i]-(player[j].max_shares[i]%100);
                }
            }
            Text card_0B(50,325+15*1,company(player[0].array_company[0]));
            Text card_1B(50,325+15*2,company(player[0].array_company[1]));
            Text card_2B(50,325+15*3,company(player[0].array_company[2]));
            Text card_3B(50,325+15*4,company(player[0].array_company[3]));
            Text card_4B(50,325+15*5,company(player[0].array_company[4]));
            Text card_5B(50,325+15*6,company(player[0].array_company[5]));
            Text card_6B(50,325+15*7,company(player[0].array_company[6]));
            Text card_7B(50,325+15*8,company(player[0].array_company[7]));
            Text card_8B(50,325+15*9,company(player[0].array_company[8]));
            Text card_9B(50,325+15*10,company(player[0].array_company[9]));//name of companies on the 10 cards displayed.

            Text p_0B(110,325+15*1,player[0].array2[0]);
            Text p_1B(110,325+15*2,player[0].array2[1]);
            Text p_2B(110,325+15*3,player[0].array2[2]);
            Text p_3B(110,325+15*4,player[0].array2[3]);
            Text p_4B(110,325+15*5,player[0].array2[4]);
            Text p_5B(110,325+15*6,player[0].array2[5]);
            Text p_6B(110,325+15*7,player[0].array2[6]);
            Text p_7B(110,325+15*8,player[0].array2[7]);
            Text p_8B(110,325+15*9,player[0].array2[8]);
            Text p_9B(110,325+15*10,player[0].array2[9]);//price fluctuations on the 10 cards displayed.

            Text netP_0B(360,345+15*0,player[0].net_fluctuation[0]);
            Text netP_1B(360,345+15*1,player[0].net_fluctuation[1]);
            Text netP_2B(360,345+15*2,player[0].net_fluctuation[2]);
            Text netP_3B(360,345+15*3,player[0].net_fluctuation[3]);
            Text netP_4B(360,345+15*4,player[0].net_fluctuation[4]);
            Text netP_5B(360,345+15*5,player[0].net_fluctuation[5]);

            card_0B.show();
            card_1B.show();
            card_2B.show();
            card_3B.show();
            card_4B.show();
            card_5B.show();
            card_6B.show();
            card_7B.show();
            card_8B.show();
            card_9B.show();

            p_0B.show();
            p_1B.show();
            p_2B.show();
            p_3B.show();
            p_4B.show();
            p_5B.show();
            p_6B.show();
            p_7B.show();
            p_8B.show();
            p_9B.show();

            netP_0B.show();
            netP_1B.show();
            netP_2B.show();
            netP_3B.show();
            netP_4B.show();
            netP_5B.show();
            char select;
            cout<<"\nChance "<<chance<<": "<<player[0].name<<", what do want to do: buy(b)/sell(s)/pass(p)?";
            cin>>select;

            while(select=='b' && price_per_share[0]*100>player[0].cash && price_per_share[1]*100>player[0].cash && price_per_share[2]*100>player[0].cash && price_per_share[3]*100>player[0].cash && price_per_share[4]*100>player[0].cash && price_per_share[5]*100>player[0].cash)
            {
                cout<<"\nYou do not have enough cash to buy any company";
                cout<<"\nChance "<<chance<<": "<<player[0].name<<", what do want to do: buy(b)/sell(s)/pass(p)?";
                cin>>select;
            }
            while(select=='s' && player[0].shares[0]==0 && player[0].shares[1]==0 && player[0].shares[2]==0 && player[0].shares[3]==0 && player[0].shares[4]==0 && player[0].shares[5]==0)
            {
                cout<<"You do not have any shares to sell!";
                cout<<"\nChance "<<chance<<": "<<player[0].name<<", what do want to do: buy(b)/sell(s)/pass(p)?";
                cin>>select;
            }
            if(select=='b')
            {
                player[0].WhichCompany();

                while(price_per_share[player[0].company_name]<=0 || price_per_share[player[0].company_name]*100>player[0].cash)
                {

                    if(price_per_share[player[0].company_name]<=0)
                    {

                        cout<<"\nYou cannot buy shares of a bankrupt company!";
                        //cout<<"\nEnter another company"<<endl;
                        player[0].WhichCompany();
                    }//checks that company to be bought is not bankrupt.

                    else if(price_per_share[player[0].company_name]*100>player[0].cash)
                    {
                        cout<<"\nYou do not have enough cash to buy this company !";
                        // cout<<"\nEnter another company"<<endl;
                        player[0].WhichCompany();
                    }
                }
                player[0].amountf();
                while(player[0].amount*price_per_share[player[0].company_name]>player[0].cash || (player[0].amount+player[0].shares[player[0].company_name]+player[1].shares[player[1].company_name])>20000 || player[0].amount%100!=0 )
                {

                    if(player[0].amount*price_per_share[player[0].company_name]>player[0].cash)
                    {

                        cout<<"\nNot enough cash! Enter according to max. shares you can buy.";
                        player[0].amountf();
                    }//checks that player has sufficient cash to buy required amount of shares.

                    else if(player[0].amount+player[0].shares[player[0].company_name]+player[1].shares[player[1].company_name]>20000)
                    {

                        cout<<"\nTotal shares for each company cannot exceed more than 20000";
                        player[0].amountf();
                    }

                    else if(player[0].amount%100!=0)
                    {
                        cout<<"\nPlease enter number of shares in multiples of hundred only.";
                        player[0].amountf();
                    }
                }

                player[0].shares[player[0].company_name]=player[0].shares[player[0].company_name]+player[0].amount;
                player[0].cash=player[0].cash-(player[0].amount*price_per_share[player[0].company_name]);

                cash_valueB.reset(150,570,player[0].cash);

                shares_value_0B.reset(600,330+15*0,player[0].shares[0]);
                shares_value_1B.reset(600,330+15*1,player[0].shares[1]);
                shares_value_2B.reset(600,330+15*2,player[0].shares[2]);
                shares_value_3B.reset(600,330+15*3,player[0].shares[3]);
                shares_value_4B.reset(600,330+15*4,player[0].shares[4]);
                shares_value_5B.reset(600,330+15*5,player[0].shares[5]);//updates the changed number of shares of each company that player has.
            }

            if(select=='s')
            {
                player[0].WhichCompany();
                while(price_per_share[player[0].company_name]<=0 || player[0].shares[player[0].company_name]==0)
                {

                    if(price_per_share[player[0].company_name]<=0)
                    {

                        cout<<"\nYou cannot sell shares of a bankrupt company!";
                        player[0].WhichCompany();
                    }
                    else if(player[0].shares[player[0].company_name]==0)
                    {
                        cout<<"\nYou do not have any shares of this company to sell!";
                        player[0].WhichCompany();
                    }
                }
                //checks that company to be sold is not bankrupt.
                player[0].amountf1();
                while(player[0].amount>player[0].shares[ player[0].company_name] || player[0].amount%100!=0)
                {

                    if(player[0].amount>player[0].shares[player[0].company_name])
                    {
                        cout<<"You cannot sell more than what you own! Enter again according to max. shares you can sell.";
                        player[0].amountf1();
                    }
                    else if(player[0].amount%100!=0)
                    {
                        player[0].amountf1();

                    }
                }

                player[0].shares[player[0].company_name]=player[0].shares[player[0].company_name]-player[0].amount;
                player[0].cash=player[0].cash+(player[0].amount*price_per_share[player[0].company_name]);

                cash_valueB.reset(150,570,player[0].cash);

                shares_value_0B.reset(600,330+15*0,player[0].shares[0]);
                shares_value_1B.reset(600,330+15*1,player[0].shares[1]);
                shares_value_2B.reset(600,330+15*2,player[0].shares[2]);
                shares_value_3B.reset(600,330+15*3,player[0].shares[3]);
                shares_value_4B.reset(600,330+15*4,player[0].shares[4]);
                shares_value_5B.reset(600,330+15*5,player[0].shares[5]);//updates the changed number of shares of each company that player owns.
            }
            card_0B.hide();
            card_1B.hide();
            card_2B.hide();
            card_3B.hide();
            card_4B.hide();
            card_5B.hide();
            card_6B.hide();
            card_7B.hide();
            card_8B.hide();
            card_9B.hide();

            p_0B.hide();
            p_1B.hide();
            p_2B.hide();
            p_3B.hide();
            p_4B.hide();
            p_5B.hide();
            p_6B.hide();
            p_7B.hide();
            p_8B.hide();
            p_9B.hide();

            netP_0B.hide();
            netP_1B.hide();
            netP_2B.hide();
            netP_3B.hide();
            netP_4B.hide();
            netP_5B.hide();

            cout<<"\nPass the computer to "<<player[1].name<<"\nPress any key"<<endl;
            cin>>c;

            Text card_0(750,325+15*1,company(player[1].array_company[0]));
            Text card_1(750,325+15*2,company(player[1].array_company[1]));
            Text card_2(750,325+15*3,company(player[1].array_company[2]));
            Text card_3(750,325+15*4,company(player[1].array_company[3]));
            Text card_4(750,325+15*5,company(player[1].array_company[4]));
            Text card_5(750,325+15*6,company(player[1].array_company[5]));
            Text card_6(750,325+15*7,company(player[1].array_company[6]));
            Text card_7(750,325+15*8,company(player[1].array_company[7]));
            Text card_8(750,325+15*9,company(player[1].array_company[8]));
            Text card_9(750,325+15*10,company(player[1].array_company[9]));//name of companies on the 10 cards displayed.

            Text p_0(810,325+15*1,player[1].array2[0]);
            Text p_1(810,325+15*2,player[1].array2[1]);
            Text p_2(810,325+15*3,player[1].array2[2]);
            Text p_3(810,325+15*4,player[1].array2[3]);
            Text p_4(810,325+15*5,player[1].array2[4]);
            Text p_5(810,325+15*6,player[1].array2[5]);
            Text p_6(810,325+15*7,player[1].array2[6]);
            Text p_7(810,325+15*8,player[1].array2[7]);
            Text p_8(810,325+15*9,player[1].array2[8]);
            Text p_9(810,325+15*10,player[1].array2[9]);//price fluctuations on the 10 cards displayed.

            Text netP_0(1060,345+15*0,player[1].net_fluctuation[0]);
            Text netP_1(1060,345+15*1,player[1].net_fluctuation[1]);
            Text netP_2(1060,345+15*2,player[1].net_fluctuation[2]);
            Text netP_3(1060,345+15*3,player[1].net_fluctuation[3]);
            Text netP_4(1060,345+15*4,player[1].net_fluctuation[4]);
            Text netP_5(1060,345+15*5,player[1].net_fluctuation[5]);//net fluctuation against each company displayed.


            card_0.show();
            card_1.show();
            card_2.show();
            card_3.show();
            card_4.show();
            card_5.show();
            card_6.show();
            card_7.show();
            card_8.show();
            card_9.show();

            p_0.show();
            p_1.show();
            p_2.show();
            p_3.show();
            p_4.show();
            p_5.show();
            p_6.show();
            p_7.show();
            p_8.show();
            p_9.show();

            netP_0.show();
            netP_1.show();
            netP_2.show();
            netP_3.show();
            netP_4.show();
            netP_5.show();
            cout<<"\nChance "<<chance<<": "<<player[1].name<<", what do want to do: buy(b)/sell(s)/pass(p)?";
            cin>>select;

            while(select=='b' && price_per_share[0]*100>player[1].cash && price_per_share[1]*100>player[1].cash && price_per_share[2]*100>player[1].cash && price_per_share[3]*100>player[1].cash && price_per_share[4]*100>player[1].cash && price_per_share[5]*100>player[1].cash)
            {
                cout<<"\nYou do not have enough cash to buy any company";
                cout<<"\nChance "<<chance<<": "<<player[1].name<<", what do want to do: buy(b)/sell(s)/pass(p)?";
                cin>>select;
            }
            while(select=='s' && player[1].shares[0]==0 && player[1].shares[1]==0 && player[1].shares[2]==0 && player[1].shares[3]==0 && player[1].shares[4]==0 && player[1].shares[5]==0)
            {
                cout<<"You do not have any shares to sell!";
                cout<<"\nChance "<<chance<<": "<<player[1].name<<", what do want to do: buy(b)/sell(s)/pass(p)?";
                cin>>select;
            }
            if(select=='b')
            {
                player[1].WhichCompany();

                while(price_per_share[player[1].company_name]<=0 || price_per_share[player[1].company_name]*100>player[1].cash)
                {

                    if(price_per_share[player[1].company_name]<=0)
                    {

                        cout<<"\nYou cannot buy shares of a bankrupt company!";
                        player[1].WhichCompany();
                    }

                    else if(price_per_share[player[1].company_name]*100>player[1].cash)
                    {
                        cout<<"\nYou do not have enough cash to buy this company !";
                        player[1].WhichCompany();
                    }
                }

                player[1].amountf();
                while(player[1].amount*price_per_share[player[1].company_name]>player[1].cash || (player[1].amount+player[1].shares[player[1].company_name]+player[0].shares[player[0].company_name])>20000 || player[1].amount%100!=0 )
                {

                    if(player[1].amount*price_per_share[player[1].company_name]>player[1].cash)
                    {

                        cout<<"\nNot enough cash! Enter according to max. shares you can buy.";

                        player[1].amountf();
                    }//checks that player has sufficient cash to buy required amount of shares.

                    else if(player[1].amount+player[1].shares[player[1].company_name]+player[0].shares[player[0].company_name]>20000)
                    {
                        cout<<"\nTotal shares for each company cannot exceed more than 20000";

                        player[1].amountf();
                    }

                    else if(player[1].amount%100!=0)
                    {
                        cout<<"\nPlease enter number of shares in multiples of hundred only.";

                        player[1].amountf();
                    }
                }

                player[1].shares[player[1].company_name]=player[1].shares[player[1].company_name]+player[1].amount;
                player[1].cash=player[1].cash-(player[1].amount*price_per_share[player[1].company_name]);

                cash_value.reset(850,570,player[1].cash);

                shares_value_0.reset(1300,330+15*0,player[1].shares[0]);
                shares_value_1.reset(1300,330+15*1,player[1].shares[1]);
                shares_value_2.reset(1300,330+15*2,player[1].shares[2]);
                shares_value_3.reset(1300,330+15*3,player[1].shares[3]);
                shares_value_4.reset(1300,330+15*4,player[1].shares[4]);
                shares_value_5.reset(1300,330+15*5,player[1].shares[5]);//updates the changed number of shares of each company that player has.
            }

            if(select=='s')
            {


                player[1].WhichCompany();
                while(price_per_share[player[1].company_name]<=0 || player[1].shares[player[1].company_name]==0)
                {

                    if(price_per_share[player[1].company_name]<=0)
                    {

                        cout<<"\nYou cannot sell shares of a bankrupt company!";

                        player[1].WhichCompany();
                    }
                    else if(player[1].shares[player[1].company_name]==0)
                    {
                        cout<<"\nYou do not have any shares of this company to sell!";

                        player[1].WhichCompany();
                    }
                }

                player[1].amountf1();
                while(player[1].amount>player[1].shares[ player[1].company_name] || player[1].amount%100!=0)
                {

                    if(player[1].amount>player[1].shares[player[1].company_name])
                    {
                        cout<<"You cannot sell more than what you own! Enter again according to max. shares you can sell.";

                        player[1].amountf1();
                    }

                    else if(player[1].amount%100!=0)
                    {

                        player[1].amountf1();

                    }
                }

                player[1].shares[player[1].company_name]=player[1].shares[player[1].company_name]-player[1].amount;
                player[1].cash=player[1].cash+(player[1].amount*price_per_share[player[1].company_name]);

                cash_value.reset(850,570,player[1].cash);

                shares_value_0.reset(1300,330+15*0,player[1].shares[0]);
                shares_value_1.reset(1300,330+15*1,player[1].shares[1]);
                shares_value_2.reset(1300,330+15*2,player[1].shares[2]);
                shares_value_3.reset(1300,330+15*3,player[1].shares[3]);
                shares_value_4.reset(1300,330+15*4,player[1].shares[4]);
                shares_value_5.reset(1300,330+15*5,player[1].shares[5]);//updates the changed number of shares of each company that player owns.
            }

            card_0.hide();
            card_1.hide();
            card_2.hide();
            card_3.hide();
            card_4.hide();
            card_5.hide();
            card_6.hide();
            card_7.hide();
            card_8.hide();
            card_9.hide();

            p_0.hide();
            p_1.hide();
            p_2.hide();
            p_3.hide();
            p_4.hide();
            p_5.hide();
            p_6.hide();
            p_7.hide();
            p_8.hide();
            p_9.hide();

            netP_0.hide();
            netP_1.hide();
            netP_2.hide();
            netP_3.hide();
            netP_4.hide();
            netP_5.hide();


            if(chance==3)
            {
                cout<<"\nKeep the computer with you";
            }
            else
            {
                cout<<"\nPass the computer to "<<player[0].name<<"\nPress any key"<<endl;
                cin>>c;
            }
        }

        j=j+1;
        number+=1;

        for(int i=0; i<6; i++)
        {
            price_per_share[i]+=player[1].net_fluctuation[i]+player[0].net_fluctuation[i];
        }

        player[1].ShareProperty=0;
        player[0].ShareProperty=0;

        for(int i=0; i<6; i++)
        {
            player[1].ShareProperty+=(player[1].shares[i]*price_per_share[i]);
            player[0].ShareProperty+=(player[0].shares[i]*price_per_share[i]);
        }//updates the new value of price per share and share property.

        player[0].NetProperty=player[0].cash+player[0].ShareProperty;
        player[1].NetProperty=player[1].cash+player[1].ShareProperty;

        Net_prop_value.reset(1050,570,player[0].NetProperty);//displays the updated net property.
        Net_prop_valueB.reset(350,570,player[1].NetProperty);
        Text save_game(700,670," save game ");
        save_game.imprint();
        Rectangle save_game1(700,670,100,30);
        save_game1.imprint();
        cout<<"\ndo you want to save game"<<endl;
        cout<<"else click anywhere else"<<endl;
        int ClickPos=getClick();
        int x=ClickPos/65536,y=ClickPos%65536;
        if(x>=600 && x<=800 && y>=640 && y<=700)
        {

            fstream file;
            file.open("save",ios::binary|ios::app|ios::in|ios::out);

            for(int i=0; i<2; i++)
            {

                file.write((char*)&player[i],sizeof(p));



            }

            file.close();
            return 0;
        }
        else
        {
        save_game.hide();
        save_game1.hide();
        }
    }


    player[0].ShareProperty=0;
    player[1].ShareProperty=0;

    for(int i=0; i<6; i++)
    {
        player[0].ShareProperty+=(player[0].shares[i]*price_per_share[i]);
        player[1].ShareProperty+=(player[1].shares[i]*price_per_share[i]);
    }//updates the new value of price per share and share property.

    player[0].NetProperty=player[0].cash+player[0].ShareProperty;
    player[1].NetProperty=player[1].cash+player[1].ShareProperty;

    Text Net_prop_value_1(1050,570,player[1].NetProperty);
    Text Net_prop_value_1B(350,570,player[0].NetProperty);
    Net_prop_value_1.imprint();
    Net_prop_value_1B.imprint();

    //displays the updated net property.

    Text cash_value_1(850,570,player[1].cash);
    cash_value_1.imprint();

    Text cash_value_1B(150,570,player[0].cash);
    cash_value_1B.imprint();

    Text shares_value_0_1(1300,330+15*0,player[1].shares[0]);
    Text shares_value_1_1(1300,330+15*1,player[1].shares[1]);
    Text shares_value_2_1(1300,330+15*2,player[1].shares[2]);
    Text shares_value_3_1(1300,330+15*3,player[1].shares[3]);
    Text shares_value_4_1(1300,330+15*4,player[1].shares[4]);
    Text shares_value_5_1(1300,330+15*5,player[1].shares[5]);

    shares_value_0_1.imprint();
    shares_value_1_1.imprint();
    shares_value_2_1.imprint();
    shares_value_3_1.imprint();
    shares_value_4_1.imprint();
    shares_value_5_1.imprint();

    Text shares_value_0_1B(600,330+15*0,player[0].shares[0]);
    Text shares_value_1_1B(600,330+15*1,player[0].shares[1]);
    Text shares_value_2_1B(600,330+15*2,player[0].shares[2]);
    Text shares_value_3_1B(600,330+15*3,player[0].shares[3]);
    Text shares_value_4_1B(600,330+15*4,player[0].shares[4]);
    Text shares_value_5_1B(600,330+15*5,player[0].shares[5]);

    shares_value_0_1B.imprint();
    shares_value_1_1B.imprint();
    shares_value_2_1B.imprint();
    shares_value_3_1B.imprint();
    shares_value_4_1B.imprint();
    shares_value_5_1B.imprint();

    if(player[1].NetProperty>player[0].NetProperty)
    {
        cout<<"\n"<<player[1].name<<" WINS!!";
    }

    else if(player[1].NetProperty<player[0].NetProperty)
    {
        cout<<"\n"<<player[0].name<<" WINS!!";
    }

    else
    {
        cout<<"\nGAME TIED!!";
    }


    wait(-1);
}
//make java server(recieve and broadcast)
//make c++ socket program(send id, movetype,cardno, amount....)
//adjust code to account for multiple users.(send in data function...main loop---send--recieve--process.

//multiple of 100....debug



