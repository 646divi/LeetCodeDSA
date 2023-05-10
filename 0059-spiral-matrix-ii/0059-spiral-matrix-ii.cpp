class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n));
        int val=1;
        int left=0,right=n-1,up=0,down=n-1;
        while(left<=right and up<=down){
            for(int i=left;i<=right;i++){
                matrix[up][i]=val;
                // cout<<val;
                val++;
            }
            for(int i=up+1;i<down;i++){
                matrix[i][right]=val;
                val++;
            }
            if(left<right and up<down){
                for(int i=right;i>=left;i--){
                matrix[down][i]=val;
                val++;
            }
            for(int i=down-1;i>up;i--){
                matrix[i][left]=val;
                val++;
            }
            }
            
            left++,right--,up++,down--;
        }
        
        return matrix;
    }
};