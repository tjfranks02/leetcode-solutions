class KthLargest {
    
private:
    int _k;
    priority_queue<int, vector<int>, greater<int>> _q;
    
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        
        for (int num : nums) {
            _q.push(num);
        }
        
        while (_q.size() > _k) {
            _q.pop();
        }
    }
    
    int add(int val) {
        _q.push(val);
        
        if (_q.size() > _k) {
            _q.pop();
        }
        
        return _q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */