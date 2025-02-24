class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> s;
        
        for (int i = 0; i < n; i++) {
            while (!s.empty() && k > 0 && s.top() > num[i]) {
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        
        // If k is still greater than 0, remove remaining digits from the end
        while (k > 0 && !s.empty()) {
            s.pop();
            k--;
        }
        
        string ans = "";
        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        
        // Remove leading zeros
        int start = 0;
        while (start < ans.size() && ans[start] == '0') {
            start++;
        }
        ans = ans.substr(start);

        return ans.empty() ? "0" : ans;
    }
};
