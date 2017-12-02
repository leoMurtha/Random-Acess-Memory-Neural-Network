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
	neuron = (Neuron*)calloc(this->n_neurons,sizeof(Neuron));

	this->n_receptors = n_receptors;

	/* Creating the wizards neurons */
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
		neuron[i].printNeuron();
	}
}