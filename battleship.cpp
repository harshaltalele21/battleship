#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
class battleship
{
	private:
	char arr[5][5];
	int set_row1[2][2],set_col1[2][2],count,count1,wins1,wins2; //count and count 1 are for ship 1 and ship 2...... wins1 for player 1 win and wins2 for player 2 win
	string player1,player2;
	public:
	/*************CONSTRUCTOR**************/
	battleship()
	{
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				arr[i][j]='O';
				
			}
		}
		count=count1=wins1=wins2=0;	
		player1="Player_1",player2="Player_2";	
	}
	void init()
	{
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				arr[i][j]='O';
				
			}
		}
		count=count1=0;	
	}
	/**************HIDING THE SHIP IN THE OCEAN*******************/
	void hide_ship()
	{  
	    init();
	    int n=0,j=0;
	    
	   for(j=0;j<2;j++)         //to include 2 ships
	   {
	       cout<<"\nHide ship no: "<<j+1;
			do
			{   
				int flag=0;              //for breaking the loop if same input exists in 2 ships
				cout<<"\nEnter row:";
				system("stty -echo");
				cin>>set_row1[j][n];
				system("stty echo");
				cout<<"\nEnter column:";
				system("stty -echo");
				cin>>set_col1[j][n];
				system("stty echo");
				if(set_row1[j][n]>5 || set_col1[j][n]>5)
				{
					cout<<"\nShip is being placed out of the ocean";
					continue;
				}	
				if(j==1)              // for second ship
				{
					for(int k=0;k<2;k++)
					{
						
						if(set_row1[1][n]==set_row1[0][k] && set_col1[1][n]==set_col1[0][k])
						{
							
						 	cout<<"\nYou gave the same input! Redo..";
						 	flag=1;
						 	break;
						}
								
					}
					if(flag==1)
						continue;	
				}  //If ends here
				if(n==0)               //for second hide
				{
					n++;
					continue;
				}
				else
				{
					if(( (set_row1[j][n]==set_row1[j][n-1]) && ((set_col1[j][n]==set_col1[j][n-1]+1)||(set_col1[j][n]==set_col1[j][n-1]-1)) ) || ( (set_col1[j][n]==set_col1[j][n-1]) && ((set_row1[j][n]==set_row1[j][n-1]+1)||(set_row1[j][n]==set_row1[j][n-1]-1)) ))
					
					// for adjacent inputs as ship is 2 boxes long
					{
						n++;
						continue;
					}
					else
					{
						cout<<"\nThe inputs should be adjacent! Redo..";
					} 
				}
				
			}while(n!=2);
			
			n=0;                       //for setting hide counter of 2d array to 0
	  }	
		
	/*******************SHIP DISPLAY******************/	
	}
	void display()         //displaying the ocean
	{
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				cout<<arr[i][j]<<" ";
				
			}
			cout<<"\n";
		}		
	}
	/********************GUESSING****************/
	void guess()
	{
		
		init();
		int turn=5,guess_row,guess_col,aa=0;
		
		do
		{
			
		    	display();
		        cout<<"\nTurns left:"<<turn<<"\n";
			cout<<"\nEnter row:";
			cin>>guess_row;
			cout<<"\nEnter column:";
			cin>>guess_col;
			int i,j,flag=0,flag1=0;
			for(i=0;i<2;i++)            //for length 2 of the ship 
			{
				for(j=0;j<2;j++)          //checking with every element of 2d array
				{ 
					for(int k=0;k<2;k++)          //checking with every element of 2d array
					{
						if(guess_row==set_row1[j][k] && guess_col==set_col1[j][k])      //for checking if ship part exists
						{
							if(arr[set_row1[j][k]-1][set_col1[j][k]-1]=='#')
							{
								cout<<"\nAlready found\n";
								flag1=1;
								break;
								
							}
							else
							{
								cout<<"\nHit Confirmed!\n";
								
								if((j==0 &&k==0)||(j==0&&k==1))        //for hits of ship 1
								count++;
								if((j==1 &&k==0)||(j==1&&k==1))        //for hits of ship 2 
								count1++;
								arr[set_row1[j][k]-1][set_col1[j][k]-1]='#';     //revealing that ship exists
								flag=1;
								break;
							}	
								
						}
						if(flag==1)
							break;
						if(flag1==1)
							break;	  
							          //for breaking j loop if ship hit confirmed
					}	
				}
				
				if(flag==1)                              //for breaking i loop if ship hit confirmed
					break;
				if(flag1==1)
					break;	
				                  
						
					if (guess_row>5 || guess_col>5)
					{
						cout<<"\nUse your brains! Its just a 5x5 grid\n";
						break;
				
					}
					else 
					{
						if(arr[guess_row-1][guess_col-1]=='X')
						{
							cout<<"\nAlready done with this! Redo..\n";
							break;
						}
						else
						{	
							continue;
						}	
					}
			}
			if(aa==0)
			{	
				if(count==2 || count1==2)
				{
					cout<<"Ship found\n";
					aa++;
				}
			}
			if(i==2)                                          //fail to hit the ship
			{
				cout<<"\nTry harder\n";
				arr[guess_row-1][guess_col-1]='X';
				turn--;
			}
			if(count==2 && count1==2)                        // both ships found
			{
				cout<<"Both Ships found\n";
				break;
			}
		}while(turn!=0);
		
		
		
		if(count==2 && count1==2)
		{
			
			display();
			cout<<"\n\nCONGRATULATIONS!!!!";             //both ships found
			
		}
			
		if(turn==0)                                      // game over
		{
			cout<<"\n Game Over.Train your brain harder\n";
			
			for(int i=0;i<2;i++)
			{
				for(int j=0;j<2;j++)
					arr[set_row1[i][j]-1][set_col1[i][j]-1]='#';              //revealing both the hidden ships
			}
				
			display();
			cout<<"\nThe ship was hidden here";
			
		}
		
	}
	
	void results()
	{
		ifstream f;
		int a;
		string name;
		f.open("gamedata.dat",ios::in);
		f>>name>>a;
		cout<<"\nName:"<<name<<"\nWins:"<<a;
		f>>name>>a;
		cout<<"\nName:"<<name<<"\nWins:"<<a;
		f.close();
		
	}
	/***************PLAYER ONE WIN COUNTING*****************/
	void player_1()
	{
	        ofstream f;
		f.open("gamedata.dat",ios::out);
		if(count==2 && count1==2)   // to see if player 2 found both ships or not
			wins2++;
		else 
			wins1++;	
			
		f<<player1<<"\n"<<wins1;
		f<<player2<<"\n"<<wins2;
		f.close();
	}
	/***************PLAYER TWO WIN COUNTING******************/
	void player_2()
	{
	    	fstream f;
		f.open("gamedata.dat",ios::out);
		if(count==2 && count1==2)           // to see if player 1 found both ships or not
			wins1++;
		else 
			wins2++;	
			
		f<<player1<<"\n"<<wins1;
		f<<player2<<"\n"<<wins2;
		f.close();
	}
	
};

