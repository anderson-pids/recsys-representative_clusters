#ifndef ML2K_H
#define ML2K_H

#include <iostream>
#include <string>
#include "dataset_base.h"
#include "util.h"
#include "graph.h"

using namespace std;

class ml2k: public Dataset_Base
{
public:
	ml2k(string path, string sim_function);
	~ml2k();
protected:
	int LoadRatings();
};


#endif