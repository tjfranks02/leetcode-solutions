/**
 * Priority queue implementation taken from neetcode. Still don't really
 * understand this solution but will revisit.
 */
#include <vector>
#include <queue>

using namespace std;

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
