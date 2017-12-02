#include <ConfMatrix.h>
#include <stdlib.h>
#include <stdio.h>
#include <Helper.h>
#include <vector>

ConfMatrix::ConfMatrix(){};

ConfMatrix::ConfMatrix(bool **sensors,int *n_sensors,int *n_neurons){
	while(((*n_sensors) % (*n_neurons))){
		printf("ERROR: Number of neurons is not proportional to the number of sensors.\n");
		printf("Type valid inputs, current numbers: Sensors[%d] and Neurons[%d]\n",(*n_sensors),(*n_neurons));
		scanf("%d %d",n_sensors,n_neurons);
	}
	
	this->n_sensors = *n_sensors;
	this->n_neurons = *n_neurons;
	this->n_receptors = this->n_sensors/this->n_neurons;

	/* Vec of bool pointers */
	lines = (M*)calloc(this->n_neurons,sizeof(M));

	bool bitmap[this->n_sensors] = {0};
	for(int i = 0; i < this->n_neurons; i++){
		lines[i].v = vector<bool*>();
		for(int j = 0,id = -1; j < this->n_receptors; j++,id = -1){
			/* Selecting a free sensor */
			while(id == -1){
				id = randomInt(this->n_sensors);
				id = bitmap[id] ? -1 : id;
			}

			lines[i].v.push_back(sensors[id]);
		}
	}
	
}

int ConfMatrix::getNsensors(){
	return this->n_sensors;
}

int ConfMatrix::getNneurons(){
	return this->n_neurons;
}

int ConfMatrix::getNreceptors(){
	return this->n_receptors;
}

void ConfMatrix::printSensorsValue(){
	for(int i = 0; i < n_neurons; i++){
		for(int j = 0 ; j < n_receptors; j++){
			printf("[%d]\n",*(lines[i].v[j]));
		}
	}
}
