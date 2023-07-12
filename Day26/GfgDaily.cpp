    long long mod=1000000007;
       long long a=N,b=1;
       while(R){
           if(R&1){
               b=(b*a)%mod;
           }
           a=(a*a)%mod;
           R/=2;
       }
        return b;
        
    }