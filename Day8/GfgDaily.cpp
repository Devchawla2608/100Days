// Lemonade Change

// You are an owner of lemonade island, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by given array bills[]). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

// NOTE: At first, you do not have any bill to provide changes with. You can provide changes from the bills that you get from the previous customers.

// Given an integer array bills of size N where bills [ i ] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.

bool lemonadeChange(int N, vector<int> &arr) {
    int five = 0;
    int ten = 0;
    int tnty = 0;
    for(int i = 0 ;i<N; i++){
        if(arr[i] == 5){
            five++;
        }else if(arr[i] == 10){
            if(five == 0) return false;
            five--;
            ten++;
        }else if(arr[i]==20){
            if(five != 0 && ten != 0){
                five--;
                ten--;
                tnty++;
            }else if(five>=3 && ten == 0){
                five = five - 3;
                tnty++;
            }else return false;
        }
    }
    return true;
    }