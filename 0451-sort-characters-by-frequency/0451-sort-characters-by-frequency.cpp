class Solution {
public:
    static bool comp(pair<char,int>&a,pair<char,int>&b){
        return a.second > b.second;
    }
    string frequencySort(string s) {
        map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        vector<pair<char,int>>freq(mp.begin(),mp.end());
        sort(freq.begin(),freq.end(),comp);
        string temp="";
        for(auto it:freq){
            temp.append(it.second,it.first);
        }
        return temp;
        
    }
};