// Stock buy and sell II
// The cost of stock on each day is given in an array price[] of size n. Each day you may decide to either buy or sell the stock i at price[i], you can even buy and sell the stock on the same day, Find the maximum profit which you can get.
// Note: You can only hold one stock at a time.
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        vector<int> front(2,0), curr(2,0);
        
        for(int ind = n-1; ind >= 0 ; ind--)
        {
            curr[1] = max(front[1] , -prices[ind] + front[0]);
            curr[0] = max(front[0] , prices[ind] + front[1]);
            
            front = curr;
        }
        return curr[1];
    }