#ifndef _WIZARD_H_
#define _WIZARD_H_

#include <Neuron.h>
#include <ConfMatrix.h>

/* Group of neurons */
class Wizard{
	private:	
		int k; /* Wizard class, the command it sends */
		int O; /* Result of neurons sums */
		int n_neurons;
		int n_sensors;
		int n_receptors;
		Neuron *neuron; /* Neurons of the group */
	
	public:
		Wizard();
		Wizard(int,int,int); /* Uses nsensor,nneurons and nreceptors*/
		//~Wizard();
		void connectStoR(M*); /* Connect sensors to receptors */
		int adder(); /* adds the adressed locs */
};

#endif