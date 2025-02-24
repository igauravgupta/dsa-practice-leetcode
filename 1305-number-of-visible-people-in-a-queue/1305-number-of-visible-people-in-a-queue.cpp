class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {
        int n =arr.size();
        vector<int>ans(n,0);
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            int count=0;
            while(!s.empty()&&s.top()<arr[i]){
                s.pop();
                count++;
            }
            if(!s.empty()) count++;

            ans[i]=count;
            s.push(arr[i]);
        }
        return ans;
    }
};