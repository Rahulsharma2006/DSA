class Solution {
public:

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>stack;
    vector<int> arr(temperatures.size(), 0);
        for(int i =0;i<temperatures.size();i++){
            while(!stack.empty() && temperatures[stack.top()]<temperatures[i]){
                arr[stack.top()] = i -stack.top();
                stack.pop();
            }
            stack.push(i);
        }
        return arr;
    }
};