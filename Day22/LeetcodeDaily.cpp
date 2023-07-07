// . Maximize the Confusion of an Exam
// A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).
// You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:
// Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
// Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.
class Solution {
public:
    int solve(string &s,char b,int &k){
       int left=0,res=0,size=s.size(),cnt=0;
      for(int i=0;i<size;i++){
            if(s[i]==b)
                cnt++;
            while(cnt>k){
                if(s[left]==b)
                    cnt--;
                left++;
            }
            res=max(i-left+1,res);
        }
        return res;
    }
    int maxConsecutiveAnswers(string s, int k) {
      return max(solve(s,'F',k),solve(s,'T',k));  
    }
};