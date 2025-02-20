class Solution {
public:
     bool compare(map<char, int>& hash1, map<char, int>& hash2) {
        return hash1 == hash2;  
    }

    vector<int> findAnagrams(string s, string p) {
        int n=p.size();
        map<char,int>hash1;
        for(int i=0;i<n;i++){
            hash1[p[i]]++;
        }
        int l=0,r=0,count=0;
        map<char,int>hash2;
        vector<int>ans;
        while(r<s.size()){
            hash2[s[r]]++;
            if(r-l+1==n){
                if(compare(hash1,hash2))    ans.push_back(l);
                hash2[s[l]]--;
                if(hash2[s[l]]==0) hash2.erase(s[l]);  
                l++;
            }
            r++;
        }
        return ans;
    }
};