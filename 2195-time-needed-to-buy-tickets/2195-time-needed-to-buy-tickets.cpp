class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n= tickets.size();
        queue<int>temp;
        for(int i=0;i<n;i++){
            temp.push(i);
        }
        int count=0;
        while(true){
            int x= temp.front();
            temp.pop();
            tickets[x]--;
            count++;
            if(x==k && tickets[k]==0){
                break;
            }
            if(tickets[x]>0)    temp.push(x);
        }
        return count;
    }
};