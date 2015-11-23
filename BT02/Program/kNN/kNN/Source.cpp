#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <utility>
#include <functional>
#include <map>
#include "data.h"
using namespace std;

vector<double> dist;
vector<data> T;
data U;
int n, m, k;

/*
Input file's format:
- First line is m, n, k - the number of samples in the data set,
the number of features, and the maximum number of neighbors, respectively.
- Second line is the sample data (including n-1 real numbers representing n-1 feature of the sample
that needs to be classified.
- In the next m lines, each line contains n real numbers representing the features and the class
of the data of the data set.

NOTE: the last feature in n feature of data is its label (or class).
*/
void input(string filename, data& U, vector<data>& T, int &n, int &m, int &k)
{
	ifstream inp(filename);
	if (!inp.is_open())
	{
		cout << "Error opening file.";
		return;
	}

	inp >> m >> n >> k;
	
	U.init(n);
	for (int i = 0; i < n - 1; ++i)
		inp >> U.feature[i];
	
	T.resize(m);

	for (int i = 0; i < m; ++i)
	{
		T[i].init(n);
		inp >> T[i];
	}

	inp.close();
}

bool myComp(const int& a, const int& b)
{
	return dist[a] < dist[b];
}

//create a distance's array to speed up the compare phase in kNN
void initDistance(const data& U, const vector<data>& T, vector<double>& dist)
{
	dist.resize(T.size());
	for (int i = 0; i < T.size(); ++i)
		dist[i] = U.getDistance(T[i]);
}

LABELTYPE kNN(const data& U, const vector<data>& T, int k)
{
	vector<int> id;
	id.resize(T.size());
	for (int i = 0; i < id.size(); ++i)
		id[i] = i;
	initDistance(U, T, dist);

	//sorting the id list depending on the distance of each sample to U
	sort(id.begin(), id.end(), myComp);

	//map to count the number of each kind of label in k-nearest neighbors
	map<LABELTYPE, int> labelCount;

	for (int i = 0; i < k; ++i)
		++labelCount[T[id[i]].label];

	//ret is the current optimal label. cc is the number of current label in k-nearest neighbors.
	LABELTYPE ret;
	int cc = -1;

	//finding the major label by iterating through the map
	for (map<LABELTYPE, int>::iterator it = labelCount.begin(); it != labelCount.end(); ++it)
		if (it->second > cc)
		{
			cc = it->second;
			ret = it->first;
		}

	return ret;
}

void output(string filename, int label)
{
	ofstream out(filename);
	if (!out.is_open())
	{
		cout << "Error creating output file.";
		return;
	}

	out << label;

	out.close();
}

int main()
{
	input("input.txt", U, T, n, m, k);
	int ans = kNN(U, T, k);
	output("output.txt", ans);
	
	
	return 0;
}