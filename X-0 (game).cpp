/*
X 0 game in c++ by AmriT PaL SingH
*/
#include <iostream>
#include <limits>
using namespace std;

char value[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };


void
layout (char value[]) 
{
  cout << endl;
  
cout << "\t\t   \t| \t| \t" << endl;
  
cout << "\t\t    " << value[0] << "\t|   " << value[1] << "\t|   " <<
    value[2] << "\t" << endl;
  
cout << "\t\t _______|_______|_______" << endl;
  
cout << "\t\t   \t| \t| \t" << endl;
  
cout << "\t\t    " << value[3] << "\t|   " << value[4] << "\t|   " <<
    value[5] << "\t" << endl;
  
cout << "\t\t _______|_______|_______" << endl;
  
cout << "\t\t   \t| \t| \t" << endl;
  
cout << "\t\t    " << value[6] << "\t|   " << value[7] << "\t|   " <<
    value[8] << "\t" << endl;
  
cout << "\t\t        |       |       " << endl;

 
} 
int

winner (char value[]) 
{
  
int i;
  
for (i = 0; i < 9; i++)
    {
      
if (value[i] == value[i + 1] && value[i + 1] == value[i + 2])
	return 1;
      
i = i + 2;
    }
  
if ((value[0] == value[4] && value[4] == value[8])
       || (value[2] == value[4] && value[4] == value[6]))
    return 1;
  
for (i = 1; i <= 3; i++)
    if ((value[i - 1] == value[i + 2]) && (value[i + 2] == value[i + 5]))
      return 1;
  
return 0;

 
}


int
main () 
{
  
cout << "Press Enter to start the game\t";
  cin.ignore (std::numeric_limits < streamsize >::max (), '\n');
  
cout << "Welcome (: \nX is for player 1\n0 is for player 2\n";
  
char choice;
  int ch = 0, result = 0, f = 0, p1 = 0, p2 = 0, draw_Check = 0;	// choice if for rules and starting game, ch for position of X and 0, result is for checking winner, and f is for ending game, p1 and p2 are for respective scores
  cout <<
    "Enter R for rules, how to play or\nsimply press P to play\nEnter 0 to exit the game\n";
  
cin >> choice;
  
while (choice != '0')
    
    {
      f = 0;
      char value[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
      
if (choice == 'r' || choice == 'R')
	
	{
	  
cout << "Below you can see layout of the game\n";
	  
layout (value);
	  
cout <<
	    "\nSay you have to enter X or 0 at centre that is 5\n press 5, like this yu can play the game.\nIn order to win you have to get 3(X or 0)\nHorizontally,\nVertically,or\nDiagonally";
	  
cout <<
	    "\nEnter R for rules, how to play or simply press P to play\nEnter 0 to exit the game\n";
	  
cin >> choice;
	
}
      
      else if (choice == 'p' || choice == 'P')
	
	{			//value[1]='x',value[5]='x',value[9]='x'; int res=winner(value); if(res==1) cout<<"Ap won\n";
	  layout (value);
	  
while (true)
	    
	    {
	      
while (true)
		
		{
		  
cout <<
		    "Player 1 turn\nEnter place where you want to enter X\n";
		  
cin >> ch;
		  
if (ch >= 1 && ch <= 9 && value[ch - 1] != '0'
		       && value[ch - 1] != 'X')
		    
		    {
		      draw_Check++;
		      
value[ch - 1] = 'X';
		      
result = winner (value);
		      
if (result == 1)
			{
			  f = 1;
			  p1++;
			  layout (value);
			  cout << " (: AP won :)\n";
			  break;
			}
		      
break;
		    
}
		  
		  else if (ch < 1 && ch > 9)
		    cout << "Please enter a valid position\n";
		  
		  else
		    cout << "Cheating is not allowed\n";
		
}
	      
if (draw_Check == 5&&result!=1)
		{
		  cout << "It's a Draw\n";
		  break;
		}
	      
if (f == 1)
		break;
	      
	      else
		layout (value);
	      
while (true)
		
		{
		  
cout <<
		    "Player 2 turn\nEnter place where you want to enter 0\n";
		  
cin >> ch;
		  
if (ch >= 1 && ch <= 9 && value[ch - 1] != 'X'
		       && value[ch - 1] != '0')
		    
		    {
		      
value[ch - 1] = '0';
		      result = winner (value);
		      
if (result == 1)
			{
			  f = 1;
			  p2++;
			  layout (value);
			  cout << " (: AP won :)\n";
			  break;
			}
		      
break;
		    
}
		  
		  else if (ch < 1 && ch > 9)
		    cout << "Please enter a valid position\n";
		  
		  else
		    cout << "Cheating is not allowed\n";
		
}
	      
if (f == 1)
		break;
	      else
		layout (value);
	    
}
	  
while (true)
	    
	    {
	      
cout << "Game " << p1 +
		p2 << " is over\nScore is " << p1 << "-" << p2 <<
		"\nPress P to start new game OR press 0 to exit\n";
	      
cin >> choice;
	      
if (choice == 'P' || choice == 'p' || choice == '0')
		break;
	      
	      else
		cout << "Enter a valid Input\n";
	    
}
	
}
      
      else
	
	{
	  
cout << "Invalid Input\n";
	  
cout <<
	    "Enter R for rules, how to play or simply press P to play\nEnter 0 to exit the game\n";
	  
cin >> choice;
	
}
    
}
  
return 0;

}


 


