// ******************************************
// This Program was written by Steven Reynolds for an Assignment at Bournemouth University
// ******************************************


//Include Header Files
#include<iostream>
#include<cstring> 
#include<Windows.h>
#include<time.h>
#include<string.h>
using namespace std;

//Begin use of void Functions - Used to keep int main very clean.

void wordStorage (char wordStore[15]); // Store words
void callAscii (int livesLeft); 



//Begin game programming

int main()
{   //The use of the enum is to have a working menu system.
	enum gameState {Menu, Program, Exit};
	gameState state = Menu;
	int userChoice = 0;

	while(true)
	{
		switch(state)
		{
		case Menu:
			system("cls");
		
			cout << " _   _                                         \n";
			cout << "| | | |                                        \n";
			cout << "| |_| | __ _ _ __   __ _ _ __ ___   __ _ _ __  \n";
			cout << "|  _  |/ _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ \n";
			cout << "| | | | (_| | | | | (_| | | | | | | (_| | | | |\n";
			cout << "\\_| |_/\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_|\n";
			cout << "                    __/ |                      \n";
			cout << "                   |___/                       \n";


			cout << "Welcome to Hangman!\n"<<endl;
			cout << "What would you like to do!\n"<<endl;

			cout << "1.Play Hangman?\n"; 
			cout << "2.Leave Hangman?\n\n";
			cin >> userChoice;
			
			if(userChoice == 1)
				{
					state = Program;
				}
			else if(userChoice == 2)
			{
				exit(1);
			}

		case Program:
			system("cls");

			//Start up game parameters
		
			int Lives, letters, lose, win;		//Game Handles for Lives, Letters stored and	Lose and win conditions
			char hiddenWord[15]="wordStorage";	// Sets up hidden word
			wordStorage(hiddenWord);	
			letters=strlen(hiddenWord);
			cout <<"There are " <<letters<<" letters in the hidden word! Good luck!\n";
			//Initilize game parameters
				Lives = 6;
				lose = 0;
				win = 0;
				callAscii(Lives);
				//End
				
			char hideWord[15]="*";
			for(int i=0; i<letters; i++) 
				{
					hideWord[i]='*';
				}
			
			char guessLetter;
			do
			{
				system("cls");
				callAscii(Lives);
				lose =0;
				cout<<"This is a "<<letters<<" letter word! Can you guess it correctly?\n"<<endl;
				cout<<hideWord<<endl;
				cout<< "You have "<<Lives<<" lives Left!"<<endl;
				cout << "Guess a letter!\n\n"<<endl;
				
					cin >> guessLetter;
				
				for (int y=0; y<letters; y++)
				{
					if (hiddenWord[y]==guessLetter)
					{
						hideWord[y]=guessLetter;
					}
					else
					{
						lose = lose+1;
						if(lose==letters)
						{
							Lives=Lives-1;
						}
					}
				}
				if (Lives == 0)
				{
					win =2;
				}
				else if(strcmp (hideWord,hiddenWord) ==0)
				{
					win=1;
					cin.get();
					cin.get();
				}
				else
				{}
			}

			while(win==!1 || win==!2);
			if(win==1)
			{
				system("cls");

			cout << "__   __                     _       _			\n";
			cout << "\\ \\ / /                    (_)     | |		\n";
			cout << " \\ V /___  _   _  __      ___ _ __ | |		\n";
			cout << "  \\ // _ \\| | | | \\ \\ /\\ / / | '_ \\| |	\n";
			cout << "  | | (_) | |_| |  \\ V  V /| | | | |_|		\n";
			cout << "  \\_/\\___/ \\__,_|   \\_/\\_/ |_|_| |_(_)	\n"<<endl;
                                      
                                      
				cout<< "Well done! You have succesfully guessed the word!"<<endl<<endl;
				cout<< "The word was " << hideWord << ""<<endl;
				cout<< "What would you like to do?"<<endl;
				
				cout << "1.Play Again?"<<endl;
				cout << "2.Exit Game?\n";
				cin >> userChoice;

				if(userChoice = 1)
				{
					state = Program;
				}
				else if(userChoice = 2)
				{
					exit(1);
				}
		
			}
			else
			{
				system("cls");
				cout << "__   __            _                    _			\n";
				cout << "\\ \\ / /           | |                  | |		\n";
				cout << " \\ V /___  _   _  | |     ___  ___  ___| |		\n";
				cout << "  \\ // _ \\| | | | | |    / _ \\/ __|/ _ \\ |		\n";
				cout << "  | | (_) | |_| | | |___| (_) \\__ \\  __/_|		\n";
				cout << "  \\_/\\___/ \\__,_| \\_____/\\___/|___/\\___(_)	\n"<<endl;
				
				cout<< "Sorry you used all your lives up and are now dead!\n\n";
				cout<< "The word was "<<hiddenWord<<" Better luck next time!\n";
				cout << "1.Play Again?"<<endl;
				cout << "2.Exit Game?\n";
				cin >> userChoice;

				if(userChoice = 1)
				{
					state = Program;
				}
				else if(userChoice = 2)
				{
					exit(1);
				}
		
				
			}
		}
	}
}

void wordStorage (char wordBank[])
{
	srand(time(NULL));
	int num=rand() % 10;
	switch(num)
	{
		
		case 0:
		{
			strcpy(wordBank, "dayz");
			break;
		}
		case 1:
		{
			strcpy(wordBank, "snow");
			break;
		}
		case 2:
		{
			strcpy(wordBank, "terraria");
			break;
		}
		case 3:
		{
			strcpy(wordBank, "rust");
			break;
		}
		case 4:
		{
			strcpy(wordBank, "forest");
			break;
		}
			case 5:
		{
			strcpy(wordBank, "evolve");
			break;
		}
			case 6:
		{
			strcpy(wordBank, "amnesia");
			break;
		}
			case 7:
		{
			strcpy(wordBank, "payday");
			break;
		}
			case 8:
		{
			strcpy(wordBank, "hearthstone");
			break;
		}

		
	}
}
void callAscii (int livesLeft)
{
	switch(livesLeft)
	{
	case 0:
		cout<< "Game Over!";
		break;
	case 1:
			cout << "_______" << endl;
			cout << "|     |" << endl;
			cout << "|     o" << endl;
			cout << "|    /X\\" << endl;
			cout << "|    / \\" << endl;
			cout << "|" << endl;
			break;
	case 2:
			cout << "_______" << endl;
			cout << "|     |" << endl;
			cout << "|     o" << endl;
			cout << "|    /X\\" << endl;
			cout << "|    /" << endl;
			cout << "|" << endl;
		break;
	case 3:
			cout << "_______" << endl;
			cout << "|     |" << endl;
			cout << "|     o" << endl;
			cout << "|    /X\\" << endl;
			cout << "|" << endl;
			cout << "|" << endl;
		break;
	case 4:
			cout << "_______" << endl;
			cout << "|     |" << endl;
			cout << "|     o" << endl;
			cout << "|    /X" << endl;
			cout << "|" << endl;
			cout << "|" << endl;
		break;
	case 5:
			cout << "_______" << endl;
			cout << "|     |" << endl;
			cout << "|     o" << endl;
			cout << "|    /" << endl;
			cout << "|" << endl;
			cout << "|" << endl;
			break;
	case 6:
			cout << "_______" << endl;
			cout << "|     |" << endl;
			cout << "|     o" << endl;
			cout << "|" << endl;
			cout << "|" << endl;
			cout << "|" << endl;
			break;
	}
}




