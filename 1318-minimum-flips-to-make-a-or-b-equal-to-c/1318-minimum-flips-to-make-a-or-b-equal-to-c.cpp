class Solution {
public:
    int minFlips(int a, int b, int c) {
        int d=a|b;
        if(d==c)return 0;
        int min_op=0;
        while(a>0 or b>0 or c>0){
            int lb1=a&1;
            int lb2=b&1;
            int lb=c&1;
            if(lb==0){
                min_op+=(lb1+lb2);
            }else{
                if(lb1==0 and lb2==0)min_op++;
            }
            a>>=1;b>>=1;c>>=1;
        }
        return min_op;
    }
};