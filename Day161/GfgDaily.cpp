ll countStrings(int n) {
        int mod = 1e9+7;
        ll c0 = 1,c1 = 1;
        while (--n){
            ll t0 = (c0+c1)%mod,t1 = c0;
            c0 = t0,c1 = t1;
        }
        return (c0+c1)%mod;
    }