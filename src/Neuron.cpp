#include <Neuron.h>
#include <stdlib.h>
#include <stdio.h>
#include <Helper.h>
#include <vector>

Neuron::Neuron(){}

Neuron::~Neuron(){
}

void printBin(int n,int n_receptors){
	int q, r;
	int result[n_receptors]; // 5 * 4 bytes = 20 bytes
	int i;

	i = 0;
	for (; i < n_receptors;) {
		result[i] = 0;
		i++;
	}

	i = 0;
	while (n >= 2) {
		q = n / 2;
		r = n - (2*q);
		//printf("Resto: %d\n", r);
		
		result[i] = r;
		i = i + 1; // i++;

		n = q;
	}

	//printf("Último quociente: %d\n", n);
	result[i] = n;

	for (i = n_receptors-1; i >= 0; i--) {
		printf("%d", result[i]);
	}
}

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

	for(int i = 0 ; i < n_receptors; i++){
		loc += (*receptor[i])*power2(i);
	}
	if(loc < 0 || loc > this->n) printf("ERROR: Invalid loc\n");
	
	return chromo[loc];
}

void Neuron::setReceptor(vector<bool*> sensors){
	this->receptor = sensors;
}

int Neuron::getN(){return this->n;}

void Neuron::printNeuron(){
	for(int i = 0; i < n ; i++){
		printf("In:[ ");
		
		printf("%d", i);
		//printBin(i,this->n_receptors);

		printf("]\tOut:[%d]\n",chromo[i]);
	}
}