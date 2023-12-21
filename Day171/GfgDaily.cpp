    int minCandy(int N, std::vector<int> &ratings) {
        if (N == 0) return 0;

        vector<int> candies(N, 1);

        // Iterate from left to right
        for (int i = 1; i < N; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Iterate from right to left and update candies array
        for (int i = N - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        int ans = 0;
        for (int i = 0; i < N; ++i) {
            ans += candies[i];
        }

        return ans;
    }