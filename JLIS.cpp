#include <iostream>
using namespace std;

int arr1[101];
int arr2[101];
int ans[100];

void sort(int arr[],int len) {
	int p,q,key;
	for (p = 1; p < len; ++p) {
		key = arr[p];
		for (q = p - 1; q >= 0 && arr[q] > key; q--) {
			arr[q + 1] = arr[q];
		}
		arr[q + 1] = key;
	}
}

int main()
{
	int i = 0,j=0;
	int p, q, key;
	int a = 0, b = 0;
	int num;
	int len1, len2;
	int count = 0;
	cin >> num;

	while (i < num) {
		cin >> len1 >> len2;
		for (j = 0; j < len1; j++) cin >> arr1[j];
		for (j = 0; j < len2; j++) cin >> arr2[j];
		for (p = 1; p < len1; ++p) {
			key = arr1[p];
			for (q = p - 1; q >= 0 && arr1[q] > key; q--) {
				arr1[q + 1] = arr1[q];
			}
			arr1[q + 1] = key;
		}
		for (p = 1; p < len2; ++p) {
			key = arr2[p];
			for (q = p - 1; q >= 0 && arr2[q] > key; q--) {
				arr2[q + 1] = arr2[q];
			}
			arr2[q + 1] = key;
		}

		for (a = 0, b = 0; a < len1 && b < len2;) {
			if (arr1[a] > arr2[b]) {
				//ans[a + b] = arr2[b];
				count += 1;
				b++;
			}
			else if (arr1[a] < arr2[b]) {
				//ans[a + b] = arr2[a];
				count += 1;
				a++;
			}
			else {
				//ans[a + b] = arr2[b];
				count += 1;
				a++;
				b++;
			}
		}
		if (a == len1 && b < len2) {
			while (b < len2) {
				//ans[a + b] = arr2[b];
				count += 1;
				b++;
			}
		}
		if (b == len2 && a < len1) {
			while (a < len1) {
				//ans[a + b] = arr1[a];
				count += 1;
				a++;
			}
		}
		ans[i] = count;
		count = 0;
		i++;
	}

	for (int i = 0; i < num; ++i) cout << ans[i] << endl;

}