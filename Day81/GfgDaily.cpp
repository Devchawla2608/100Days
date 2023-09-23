// Equilibrium Point

// Given an array A of n positive numbers. The task is to find the first equilibrium point in an array. Equilibrium point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

// Note: Return equilibrium point in 1-based indexing. Return -1 if no such point exists.

// Link : https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1

    int equilibriumPoint(long long a[], int n) {
        long long sum = 0;
        for(int i = 0 ;i<n ; i++){
            sum += a[i];
        }
        long long temp = 0;
        for(int i = 0 ;i<n ; i++){
            if(temp == (sum-temp-a[i])) return i+1;
            temp += a[i];
        }
        return -1;
    }

    Time Complexity : O(n)
    Space Complexity : O(1)