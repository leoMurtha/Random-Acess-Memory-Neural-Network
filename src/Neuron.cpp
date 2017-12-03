#include <Neuron.h>
#include <stdlib.h>
#include <stdio.h>
#include <Helper.h>
#include <vector>

Neuron::Neuron(){}

/* Default constructor, called in the Wizard class */
Neuron::Neuron(int n_receptors){
	
	this->n_receptors = n_receptors;
	this->n = power2(n_receptors); /* n = 2^n_recepetors */
	//printf("Number of chromo %d\n", this->n);
	chromo = (bool*)calloc(this->n, sizeof(bool));

	/* Generating a random gene set */
	randomChromos();
}

/* In this case we don't have data to fill it */
void Neuron::randomChromos(){
	for(int i = 0 ; i < n; i++) chromo[i] = randomInt(2); /* Chromossome can be 0 or 1 */
}

/* Returns the gene adressed by the receptors */
bool Neuron::getChromoAt(){
	int loc = 0; /* Loc to acess the gene and get the output */

	for(int i = 0 ; i < n_receptors; i++) loc += (*receptor[i])*power2(i);
	
	if(loc < 0 || loc > this->n) printf("ERROR: Invalid loc\n");

	return chromo[loc];
}

void Neuron::setReceptor(vector<bool*> sensors){
	this->receptor = sensors;
	
	//for(int i =0; i < n_receptors; i++){
	//	receptor[i] = sensors[i]; /* Saving the adresses */
	//}
}


void Neuron::printNeuron(){
	for(int i = 0; i < n ; i++) printf("In:[%d %d %d %d]\tOut:[%d]\n",(*receptor[0]),(*receptor[1]),(*receptor[2]),(*receptor[3]),chromo[i]);
}