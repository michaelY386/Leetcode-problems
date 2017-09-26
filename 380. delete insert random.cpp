class RandomizedSet {
    
public:
    /** Initialize your data structure here. */
    vector<int> mySet;
    unordered_map<int, int> hash;
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hash.find(val)!=hash.end()) return false;
        mySet.push_back(val);
        hash[val] = mySet.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (hash.find(val)==hash.end()) return false;
        mySet[hash[val]] = mySet.back();
        hash[mySet.back()] = hash[val];
        mySet.pop_back();
        hash.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if (!mySet.size()) return 0;
        return mySet[rand()%(mySet.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */