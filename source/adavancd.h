

string company1(int i){
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
    else if (i==6)
        return "ShareSuspend";
    else if (i==7)
        return "Right Issue ";
    else if (i==8)
        return "Loan Stock  ";
    else if (i==9)
        return "Debenture   ";
    else if (i==10)
        return "Currency+10%";
    else if (i==11)
        return "Currency-10%";
    else if (i==12)
        return "            ";
    else return 0;
}
//assigned a number to each company1.

void advanced(){


    const double start_price_per_share[6]={2,2.5,4,5.5,7.5,8};
    double price_per_share[6]={2,2.5,4,5.5,7.5,8};//value of shares of each company1.

    int random_row[10], random_column[10];//for above 2-D array.
    int random_rowB[10], random_columnB[10];//any variable name ending with "B" is for player 1.

    srand(time(0));

    double array2[10];//will contain the fluctuation value of the ten cards distributed to player 2.
    double array2B[10];//will contain the fluctuation value of the ten cards distributed to player 1.

    int array_company1[10];//will contain knowledge of the name of company1 the corresponding fluctuation in price is.
    int array_company1B[10];//will contain knowledge of the name of company1 the corresponding fluctuation in price is.

    double shares[6]={0};//will contain number of shares player2 has of each company1.
    double sharesB[6]={0};//will contain number of shares player1 has of each company1.

    unsigned int cash=6000;//cash owned by player 2.
    unsigned int cashB=6000;//cash owned by player 1.

    long int ShareProperty=0;//Total cash worth of shares of player 2.
    long int SharePropertyB=0;//Total cash worth of shares of player 1.

    long int NetProperty=cash+ShareProperty;//net property of player 2.
    long int NetPropertyB=cashB+SharePropertyB;//net property of player 1.

    Text card[10];
    Text cardB[10];
    Text p[10];
    Text pB[10];
    Text netP[6];
    Text netPB[6];

    int j=0;//used for creating next round chart table.
    int number=1;//used for first round rotation.
    char c;//used against the output "Enter any key".

    string player1;
    cout<<"\nEnter name of player 1: ";
    cin>>player1;//Defines the name of player1.

    string player2;
    cout<<"\nEnter name of player 2: ";
    cin>>player2;//defines the name of player 2.

    int NumberOfRounds;
    cout<<"\nHow many rounds do you want to play? (Maximum you can play is 10 rounds)"<<endl;
    cin>>NumberOfRounds;//defines number of rounds to be played.

    while(NumberOfRounds>10||NumberOfRounds<=0)
    {
        cout<<"\nInvalid input.\nPlease enter again."<<endl;
        cin>>NumberOfRounds;
    }//checks that no. of rounds entered is valid.

    for(int round_number=0; round_number<NumberOfRounds; round_number++){

        Text round(50,50," Round ");
        round.imprint();

        Rectangle roundR(50,50,100,textHeight()+5);
        roundR.imprint();

        for(int i=0;i<6;i++){

            Text company1_list(150+100*i,50,company1(i));
            company1_list.imprint();

            Rectangle company1R(150+100*i,50,100,textHeight()+5);
            company1R.imprint();
        }//displays each company1's name in the table.

        for(int i=0;i<7;i++){

            Rectangle r(50+100*(i),50+((textHeight()+5)*(j+1)),100,textHeight());
            r.imprint();

            Text round_no(50,50+((textHeight()+5)*(j+1)),j+1);
            round_no.imprint();
        }

        for(int i=0;i<6;i++){

            Text round1(50+100*(i+1),50+((textHeight()+5)*(j+1)),price_per_share[i]);
            round1.imprint();
        }//creates table for a particular round.

        Line l(650,300,650,700);
        l.imprint();//line for separating display area of player 1 and player 2.

        Text Player1(350,650,player1);
        Player1.imprint();//displays name of player 1.

        Text Player2 (1050,650,player2);
        Player2.imprint();//displays name of player 2.

        Text Player(250,650,"Player 1: ");
        Player.imprint();

        Text Player_(950,650,"Player 2: ");
        Player_.imprint();//prints the name of the players.

        Text SharesYouHave(1200,305+textHeight(),"Shares  you have of: " );
        SharesYouHave.imprint();

        Text SharesYouHaveB(500,305+textHeight(),"Shares  you have of: " );
        SharesYouHaveB.imprint();

        for(int i=0;i<6;i++){

            Text shares_company1(1200,345+15*i,company1(i));
            shares_company1.imprint();

            Text shares_company1B(500,345+15*i,company1(i));
            shares_company1B.imprint();
        }

        Text shares_value[6];
        for(int i=0; i<6; i++)
        {
            shares_value[i]={1300,345.0+15.0*i,shares[i]};
        }//displays shares player 2 has of each company1.

        Text shares_valueB[6];
        for(int i=0; i<6; i++)
        {
            shares_valueB[i]={600,345.0+15.0*i,sharesB[i]};
        }//displays shares player 1 has of each company1.

        Text CashInHand(850,550,"Cash in Hand: ");
        CashInHand.imprint();

        Text CashInHandB(150,550,"Cash in Hand: ");
        CashInHandB.imprint();

        Text cash_value(850,570,cash);//displays cash in hand of player 2.
        Text cash_valueB(150,570,cashB);//displays cash in hand of player 1.

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

        Text Net_prop_value(1050,570,NetProperty);//displays net property of player 2.
        Text Net_prop_valueB(350,570,NetPropertyB);//displays net property of player 1.

        if(round_number==NumberOfRounds-1)
        {
            break;
        }//no trade is made with the prices of last round. it is only displayed to calculate final net property of both players.

        Text cards_display(800,300,"Your cards are displayed below: ");
        cards_display.imprint();

        Text cards_displayB(110,300,"Your cards are displayed below: ");
        cards_displayB.imprint();

        Text title(800,305+textHeight(),"  company1       Price Fluctuation ");
        title.imprint();

        Text titleB(100,305+textHeight(),"  company1       Price Fluctuation ");
        titleB.imprint();

        long double array_fluctuation[6][24]={{-1,-0.5,0.5,1,0,0,0,0,0,0,8,4,-1,-0.5,0.5,1,0,0,0,0,0,0,9,5},{-1.5,-1,-0.5,0.5,1,1.5,0,0,0,0,8,6,-1.5,-1,-0.5,0.5,1,1.5,0,0,0,0,9,7},{-1.5,-1,-0.5,0.5,1,1.5,0,0,0,0,8,8,-1.5,-1,-0.5,0.5,1,1.5,0,0,0,0,9,9},{-2,-1.5,-1,-0.5,0.5,1,1.5,2,0,0,8,4,-2,-1.5,-1,-0.5,0.5,1,1.5,2,0,0,9,5},{-2.5,-2,-1.5,-1,-0.5,0.5,1,1.5,2,2.5,0,6,-2.5,-2,-1.5,-1,-0.5,0.5,1,1.5,2,2.5,0,7},{-3,-2.5,-2,-1.5,-1,-0.5,0.5,1,1.5,2,2.5,3,-3,-2.5,-2,-1.5,-1,-0.5,0.5,1,1.5,2,2.5,3}};//2-D array containing price fluctuations a particular company1 can have.
        int q;

        for(q=0;q<10;q++){

            a:random_row[q]=randuv(0,6);//selects a random company1.
            random_column[q]=randuv(0,24);//selects a random price fluctuation.
            if(array_fluctuation[random_row[q]][random_column[q]]==0)
                goto a;

            if(array_fluctuation[random_row[q]][random_column[q]]<=3)
            {
                array2[q]=array_fluctuation[random_row[q]][random_column[q]];
                array_company1[q]=random_row[q];
            }

            else if(array_fluctuation[random_row[q]][random_column[q]]==4)
                array_company1[q]=6;
            else if(array_fluctuation[random_row[q]][random_column[q]]==5)
                array_company1[q]=7;
            else if(array_fluctuation[random_row[q]][random_column[q]]==6)
                array_company1[q]=8;
            else if(array_fluctuation[random_row[q]][random_column[q]]==7)
                array_company1[q]=9;
            else if(array_fluctuation[random_row[q]][random_column[q]]==8)
                array_company1[q]=10;
            else if(array_fluctuation[random_row[q]][random_column[q]]==9)
                array_company1[q]=11;

            if(array_fluctuation[random_row[q]][random_column[q]]>3)
                array2[q]=0;

            array_fluctuation[random_row[q]][random_column[q]]=0;

            b:random_rowB[q]=randuv(0,6);
            random_columnB[q]=randuv(0,24);
            if(array_fluctuation[random_rowB[q]][random_columnB[q]]==0)
                goto b;

            if(array_fluctuation[random_rowB[q]][random_columnB[q]]<=3)
            {
                array2B[q]=array_fluctuation[random_rowB[q]][random_columnB[q]];
                array_company1B[q]=random_rowB[q];
            }
            else if(array_fluctuation[random_rowB[q]][random_columnB[q]]==4)
                array_company1B[q]=6;
            else if(array_fluctuation[random_rowB[q]][random_columnB[q]]==5)
                array_company1B[q]=7;
            else if(array_fluctuation[random_rowB[q]][random_columnB[q]]==6)
                array_company1B[q]=8;
            else if(array_fluctuation[random_rowB[q]][random_columnB[q]]==7)
                array_company1B[q]=9;
            else if(array_fluctuation[random_rowB[q]][random_columnB[q]]==8)
                array_company1B[q]=10;
            else if(array_fluctuation[random_rowB[q]][random_columnB[q]]==9)
                array_company1B[q]=11;

            if(array_fluctuation[random_rowB[q]][random_columnB[q]]>3)
                array2B[q]=0;

            array_fluctuation[random_rowB[q]][random_columnB[q]]=0;
        }

        double net_fluctuation[6]={0};//sum up the fluctuation of a particular company1 according to cards of player 2 and  store in an array of size six.
        double net_fluctuationB[6]={0};//sum up the fluctuation of a particular company1 according to cards of player 1 and  store in an array of size six.

        for(int j=0;j<6;j++){
            for(int i=0;i<10;i++){

                if(array_company1[i]==j){
                    net_fluctuation[j]+=array2[i];
                }
            }
        }

        for(int j=0;j<6;j++){
            for(int i=0;i<10;i++){

                if(array_company1B[i]==j){
                    net_fluctuationB[j]+=array2B[i];
                }
            }
        }

        Text net(1000,300,"As per your cards ");
        net.imprint();

        Text netB(300,300,"As per your cards ");
        netB.imprint();

        Text net2(1000,305+textHeight(),"Net price fluctuation of: ");
        net2.imprint();

        Text net2B(300,305+textHeight(),"Net price fluctuation of: ");
        net2B.imprint();

        for(int i=0;i<6;i++){

            Text netC(1000,345+15*i,company1(i));
            netC.imprint();

            Text netCB(300,345+15*i,company1(i));
            netCB.imprint();
        }//Name of the six companies displayed.

        for(int chance=1;chance<4;chance++){

            if(number%2!=0)
            {
                break;
            }

            int max_shares[6];//contains information of max shares that can be bought.
            int max_sharesB[6];
            int max_shares_inThou[6];
            int max_shares_inThouB[6];//contains information of max shares (in multiples of thousands) that can be bought.

            for(int i=0;i<6;i++){

                max_shares[i]=cash/price_per_share[i];
                max_shares_inThou[i]=max_shares[i]-(max_shares[i]%100);

                max_sharesB[i]=cashB/price_per_share[i];
                max_shares_inThouB[i]=max_sharesB[i]-(max_sharesB[i]%100);
            }

            for(int i=0;i<10;i++)
            {
                card[i]={750,345.0+15.0*i,company1(array_company1[i])};
            }//name of companies on the 10 cards displayed.

            for(int i=0; i<10; i++)
            {
                if (array2[i]==0)
                    goto e;
                p[i]={810,345.0+15.0*i,array2[i]};
                e:;
            }//price fluctuations on the 10 cards displayed.

            for(int i=0; i<6; i++)
            {
                netP[i]={1060,345.0+15.0*i,net_fluctuation[i]};
            }//net fluctuation against each company1 displayed.

            for(int i=0; i<10; i++)
            {
                card[i].show();
            }

            for(int i=0; i<10; i++)
            {
                p[i].show();
            }

            for(int i=0; i<6; i++)
            {
                netP[i].show();
            }

            char select;

            for(int i=0; i<10; i++)
            {
                if(array_company1[i]==8)
                {
                    cout<<"\nYou have a Loan Stock Card, which awards Rs.1000 to you.\nWould you like to use it now?(y/n)"<<endl;
                    char ans;
                    cin>>ans;
                    while(ans!='n' && ans!='y')
                    {
                        cout<<"\nInvalid input!\nEnter again"<<endl;
                        cin>>ans;
                    }
                    if (ans=='n')
                    {

                    }
                    else if (ans=='y')
                    {
                        cash=cash+1000;
                        cash_value.reset(850,570,cash);
                        NetProperty+=1000;
                        Net_prop_value.reset(1050,570,NetProperty);
                        array_company1[i]=12;
                        goto k;
                    }
                }
            }
            cout<<"\nChance "<<chance<<": "<<player2<<", what do want to do: buy(b)/sell(s)/pass(p)?";
            cin>>select;

            while(select!='b' && select !='s' && select!='p')
            {
                cout<<"\nInvalid input!\nEnter again."<<endl;
                cin>>select;
            }

            while(select=='b' && abs(price_per_share[0]*100)>cash && abs(price_per_share[1]*100)>cash && abs(price_per_share[2]*100)>cash && abs(price_per_share[3]*100)>cash && abs(price_per_share[4]*100)>cash && abs(price_per_share[5]*100)>cash)
            {
                cout<<"\nYou do not have enough cash to buy any company1";
                cout<<"\nChance "<<chance<<": "<<player2<<", what do want to do: buy(b)/sell(s)/pass(p)?";
                cin>>select;
            }
            while(select=='s' && shares[0]==0 && shares[1]==0 && shares[2]==0 && shares[3]==0 && shares[4]==0 && shares[5]==0)
            {
                cout<<"You do not have any shares to sell!";
                cout<<"\nChance "<<chance<<": "<<player2<<", what do want to do: buy(b)/sell(s)/pass(p)?";
                cin>>select;
            }
            if(select=='b'){

                int Whichcompany1;
                cout<<"\nWhich company1?"<<endl<<endl;

                for (int i=0;i<6;i++){
                    cout<<"For "<<company1(i)<<" press "<<i<<endl;
                }

                cin>>Whichcompany1;

                while(price_per_share[Whichcompany1]<=0 || price_per_share[Whichcompany1]*100>cash){

                    if(price_per_share[Whichcompany1]<=0){

                        cout<<"\nYou cannot buy shares of a bankrupt company1!";
                        cout<<"\nEnter another company1"<<endl;
                        cin>>Whichcompany1;
                    }//checks that company1 to be bought is not bankrupt.

                    else if(price_per_share[Whichcompany1]*100>cash){
                        cout<<"\nYou do not have enough cash to buy this company1 !";
                        cout<<"\nEnter another company1"<<endl;
                        cin>>Whichcompany1;
                    }
                }

                int amount;
                cout<<"\nHow much?  (Maximum you can buy is: "<<max_shares_inThou[Whichcompany1]<<" )"<<endl;
                cin>>amount;

                while(amount*price_per_share[Whichcompany1]>cash || (amount+shares[Whichcompany1]+sharesB[Whichcompany1])>20000 || amount%100!=0 ){

                    if(amount*price_per_share[Whichcompany1]>cash){

                        cout<<"\nNot enough cash! Enter according to max. shares you can buy.";
                        cout<<"\nHow much?  (Maximum you can buy is: "<<max_shares_inThou[Whichcompany1]<<" )"<<endl;
                        cin>>amount;
                    }//checks that player has sufficient cash to buy required amount of shares.

                    else if((amount+shares[Whichcompany1]+sharesB[Whichcompany1])>20000)
                    {
                        cout<<"\nTotal shares for each company1 cannot exceed more than 20000";
                        cout<<"\nEnter again."<<endl;
                        cin>>amount;
                    }

                    else if(amount%100!=0){
                        cout<<"\nPlease enter number of shares in multiples of hundred only.";
                        cout<<"\nHow much?  (Maximum you can buy is: "<<max_shares_inThou[Whichcompany1]<<" )"<<endl;
                        cin>>amount;
                    }
                }

                shares[Whichcompany1]=shares[Whichcompany1]+amount;
                cash=cash-(amount*price_per_share[Whichcompany1]);

                cash_value.reset(850,570,cash);

                for(int i=0; i<6; i++)
                {
                    shares_value[i].reset(1300,345+15*i,shares[i]);
                }//updates the changed number of shares of each company1 that player has.
            }

            if(select=='s'){

                int Whichcompany1;
                cout<<"\nWhich company1?"<<endl<<endl;

                for (int i=0;i<6;i++){
                    cout<<"For "<<company1(i)<<" press "<<i<<endl;
                }

                cin>>Whichcompany1;

                while(price_per_share[Whichcompany1]<=0 || shares[Whichcompany1]==0){

                    if(price_per_share[Whichcompany1]<=0){

                        cout<<"\nYou cannot sell shares of a bankrupt company1!";
                        cout<<"\nEnter another company1"<<endl;
                        cin>>Whichcompany1;
                    }
                    else if(shares[Whichcompany1]==0)
                    {
                        cout<<"\nYou do not have any shares of this company1 to sell!";
                        cout<<"\nEnter another company1"<<endl;
                        cin>>Whichcompany1;
                    }
                }
                //checks that company1 to be sold is not bankrupt.

                int amount;
                cout<<"\nHow much?  (Maximum you can sell is: "<<shares[Whichcompany1]<<" )"<<endl;
                cin>>amount;

                while(amount>shares[Whichcompany1] || amount%100!=0){

                    if(amount>shares[Whichcompany1])
                    {
                        cout<<"You cannot sell more than what you own! Enter again according to max. shares you can sell.";
                        cout<<"\nHow much?  (Maximum you can sell is: "<<shares[Whichcompany1]<<" )"<<endl;
                        cin>>amount;
                    }

                    else if(amount%100!=0){
                        cout<<"\nPlease enter number of shares in multiples of hundred only.";
                        cout<<"\nHow much?  (Maximum you can sell is: "<<shares[Whichcompany1]<<" )"<<endl;
                        cin>>amount;
                    }
                }

                shares[Whichcompany1]=shares[Whichcompany1]-amount;
                cash=cash+(amount*price_per_share[Whichcompany1]);

                cash_value.reset(850,570,cash);

                for(int i=0; i<6; i++)
                {
                    shares_value[i].reset(1300,345+15*i,shares[i]);
                }//updates the changed number of shares of each company1 that player has.
            }

            k:for(int i=0; i<10; i++)
            {
                card[i].hide();
            }

            for(int i=0; i<10; i++)
            {
                p[i].hide();
            }

            for(int i=0; i<6; i++)
            {
                netP[i].hide();
            }

            cout<<"\nPass the computer to "<<player1<<"\nPress any key"<<endl;
            cin>>c;

            for(int i=0;i<10;i++)
            {
                cardB[i]={50,345.0+15.0*i,company1(array_company1B[i])};
            }//name of companies on the 10 cards displayed.

            for(int i=0; i<10; i++)
            {
                if (array2B[i]==0)
                    goto f;
                pB[i]={110,345.0+15.0*i,array2B[i]};
                f:;
            }//price fluctuations on the 10 cards displayed.

            for(int i=0; i<6; i++)
            {
                netPB[i]={360,345.0+15.0*i,net_fluctuationB[i]};
            }//net fluctuation against each company1 displayed.

            for(int i=0; i<10; i++)
            {
                cardB[i].show();
            }

            for(int i=0; i<10; i++)
            {
                pB[i].show();
            }

            for(int i=0; i<6; i++)
            {
                netPB[i].show();
            }

            for(int i=0; i<10; i++)
            {
                if(array_company1B[i]==8)
                {
                    cout<<"\nYou have a Loan Stock Card, which awards Rs.1000 to you.\nWould you like to use it now?(y/n)"<<endl;
                    char ans;
                    cin>>ans;
                    while(ans!='n' && ans!='y')
                    {
                        cout<<"\nInvalid input!\nEnter again"<<endl;
                        cin>>ans;
                    }
                    if (ans=='n')
                    {

                    }
                    else if (ans=='y')
                    {
                        cashB=cashB+1000;
                        cash_valueB.reset(150,570,cashB);
                        NetPropertyB+=1000;
                        Net_prop_valueB.reset(350,570,NetProperty);
                        array_company1B[i]=12;
                        goto l;
                    }
                }
            }
            cout<<"\nChance "<<chance<<": "<<player1<<", what do want to do: buy(b)/sell(s)/pass(p)?";
            cin>>select;

            while(select!='b' && select !='s' && select!='p')
            {
                cout<<"\nInvalid input!\nEnter again."<<endl;
                cin>>select;
            }

            while(select=='b' && abs(price_per_share[0]*100)>cashB && abs(price_per_share[1]*100)>cashB && abs(price_per_share[2]*100)>cashB && abs(price_per_share[3]*100)>cashB && abs(price_per_share[4]*100)>cashB && abs(price_per_share[5]*100)>cashB)
            {
                cout<<"\nYou do not have enough cash to buy any company1";
                cout<<"\nChance "<<chance<<": "<<player1<<", what do want to do: buy(b)/sell(s)/pass(p)?";
                cin>>select;
            }
            while(select=='s' && sharesB[0]==0 && sharesB[1]==0 && sharesB[2]==0 && sharesB[3]==0 && sharesB[4]==0 && sharesB[5]==0)
            {
                cout<<"You do not have any shares to sell!";
                cout<<"\nChance "<<chance<<": "<<player1<<", what do want to do: buy(b)/sell(s)/pass(p)?";
                cin>>select;
            }

            if(select=='b'){

                int Whichcompany1;
                cout<<"\nWhich company1?"<<endl<<endl;

                for (int i=0;i<6;i++){
                    cout<<"For "<<company1(i)<<" press "<<i<<endl;
                }

                cin>>Whichcompany1;

                 while(price_per_share[Whichcompany1]<=0 || price_per_share[Whichcompany1]*100>cashB){

                    if(price_per_share[Whichcompany1]<=0){

                        cout<<"\nYou cannot buy shares of a bankrupt company1!";
                        cout<<"\nEnter another company1"<<endl;
                        cin>>Whichcompany1;
                    }//checks that company1 to be bought is not bankrupt.

                    else if(price_per_share[Whichcompany1]*100>cashB){
                        cout<<"\nYou do not have enough cash to buy this company1!";
                        cout<<"\nEnter another company1"<<endl;
                        cin>>Whichcompany1;
                    }
                 }

                int amountB;
                cout<<"\nHow much?  (Maximum you can buy is: "<<max_shares_inThouB[Whichcompany1]<<" )"<<endl;
                cin>>amountB;

                while(amountB*price_per_share[Whichcompany1]>cashB || (amountB+shares[Whichcompany1]+sharesB[Whichcompany1])>20000 || amountB%100!=0 ){

                    if(amountB*price_per_share[Whichcompany1]>cashB){
                        cout<<"\nNot enough cash! Enter according to max. shares you can buy.";
                        cout<<"\nHow much?  (Maximum you can buy is: "<<max_shares_inThouB[Whichcompany1]<<" )"<<endl;

                        cin>>amountB;
                    }//checks that player has sufficient cash to buy required amount of shares.

                    else if((amountB+shares[Whichcompany1]+sharesB[Whichcompany1])>20000)
                    {
                        cout<<"\nTotal shares for each company1 cannot exceed more than 20000";
                        cout<<"\nEnter again."<<endl;
                        cin>>amountB;
                    }

                    else if(amountB%100!=0){
                        cout<<"\nPlease enter number of shares in multiples of hundred only.";
                        cout<<"\nHow much?  (Maximum you can buy is: "<<max_shares_inThouB[Whichcompany1]<<" )"<<endl;
                        cin>>amountB;
                    }
                }

                sharesB[Whichcompany1]=sharesB[Whichcompany1]+amountB;
                cashB=cashB-(amountB*price_per_share[Whichcompany1]);

                cash_valueB.reset(150,570,cashB);

                for(int i=0; i<6; i++)
                {
                    shares_valueB[i].reset(600,345+15*i,sharesB[i]);
                }//updates the changed number of shares of each company1 that player has.
            }

            if(select=='s'){

                int Whichcompany1;
                cout<<"\nWhich company1?"<<endl<<endl;

                for (int i=0;i<6;i++){
                    cout<<"For "<<company1(i)<<" press "<<i<<endl;
                }

                cin>>Whichcompany1;

                while(price_per_share[Whichcompany1]<=0 || sharesB[Whichcompany1]==0){

                    if(price_per_share[Whichcompany1]<=0){

                        cout<<"\nYou cannot sell shares of a bankrupt company1!";
                        cout<<"\nEnter another company1"<<endl;
                        cin>>Whichcompany1;
                    }
                    else if(sharesB[Whichcompany1]==0)
                    {
                        cout<<"\nYou do not have any shares of this company1 to sell!";
                        cout<<"\nEnter another company1"<<endl;
                        cin>>Whichcompany1;
                    }
                }

                int amountB;
                cout<<"\nHow much?  (Maximum you can sell is: "<<sharesB[Whichcompany1]<<" )"<<endl;
                cin>>amountB;

                while(amountB>sharesB[Whichcompany1] || amountB%100!=0){

                    if(amountB>sharesB[Whichcompany1]){

                        cout<<"\nYou cannot sell more than what you own! Enter again according to max. shares you can sell.";
                        cout<<"\nHow much?  (Maximum you can sell is: "<<sharesB[Whichcompany1]<<" )"<<endl;
                        cin>>amountB;
                    }

                    else if(amountB%100!=0){

                        cout<<"\nPlease enter number of shares in multiples of hundred only.";
                        cout<<"\nHow much?  (Maximum you can sell is: "<<sharesB[Whichcompany1]<<" )"<<endl;
                        cin>>amountB;
                    }
                }

                sharesB[Whichcompany1]=sharesB[Whichcompany1]-amountB;
                cashB=cashB+(amountB*price_per_share[Whichcompany1]);

                cash_valueB.reset(150,570,cashB);

                for(int i=0; i<6; i++)
                {
                    shares_valueB[i].reset(600,345+15*i,sharesB[i]);
                }//updates the changed number of shares of each company1 that player has.

                }

            l:for(int i=0; i<10; i++)
            {
                cardB[i].hide();
            }

            for(int i=0; i<10; i++)
            {
                pB[i].hide();
            }

            for(int i=0; i<6; i++)
            {
                netPB[i].hide();
            }

            if(chance==3){
                cout<<"\nKeep the computer with you";
            }

            else{
                cout<<"\nPass the computer to "<<player2<<"\nPress any key"<<endl;
                cin>>c;
            }

        }

        for(int chance=1;chance<4;chance++){

            if(number%2==0){
                break;
             }

            int max_shares[6];//contains information of max shares that can be bought.
            int max_sharesB[6];
            int max_shares_inThou[6];
            int max_shares_inThouB[6];//contains information of max shares (in multiples of thousands) that can be bought.

            for(int i=0;i<6;i++){
                max_shares[i]=cash/price_per_share[i];
                max_shares_inThou[i]=max_shares[i]-(max_shares[i]%100);

                max_sharesB[i]=cashB/price_per_share[i];
                max_shares_inThouB[i]=max_sharesB[i]-(max_sharesB[i]%100);
            }

            for(int i=0;i<10;i++)
            {
                cardB[i]={50,345.0+15.0*i,company1(array_company1B[i])};
            }//name of companies on the 10 cards displayed.

            for(int i=0; i<10; i++)
            {
                if (array2B[i]==0)
                    goto d;
                pB[i]={110,345.0+15.0*i,array2B[i]};
                d:;
            }//price fluctuations on the 10 cards displayed.

            for(int i=0; i<6; i++)
            {
                netPB[i]={360,345.0+15.0*i,net_fluctuationB[i]};
            }//net fluctuation against each company1 displayed.

            for(int i=0; i<10; i++)
            {
                cardB[i].show();
            }

            for(int i=0; i<10; i++)
            {
                pB[i].show();
            }

            for(int i=0; i<6; i++)
            {
                netPB[i].show();
            }

            char select;

            for(int i=0; i<10; i++)
            {
                if(array_company1B[i]==8)
                {
                    cout<<"\nYou have a Loan Stock Card, which awards Rs.1000 to you.\nWould you like to use it now?(y/n)"<<endl;
                    char ans;
                    cin>>ans;
                    while(ans!='n' && ans!='y')
                    {
                        cout<<"\nInvalid input!\nEnter again"<<endl;
                        cin>>ans;
                    }
                    if (ans=='n')
                    {

                    }
                    else if (ans=='y')
                    {
                        cashB=cashB+1000;
                        cash_valueB.reset(150,570,cashB);
                        NetPropertyB+=1000;
                        Net_prop_valueB.reset(350,570,NetPropertyB);
                        array_company1B[i]=12;
                        goto m;
                    }
                }
            }

            cout<<"\nChance "<<chance<<": "<<player1<<", what do want to do: buy(b)/sell(s)/pass(p)?";
            cin>>select;

            while(select!='b' && select !='s' && select!='p')
            {
                cout<<"\nInvalid input!\nEnter again."<<endl;
                cin>>select;
            }

            while(select=='b' && abs(price_per_share[0]*100)>cashB && abs(price_per_share[1]*100)>cashB && abs(price_per_share[2]*100)>cashB && abs(price_per_share[3]*100)>cashB && abs(price_per_share[4]*100)>cashB && abs(price_per_share[5]*100)>cashB)
            {
                cout<<"\nYou do not have enough cash to buy any company1";
                cout<<"\nChance "<<chance<<": "<<player1<<", what do want to do: buy(b)/sell(s)/pass(p)?";
                cin>>select;
            }
            while(select=='s' && sharesB[0]==0 && sharesB[1]==0 && sharesB[2]==0 && sharesB[3]==0 && sharesB[4]==0 && sharesB[5]==0)
            {
                cout<<"You do not have any shares to sell!";
                cout<<"\nChance "<<chance<<": "<<player1<<", what do want to do: buy(b)/sell(s)/pass(p)?";
                cin>>select;
            }

            if(select=='b'){

                int Whichcompany1;
                cout<<"\nWhich company1?"<<endl<<endl;

                for (int i=0;i<6;i++){
                    cout<<"For "<<company1(i)<<" press "<<i<<endl;
                }

                cin>>Whichcompany1;

                while(price_per_share[Whichcompany1]<=0 || price_per_share[Whichcompany1]*100>cashB){

                    if(price_per_share[Whichcompany1]<=0){

                    cout<<"\nYou cannot buy shares of a bankrupt company1!";
                    cout<<"\nEnter another company1"<<endl;
                    cin>>Whichcompany1;
                    }//checks that company1 to be bought is not bankrupt.

                    else if(price_per_share[Whichcompany1]*100>cashB){
                        cout<<"\nYou do not have enough cash to buy this company1!";
                        cout<<"\nEnter another company1"<<endl;
                        cin>>Whichcompany1;
                    }
                }

                int amountB;

                cout<<"\nHow much?  (Maximum you can buy is: "<<max_shares_inThouB[Whichcompany1]<<" )"<<endl;
                cin>>amountB;

                while(amountB*price_per_share[Whichcompany1]>cashB || (amountB+shares[Whichcompany1]+sharesB[Whichcompany1])>20000 || amountB%100!=0 ){

                    if(amountB*price_per_share[Whichcompany1]>cashB){

                        cout<<"\nNot enough cash! Enter according to max. shares you can buy.";
                        cout<<"\nHow much?  (Maximum you can buy is: "<<max_shares_inThouB[Whichcompany1]<<" )"<<endl;
                        cin>>amountB;
                    }//checks that player has sufficient cash to buy required amount of shares.

                    else if((amountB+shares[Whichcompany1]+sharesB[Whichcompany1])>20000)
                    {
                        cout<<"\nTotal shares for each company1 cannot exceed more than 20000";
                        cout<<"\nEnter again."<<endl;
                        cin>>amountB;
                    }

                    else if(amountB%100!=0){

                        cout<<"\nPlease enter number of shares in multiples of hundred only.";
                        cout<<"\nHow much?  (Maximum you can buy is: "<<max_shares_inThouB[Whichcompany1]<<" )"<<endl;
                        cin>>amountB;
                    }
                }

                sharesB[Whichcompany1]=sharesB[Whichcompany1]+amountB;
                cashB=cashB-(amountB*price_per_share[Whichcompany1]);

                cash_valueB.reset(150,570,cashB);

                for(int i=0; i<6; i++)
                {
                    shares_valueB[i].reset(600,345+15*i,sharesB[i]);
                }//updates the changed number of shares of each company1 that player has.
            }

            if(select=='s'){

                int Whichcompany1;
                cout<<"\nWhich company1?"<<endl<<endl;

                for (int i=0;i<6;i++){
                    cout<<"For "<<company1(i)<<" press "<<i<<endl;
                }

                cin>>Whichcompany1;

                while(price_per_share[Whichcompany1]<=0 || sharesB[Whichcompany1]==0){

                    if(price_per_share[Whichcompany1]<=0){

                        cout<<"\nYou cannot sell shares of a bankrupt company1!";
                        cout<<"\nEnter another company1"<<endl;
                        cin>>Whichcompany1;
                    }
                    else if(sharesB[Whichcompany1]==0)
                    {
                        cout<<"\nYou do not have any shares of this company1 to sell!";
                        cout<<"\nEnter another company1"<<endl;
                        cin>>Whichcompany1;
                    }
                }

                int amountB;
                cout<<"\nHow much?  (Maximum you can sell is: "<<sharesB[Whichcompany1]<<" )"<<endl;
                cin>>amountB;

                while(amountB>sharesB[Whichcompany1] || amountB%100!=0){

                    if(amountB>sharesB[Whichcompany1]){
                        cout<<"You cannot sell more than what you own! Enter again according to max. shares you can sell.";

                        cout<<"\nHow much?  (Maximum you can sell is: "<<sharesB[Whichcompany1]<<" )"<<endl;
                        cin>>amountB;
                    }

                    else if(amountB%100!=0){
                        cout<<"\nPlease enter number of shares in multiples of hundred only.";
                        cout<<"\nHow much?  (Maximum you can sell is: "<<sharesB[Whichcompany1]<<" )"<<endl;
                        cin>>amountB;
                    }
                }

                sharesB[Whichcompany1]=sharesB[Whichcompany1]-amountB;
                cashB=cashB+(amountB*price_per_share[Whichcompany1]);

                cash_valueB.reset(150,570,cashB);

                for(int i=0; i<6; i++)
                {
                    shares_valueB[i].reset(600,345+15*i,sharesB[i]);
                }//updates the changed number of shares of each company1 that player has.
            }

            m:for(int i=0; i<10; i++)
            {
                cardB[i].hide();
            }

            for(int i=0; i<10; i++)
            {
                pB[i].hide();
            }

            for(int i=0; i<6; i++)
            {
                netPB[i].hide();
            }

            cout<<"\nPass the computer to "<<player2<<"\nPress any key"<<endl;
            cin>>c;

            for(int i=0;i<10;i++)
            {
                card[i]={750,345.0+15.0*i,company1(array_company1[i])};
            }//name of companies on the 10 cards displayed.

            for(int i=0; i<10; i++)
            {
                if (array2[i]==0)
                    goto c;
                p[i]={810,345.0+15.0*i,array2[i]};
                c:;
            }//price fluctuations on the 10 cards displayed.

            for(int i=0; i<6; i++)
            {
                netP[i]={1060,345.0+15.0*i,net_fluctuation[i]};
            }//net fluctuation against each company1 displayed.

            for(int i=0; i<10; i++)
            {
                card[i].show();
            }

            for(int i=0; i<10; i++)
            {
                p[i].show();
            }

            for(int i=0; i<6; i++)
            {
                netP[i].show();
            }

            for(int i=0; i<10; i++)
            {
                if(array_company1[i]==8)
                {
                    cout<<"\nAlso,you have a Loan Stock Card, which awards Rs.1000 to you.\nWould you like to use it now?(y/n)"<<endl;
                    char ans;
                    cin>>ans;
                    while(ans!='n' && ans!='y')
                    {
                        cout<<"\nInvalid input!\nEnter again"<<endl;
                        cin>>ans;
                    }
                    if (ans=='n')
                    {

                    }
                    else if (ans=='y')
                    {
                        cash=cash+1000;
                        cash_value.reset(850,570,cash);
                        NetProperty+=1000;
                        Net_prop_value.reset(1050,570,NetProperty);
                        array_company1[i]=12;
                        goto n;
                    }
                }
            }
            cout<<"\nChance "<<chance<<": "<<player2<<", what do want to do: buy(b)/sell(s)/pass(p)?";
            cin>>select;

            while(select!='b' && select !='s' && select!='p')
            {
                cout<<"\nInvalid input!\nEnter again."<<endl;
                cin>>select;
            }

            while(select=='b' && abs(price_per_share[0]*100)>cash && abs(price_per_share[1]*100)>cash && abs(price_per_share[2]*100)>cash && abs(price_per_share[3]*100)>cash && abs(price_per_share[4]*100)>cash && abs(price_per_share[5]*100)>cash)
            {
                cout<<"\nYou do not have enough cash to buy any company1";
                cout<<"\nChance "<<chance<<": "<<player2<<", what do want to do: buy(b)/sell(s)/pass(p)?";
                cin>>select;
            }
            while(select=='s' && shares[0]==0 && shares[1]==0 && shares[2]==0 && shares[3]==0 && shares[4]==0 && shares[5]==0)
            {
                cout<<"You do not have any shares to sell!";
                cout<<"\nChance "<<chance<<": "<<player2<<", what do want to do: buy(b)/sell(s)/pass(p)?";
                cin>>select;
            }

            if(select=='b'){

                int Whichcompany1;
                cout<<"\nWhich company1?"<<endl<<endl;

                for (int i=0;i<6;i++){
                    cout<<"For "<<company1(i)<<" press "<<i<<endl;
                }

                cin>>Whichcompany1;

                while(price_per_share[Whichcompany1]<=0 || price_per_share[Whichcompany1]*100>cash){

                    if(price_per_share[Whichcompany1]<=0){

                        cout<<"\nYou cannot buy shares of a bankrupt company1!";
                        cout<<"\nEnter another company1"<<endl;
                        cin>>Whichcompany1;
                    }//checks that company1 to be bought is not bankrupt.

                    else if(price_per_share[Whichcompany1]*100>cash)
                    {
                        cout<<"\nYou do not have enough cash to buy this company1!";
                        cout<<"\nEnter another company1"<<endl;
                        cin>>Whichcompany1;
                    }
                }

                int amount;
                cout<<"\nHow much?  (Maximum you can buy is: "<<max_shares_inThou[Whichcompany1]<<" )"<<endl;
                cin>>amount;

                while(amount*price_per_share[Whichcompany1]>cash || (amount+shares[Whichcompany1]+sharesB[Whichcompany1])>20000 || amount%100!=0 ){

                    if(amount*price_per_share[Whichcompany1]>cash)
                    {
                        cout<<"\nNot enough cash! Enter according to max. shares you can buy.";
                        cout<<"\nHow much?  (Maximum you can buy is: "<<max_shares_inThou[Whichcompany1]<<" )"<<endl;

                        cin>>amount;
                    }//checks that player has sufficient cash to buy required amount of shares.

                    else if((amount+shares[Whichcompany1]+sharesB[Whichcompany1])>20000)
                    {
                        cout<<"\nTotal shares for each company1 cannot exceed more than 20000";
                        cout<<"\nEnter again."<<endl;
                        cin>>amount;
                    }

                    else if(amount%100!=0)
                    {
                        cout<<"\nPlease enter number of shares in multiples of hundred only.";
                        cout<<"\nHow much?  (Maximum you can buy is: "<<max_shares_inThou[Whichcompany1]<<" )"<<endl;
                        cin>>amount;
                    }
                }

                shares[Whichcompany1]=shares[Whichcompany1]+amount;
                cash=cash-(amount*price_per_share[Whichcompany1]);

                cash_value.reset(850,570,cash);

                for(int i=0; i<6; i++)
                {
                    shares_value[i].reset(1300,345+15*i,shares[i]);
                }//updates the changed number of shares of each company1 that player has.
            }

            if(select=='s'){

                int Whichcompany1;
                cout<<"\nWhich company1?"<<endl<<endl;

                for (int i=0;i<6;i++){
                    cout<<"For "<<company1(i)<<" press "<<i<<endl;
                }

                cin>>Whichcompany1;

                while(price_per_share[Whichcompany1]<=0 || shares[Whichcompany1]==0){

                    if(price_per_share[Whichcompany1]<=0){

                        cout<<"\nYou cannot sell shares of a bankrupt company1!";
                        cout<<"\nEnter another company1"<<endl;
                        cin>>Whichcompany1;
                    }
                    else if(shares[Whichcompany1]==0)
                    {
                        cout<<"\nYou do not have any shares of this company1 to sell!";
                        cout<<"\nEnter another company1"<<endl;
                        cin>>Whichcompany1;
                    }
                }
                int amount;
                cout<<"\nHow much?  (Maximum you can sell is: "<<shares[Whichcompany1]<<" )"<<endl;
                cin>>amount;

                while(amount>shares[Whichcompany1] || amount%100!=0){

                    if(amount>shares[Whichcompany1]){
                         cout<<"You cannot sell more than what you own! Enter again according to max. shares you can sell.";

                        cout<<"\nHow much?  (Maximum you can sell is: "<<shares[Whichcompany1]<<" )"<<endl;
                        cin>>amount;
                    }

                    else if(amount%100!=0){
                        cout<<"\nPlease enter number of shares in multiples of hundred only.";
                        cout<<"\nHow much?  (Maximum you can sell is: "<<shares[Whichcompany1]<<" )"<<endl;
                        cin>>amount;
                    }
                }

                shares[Whichcompany1]=shares[Whichcompany1]-amount;
                cash=cash+(amount*price_per_share[Whichcompany1]);

                cash_value.reset(850,570,cash);

                for(int i=0; i<6; i++)
                {
                    shares_value[i].reset(1300,345+15*i,shares[i]);
                }//updates the changed number of shares of each company1 that player has.
            }

            n:for(int i=0; i<10; i++)
            {
                card[i].hide();
            }

            for(int i=0; i<10; i++)
            {
                p[i].hide();
            }

            for(int i=0; i<6; i++)
            {
                netP[i].hide();
            }


            if(chance==3){
                cout<<"\nKeep the computer with you";
            }
            else{
                cout<<"\nPass the computer to "<<player1<<"\nPress any key"<<endl;
                cin>>c;
            }
        }

        cout<<"\n\nThis round has come to an end.\nBoth players can look at the screen now.\nPress any key to continue"<<endl;
        cin>>c;

        for(int i=0; i<10; i++)
            {
                card[i].show();
            }

        for(int i=0; i<10; i++)
            {
                p[i].show();
            }
        for(int i=0; i<6; i++)
            {
                netP[i].show();
            }

        for(int i=0; i<10; i++)
            {
                cardB[i].show();
            }

        for(int i=0; i<10; i++)
            {
                pB[i].show();
            }

        for(int i=0; i<6; i++)
            {
                netPB[i].show();
            }

        j=j+1;
        number+=1;
        int count_currency=0;
        int count_currency_neg=0;

        for(int i=0;i<10;i++)
        {
            if(array_company1[i]==10)
                count_currency+=1;
            if(array_company1B[i]==10)
                count_currency+=1;
            if(array_company1[i]==11)
                count_currency-=1;
            if(array_company1B[i]==11)
                count_currency-=1;
        }

        count_currency_neg=-count_currency;

        if(count_currency>=0)
        {   cash=cash+(cash*count_currency*10/100)-((cash*count_currency*10/100)%50);
            cashB=cashB+(cashB*count_currency*10/100)-((cashB*count_currency*10/100)%50);
        }
        else
        {
            cash=cash-(cash*count_currency_neg*10/100)+((cash*count_currency_neg*10/100)%50);
            cashB=cashB-(cashB*count_currency_neg*10/100)+((cashB*count_currency_neg*10/100)%50);
        }

        for(int i=0; i<10; i++)
        {
            if(array_company1[i]==6)
            {
                char ans;
                cout<<"\n"<<player2<<", you have a Share Suspend card.\nWould you like to use it?(y/n)"<<endl;
                cin>>ans;

                while(ans!='n' && ans!='y')
                {
                    cout<<"\nInvalid input!\nEnter again."<<endl;
                    cin>>ans;
                }
                if(ans=='y')
                {
                    cout<<"\nWhich company1 would you like to suspend shares of?"<<endl<<endl;
                    for (int i=0;i<6;i++)
                    {
                        cout<<"For "<<company1(i)<<" press "<<i<<endl;
                    }
                    int suspend_company1;
                    cin>>suspend_company1;
                    while(suspend_company1>5 || suspend_company1<0)
                    {
                        cout<<"\nInvalid input!\nEnter again"<<endl;
                        cin>>suspend_company1;
                    }
                    net_fluctuation[suspend_company1]=0;
                    net_fluctuationB[suspend_company1]=0;
                }
            }
        }

        for(int i=0; i<10; i++)
        {
            if(array_company1B[i]==6)
            {
                char ans;
                cout<<"\n"<<player1<<", you have a Share Suspend card.\nWould you like to use it?(y/n)"<<endl;
                cin>>ans;

                while(ans!='n' && ans!='y')
                {
                    cout<<"\nInvalid input!\nEnter again."<<endl;
                    cin>>ans;
                }
                if(ans=='y')
                {
                    cout<<"\nWhich company1 would you like to suspend shares of?"<<endl<<endl;
                    for (int i=0;i<6;i++)
                    {
                        cout<<"For "<<company1(i)<<" press "<<i<<endl;
                    }
                    int suspend_company1;
                    cin>>suspend_company1;
                    while(suspend_company1>5 || suspend_company1<0)
                    {
                        cout<<"\nInvalid input!\nEnter again"<<endl;
                        cin>>suspend_company1;
                    }
                    net_fluctuation[suspend_company1]=0;
                    net_fluctuationB[suspend_company1]=0;
                }
            }
        }

        for(int i=0;i<6;i++)
        {
            price_per_share[i]+=net_fluctuation[i]+net_fluctuationB[i];
        }

        for(int i=0; i<10; i++)
        {
            if(array_company1B[i]==9)
            {
                char ans;
                cout<<"\n"<<player1<<", you have a Debenture card.\nWould you like to use it?(y/n)"<<endl;
                cin>>ans;

                while(ans!='n' && ans!='y')
                {
                    cout<<"\nInvalid input!\nEnter again."<<endl;
                    cin>>ans;
                }
                if(ans=='y' && price_per_share[0]>0 && price_per_share[1]>0 && price_per_share[2]>0 && price_per_share[3]>0 && price_per_share[4]>0 && price_per_share[5]>0)
                {
                    cout<<"\nSorry! None  of the companies are bankrupt.\nThus, you cannot use debenture.\nPress any key to continue."<<endl;
                    cin>>c;
                }
                else if(ans=='y'){
                    cout<<"\nWhich company1 would you like to use it on?\nNote: You can only use it on a bankrupt company1"<<endl<<endl;
                    for (int i=0;i<6;i++)
                    {
                        cout<<"For "<<company1(i)<<" press "<<i<<endl;
                    }
                    int debenture_company1;
                    cin>>debenture_company1;
                    while(debenture_company1>5 || debenture_company1<0 || price_per_share[debenture_company1]>0)
                    {
                        cout<<"\nInvalid input!\nEnter again"<<endl;
                        cin>>debenture_company1;
                    }
                    price_per_share[debenture_company1]=start_price_per_share[debenture_company1];
                }
            }
        }

        for(int i=0; i<10; i++)
        {
            if(array_company1[i]==9)
            {
                char ans;
                cout<<"\n"<<player2<<", you have a Debenture card.\nWould you like to use it?(y/n)"<<endl;
                cin>>ans;

                while(ans!='n' && ans!='y')
                {
                    cout<<"\nInvalid input!\nEnter again."<<endl;
                    cin>>ans;
                }
                if(ans=='y' && price_per_share[0]>0 && price_per_share[1]>0 && price_per_share[2]>0 && price_per_share[3]>0 && price_per_share[4]>0 && price_per_share[5]>0)
                {
                    cout<<"\nSorry! None  of the companies are bankrupt.\nThus, you cannot use debenture.\nPress any key to continue."<<endl;
                    cin>>c;
                }
                else if(ans=='y'){
                    cout<<"\nWhich company1 would you like to use it on?\nNote: You can only use it on a bankrupt company1"<<endl<<endl;
                    for (int i=0;i<6;i++)
                    {
                        cout<<"For "<<company1(i)<<" press "<<i<<endl;
                    }
                    int debenture_company1;
                    cin>>debenture_company1;
                    while(debenture_company1>5 || debenture_company1<0 || price_per_share[debenture_company1]>0)
                    {
                        cout<<"\nInvalid input!\nEnter again"<<endl;
                        cin>>debenture_company1;
                    }
                    price_per_share[debenture_company1]=start_price_per_share[debenture_company1];
                }
            }
        }

        ShareProperty=0;
        SharePropertyB=0;

        for(int i=0;i<6;i++)
        {
            ShareProperty+=(shares[i]*price_per_share[i]);
            SharePropertyB+=(sharesB[i]*price_per_share[i]);
        }//updates the new value of price per share and share property.

        NetProperty=cash+ShareProperty;
        NetPropertyB=cashB+SharePropertyB;

        Net_prop_value.reset(1050,570,NetProperty);//displays the updated net property.
        Net_prop_valueB.reset(350,570,NetPropertyB);

        for(int i=0; i<10; i++)
            {
                card[i].hide();
            }

        for(int i=0; i<10; i++)
            {
                p[i].hide();
            }

        for(int i=0; i<6; i++)
            {
                netP[i].hide();
            }
        for(int i=0; i<10; i++)
            {
                cardB[i].hide();
            }

        for(int i=0; i<10; i++)
            {
                pB[i].hide();
            }

        for(int i=0; i<6; i++)
            {
                netPB[i].hide();
            }

    }

    ShareProperty=0;
    SharePropertyB=0;

    for(int i=0;i<6;i++)
    {
        ShareProperty+=(shares[i]*price_per_share[i]);
        SharePropertyB+=(sharesB[i]*price_per_share[i]);
    }//updates the new value of price per share and share property.

    NetProperty=cash+ShareProperty;
    NetPropertyB=cashB+SharePropertyB;

    Text Net_prop_value_1(1050,570,NetProperty);
    Text Net_prop_value_1B(350,570,NetPropertyB);
    Net_prop_value_1.imprint();
    Net_prop_value_1B.imprint();

    //displays the updated net property.

    Text cash_value_1(850,570,cash);
    cash_value_1.imprint();

    Text cash_value_1B(150,570,cashB);
    cash_value_1B.imprint();

    Text shares_value_1[6];
    Text shares_value_1B[6];
    for(int i=0; i<6; i++)
    {
        shares_value_1[i]={1300,345.0+15.0*i,shares[i]};
        shares_value_1[i].imprint();

        shares_value_1B[i]={600,345.0+15.0*i,sharesB[i]};
        shares_value_1B[i].imprint();
    }

    if(NetProperty>NetPropertyB)
    {
        cout<<"\n"<<player2<<" WINS!!";
    }

    else if(NetProperty<NetPropertyB)
    {
        cout<<"\n"<<player1<<" WINS!!";
    }

    else
    {
        cout<<"\nGAME TIED!!";
    }

    wait(5000);
}



