class Solution {
public:
    vector<int>prevSmaller(vector<int>arr){
        int n=arr.size();
        vector<int>prevS(n,-1);
        stack<int>s;
        for( int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }
            if(s.empty())    s.push(i);
            else {
                prevS[i]=s.top();
            }
            s.push(i);
        }
        return prevS;
    }
    vector<int>nextSmaller(vector<int>arr){
         int n =arr.size();
        vector<int>nextS(n,n);
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.empty())    s.push(i);
            else {
                nextS[i]=s.top();
            }
            s.push(i);
        }
        return nextS;
        }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int>prevS=prevSmaller(arr);
        vector<int>nextS=nextSmaller(arr);
        const int MOD=1e9+7;
        long long sum=0;
        for(int i=0;i<arr.size();i++){
            sum+= 1l* (i-prevS[i])*(nextS[i]-i)*arr[i]%MOD;
        }
       return sum%MOD;
    }
};