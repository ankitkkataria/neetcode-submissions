class Solution {
public:


    bool checkPalindrome(int i, int j, string s) {
        while(i < j) {
            if(s[i] != s[j]) 
                return false;
            i++;
            j--;
        }
        return true;

    }


    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while(l < r) {
           if(s[l] != s[r]) {
                return checkPalindrome(l+1, r, s) || checkPalindrome(l, r-1, s);
            }
            l++;
            r--;
        }
        return true;
    }
};