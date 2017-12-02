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
		Wizard *klass; /* Classes of the neural net */

	public:
		Ram();
		Ram(ConfMatrix);
		//~Ram();
		void connectStoR(bool*); /* Connect sensors to receptors */

	
};

#endif