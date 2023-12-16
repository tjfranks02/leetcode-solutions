/**
 * Solution using a hashmap. O(n) time, O(n) space.
*/
class Solution {
public:
    string convertLocal(string local) {
        erase(local, '.');

        if (local.find("+")) {
            local = local.substr(0, local.find("+"));
        }

        return local;
    }

    int numUniqueEmails(vector<string>& emails) {
        int numUnique = 0;
        set<string> seen;

        for (int i = 0; i < emails.size(); i++) {
            int atPos = emails[i].find("@");
            string uniqueEmail = convertLocal(emails[i].substr(0, atPos)) + emails[i].substr(atPos, emails[i].length());

            if (!seen.contains(uniqueEmail)) {
                numUnique++;
                seen.insert(uniqueEmail);
            }
        }

        return numUnique;
    }
};