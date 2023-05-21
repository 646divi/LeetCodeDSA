class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>lis(n,1);
        vector<int>h(n);
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)h[i]=i;
        for(int i=1;i<n;i++){
            lis[i]=1;
            for(int j=0;j<i;j++){
                if(nums[j]%nums[i]==0 || nums[i]%nums[j]==0){
                    if(1+lis[j] > lis[i]){
                        lis[i]=max(lis[i],1+lis[j]);
                        h[i]=j;
                    } 
                }
            }
        }
        int ans=-1,li=0;
        for(int i=0;i<n;i++){
            if(lis[i]>ans){
                ans=lis[i];
                li=i;
            }
        }
        vector<int>temp;
        temp.push_back(nums[li]);
        while(h[li]!=li){
            li=h[li];
            temp.push_back(nums[li]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
        
    }
};