/*******************CLASS ENDS******************/
main()
{
	battleship b1;
	int ch,ch1;
	system("clear");
	cout<<"\nWELCOME TO BATTLESHIP.\nThe objective of the game is to find 2 hidden ships in the ocean\n.There are two ships to be hidden in the ocean.\nBoth the ships are of length 2.\nOne player will hide the ship somewhere in the ocean and the other will have 5\n chances to find both the hidden ships.\n Winner is decided if the player finding the ships finds both the ships or if he fails to find the ships.\n";
	cin.get();
	system("clear");
	do
	{
		
		cout<<"\n1.START the Game\n2.View RESULTS\n3.Exit\n\nEnter the choice: ";
		cin>>ch;
			switch(ch)
			{
				case 1:
				{
					cout<<"\n1.Player 1 hides";
					cout<<"\n2.Player 2 hides";
					cout<<"\nEnter your choice:";
					cin>>ch1;
					switch(ch1)
					{
						case 1:	
							{
							        b1.init();
								b1.display();
								b1.hide_ship();
								system("clear");
								b1.guess();
								b1.player_1();
								break;
							}
						case 2:
							{
								b1.init();
								b1.display();
								b1.hide_ship();
								system("clear");
								b1.guess();
								b1.player_2();
								break;
							}	
							default:
								cout<<"\nWrong input";
					}  
					break;
				}
				case 2:
				{
				  	b1.results();
				  	break;
				}
			}
	}while(ch!=3);
}

