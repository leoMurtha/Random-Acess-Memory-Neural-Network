#ifndef _NEURON_H_
#define _NEURON_H_

using namespace std;
#include <vector>

/* bool*chromo = NEURON DNA */

/* Neuron helper class */
class Neuron{
	private:
		int n; /* Number of outputs */
		int n_receptors; /* Number of recepetors, used to allocate the gene pointer, chromossome = bool(2^n_receptors) */
		bool *chromo; /* Neuron chromossomes, basically the truth table output */
		vector<bool*> receptor; /* Receptors conected to the sensors */

	public:
		Neuron();
		Neuron(int);
		//~Neuron();

		/* Functions */
		bool getChromoAt(); /* Returns value of the adressed output, uses receptors */	
		void randomChromos(); /* Generates a random chromossome */ 
		void printNeuron();
		void setReceptor(vector<bool*>);

};

#endif