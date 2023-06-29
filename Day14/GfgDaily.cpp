// Next Happy Number

// For a given non-negative integer N, find the next smallest Happy Number. A number is called Happy if it leads to 1 after a sequence of steps. Wherein at each step the number is replaced by the sum of squares of its digits that is, if we start with Happy Number and keep replacing it with sum of squares of its digits, we reach 1 at some point.
//  

int nextHappy(int N) {
    unordered_set<int> s;
    int n = N + 1, i = N + 1;
    s.insert(n);
    while (1) {
        int sum = 0;
        while (n > 0) {
            sum += ((n % 10) * (n % 10));
            n /= 10;
        }
        n = sum;

        if (n == 1)
            break;
        else if (s.find(n) != s.end())
            n = ++i;
        else
            s.insert(n);
    }
    return i;
}