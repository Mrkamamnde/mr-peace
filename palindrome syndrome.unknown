#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers or multiples of 10 (but not 0) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int reversedHalf = 0;
        while (x > reversedHalf) {
            int digit = x % 10;
            reversedHalf = reversedHalf * 10 + digit;
            x /= 10;
        }

        // Check for even and odd length numbers
        return (x == reversedHalf || x == reversedHalf / 10);
    }
};

int main() {
    Solution sol;
    cout << boolalpha;  // print true/false instead of 1/0
    cout << sol.isPalindrome(121) << endl;   // true
    cout << sol.isPalindrome(-121) << endl;  // false
    cout << sol.isPalindrome(10) << endl;    // false
    cout << sol.isPalindrome(12321) << endl; // true
    return 0;
}
