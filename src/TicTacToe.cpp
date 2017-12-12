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
bool tictactoe(vector<Ind*> p, vector<bool*> sensor, int n_sensors, float ms){
	int player = 0,i,choice = 0;
	char mark;
	float elapsed_secs = 0;

	for(int j = 0 ; j < n_sensors; j++) sensor[0][j] = sensor[1][j] = 0; /* Zeroing sensor */
	
	//printf("TICCC\n");
	clock_t begin = clock();

	do{
		//board()

		//printf("Player [%d]: Choose a valid position in the board.\n", (player+1));
		choice = (*p[player]).choice();
		//n = 0;
		//	scanf("%d",&n);

		
		mark = (!player) ? 'X' : 'O'; 

		if(isdigit(square[choice])){
			(*p[player]).add2Fitness(24);			
			square[choice] = mark;
			sensor[player][choice] = true;
			player++;
			player %= 2;
			sensor[player][8+choice] = true;
		}
		else{
			
			(*p[player]).add2Fitness(-36);			
			
			//printf("Player [%d] choice %d\n", (player+1),choice);

			//cout<<"Invalid move \n";

			//printf("->%d\n", 17+choice);
			sensor[player][17+choice] = true;
			
			
		}
		i=checkwin();
		clock_t end = clock();
  		elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		
	}while((elapsed_secs <= ms) && i ==- 1);

	//board();
	//cout << "i" <<i;

	if(i == -1){
		//printf("Alguem travou jogo\n");
	}else if(i==1){
		//cout<<"Player "<<player+1<<" win "<<endl;
		(*p[player]).add2Fitness(250);			
	}else{
		//cout<<"Deu velha"<<endl;
	}

	//printf("Cabou gamer\n");
	//printf("%f %f\n", p[0].getFitness(),p[1].getFitness());

	for(int i = 1; i <= 9; i++){
		square[i] = '0' + i;
	}
	return 0;
}

/* IA Game */
bool game(Ind p, bool *sensor, int n_sensors, unsigned int secs){
	int player = 0,i,choice;
	char mark;
	
	for(int i = 0 ; i < n_sensors; i ++) sensor[i] = 0; /* Zeroing sensor */
	for(int i = 1; i <= 9; i++)	square[i] = '0' + i;

	unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.

	do{
		board();
		player %= 2;

		printf("Player [%d]: Choose a valid position in the board.\n", (player+1));
		if(!player) scanf("%d",&choice);
		else{
			choice = p.choice();
		}
		printf("Player [%d] choice %d\n", (player+1),choice);

		mark = (!player) ? 'X' : 'O'; 

		if(isdigit(square[choice])){
			square[choice] = mark;
			if(player){
				sensor[choice] = true;
			}else{
				sensor[8+choice] = true;
			}
			player++;
			player %= 2;
			
		}
		else{
			
			if(player){
				sensor[17+choice] = true;	
			}


			cout<<"INVALID MOVE :: Press 1 to quit\n";
			int n;
			scanf("%d",&n);
			if(n == 1) return false;
		}
		i=checkwin();

	}while(i==-1);
	
	board();
	
	if(i == -1){
		printf("Naaaada\n");
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
