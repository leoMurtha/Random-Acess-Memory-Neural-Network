#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <Ram.h>
#include <Ind.h>
using namespace std;

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};

int checkwin();
void board();

/* Runs the game routine */
bool game(vector<Ind> p, bool **sensor, int n_sensors, unsigned int secs){
	int player = 0,i,choice;
	char mark;
	
	for(int i = 0 ; i < n_sensors; i ++) sensor[i] = 0; /* Zeroing sensor */
	
	unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.

	do{
		printf("Player [%d] choice %d\n", (player+1),choice);
		board();
		player %= 2;

		printf("Player [%d]: Choose a valid position in the board.\n", (player+1));
		choice = p[player].choice();

		printf("Player [%d] choice %d\n", (player+1),choice);

		mark = (!player) ? 'X' : 'O'; 

		if(isdigit(square[choice])){
			square[choice] = mark;
			sensor[player][choice] = true;
			sensor[player][18] = false;
			sensor[player][19] = false;
			
		}
		else{
			
			p[player].add2Fitness(-1);			
			sensor[player][18] = true;
			sensor[player][19] = true;
			
			cout<<"Invalid move ";

			player--;
			
		}
		i=checkwin();

		player++;
	}while((time(0) < retTime) && i==-1);

	board();
	
	if(i == -1){
		printf("POHA CARAIOOO\n");
	}
	if(i==1) cout<<"Player "<<--player<<" win ";
	else
		cout<<"==>\aGame draw";

	
	return 0;
}

/*********************************************

	FUNCTION TO RETURN GAME STATUS
	1 FOR GAME IS OVER WITH RESULT
	-1 FOR GAME IS IN PROGRESS
	O GAME IS OVER AND NO RESULT
**********************************************/

int checkwin(){
	if (square[1] == square[2] && square[2] == square[3])

		return 1;
	else if (square[4] == square[5] && square[5] == square[6])

		return 1;
	else if (square[7] == square[8] && square[8] == square[9])

		return 1;
	else if (square[1] == square[4] && square[4] == square[7])

		return 1;
	else if (square[2] == square[5] && square[5] == square[8])

		return 1;
	else if (square[3] == square[6] && square[6] == square[9])

		return 1;
	else if (square[1] == square[5] && square[5] == square[9])

		return 1;
	else if (square[3] == square[5] && square[5] == square[7])

		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
                    && square[4] != '4' && square[5] != '5' && square[6] != '6' 
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

		return 0;
	else
		return -1;
}


/*******************************************************************
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/


void board(){
	system("clear");
	cout << "\n\n\tTic Tac Toe\n\n";

	printf("Player [1] (X) - Player [2] (0)\n\n");
	
	cout << "     |     |     " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

	cout << "     |     |     " << endl << endl;
}
