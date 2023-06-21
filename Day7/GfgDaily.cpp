    
// You will be given an integer n, your task is to return the sum of all natural number less than or equal to n.

// As the answer could be very large, return answer modulo 109+7.

int sumOfNaturals(int n) {
        const int long long mod = 1e9+7;
       return (((long)n*(long)(n+1))/2)%mod;
    }