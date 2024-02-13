#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Rect
{
	double x, y, w, h;
};

double overlap(Rect *R1, Rect *R2)
{
	double Xmax, Xmin, Ymax, Ymin;

	if (fabs(R1->x) + fabs(R1->w) >= fabs(R2->x) + fabs(R2->w) || fabs(R1->y) + fabs(R1->h) >= fabs(R2->y) + fabs(R2->h))
	{
		Ymax = min(R1->y, R2->y);
	}
	else
	{
		Ymax = max(R1->y, R2->y);
	}

	Xmax = max(R1->x, R2->x);
	Xmin = min(R1->x + R1->w, R2->x + R2->w);
	Ymin = min(fabs(R1->y) + R1->h, fabs(R2->y) + R2->h);

	if (Xmax >= Xmin || Ymax >= Ymin)
		return 0;

	double overlapWidth = Xmin - Xmax;
	double overlapHeight = Ymin - Ymax;

	return fabs(overlapWidth * overlapHeight);
}