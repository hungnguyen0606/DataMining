#ifndef _MY_DATA_H_
#define _MY_DATA_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

typedef int LABELTYPE;
struct data
{
	vector<double> feature;
	LABELTYPE label;
	int n;

	data()
	{
		n = 0;
		label = -1;
	}
	void init(int nfeature)
	{
		this->n = nfeature - 1;
		label = -1;
		feature.resize(n);
	}
	double getDistance(const data& b) const
	{
		double ret = 0;
		for (int i = 0; i < feature.size(); ++i)
		{
			double tmp = feature[i] - b.feature[i];
			ret = ret + tmp*tmp;
		}
		return sqrt(ret);
	}
};

istream& operator >> (istream& inp, data& dat);


#endif