class Solution {
public:
    static bool comp(string &s1,string &s2){
        return s1.size() < s2.size();
    }
    bool check(string s1,string s2){
        if(s2.length()!=s1.length()+1)return false;
        int first=0,second=0;
        while(first<s2.length()){
            if(s2[first]==s1[second]){
                first++;
                second++;
            }else{
                first++;
            }
            
        }
        if(first==s2.size()  and second==s1.size())return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        
        int n=words.size();
        vector<int>lis(n,1);
         
        for(int i=0;i<n;i++){
            // lis[i]=1;
            for(int j=0;j<i;j++){
                
                if(check(words[j],words[i])){
                    lis[i]=max(lis[i],1+lis[j]);
                    
                }
            }
        }
        return *max_element(lis.begin(),lis.end());
    }
};