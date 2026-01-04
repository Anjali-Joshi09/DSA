class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int n : nums) {
            for (int d = 2; d * d <= n; d++) {
                if (n % d == 0) {
                    int a = d;
                    int b = n / d;
                    if (a != b && isPrime(a) && isPrime(b)) {
                        ans += 1 + a + b + n;
                    }
                    else if (a == b && isPrime(a)) {
                    }
                    else if (isPrime(a) && b == a * a) {
                        ans += 1 + a + a * a + n;
                    }
                    break;
                }
            }
        }
        return ans;
    }
};
