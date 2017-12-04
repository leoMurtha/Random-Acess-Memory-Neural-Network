#include <Wizard.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <Neuron.h>
#include <Helper.h>
#include <ConfMatrix.h>
#include <vector>

Wizard::Wizard(){}

Wizard::Wizard(int n_sensors, int n_neurons, int n_receptors){
	this->n_sensors = n_sensors;
	this->n_neurons = n_neurons;
	this->n_receptors = n_receptors;

	neuron = (Neuron*)calloc(this->n_neurons,sizeof(Neuron));

	
	/* Creating the wizard neurons */
	for(int i = 0; i < this->n_neurons; i++){
		neuron[i] = Neuron(this->n_receptors);
		//neuron[i].printNeuron();
		//printf("=============================\n");
	}
}
/* Connect sensors to receptors */
void Wizard::connectStoR(M *lines){
	
	for(int i = 0; i < n_neurons; i++){
		neuron[i].setReceptor(lines[i].v);
		//printf("----->Neuron [%d] \n", i);
		//neuron[i].printNeuron();
	}
}

/* Adds all the 1's in the wizard */
int Wizard::adder(){
	int sum = 0;
	/* Creating the wizard neurons */
	for(int i = 0; i < this->n_neurons; i++){
		sum += neuron[i].getChromoAt();
	}

	return sum;
}