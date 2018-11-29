class Solution {
public:
    string reverseString(string s) {
        auto size = s.size();
        for (int i = 0; i < size / 2; ++i) {
            swap(s[i], s[size - i - 1]);
        }
        return s;
    }
};

