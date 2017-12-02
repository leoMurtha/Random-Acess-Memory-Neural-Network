#include <stdlib.h>
#include <stdio.h>
#include <Wizard.h>
#include <Neuron.h>
#include <ConfMatrix.h>
#include <time.h>
#include <vector>

int main(int argc, char const *argv[]){
	srand(time(NULL));

	int n_s = 20;
	int n = 5;
	bool e[n_s];

	bool **p = (bool**)malloc(sizeof(bool*)*n_s); 
	for(int i = 0 ; i < n_s ; i++) p[i] = &e[i]; 
	
	for(int i = 0 ; i < n_s ; i++){
		printf("%d\n", (*p)[i]);
	}
	printf("================================\n");
	ConfMatrix conf(p,&n_s,&n);

	conf.printSensorsValue();

	return 0;
}