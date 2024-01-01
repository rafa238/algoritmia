class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        priority_queue<int, vector<int>, greater<int>> cookies, children;
        for (int cookie : s) {
            cookies.push(cookie);
        }

        for (int child : g) {
            children.push(child);
        }
        int satisfied = 0;
        while (!cookies.empty() && !children.empty()) {
            int currCookie = cookies.top(),
                currChild = children.top();
            
            if (currCookie >= currChild) {
                satisfied++;
                children.pop();
            }
            cookies.pop();
        }

        return satisfied;
    }
};