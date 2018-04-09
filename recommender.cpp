#include <iostream>
#include "graph.h"
#include "parser.h"
#include "representative.h"
#include "estimator.h"

using namespace std;

string ratingsPath, clusterPrefix, reprClusterPrefix;
int repetitions=1, n_multi_clusters;

void GetDatasetName(int argc, char *argv[]);

int main(int argc, char *argv[])
{
	GetDatasetName(argc, argv);

	Parser p(ratingsPath, clusterPrefix, reprClusterPrefix, n_multi_clusters);
	p.Process();

	vector<Representative*> *repr = p.GetRepresentatives();
	cout << "Size of representatives: " << to_string(repr->size()) << endl;
	cout << "Parser completed!" << endl;

	exit(1);

	Estimator est;
	est.SetRatings(p.GetRatings());
	// est.SetUsers(p.GetUsers());
	// est.SetItemClusters(p.GetMovieClusters());

	vector<double> results(4), parcResult;
	for(int i=0; i<repetitions; ++i)
	{
		parcResult = est.Process(i+1);
		for (int j = 0; j < parcResult.size(); ++j)
			results[j] += parcResult[j];
	}
	cout << endl;
	cout << "**********************" << endl;
	cout << "**********************" << endl;
	cout << "   Mean of Results" << endl;
	cout << "**********************" << endl;
	cout << "**********************" << endl;
	cout << "RMSE: " << results[0]/repetitions << endl;
	cout << "MAE: " << results[1]/repetitions << endl;
	cout << "Error: " << results[2]/repetitions << endl;
	cout << "Square Error: " << results[3]/repetitions << endl;
	cout << "Predictions: " << results[4] << endl;

	return 0;
}

void GetDatasetName(int argc, char *argv[])
{
	if(argc == 5)
	{
		ratingsPath = argv[1];
		clusterPrefix = argv[2];
		reprClusterPrefix = argv[3];
		n_multi_clusters = atoi(argv[4]);
	}
	else if(argc == 6)
	{

		ratingsPath = argv[1];
		clusterPrefix = argv[2];
		reprClusterPrefix = argv[3];
		n_multi_clusters = atoi(argv[4]);
		repetitions = atoi(argv[5]);
	}
	else
	{
		cout << "[Error] Missing parameters!" << endl;
		cout << "[INFO] ./rec.out <RATINGS_PATH> <CLUSTER_PREFIX> <REPR_CLUSTERS_PREFIX> <N_MULTI_CLUSTERS> <REPETITIONS>" << endl;
		exit(1);
	}
}