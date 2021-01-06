#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	int pivot = 0;

	for (int i = 0; i < number.size() - k; i++) {
		char max = number[pivot];
		int index = pivot;
		for (int j = pivot; j <= k + i; j++) {
			if (max < number[j]) {
				max = number[j];
				index = j;
			}
		}
		pivot = index + 1;
		answer.push_back(number[index]);
	}
	return answer;
}