class RandomizedSet {
public:
  vector<int>values;
  unordered_map<int,int>mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)==mp.end()){
            mp[val]=values.size();
            values.push_back(val);
            return  true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val)!=mp.end()){
          int index = mp[val];
          int n = values.back();
          values[index]=values.back();
          values.pop_back();
          mp[n]=mp[val];
          mp.erase(val);
          return true;
        }
        return false;
    }
    
    int getRandom() {
                int index = rand() % values.size();
        return values[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */