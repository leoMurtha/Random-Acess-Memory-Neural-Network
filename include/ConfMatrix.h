#ifndef _CONFMATRIX_H_
#define _CONFMATRIX_H_

#include <vector>
using namespace std;

typedef struct mat{
	vector <bool*> v;
	int *ids; /* Indexes to sensors, used in replaceSensors */
}M;

/* Sparse matrix */
class ConfMatrix{
	private:
		int n_sensors;
		int n_neurons;
		int n_receptors;
		M *lines;

	public:
		ConfMatrix();
		ConfMatrix(bool**,int*,int*);
		//~ConfMatrix();

		/* Methods */
		void printSensorsValue();
		int getNsensors();
		int getNneurons();
		int getNreceptors();
		M *getLines();
		void replaceSensors(bool**);

};

#endif