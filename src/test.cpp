#include <stdlib.h>
#include <stdio.h>
#include <Ram.h>
#include <Helper.h>
#include <ConfMatrix.h>
#include <ctime>

bool **link2Sensor(bool *sensor, int n_sensors){
	bool **p = (bool**)malloc(sizeof(bool*)*n_sensors); 
	
	for(int i = 0 ; i < n_sensors ; i++) p[i] = &sensor[i];

	return p;
}

int n_sensors = 8,n_neurons = 4,n_klasses = 1; /* Ram parameters */

int main(int argc, char const *argv[]){
	vector <bool*> sensors = vector<bool*>();
	bool *sensor = (bool*)malloc(sizeof(bool)*n_sensors); /* Sensors */
	bool **psensor = link2Sensor(sensor,n_sensors); /* Getting adresses for the sensors */
	srand(time(NULL));
	
	for(int i = 0; i < n_sensors; i++) sensor[i] = randomInt(2);



	/* Making the matrix */
	ConfMatrix matrix(psensor,&n_sensors,&n_neurons);
	Ram test = Ram(matrix,n_klasses);

	printf("ACTION %d\n",test.getAction());

	return 0;
}