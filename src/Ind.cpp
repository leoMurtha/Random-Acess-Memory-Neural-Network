#include <Ind.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

Ind::Ind(){
	this->fitness = INT_MIN;
	this->id = -1;
}

Ind::Ind(ConfMatrix matrix, int nKlasses, int id){
	this->brain = Ram(matrix,nKlasses);
	this->fitness = 0;
	this->id = id;
}

int Ind::getId(){
	return this->id;
}

void Ind::add2Fitness(float add){
	this->fitness += add;
}

void Ind::setFitness(float val){
	this->fitness = val;
}

float Ind::getFitness(){
	return this->fitness;
}

int Ind::choice(){
	return brain.getAction();
}

Ram* Ind::getBrain(){
	return &brain;
}