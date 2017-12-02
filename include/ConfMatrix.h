#ifndef _CONFMATRIX_H_
#define _CONFMATRIX_H_

#include <vector>
using namespace std;

typedef struct mat{
	vector <bool*> v;
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
		
	
};

#endif