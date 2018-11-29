class Solution {
public:
    vector<string> fizzBuzz(int n) {
        int i = 1;
        vector<string> out;
        while (i <= n) {
            string str = "";
            if (i % 3 == 0) str += "Fizz";
            if (i % 5 == 0) str += "Buzz";
            if (str.empty()) {
                out.push_back(to_string(i));
            } else {
                out.push_back(str);
            }
            ++i;
        }
        return out;
    }
};

