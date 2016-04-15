/*************************************
**  Name:   Josh Jurss				**
**	Date:	Nov 15, 2015			**
** 	Lab:	Final					**
**	Desc:	Battleship				**
*************************************/
#include <iostream>
#include <string>
#include <fstream> 
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
#include<algorithm>
#include <windows.h>
#include <stdlib.h>
#include <time.h>  
#include <windows.h> 
#include <stdio.h> 

WORD Attributes = 0;

using namespace std; 
ofstream ofs("jurss_final.txt");
/*************************************
**		  ---Variables---			**
*************************************/
string no = "EOF MESSAGE: ";
string hard = "Josh Jurss ";  
string coding = "Dec 12, 2015 ";
string of = "Battleship ";
string labn = "Final ";
string course = "CIS2542-001 ";
string anything = "Cheers!";
string sp = " ";
string star =
"|-----------------------------------------------------------------------------|";
string star2 = 
"|=============================================================================|";
string rstar = " |";
string lstar = "| ";
string lstar2 = " || ";
string header = "---Battleship Statistics---";
string sl = "/";
string co = ", ";
string colon = ":";
string qu = "?";
string pcnt = "%";
string err = "ERROR: Input must be between 1-3 \n"
"Please try again: ";
string err7 = "ERROR: Input must be between 1-7 \n"
"Please try again: ";
string shipDuplicate = 
"|=============================================================================|\n"	
"| ERROR : That ship has already been entered. Please select another...        |";
string entCompGuess = "Hit Enter for Computer Guess";
string dispCompGuess = "Computer Guesses: " ;
string dispHit = " HIT!";
string dispMiss = " MISS!";
string gameNumb = "Game ";
string hits = "  Hit: ";
string misses = "  Miss: ";
string hitPnct = "  Hit Percentage: ";
string shots = " Shots: ";
string input;
int menuSelection;
int number;
int z = 0;
int o = 1;
int row = 10;
int column = 10;
int r;
int col;
int dir;
int patrolBoat = 2;
int destroyer = 3;
int submarine = 3;
int battleship = 4;
int aCarrier = 5;
int el = 11;
char columnLetter;
int check = 1;
int rCheck, colCheck;
int hund = 100;
int test;
int health = 0;
int times;
/*************************************
**	   ---Counter Variables---		**
*************************************/
int carrierCount, battleshipCount, subCount, destroyerCount, patrolCount = 0;
int gameCount = 0;
double totGuessCount = 0, hitCount = 0, missCount = 0;
double shotRatio;
int i, j, k;
int shoot;
/*************************************
**	   ---Board Variables---		**
*************************************/
int gameBoard[10][10];
char colHead[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
int rowHead[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
char hit = 'X';
char miss = '-';
/*************************************
**	   ---Guess Variables---		**
*************************************/
int rowGuess, colGuess, compGuess;
char letterGuess;
int gameOver = 0;
int guess = 1;
/*************************************
**	 ---Good looking Menu Prints---	**
*************************************/
string healthBar = 
"|                        HEALTH |";
string titleScreen = 
"\n|=============================================================================|\n"
"| ____              __    __    ___                   __                      |\n"
"|/\\   `\\           /\\ \\__/\\ \\__/\\_ \\                 /\\ \\      __             |\n"
"|\\ \\ \\L\\ \\         \\ \\ ,_\\ \\ ,_\\//\\ \\      __    ____\\ \\ \\___ /\\_\\  _____     |\n"
"| \\ \\  _ <'  /'__`\\ \\ \\ \\/\\ \\ \\/ \\ \\ \\   /'__`\\ /',__\\\\ \\  _ `\\/\\ \\/\\ '__`\\   |\n"
"|  \\ \\ \\L\\ \\/\\ \\L\\.\\_\\ \\ \\_\\ \\ \\_ \\_\\ \\_/\\  __//\\__, `\\\\ \\ \\ \\ \\ \\ \\ \\ \\L\\ \\  |\n"
"|   \\ \\____/\\ \\__/.\\_\\\\ \\__\\\\ \\__\\/\\____\\ \\____\\/\\____/ \\ \\_\\ \\_\\ \\_\\ \\ ,__/  |\n"
"|    \\/___/  \\/__/\\/_/ \\/__/ \\/__/\\/____/\\/____/\\/___/   \\/_/\\/_/\\/_/\\ \\ \\/   |\n"
"|                                                                     \\ \\_\\   |\n"
"|                                                                      \\/_/   |\n";
string titleScreen2 =
"|=============================================================================|\n"
"|                  A Program of a Popular Game by Josh Jurss                  |\n"
"|                           PRESS ENTER TO BEGIN                              |\n"
"|=============================================================================|\n";
string dispGameOver =
"\n|=============================================================================|\n"
"|  _______  _______  __   __  _______    _______  __   __  _______  ______    |\n"
"| |       ||   _   ||  |_|  ||       |  |       ||  | |  ||       ||    _ |   |\n"
"| |    ___||  |_|  ||       ||    ___|  |   _   ||  |_|  ||    ___||   | ||   |\n"
"| |   | __ |       ||       ||   |___   |  | |  ||       ||   |___ |   |_||_  |\n"
"| |   ||  ||       ||       ||    ___|  |  |_|  ||       ||    ___||    __  | |\n"
"| |   |_| ||   _   || ||_|| ||   |___   |       | |     | |   |___ |   |  | | |\n"
"| |_______||__| |__||_|   |_||_______|  |_______|  |___|  |_______||___|  |_| |\n"
"|                                                                             |\n";
                                                                                          
string menu1 =
"\n|=============================================================================|\n"
"|                          What would you like to do?                         |\n"
"|-----------------------------------------------------------------------------|\n"
"|  1. Rules                                                                   |\n"
"|-----------------------------------------------------------------------------|\n"
"|  2. Set Ship Locations and Begin Game                                       |\n"
"|-----------------------------------------------------------------------------|\n"
"|  3. Set Ship Locations/ Begin CLUSTER SHOT VERSION (AKA 10 SHOTS AT ONCE)   |\n"
"|-----------------------------------------------------------------------------|\n"
"|  4. Print Stats and Exit                                                    |\n"
"|=============================================================================|\n"
"| Selection: ";
string menu1_1 =
"\n|=============================================================================|\n"
"|                          Which ship are you placing?                        |\n"
"|-----------------------------------------------------------------------------|\n"
"|  1. Aircraft Carrier (5 spots)                                              |\n"
"|-----------------------------------------------------------------------------|\n"
"|  2. Battleship (4 spots)                                                    |\n"
"|-----------------------------------------------------------------------------|\n"
"|  3. Submarine (3 spots)                                                     |\n"
"|-----------------------------------------------------------------------------|\n"
"|  4. Destroyer (3 spots)                                                     |\n"
"|-----------------------------------------------------------------------------|\n"
"|  5. Patrol Boat (2 spots)                                                   |\n"
"|-----------------------------------------------------------------------------|\n"
"|  6. See Current Board Layout/Ship Placements                                |\n"
"|-----------------------------------------------------------------------------|\n"
"|  7. Done! Proceed with Computer Generated Guessing!                         |\n"
"|=============================================================================|\n"
"| Selection: ";
string overlap = 
"|=============================================================================|\n"
"| ERROR: Ship placement overlaps another ship. Please try again!              |\n"
"|=============================================================================|\n";
string offBoard = 
"|=============================================================================|\n"
"| ERROR: Ship placement extends off the board. Please try again!              |\n"
"|=============================================================================|\n";
string enterShip = 
"| Enter Column and Row of Edge of Ship                                        |\n"
"| EXAMPLE: B3 ( equal to Column B - Row 3)                                    |\n"
"|=============================================================================|\n"
"| Selection: ";
string directionSelection = 
"|=============================================================================|\n"
"| Choose ship direction from spot: UP (1), DOWN (2) , LEFT (3) , or RIGHT (4) |\n"
"|=============================================================================|\n"
"| Selection: ";
string successPlacement = 
"|=============================================================================|\n"
"|                      Ship has been successfully placed!                     |\n"
"|=============================================================================|\n";
string cont = 
"|=============================================================================|\n"
"|                       ---Press ENTER to Continue---                         |\n"
"|=============================================================================|\n";
string allPlaced = 
"|=============================================================================|\n"
"|  All BATTLESHIPS have been placed...         ---ENTER 7 to Continue---      |\n"
"|=============================================================================|";
string errBoard = 
"|=============================================================================|\n"
"| ERROR: You must enter a grid number between 1 and 10 -- ENTER TO CONTINUE   |\n"
"|=============================================================================|\n";
string rules =
"\n|=============================================================================|\n"
"|                              HOW TO PLAY                                    |\n"
"|=============================================================================|\n"
"| This version of Battleship is a game of chance and luck and you command a   |\n"
"| squadron of 5 ships, placing them strategically in the waters of the Pacific|\n"
"| while the computer guesses where your ships are by shooting them out of the |\n"
"| water.                                                                      |\n"
"|   I. Place Ships                                                            |\n"
"|      Choose the ship you would like to place on the grid. The game will     |\n"
"|      prompt you for a square to start the ship at then a direction to have  |\n"
"|      the ship go from the original square. The screen will then show where  |\n"
"|      the ship has been placed.                                              |\n"
"|                                                                             |\n"
"|  II. Guessing                                                               |\n"
"|      After you have placed all of your ships, you can begin the game by     |\n"
"|      selecting the begin game menu option. From this point on, you press    |\n"
"|      the ENTER key and the computer will guess a spot. If it is a hit, you  |\n"
"|      will see it turn red. A miss will turn the screen white at the place   |\n"
"|      guessed. Play continues like this until the computer guesses all the   |\n"
"|      ship placements or the computer does not sink all ships by guess 75.   |\n"
"|                                                                             |\n"
"|=============================================================================|\n"
"|                         PRESS ENTER TO CONTINUE                             |\n"
"|=============================================================================|\n";
string winner = 
"\n|=============================================================================|\n"
"|                                                                             |\n"
"|           /$$   /   $$ /$$                                                  |\n"
"|          | $$  /$ | $$|__/                                                  |\n"
"|          | $$ /$$$| $$ /$$ /$$$$$$$  /$$$$$$$   /$$$$$$   /$$$$$$           |\n"
"|          | $$/$$ $$ $$| $$| $$__  $$| $$__  $$ /$$__  $$ /$$__  $$          |\n"
"|          | $$$$_  $$$$| $$| $$  \\ $$| $$  \\ $$| $$$$$$$$| $$  \\__/          |\n"
"|          | $$$/ \\  $$$| $$| $$  | $$| $$  | $$| $$_____/| $$                |\n"
"|          | $$/   \\  $$| $$| $$  | $$| $$  | $$|  $$$$$$$| $$                |\n"
"|          |__/     \\__/|__/|__/  |__/|__/  |__/ \\_______/|__/                |\n"
"|                                                                             |\n"
"|=============================================================================|\n";

/*************************************
**		  ALL FUNCTION LIST			**
*************************************/
void hdr();
void ftr();
void eof();
double errCheck4(string);
double errCheck7(string);
void title();
void displayMenuMain();
void mainMenu();
void shipPlacement();
void resetCounts();
void placeShip(int, int);
void shipPlacementCheck(int, int, int);
void countIncrease(int n);
void convertLetter(char);
void showBoard();
bool overlapping(int, int);
WORD GetConsoleTextAttribute (HANDLE hCon);
void battleshipGuess();
void battleshipGuess2();
void randNumb();
void convertLetter(int);
void convertGuess(int);
bool checkWin();
void SetConsoleColour(WORD* Attributes, DWORD Colour);
void ResetConsoleColour(WORD Attributes);
void setTextColor(DWORD Colour);
void dispHealth(int);
void tenShots(int);

/*************************************
**		  ---Main Function---	 	**
*************************************/
void main()
{
	srand(time(NULL));
	title();
	mainMenu();
}

/*************************************
**		  ---Print Class---	 		**
*************************************/
class Print
{
public:
	void pos(short C, short R)
	{
		COORD xy ;
		xy.X = C ;
		xy.Y = R ;
		SetConsoleCursorPosition( 
		GetStdHandle(STD_OUTPUT_HANDLE), xy);
	}
	void cls()
	{
		pos(0,0);
		for(int j=0;j<100;j++)
		cout << string(100, ' ');
		pos(0,0);
	}
	void prntBoard();
	void resetBoard();
	void statsPrint();
	void printStats();
};
/*************************************
**		  ---Print Stats---	 		**
*************************************/
void Print::printStats()
{
	cout << star2 << endl << healthBar << setw(health);
	SetConsoleColour(&Attributes,BACKGROUND_INTENSITY | BACKGROUND_RED);
	dispHealth(health);
	ResetConsoleColour(Attributes);
	if (health == 17)
	{
		cout << lstar << setw(27) << rstar << endl;
	}
	else if (health == 16)
	{
		cout << setw(3) << lstar << setw(27) << rstar << endl;
	}
	else
	{
		cout << setw(17-health) << rstar << setw(29) << rstar << endl;
	}
	if (totGuessCount <= 1)
	{
		shotRatio = 0.00;
	}
	else
	{
		shotRatio = (hitCount/totGuessCount)*hund;
	}
	cout << fixed << setprecision(0);
	cout << star2 << endl << lstar << shots << setw(3) << totGuessCount << rstar 
		<< hits << setw(3) <<  hitCount << rstar << misses << setw(3) << missCount << rstar 
		<< hitPnct << setw(10) << fixed << setprecision(2) << shotRatio 
		<< pcnt << setw(10) << rstar << endl;
}
/*************************************
**		  ---Print Board---	 		**
*************************************/
void Print::prntBoard()
{
	k = 0;
	cout << star2 << endl << lstar << setw(3) << miss << setw(5) << lstar2;
	for (i=z; i < row; i++)
	{
		cout << setw(3) << colHead[i] << setw(4) << lstar;
	}
		cout << star2;
	for (i = 0; i < row; i++)
	{
		if (k == 0)
		{
			k++;
			cout << endl;
		}
		else
		{
			cout << star << endl;
		}
		cout << lstar << setw(3) << rowHead[i] << setw(5) << lstar2;
		for (j = 0; j < column; j++)
		{
			if (gameBoard[i][j] == 0)
			{
				SetConsoleColour(&Attributes,BACKGROUND_INTENSITY | BACKGROUND_BLUE | 
					FOREGROUND_INTENSITY | FOREGROUND_BLUE);			
				cout << setw(4) << gameBoard[i][j] << setw(1) << "";
				setTextColor(FOREGROUND_INTENSITY);
				cout << lstar;
				ResetConsoleColour(Attributes);
			}
			else if (gameBoard[i][j] == 5 || gameBoard[i][j] == 4 ||
				gameBoard[i][j] == 3 || gameBoard[i][j] == 2)
			{
				SetConsoleColour(&Attributes,BACKGROUND_INTENSITY);
				cout << setw(3) << gameBoard[i][j] << setw(2) << "";				
				ResetConsoleColour(Attributes);
				cout << lstar;
			}
			else if (gameBoard[i][j] == -5 || gameBoard[i][j] == -4 ||
				gameBoard[i][j] == -3 || gameBoard[i][j] == -2)
			{
				SetConsoleColour(&Attributes,BACKGROUND_INTENSITY | BACKGROUND_RED | 
					FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout << setw(2) << gameBoard[i][j] << setw(3) << "";				
				ResetConsoleColour(Attributes);
				cout << lstar;
			}
			else if (gameBoard[i][j] == -1)
			{
				SetConsoleColour(&Attributes,BACKGROUND_INTENSITY | BACKGROUND_RED 
					| BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_INTENSITY | 
					FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << setw(2) << gameBoard[i][j] << setw(3) << "";				
				ResetConsoleColour(Attributes);
				cout << lstar;
			}
			else
			{
				cout << setw(3) << gameBoard[i][j] << setw(4) << lstar;
			}
		}
	}
	cout << star2 << endl;
}
/*************************************
**		  ---Resets Board---		**
*************************************/
void Print::resetBoard()
{
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			gameBoard[i][j] = 0;
		}
	}
}
/*************************************
**		  ---Print Stats---	 		**
*************************************/
void Print::statsPrint()
{
	if (totGuessCount <= 1)
	{
		shotRatio = 0.00;
	}
	else
	{
		shotRatio = (hitCount/totGuessCount)*hund;
	}
	ofs << fixed << setprecision(0);
	ofs << lstar << setw(38) << gameNumb << setw(3) << gameCount << setw(36) << rstar 
		<< endl << star2 << endl << lstar << shots << setw(3) << totGuessCount << rstar 
		<< hits << setw(3) <<  hitCount << rstar << misses << setw(3) << missCount << rstar 
		<< hitPnct << setw(10) << fixed << setprecision(2) << shotRatio 
		<< pcnt << setw(10) << rstar << endl << star2 << endl;

	cout << fixed << setprecision(0);
	cout << star2 << endl << lstar << setw(38) << gameNumb << setw(3) << gameCount 
		<< setw(36) << rstar << endl << star2 << endl << lstar << shots << setw(3) 
		<< totGuessCount << rstar << hits << setw(3) <<  hitCount << rstar << misses 
		<< setw(3) << missCount << rstar << hitPnct << setw(10) << fixed << setprecision(2) 
		<< shotRatio << pcnt << setw(10) << rstar << endl << star2 << endl;
}
/*************************************
**	  ---Computer Guess Class---	**
*************************************/
class Random
{
private:
	vector<int> computerGuess;
public:
	void randNumb(int z)
	{
		for (i = 0; i < hund; i++)
		{
			computerGuess.push_back(i);
		}
		for (i=0; i < z; i++)
		{
			random_shuffle(computerGuess.begin(), computerGuess.end());
		}
	}
	void deleteValue()
	{
		computerGuess.pop_back();
	}
	void getVal()
	{
		compGuess = computerGuess.back();
	}
};

WORD GetConsoleTextAttribute (HANDLE hCon)
{
  CONSOLE_SCREEN_BUFFER_INFO con_info;
  GetConsoleScreenBufferInfo(hCon, &con_info);
  return con_info.wAttributes;
}
/*************************************
**			Main Menu				**
*************************************/
void mainMenu()
{
	Print p;
	hdr();
    menuSelection = 0;

	while (menuSelection != 4)
	{
		displayMenuMain();
		do
		{
			getline(cin, input);
			menuSelection = errCheck4(input);
		} while (menuSelection == 0);
		cout << endl;

		switch (menuSelection)
		{
		case 1:
			p.cls();
			cout << rules;
			cin.get();
			p.cls();
			break;
		case 2:
			p.cls();
			resetCounts();
			p.resetBoard();
			shipPlacement();
			battleshipGuess();
			break;
		case 3:
			p.cls();
			resetCounts();
			p.resetBoard();
			shipPlacement();
			battleshipGuess2();
			break;
		case 4:
			ftr();
			eof();
			break;
		default: cout << endl;
		}
	}
};
/*************************************
**		  Ship Placement Menu		**
*************************************/
void shipPlacement()
{		
	Print p;
    menuSelection = 0;
	while (menuSelection != 7)
	{
		if (carrierCount > 0 && battleshipCount > 0 && subCount > 0 && destroyerCount > 0
			&& patrolCount > 0)
		{
			cout << endl << allPlaced;
		}
		cout << menu1_1;
		do
		{
			getline(cin, input);
			menuSelection = errCheck7(input);
		} while (menuSelection == 0);
		cout << endl;
		p.cls();
		switch (menuSelection)
		{
		case 1:
			if (carrierCount < 1)
			{
				p.prntBoard();
				placeShip(aCarrier, menuSelection);
				p.cls();
			}
			else
			{
				p.cls();
				cout << shipDuplicate;
			}
			break;
		case 2:
			if (battleshipCount < 1)
			{
				p.prntBoard();
				placeShip(battleship, menuSelection);
				p.cls();
			}
			else
			{
				p.cls();
				cout << shipDuplicate;
			}
			break;
		case 3:
			if (subCount < 1)
			{
				p.prntBoard();
				placeShip(submarine, menuSelection);
				p.cls();
			}
			else
			{
				p.cls();
				cout << shipDuplicate;
			}
			break;
		case 4:
			if (destroyerCount < 1)
			{
				p.prntBoard();
				placeShip(destroyer, menuSelection);
				p.cls();
			}
			else
			{
				p.cls();
				cout << shipDuplicate;
			}
			break;
		case 5:
			if (patrolCount < 1)
			{
				p.prntBoard();
				placeShip(patrolBoat, menuSelection);
				p.cls();
			}
			else
			{
				p.cls();
				cout << shipDuplicate;
			}
			break;
		case 6:
			p.cls();
			p.prntBoard();
			cout << cont;
			cin.get();
			p.cls();
			break;
		case 7:
			p.cls();
			break;
		default: cout << endl;
		}
	}
};
/*************************************
**	  Reset Counts for New Game		**
*************************************/
void resetCounts()
{
	carrierCount = 0;
	battleshipCount = 0;
	subCount = 0;
	destroyerCount = 0; 
	patrolCount = 0;
	gameOver = 0;
	
	totGuessCount = 0;
	hitCount = 0;
	missCount = 0;
}
/*************************************
**				Place Ship			**
*************************************/
void placeShip(int n, int menu)
{
	cout << enterShip;
	cin >> columnLetter >> r;
	convertLetter(columnLetter);
	cout << directionSelection;
	cin >> dir;
	r = r - 1;
	cin.ignore();
	shipPlacementCheck(dir, n, menu);
}
/*************************************
**		  Check Ship Placement		**
*************************************/
void shipPlacementCheck(int d, int n, int menu)
{
	Print p;
	p.cls();
	switch(d)
	{
		case 1:
			if (r-(n-1) < 0)
				{
					cout << offBoard << cont;
					cin.get();
				}
			else if (gameBoard[r][col] != 0)
			{
				cout << overlap << cont;
				cin.get();
			}
			else if (overlapping(n, d) != 0)
			{
				gameBoard[r][col] = n;

				for (i = 1; i < n; i++)
					{
						gameBoard[r-i][col] = n;		
					}
				countIncrease(menu);
				showBoard();
			}
			else
			{
				cout << overlap << cont;
				cin.get();
			}
			break;
		case 2:
			if (r+(n) > row)
				{
					cout << offBoard << cont;
					cin.get();
				}
			else if (gameBoard[r][col] != 0)
			{
				cout << overlap << cont;
				cin.get();
			}
			else if (overlapping(n, d))
			{
				gameBoard[r][col] = n;

				for (i = 1; i < n; i++)
				{
					gameBoard[r+i][col] = n;		
				}
				countIncrease(menu);
				showBoard();
			}
			else
			{
				cout << overlap << cont;
				cin.get();
			}
			break;
		case 3:
			if (col-(n-1) < 0)
				{
					cout << offBoard << cont;
					cin.get();
				}
			else if (gameBoard[r][col] != 0)
			{
				cout << overlap << cont;
				cin.get();
			}
			else if (overlapping(n, d))
			{
				gameBoard[r][col] = n;

				for (i = 1; i < n; i++)
				{
					gameBoard[r][col-i] = n;		
				}
				countIncrease(menu);
				showBoard();
			}
			else
			{
				cout << overlap << cont;
				cin.get();
			}
			break;
		case 4:
			if (col+(n) > row)
				{
					cout << offBoard << cont;
					cin.get();
				}
			else if (gameBoard[r][col])
			{
				cout << overlap << cont;
				cin.get();
			}
			else if (overlapping(n, d))
			{
				gameBoard[r][col] = n;

				for (i = 1; i < n; i++)
				{
					gameBoard[r][col+i] = n;		
				}
				countIncrease(menu);
				showBoard();
			}
			else
			{
				cout << overlap << cont;
				cin.get();
			}
			break;
		default:
			break;
	}
}
/*************************************
**		  Increase Ship Count		**
*************************************/
void countIncrease(int n)
{
	switch(n)
	{
	case 1:
		carrierCount++;
		health += 5;
		break;
	case 2:
		battleshipCount++;
		health += 4;
		break;
	case 3:
		subCount++;
		health += 3;
		break;
	case 4:
		destroyerCount++;
		health += 3;
		break;
	case 5:
		patrolCount++;
		health += 2;
		break;
	default:
		break;
	}
}
/*************************************
**		  Convert Column Letter		**
*************************************/
void convertLetter(char c)
{
	if (c == 'A' || c == 'a')
	{
		col = 0;
	}
	else if (c == 'B' || c == 'b')
	{
		col = 1;
	}
	else if (c == 'C' || c == 'c')
	{
		col = 2;
	}
	else if (c == 'D' || c == 'd')
	{
		col = 3;
	}
	else if (c == 'E' || c == 'e')
	{
		col = 4;
	}
	else if (c == 'F' || c == 'f')
	{
		col = 5;
	}
	else if (c == 'G' || c == 'g')
	{
		col = 6;
	}
	else if (c == 'H' || c == 'h')
	{
		col = 7;
	}
	else if (c == 'I' || c == 'i')
	{
		col = 8;
	}
	else if (c == 'J' || c == 'j')
	{
		col = 9;
	}
	else
	{
		cout << "ERROR";
	}
}
/*************************************
** Shows Board after Ship Placement	**
*************************************/
void showBoard()
{
	Print p;
	cout << successPlacement;
	p.prntBoard();
	cout << cont;
	cin.get();
}
/*************************************
**		Error if ships overlap		**
*************************************/
bool overlapping(int n, int dir)
{
	check = 1;
	switch(dir)
	{
	case 1:
		for (i = 0; i < n; i++)
		{
			if (gameBoard[r-i][col] != 0)
			{
				check = 0;
			}
		}
		break;
	case 2:
		for (i = 0; i < n; i++)
		{
			if (gameBoard[r+i][col] != 0)
			{
				check = 0;
			}
		}
		break;
	case 3:
		for (i = 0; i < n; i++)
		{
			if (gameBoard[r][col-i] != 0)
			{
				check = 0;
			}
		}
		break;
	case 4:
		for (i = 0; i < n; i++)
		{
			if (gameBoard[r][col+i] != 0)
			{
				check = 0;
			}
		}
		break;
	default:
		break;
	}

	if (check == 1)
	{
		return true;
	}
	else { return false; }
}
/*************************************
**		 ---Guess Function---		**
*************************************/
void battleshipGuess()
{
	Print p;
	Random r;
	r.randNumb(rand()%50+1);
	do
	{
		p.cls();
		p.printStats();
		p.prntBoard();
		cout << entCompGuess;
		cin.get();
		r.getVal();
		r.deleteValue();
		convertGuess(compGuess);
		convertLetter(colGuess);
		totGuessCount++;
		cout << dispCompGuess << letterGuess << setw(2) << rowGuess+1;

		if(gameBoard[rowGuess][colGuess] == 2 || gameBoard[rowGuess][colGuess] == 3 
			|| gameBoard[rowGuess][colGuess] == 4 || gameBoard[rowGuess][colGuess] == 5)
		{
			cout << setw(6) << dispHit << endl;
			gameBoard[rowGuess][colGuess] = gameBoard[rowGuess][colGuess] * -1;
			hitCount++;
			health--;
		}
		else
		{
			cout << setw(6) << dispMiss << endl;
			gameBoard[rowGuess][colGuess] = -1;
			missCount++;
		}
		cin.get();
		checkWin();
	} while (checkWin());

	p.cls();
	if (hitCount <= health || missCount >= 75)
	{
		cout << winner;
	}
	cout << dispGameOver;
	gameCount++;
	p.statsPrint();
	cin.get();
}
/*************************************
** Converts Guess from number 0-100	**
** to board coordinates				**
*************************************/
void convertGuess(int g)
{
	rowGuess = g % 10;

	if (g < 10)
	{
		colGuess = 0;
	}
	else if (g < 20)
	{
		colGuess = 1;
	}
	else if (g < 30)
	{
		colGuess = 2;
	}
	else if (g < 40)
	{
		colGuess = 3;
	}
	else if (g < 50)
	{
		colGuess = 4;
	}
	else if (g < 60)
	{
		colGuess = 5;
	}
	else if (g < 70)
	{
		colGuess = 6;
	}
	else if (g < 80)
	{
		colGuess = 7;
	}
	else if (g < 90)
	{
		colGuess = 8;
	}
	else
	{
		colGuess = 9;
	}
}

/*************************************
**	Reverse Convert Column Letter	**
*************************************/
void convertLetter(int guess)
{
	if (guess == 0)
	{
		letterGuess = 'A';
	}
	else if (guess == 1)
	{
		letterGuess = 'B';
	}
	else if (guess == 2)
	{
		letterGuess = 'C';
	}
	else if (guess == 3)
	{
		letterGuess = 'D';
	}
	else if (guess == 4)
	{
		letterGuess = 'E';
	}
	else if (guess == 5)
	{
		letterGuess = 'F';
	}
	else if (guess == 6)
	{
		letterGuess = 'G';
	}
	else if (guess == 7)
	{
		letterGuess = 'H';
	}
	else if (guess == 8)
	{
		letterGuess = 'I';
	}
	else if (guess == 9)
	{
		letterGuess = 'J';
	}
	else
	{
		cout << errBoard;
	}
}
/*************************************
**	Checks for Game Over Conditions	**
*************************************/
bool checkWin()
{
	gameOver = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			if (gameBoard[i][j] == 2 || gameBoard[i][j] == 3
				|| gameBoard[i][j] == 4 || gameBoard[i][j] == 5)
			{
				gameOver++;
			}
		}
	}

	if (missCount > 74)
	{
		gameOver = 0;
		return false;
	}

	if (gameOver > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/*************************************
**				Header				**
*************************************/
void hdr()
{
	ofs << titleScreen;
	ofs << star2 << endl << lstar;
	ofs << left << course << setw(63) <<
		header << right;
	ofs << rstar << endl << star2 << endl;
}
/*************************************
**				Footer				**
*************************************/
void ftr()
{
	ofs << lstar << left << hard << coding;
	ofs << labn << course << right 
		<< setw(35) << rstar;
	ofs << endl;
}
/*************************************
**			  EOF Message			**
*************************************/
void eof()
{
	ofs << star << endl << lstar;
	ofs << left << no << hard << coding;
	ofs << of << labn << anything;
	ofs << right << setw(16) << rstar 
		<< endl << star2 << endl;
}
/*************************************
**		 Displays Title Screen		**
*************************************/
void title()
{
	SetConsoleColour(&Attributes,BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE);
	cout << titleScreen;
	ResetConsoleColour(Attributes);
	SetConsoleColour(&Attributes,BACKGROUND_INTENSITY | BACKGROUND_RED);
	cout << titleScreen2;
	ResetConsoleColour(Attributes);
	cin.get();
}
/*************************************
**		   Displays Main Menu		**
*************************************/
void displayMenuMain()
{
	Print p;
	p.cls();
	cout << menu1;
}
/*************************************
**		  ---Error Check---			**
**	Specific error checks for input	**
**	from user.						**
*************************************/
double errCheck4(string test)
{
	int secondTest;
	string test2;
	if (test.length() == 0)
	{
		return 0;
	}
	if (atoi(test.c_str()) < 1)
	{
		cout << err;
		return 0;
	}
	if (atoi(test.c_str()) > 4)
	{
		cout << err;
		return 0;
	}
	secondTest = atoi(test.c_str());

	test2 = to_string(secondTest);

	if (test.length() != test2.length())
	{
		cout << err;
		return 0;
	}
	else
	{
		return secondTest;
	}
}
double errCheck7(string test)
{
	int secondTest;
	string test2;
	if (test.length() == 0)
	{
		return 0;
	}
	if (atoi(test.c_str()) < 1)
	{
		cout << err7;
		return 0;
	}
	if (atoi(test.c_str()) > 7)
	{
		cout << err7;
		return 0;
	}
	secondTest = atoi(test.c_str());

	test2 = to_string(secondTest);

	if (test.length() != test2.length())
	{
		cout << err7;
		return 0;
	}
	else
	{
		return secondTest;
	}
}
void SetConsoleColour(WORD* Attributes, DWORD Colour)
{
	CONSOLE_SCREEN_BUFFER_INFO Info;
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hStdout, &Info);
	*Attributes = Info.wAttributes;
	SetConsoleTextAttribute(hStdout, Colour);
}

void ResetConsoleColour(WORD Attributes)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Attributes);
}
void setTextColor(DWORD Colour)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const int saved_colors = GetConsoleTextAttribute(hConsole);
	SetConsoleTextAttribute(hConsole, Colour);
}
void dispHealth(int z)
{
	if (health > 0)
	{
		cout << "";
	}
}
/*************************************
**		 ---Guess Function---		**
*************************************/
void battleshipGuess2()
{
	Print p;
	Random r;
	r.randNumb(rand()%50+1);
	do
	{
		p.cls();
		p.printStats();
		p.prntBoard();
		cout << entCompGuess;
		cin.get();
		for (i=0; i<10; i++)
		{
			r.getVal();
			r.deleteValue();
			convertGuess(compGuess);
			convertLetter(colGuess);
			totGuessCount++;
			cout << dispCompGuess << letterGuess << setw(2) << rowGuess+1;

			if(gameBoard[rowGuess][colGuess] == 2 || gameBoard[rowGuess][colGuess] == 3 
				|| gameBoard[rowGuess][colGuess] == 4 || gameBoard[rowGuess][colGuess] == 5)
			{
				cout << setw(6) << right << dispHit << endl;
				gameBoard[rowGuess][colGuess] = gameBoard[rowGuess][colGuess] * -1;
				hitCount++;
				health--;
			}
			else
			{
				cout << setw(6) << right << dispMiss << endl;
				gameBoard[rowGuess][colGuess] = -1;
				missCount++;
			}
			if (missCount == 75)
			{
				i = 10;
			}
		}
		cin.get();
		checkWin();
	} while (checkWin());

	p.cls();
	if (missCount > 74)
	{
		cout << winner;
	}
	cout << dispGameOver;
	gameCount++;
	p.statsPrint();
	cin.get();
}