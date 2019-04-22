#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
using namespace std;
void print(int board[4][4])   //prints the grid
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<"["<<board[i][j]<<"] \t";
		}
		cout<<endl;
	}
}															
void moveup(int (&board)[4][4])   //moves up
{
	for(int j=0;j<4;j++)
	{
		//moves everything close together
		for(int l=0;l<3;l++)
		{
			for(int k=0;k<3;k++)
			{								
				if((board[k][j]==0)&&(board[k][j]!=board[k+1][j]))
				{
					board[k][j]=board[k+1][j];
					board[k+1][j] = 0;
				}
			}
		}
		//stop
		//adds numbers together
		int i=0;
		if((board[i][j]==board[i+1][j])&&(board[i][j]!=0))
		{
			board[i][j]=(2*board[i][j]);
			board[i+1][j]=board[i+2][j];
			board[i+2][j]=board[i+3][j];
			board[i+3][j]=0;
		}
		i=1;
		if((board[i][j]==board[i+1][j])&&(board[i][j]!=0))
		{
			board[i][j]=(2*board[i][j]);
			board[i+1][j]=board[i+2][j];
			board[i+2][j]=0;
		}
		i=2;
		if((board[i][j]==board[i+1][j])&&(board[i][j]!=0))
		{
			board[i][j]=(2*board[i][j]);
			board[i+1][j]=0;
		}
		//stop
	}	
}
void movedown(int (&board)[4][4])   //moves down
{
	for(int j=0;j<4;j++)
	{
		//moves everything close together
		for(int l=0;l<3;l++)
		{
			for(int k=3;k>0;k--)
			{								
				if((board[k][j]==0)&&(board[k][j]!=board[k-1][j]))
				{
					board[k][j]=board[k-1][j];
					board[k-1][j] = 0;
				}
			}
		}
		//stop
		//adds numbers together
		int i=3;
		if((board[i][j]==board[i-1][j])&&(board[i][j]!=0))
		{
			board[i][j]=(2*board[i][j]);
			board[i-1][j]=board[i-2][j];
			board[i-2][j]=board[i-3][j];
			board[i-3][j]=0;
		}
		i=2;
		if((board[i][j]==board[i-1][j])&&(board[i][j]!=0))
		{
			board[i][j]=(2*board[i][j]);
			board[i-1][j]=board[i-2][j];
			board[i-2][j]=0;
		}
		i=1;
		if((board[i][j]==board[i-1][j])&&(board[i][j]!=0))
		{
			board[i][j]=(2*board[i][j]);
			board[i-1][j]=0;
		}
	}
}
void moveleft(int (&board)[4][4])   //moves left
{
	for(int i=0;i<4;i++)
	{
		//moves everything close together
		for(int l=0;l<3;l++)
		{
			for(int k=0;k<3;k++)
			{								
				if((board[i][k]==0)&&(board[i][k]!=board[i][k+1]))
				{
					board[i][k]=board[i][k+1];
					board[i][k+1] = 0;
				}
			}
		}
		//stop
		//adds numbers together
		int j=0;
		if((board[i][j]==board[i][j+1])&&(board[i][j]!=0))
		{
			board[i][j]=(2*board[i][j]);
			board[i][j+1]=board[i][j+2];
			board[i][j+2]=board[i][j+3];
			board[i][j+3]=0;
		}
		j=1;
		if((board[i][j]==board[i][j+1])&&(board[i][j]!=0))
		{
			board[i][j]=(2*board[i][j]);
			board[i][j+1]=board[i][j+2];
			board[i][j+2]=0;
		}
		j=2;
		if((board[i][j]==board[i][j+1])&&(board[i][j]!=0))
		{
			board[i][j]=(2*board[i][j]);
			board[i][j+1]=0;
		}
		//stop
	}
}
void moveright(int (&board)[4][4])   //moves right
{
	for(int i=0;i<4;i++)
	{
		//moves everything close together
		for(int l=0;l<3;l++)
		{
			for(int k=3;k>0;k--)
			{								
				if((board[i][k]==0)&&(board[i][k]!=board[i][k-1]))
				{
					board[i][k]=board[i][k-1];
					board[i][k-1] = 0;
				}
			}
		}
		//stop
		//adds numbers together
		int j=3;
		if((board[i][j]==board[i][j-1])&&(board[i][j]!=0))
		{
			board[i][j]=(2*board[i][j]);
			board[i][j-1]=board[i][j-2];
			board[i][j-2]=board[i][j-3];
			board[i][j-3]=0;
		}
		j=2;
		if((board[i][j]==board[i][j-1])&&(board[i][j]!=0))
		{
			board[i][j]=(2*board[i][j]);
			board[i][j-1]=board[i][j-2];
			board[i][j-2]=0;
		}
		j=2;
		if((board[i][j]==board[i][j-1])&&(board[i][j]!=0))
		{
			board[i][j]=(2*board[i][j]);
			board[i][j-1]=0;
		}
		//stop
	}
}
bool validmove(bool v,int board[4][4],int boardcopy[4][4])   //checks if move is valid
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(!(board[i][j]==boardcopy[i][j]))
			{
				v=true;
			}
		}
	}
	return v;
}
int countzero(int board[4][4])   //counts total no. zeroes
{
	int n=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(board[i][j]==0){n++;}
		}
	}
	return n;
}
void spawnrandom(int n,int (&board)[4][4])   //spawns 2 in random square
{
	int spawn=1+(rand()%n);
	int p=0;
	bool spawn2=true;
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			if(board[i][j]==0){p++;}
			if((p==spawn)&&(spawn2==true))
			{
				board[i][j]=2;
				spawn2=false;
			}
		}
	}
}
bool endgamecheck(bool c1,bool c2,int board[4][4])   //checks for possible moves
{
	c1=false;
	c2=true;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if((j>0)&&(board[i][j]==board[i][j-1])){c1=true;}
			else if((i>0)&&(board[i][j]==board[i-1][j])){c1=true;}
			c2=c1;
		}
	}
	return c2;
}
int main()
{
	int grid[4][4];   //initialises 4x4 array
	for(int i=0;i<4;i++)   //gives values to grid as a default
	{
		for(int j=0;j<4;j++)
		{
			if((i==3)&&(j==3))
			{
				grid[i][j]=2;
			}
			else
			{
				grid[i][j]=0;
			}
		}
	}	
	ifstream infile;   //prepares to open a file
	string configfile;
	cout<<"enter initial configuration file name"<<endl;
	cin>>configfile;   //takes user input for file name
	infile.open(configfile.c_str());   //opens config file
	if(infile.is_open())   //makes start=configfile
	{
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				infile>>grid[i][j];
			}
		}
	}
	if(!(infile.is_open()))   //if file cannot open, continues with default array
	{
		cout<<"file not found, using default start configuration"<<endl;
	}
	print(grid);   //prints grid
	string direction;
	bool end=false;
	while(end==false)   //loops until end=true
	{
		srand(time(NULL));   //makes random seed=time
		int gridcopy[4][4];   //makes a copy of grid
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				gridcopy[i][j]=grid[i][j];
			}
		}
		cin>>direction;   //direction functions
		if(direction=="w")
		{
			moveup(grid);
		}
		if(direction=="s")
		{
			movedown(grid);	
		}
		if(direction=="a")
		{
			moveleft(grid);	
		}
		if(direction=="d")
		{
			moveright(grid);	
		}
		bool valid=false;
		valid=validmove(valid,grid,gridcopy);			
		if(valid==true)   //will continue if move was valid
		{		
			int z=countzero(grid);   //counts the number of zeroes
			if(z>0)   //if empty squares exist:
			{
				spawnrandom(z,grid);   //spawns a 2 in a random empty space
			}
			print(grid);
			z=countzero(grid);
			bool cont=false;
			bool cont2=true;
			if(z==0)   //if no empty squares exist:
			{
				cont2=endgamecheck(cont,cont2,grid);   //checks to see if any adjacent squares are same
			}
			if(cont2==false)   //if no same squares found:
			{
				end=true;   //exits while loop
				cout<<"GAME OVER"<<endl;
			}
		}
	}
	cout<<"thank you for playing"<<endl;
	return 0;
}
