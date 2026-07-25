class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> mp;

    RandomizedSet() {}

    bool insert(int val) {
        if (mp.count(val))
            return false;

        nums.push_back(val);
        mp[val] = nums.size() - 1; // we assining the value with the index like
                                   // 1 at index 0 i.e 1 -> 0
                            return true;
    }

    bool remove(int val) {
        if (!mp.count(val))
            return false;

        int index = mp[val];
        int last = nums.back();

        nums[index] = last;
        mp[last] = index;

        nums.pop_back();
        mp.erase(val);
        return true;
    }

    int getRandom() { 
        return nums[rand() % nums.size()]; 
    }

    
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */