class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        
        while (x % 10 == 0) {
            x /= 10;
        }
        
        bool sign = x > 0 ? false : true;
        if (sign) x = -x;
        
        int order = 0;
        int n = x;
        while (n != 0) {
            n /= 10;
            ++order;
        }
        
        n = x;
        int i = 0;
        int sum = 0;
        while (order > 0) {
            int p = pow(10, order - 1);
            int k = n / p;
            int m = k * p;
            int l = k * pow(10, i);
            n -= m;
            
            if (2147483648 - sum < l || l < 0) return 0;
            sum += l;
            ++i;
            --order;
            std::cout << "K:" << k << " L:" << l << " N:" << n << " S:" << sum << " i:" << i << " o:" << order << " x:" << 2147483648 - sum << '\n';
        }
        
        if (sign) sum = -sum;
        
        return sum;
    }
};
