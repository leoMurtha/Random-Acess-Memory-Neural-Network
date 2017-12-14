#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <Ram.h>
#include <TicTacToe.h>
#include <Ind.h>
#include <iostream>
#include <fstream>
#include <Helper.h>
#include <ctime>
#include <limits.h>

#define GEN_SIZE 1000000
#define POP_SIZE 100
#define PRED_RATE (int) (GEN_SIZE*0.001) /* 1% of the GEN SIZE */
#define GAME_TIME 0.01f
 
using namespace std;

Ind b1,b2,w1,w2;

/* Mutates de DNA */
void mutation(Ind *pop){
	Ram *normal;
	int nNeurons = pop[0].getBrain()->klass[0].getNneurons();
	int nKlasses = pop[0].getBrain()->getKlasses();
	int n = pop[0].getBrain()->klass[0].neuron[0].getN();

	for(int i = 0; i < POP_SIZE; i++){
		normal =  pop[i].getBrain();
		for(int j = 0; j < nKlasses; j++){
			for(int k = 0; k < nNeurons; k++){
				int nRand = randomInt(100);
				if(nRand > 50 && nRand < 70) nRand = 2;
				else if(nRand >= 70 && nRand <= 90) nRand = 3;
				else if(nRand > 90 && nRand <= 100) nRand = 5;				
				else if(nRand <= 50) nRand = 1;
				
				for(int t = 0; t < nRand; t++){
					/* Giving more chance to the gene of the best */
					int loc = randomInt(n);
					if(normal->klass[j].neuron[k].chromo[loc] == true){
						normal->klass[j].neuron[k].chromo[loc] = false;
					}else normal->klass[j].neuron[k].chromo[loc] = true;
				}
				
			}
		}
	}
}

/* Uses roullete to select, if anything goes wrong it returns the best of the population */
Ind roullete(Ind *pop, int popSum, int k){
	int sum = 0;
	int r = randomInt(popSum);

	for(int i = 0; i < POP_SIZE; i++){
		sum += abs(pop[i].getFitness());
		
		if(sum >= r){
			return pop[i];
		}
	}
	if(k) return b2;

	return b1;
}

/* Crossover */
void crossover(Ind *pop, Ind selected){
	Ram *selectedBrain = selected.getBrain();
	Ram *normal;
	int nNeurons = selectedBrain->klass[0].getNneurons();
	int nKlasses = selectedBrain->getKlasses();
	int n = selectedBrain->klass[0].neuron[0].getN();

	for(int i = 0; i < POP_SIZE; i++){
		normal = pop[i].getBrain();
		for(int j = 0; j < nKlasses; j++){
			for(int k = 0; k < nNeurons; k++){
				for(int t = 0; t < n; t++){
					/* Giving more chance to the gene of the selected */
					if(randomInt(100) <= 65){
						normal->klass[j].neuron[k].chromo[t] = selectedBrain->klass[j].neuron[k].chromo[t]; 
					}
				}
				
			}
		}
	}
}

/* Creates a random population */
Ind *createPop(ConfMatrix matrix, int n_klasses){
	Ind *pop = (Ind*)malloc(sizeof(Ind)*POP_SIZE);

	for(int i = 0; i < POP_SIZE; i++)  pop[i] = Ind(matrix,n_klasses,i);

	return pop;	
}

int n_sensors = 28,n_neurons = 4,n_klasses = 9; /* Ram parameters */

