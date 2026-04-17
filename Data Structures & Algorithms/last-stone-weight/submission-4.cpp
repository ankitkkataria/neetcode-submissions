class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       priority_queue<int>pq;
       for(auto stone : stones) {
            pq.push(stone);
       }

       while(pq.size() >= 2) {
            int top = pq.top();
            cout << "top ele is " << top << endl;
            pq.pop();
            int secondTop = pq.top();
            cout << "sec top ele is " << secondTop << endl;
            pq.pop();
            cout << "heap size is " << pq.size() << endl;
            if(top == secondTop) {
                if(pq.size() == 0) 
                    return 0;
            }
            else pq.push(abs(top - secondTop));
       }

       return pq.top();
    }
};
