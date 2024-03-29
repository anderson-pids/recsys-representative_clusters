#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <climits>
#include "graph.h"
#include "util.h"

using namespace std;

class Parser
{
public:
	Parser(string ratingsPath, string clusterPath, string reprClusterPath);
	~Parser();
	void Process();

	Graph* GetRatings();
	map<int,int>* GetUsers();
	map<int,map<int,double>>* GetMovieClusters();

	/* data */
private:
	string mRatingPath, mClusterPath, mReprClusterPath;
	Graph *mRatings; // user ratings
	map<int,int> mUsers; //<user, cluster>
	map<int,map<int,double>> mMovieReprCluster; //<movie, <cluster,rating>>
	fstream mFs;

	void ReadRatingsList();
	void ReadClusters();
	void ReadRepresentatives();
};

#endif