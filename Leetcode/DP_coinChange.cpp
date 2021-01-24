class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int max = amount + 1;
        int arr[amount + 1];

        for (int i = 0; i < amount + 1; i++) {
            arr[i] = max;
        }

        arr[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    arr[i] = min(arr[i], arr[i - coins[j]] + 1);
                }
            }
        }
        return arr[amount] > amount ? -1 : arr[amount];
    }
};