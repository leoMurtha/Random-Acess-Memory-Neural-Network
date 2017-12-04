#include <Ind.h>
#include <stdlib.h>
#include <stdio.h>


Ind::Ind(){};

Ind::Ind(ConfMatrix matrix, int nKlasses, int id){
	this->brain = Ram(matrix,nKlasses);
	this->fitness = 0;
	this->id = id;
}

void Ind::add2Fitness(float add){
	this->fitness += add;
}

float Ind::getFitness(){
	return this->fitness;
}

int Ind::choice(){
	return brain.getAction();
}