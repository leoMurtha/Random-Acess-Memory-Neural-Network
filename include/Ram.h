#ifndef _RAM_H_
#define _RAM_H_

using namespace std;
#include <vector>
#include <ConfMatrix.h>
#include <Wizard.h>
#include <Neuron.h>

class Ram{
	private:
		int nKlasses; /* Number of klasses int the current net */
		ConfMatrix matrix; /* Confection matrix */
		
	public:
		Wizard *klass; /* Classes of the neural net */

		Ram();
		Ram(ConfMatrix, int);
		~Ram();
		
		int getAction(); /* Runs a winnerTakesAll and returns the action */
		int getKlasses();
};	

#endif