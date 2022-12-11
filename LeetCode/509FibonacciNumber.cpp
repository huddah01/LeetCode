class Solution {
public:
    int fib(int n) {
        // Use recursion and the formula f(n) = f(n - 1) + f(n - 2) for n > 1

        // Base cases are n = 0 or n = 1
        if(n == 0) {
            return 0;
        }
        if(n == 1) {
            return 1;
        }
        // Otherwise we return the formula
        return (fib(n - 1) + fib(n - 2));
    }
};
