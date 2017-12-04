#ifndef _IND_H_
#define _IND_H_

#include <ConfMatrix.h>
#include <Ram.h>

class Ind{
	private:
		Ram brain;
		float fitness;
		int id;
	public:
		Ind();
		Ind(ConfMatrix, int, int);
		//~Ind();
		int choice();
		void add2Fitness(float);
		float getFitness();
		int getId();
		void setId();

};

#endif