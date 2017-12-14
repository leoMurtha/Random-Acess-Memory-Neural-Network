#include <Ram.h>
#include <stdlib.h>
#include <stdio.h>
#include <Wizard.h>
#include <Neuron.h>
#include <ConfMatrix.h>
#include <vector>
#include <limits.h>

Ram::Ram(){};

Ram::~Ram(){
	
};

Ram::Ram(ConfMatrix matrix, int nKlasses){
	this->matrix = matrix;
	this->nKlasses = nKlasses;
	this->klass = (Wizard*)malloc(sizeof(Wizard)*this->nKlasses); /* Allocating the layers */

	/* Now create the net */

	/* Initializing the klasses */
	for(int i = 0; i < this->nKlasses; i++){
		klass[i] = Wizard(matrix.getNsensors(),matrix.getNneurons(),matrix.getNreceptors());
		
		/* Connecting receptors */
		klass[i].connectStoR(this->matrix.getLines());
	}	

};

int Ram::getKlasses(){return this->nKlasses;}

int Ram::getAction(){
	int adder,action = -1,max = INT_MIN;

	for(int i = 0; i < nKlasses; i++){
		adder = klass[i].adder();
		if(adder > max){
			max = adder;
			action = i+1;
		}	 
	}

	return action;
}