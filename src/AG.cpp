#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <Ram.h>
#include <TicTacToe.h>
#include <Ind.h>

#define GEN_SIZE 300
#define POP_SIZE 10
#define MUTATATION 5
 
using namespace std;

bool **link2Sensor(bool *sensor, int n_sensors){
	bool **p = (bool**)malloc(sizeof(bool*)*n_sensors); 
	
	for(int i = 0 ; i < n_sensors ; i++) p[i] = &sensor[i];

	return p;
}

Ind *createPop(ConfMatrix matrix, int n_klasses){
	Ind *pop = (Ind*)malloc(sizeof(Ind)*POP_SIZE);

	for(int i = 0; i < POP_SIZE; i++)  pop[i] = Ind(matrix,n_klasses,i);

	return pop;	
}

int main(int argc, char const *argv[]){
	int n_sensors = 20,n_neurons = 5,n_klasses = 9; /* Ram parameters */
	bool *sensor = (bool*)malloc(sizeof(bool)*n_neurons); /* Sensors */
	bool **psensor = link2Sensor(sensor,n_sensors); /* Getting adresses for the sensors */
	printf("Ola\n");
	Ind *pop1; /* Population pointer */
	Ind *pop2; /* Population pointer */
	
	srand(time(NULL));
	bool *sensor2 = (bool*)malloc(sizeof(bool)*n_neurons); /* Sensors */
	bool **psensor2 = link2Sensor(sensor2,n_sensors); /* Getting adresses for the sensors */
	
	ConfMatrix matrix(psensor,&n_sensors,&n_neurons);

	
	return 0;
}