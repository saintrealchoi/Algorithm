#include <iostream>
using namespace std;

int main(){
	int len;
	int index = 0;
	cin >> len;
	double* arr = new double[len];

	while (index < len) {
		int dates, teams, count = 0;
		double ans = 9999999;
		double find = 0;
		cin >> dates >> teams;

		double* sol = new double[dates];

		for (int i = 0; i < dates; ++i) {
			cin >> sol[i];
		}
		while (count < dates - teams + 1) {
			for (int i = 0; i <= (dates - teams - count); ++i) { // 0 1 2 
				for (int j = 0; j < teams+count; ++j) { // 0 1 2 3 
					find = find + sol[i + j];
				}
				if ((find / ((double)teams + (double)count)) < ans)
					ans = find / ((double)teams+(double)count);
				find = 0;
			}
			count++;
		}
		arr[index] = ans;
		ans = 9999999;
		index++;
	}
	for (int i = 0; i < len; ++i) {
		cout << fixed;
		cout.precision(12);
		cout << arr[i]<< endl;
	}


	delete arr;
}