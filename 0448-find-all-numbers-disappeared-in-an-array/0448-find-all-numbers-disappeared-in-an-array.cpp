class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        unordered_set<int>m;
        for(int& a : nums){
            m.insert(a);
        }
        
        for(int i = 1 ;i<=nums.size();i++){
            if(m.find(i)==m.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};