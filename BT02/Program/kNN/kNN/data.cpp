#include "data.h"

istream& operator >> (istream& inp, data& dat)
{
	if (dat.feature.size() < dat.n)
		dat.feature.resize(dat.n);

	for (int i = 0; i < dat.n; ++i)
		inp >> dat.feature[i];

	inp >> dat.label;

	return inp;
}