class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        int sum = 0;
        for (int x : piles)
            sum += x;

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case
        for (int i = 0; i < n; i++)
            dp[i][i] = piles[i];

        // Fill by increasing length
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;

                int a = (l + 2 <= r) ? dp[l + 2][r] : 0;
                int b = (l + 1 <= r - 1) ? dp[l + 1][r - 1] : 0;
                int c = (l <= r - 2) ? dp[l][r - 2] : 0;

                int takeLeft = piles[l] + min(a, b);
                int takeRight = piles[r] + min(c, b);

                dp[l][r] = max(takeLeft, takeRight);
            }
        }

        int p1 = dp[0][n - 1];
        int p2 = sum - p1;

        return p1 >= p2;
    }
};