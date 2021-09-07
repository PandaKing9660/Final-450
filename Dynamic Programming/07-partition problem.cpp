#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int equalPartition(int n, int arr[]) {
        int sum = 0;

        for (int i = 0; i < n; i++) sum += arr[i];

        if (sum % 2) {
            return 0;
        }

        sum /= 2;

        bool dp[n + 1][sum + 1];

        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int i = 0; i <= sum; i++) dp[0][i] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
            }
        }

        return dp[n][sum];
    }
};