int main(int argc, char const *argv[]){
	FILE *log1 = fopen("5kT1.csv","w+");
	FILE *log2 = fopen("5kT2.csv","w+");
	/* Population init */
	vector<Ind*> pop = vector<Ind*>(); /* Populations */ 
	vector<Ind*> p; /* Where to put 2 player that will play against each other */ 
	/* Sensors stuff */
	vector <bool*> sensors = vector<bool*>();
	bool *sensor = (bool*)malloc(sizeof(bool)*n_sensors); /* Sensors */
	bool **psensor = link2Sensor(sensor,n_sensors); /* Getting adresses for the sensors */
	bool *sensor2 = (bool*)malloc(sizeof(bool)*n_sensors); /* Sensors */
	bool **psensor2 = link2Sensor(sensor2,n_sensors); /* Getting adresses for the sensors */
	/* ------------- */	
	printf("RAM TicTacToe\n");
	fprintf(log1, "Generation,Fitness\n");
	fprintf(log2, "Generation,Fitness\n");
	srand(time(NULL));
	
	/* Making the matrix */
	ConfMatrix matrix(psensor,&n_sensors,&n_neurons);
	pop.push_back(createPop(matrix,n_klasses));

	/* Replacing the sensors in the matrix, so all individuals have the same matrix */
	matrix.replaceSensors(psensor2);
	pop.push_back(createPop(matrix,n_klasses));

	sensors.push_back(sensor);
	sensors.push_back(sensor2);
	
	b1 = Ind(); /* Best of population 1 */
	b2 = Ind(); /* Best of population 2 */
	w1 = Ind(); /* Worst of population 1 */
	w2 = Ind(); /* Worst of population 2 */
	w1.setFitness(INT_MAX);
	w2.setFitness(INT_MAX);
	Ind wheelInd = Ind();


	int ri,rj,sum1,sum2;
	bool mi[POP_SIZE],mj[POP_SIZE];
	
	for(int k = 1; k <= GEN_SIZE; k++){
		sum1 = sum2 = 0;

		for(int l = 0 ; l < POP_SIZE; l++){
			mi[l] = false;
			mj[l] = false;
		}

		/* Evaluating */
		for(int i = 0; i < POP_SIZE ; i++){
			p = vector<Ind*>();

			do ri = randomInt(POP_SIZE);	
			while(mi[ri]);

			do rj = randomInt(POP_SIZE);	
			while(mj[rj]);

			if(randomInt(2)){
				p.push_back(&pop[0][ri]);
				p.push_back(&pop[1][rj]);
			}else{
				p.push_back(&pop[1][rj]);
				p.push_back(&pop[0][ri]);				
			}
			
			tictactoe(p,sensors,n_sensors,GAME_TIME);

			
			/* Getting best and worst of pop1 */
			if(pop[0][ri].getFitness() > b1.getFitness()) b1 = pop[0][ri];
			else if(pop[0][ri].getFitness() < w1.getFitness()) w1 = pop[0][ri];
			 
			/* Getting best and worst of pop2 */
			if(pop[1][rj].getFitness() > b2.getFitness()) b2 = pop[1][rj];
			else if(pop[1][rj].getFitness() < w2.getFitness()) w2 = pop[1][rj]; 

			/*----Roullete Wheel Selection: Getting the sum ------*/
			sum1 += abs(pop[0][ri].getFitness());
			sum2 += abs(pop[1][rj].getFitness()); 
		}
		
		/* Predation */
		/* Replacing the worst with a random one */
		if(!(k % PRED_RATE)){
			//printf("GEN PREDATOR %d\n", k);
			pop[0][w1.getId()] = Ind(matrix,n_klasses,w1.getId());
			pop[1][w2.getId()] = Ind(matrix,n_klasses,w2.getId());
		}
		
		/*Logging the best of pop2 */
		fprintf(log2,"%d , %.3f\n",k,b2.getFitness());
			
		/*Logging the best of pop1 */
		fprintf(log1,"%d , %.3f\n",k,b1.getFitness());

		/* Crossover : Wheel individual does all */
		wheelInd = roullete(pop[0],sum1,0);
		crossover(pop[0],wheelInd);
		wheelInd = roullete(pop[1],sum2,1);
		crossover(pop[1],wheelInd);
		
		/* Intraspecies */
		/*if(!(k % PRED_RATE*10)){
			if(randomInt(2)){
				crossover(pop[0],b1);
				crossover(pop[1],b1);
			}else{
				crossover(pop[0],b2);
				crossover(pop[1],b2);
			}
		}else{*/
			
		/* Crossover : best does all */
		//crossover(pop[0],b1);
		//crossover(pop[1],b2);

		
		/* Mutation */
		mutation(pop[0]);
		mutation(pop[1]);

		/* Zeroing fitness so they can be evaluated again */
		for(int l = 0; l < POP_SIZE; l++){
			pop[0][l].setFitness(0);
			pop[1][l].setFitness(0);
		}
	}
	fclose(log1);
	fclose(log2);
	
	int n = 0;
	while(n != 1){
		
		game(b1,sensor,n_sensors,1);		
		game(b2,sensor,n_sensors,1);		
		
		
		printf("Press 1 to quit all\n");
		scanf("%d",&n);
		
	}
	return 0;
}
