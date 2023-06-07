class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt=0;
        if(start==goal)return cnt;
        while(start>0 || goal>0){
            int lb1=start&1;
            int lb2=goal&1;
            if(lb1!=lb2)cnt++;
            start>>=1;
            goal>>=1;
        }
        return cnt;
    }
};