/**
 * Solution for baseball game. This took longer than it needed to. Moral of the story is to read the
 * goddamn question first!!! Made so many unnecessary mistakes because of this.
 * 
 * Anyway this one is pretty good. Seems optimal
 * 
 */
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stk;
        stk.push(0);
        int sum = 0;

        for (int i = 0; i < operations.size(); i++) {
            int newRecord = 0;
            string op = operations[i];

            if (op == "C") {
                sum -= stk.top();
                stk.pop();
            } else if (op == "D") {
                newRecord = 2 * stk.top();
                sum += newRecord;
                stk.push(newRecord);
            } else if (op == "+") {
                newRecord = stk.top();
                stk.pop();
                newRecord += stk.top();
                stk.push(newRecord - stk.top());
                stk.push(newRecord);
                sum += newRecord;
            } else {
                sum += stoi(op);
                stk.push(stoi(op));
            }
        }
        
        return sum;
    }
};