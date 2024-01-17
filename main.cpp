#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

float floatPoint = 1000;
double u = 5;
double v = 7;
double l = 15.001;
float r = 3.5;
double step = 0.001*floatPoint;


int main() {
		vector<int> fr(l * floatPoint, 0);
		vector<int> pref_sum(l * floatPoint, 0);
		if (int(r * 100) < int(v * 100 - u * 100)) {
			for (int i = 1; i < r * floatPoint; i += step) {
				fr[i] = 0;
				pref_sum[i] = pref_sum[i - 1] + fr[i];
			}

			for (int i = r * floatPoint; i < u * floatPoint; i += step) {
				fr[i] = 1 * floatPoint;
				pref_sum[i] = pref_sum[i - 1] + fr[i];
			}

			for (int i = u * floatPoint; i < u * floatPoint + r * floatPoint; i += step) {
				fr[i] = 0.5 * floatPoint;
				pref_sum[i] = pref_sum[i - 1] + fr[i];
			}

			for (int i = u * floatPoint + r * floatPoint; i < v * floatPoint; i += step) {
				fr[i] = (1.5 - (r * floatPoint / (i - u * floatPoint))) * floatPoint;
				pref_sum[i] = pref_sum[i - 1] + fr[i];
			}

			fr[v * floatPoint] = (1 - r/(v-u)) * floatPoint;
			pref_sum[v * floatPoint] = pref_sum[v * floatPoint - step] + fr[v * floatPoint];

		}
		else {
			for (int i = 1; i < r * floatPoint; i += step) {
				fr[i] = 0;
				pref_sum[i] = pref_sum[i - 1] + fr[i];
			}

			for (int i = r * floatPoint; i < v * floatPoint; i += step) {
				fr[i] = 0.5 * floatPoint;
				pref_sum[i] = pref_sum[i - 1] + fr[i];
			}

			fr[v * floatPoint] = 0;
			pref_sum[v * floatPoint] = pref_sum[v * floatPoint - step] + fr[v * floatPoint];
		}
		for (int i = v * floatPoint + 1; i < l * floatPoint; i += step) {
			fr[i] = (((1 * floatPoint / (i - u * floatPoint)) * pref_sum[i - u * floatPoint] / floatPoint * step / floatPoint) + ((1 * floatPoint / (i - v * floatPoint)) * pref_sum[i - v * floatPoint] / floatPoint * step / floatPoint)) * floatPoint;
			pref_sum[i] = pref_sum[i - 1] + fr[i];
		}

		for (int i = 0.001 * floatPoint; i < 7.001 * floatPoint; i+=step) {
			cout << fr[i]/floatPoint << endl;
		}
}
