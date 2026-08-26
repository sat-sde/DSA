class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = "";
        int i = 0, j = 0, ones = 0;
        while (j < n) {
            if (s[j] == '1') {
                ones++;
            }
            // shrink the window
            while (ones > k) {
                if (s[i] == '1') {
                    ones--;
                }
                i++;
            }
            if (ones == k) {
                while (i <= j && s[i] == '0') {
                    i++;
                }
                string curr = s.substr(i, j - i + 1);
                if (ans == "" || curr.size() < ans.size() ||
                    (curr.size() == ans.size() && curr < ans)) {
                    ans = curr;
                }
            }
            j++;
        }
        return ans;
    }
};