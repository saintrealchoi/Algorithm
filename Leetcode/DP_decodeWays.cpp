class Solution {
public:
	int numDecodings(string s) {
		if (s.length() == 0 || s[0] == '0')return 0;

		if (s.length() == 1)return 1;

		int tmp1 = 1, tmp2 = 1;

		for (int i = 1; i < s.length(); i++) {
			int count = 0;
			int num1 = s[i] - '0';
			int num2 = (s[i - 1] - '0') * 10 + num1;
			if (num1 >= 1)count += tmp2;
			if (num2 >= 10 && num2 <= 26)count += tmp1;
			tmp1 = tmp2;
			tmp2 = count;
		}

		return tmp2;
	}
};