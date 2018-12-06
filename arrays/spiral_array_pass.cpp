// Example program
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <queue>
#include <vector>

enum DIR { L, R, T, B };

/**
 *  1  2  3  4  5
 *  6  7  8  9  10
 *  11 12 13 14 15
 *  16 17 18 19 20
 *  21 22 23 24 25
 * 
 *  13 14 19 18 17 12 7 8 9 10 15 20 25 24 23 22 21 16 11 6 1 2 3 4 5
 */
std::vector<int> fill(int n) {
    std::vector<int> v;
    int n2 = n * n;
    v.reserve(n2);
    for (int i = 1; i <= n2; ++i) v.push_back(i);
    return v;
}

std::vector<int> solve(const std::vector<int>& v, int n) {
    std::vector<int> s;
    
    int i = n / 2 + 1;
    int j = n / 2 + 1;
    int d = i * n + j - n - 1;
    s.push_back(v[d]);
    
    int step = 0;
    for (; step < n / 2; ++step) {
        int startRights = 1 + step;  // 2 // 3
        int bottoms = 1 + step*2;  // 3 // 5
        int lefts = 2 + step*2;  // 4  // 6
        int tops = 2 + step*2;  // 4  // 6
        int endRights = 1 + step;  // 2 // 3
        
        std::queue<DIR> q;
        while (startRights > 0) {
            q.push(DIR::R);
            --startRights;
        }
        while (bottoms > 0) {
            q.push(DIR::B);
            --bottoms;
        }
        while (lefts > 0) {
            q.push(DIR::L);
            --lefts;
        }
        while (tops > 0) {
            q.push(DIR::T);
            --tops;
        }
        while(endRights > 0) {
            q.push(DIR::R);
            --endRights;
        }
        
        while (!q.empty()) {
            auto dir = q.front();
            switch (dir) {
                case DIR::L:
                    --j;
                    break;
                case DIR::R:
                    ++j;
                    break;
                case DIR::T:
                    --i;
                    break;
                case DIR::B:
                    ++i;
                    break;
            }
            q.pop();
            
            int d = i * n + j - n - 1;
            s.push_back(v[d]);
        }
    }
    
    int startRights = step;
    std::queue<DIR> q;
    while (startRights > 0) {
        q.push(DIR::R);
        --startRights;
    }
    
    while (!q.empty()) {
        auto dir = q.front();
        switch (dir) {
            case DIR::L:
                --j;
                break;
            case DIR::R:
                ++j;
                break;
            case DIR::T:
                --i;
                break;
            case DIR::B:
                ++i;
                break;
        }
        q.pop();
        
        int d = i * n + j - n - 1;
        s.push_back(v[d]);
    }
    
    return s;
}

int main() {
    std::vector<int> v = fill(5);
    std::vector<int> e = {13, 14, 19, 18, 17, 12, 7, 8, 9, 10, 15, 20, 25, 24, 23, 22, 21, 16, 11, 6, 1, 2, 3, 4, 5};
    std::vector<int> s = solve(v, 5);
    if (s == e) {
        std::cout << "SUCCESS\n";
    } else {
        std::cout << "ERROR " << std::endl;
        std::copy(s.begin(), s.end(), std::ostream_iterator<int>(std::cout, " "));
    }
    return 0;
}
