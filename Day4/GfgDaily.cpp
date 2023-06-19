
// Ticket Counter

// N people from 1 to N are standing in the queue at a movie ticket counter. It is a weird counter, as it distributes tickets to the first K people and then the last K people and again first K people and so on, once a person gets a ticket moves out of the queue. The task is to find the last person to get the ticket.

int distributeTicket(int N, int k) {
        bool flag = true;
        int i = 0;
        int j = N-1;
        while(i<=j){
            if(flag == true){
                i = min(i+k , j+1);
                flag = false;
            }else{
                j = max(j-k , i-1);
                flag = true;
            }
        }
        if(flag == true){
            return j+2;
        }else{
            return i;
        }
    }