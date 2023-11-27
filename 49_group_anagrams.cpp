/**
 * My solution which uses a hashing function potentially prone to clashes
*/
class Solution {
public:
  unsigned long long genHash(string str) {
      unsigned long long sum_hash = 0;

      for (char c : str) {
          sum_hash += int(c);
      } 

      unsigned long long mul_hash = 1;

      for (char c : str) {
          mul_hash *= int(c);
      }

      return sum_hash + mul_hash;
  }

  vector<vector<string>> groupAnagrams(vector<string>& strs) {
      map<unsigned long long, vector<string>> groups;

      for (string str : strs) {
          unsigned long long hash = genHash(str);

          if (groups.contains(hash)) {
              groups[hash].push_back(str);
          } else {
              groups[hash] = vector<string>({str});
          }
      }

      vector<vector<string>> result;

      for(auto const& group : groups) {
          result.push_back(group.second);
      }

      return result;
  }
};

/**
 * Better solution with hash function that doesn't have clashes
*/
class Solution2 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            string key = getKey(strs[i]);
            m[key].push_back(strs[i]);
        }
        
        vector<vector<string>> result;
        for (auto it = m.begin(); it != m.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }
private:
    string getKey(string str) {
        vector<int> count(26);
        for (int j = 0; j < str.size(); j++) {
            count[str[j] - 'a']++;
        }
        
        string key = "";
        for (int i = 0; i < count.size(); i++) {
            key.append(to_string(count[i]) + '#');
        }
        return key;
    }
};