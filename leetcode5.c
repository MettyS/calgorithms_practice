// https://leetcode.com/problems/longest-palindromic-substring/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool stepWithinBounds(const uint64_t len, const uint64_t i, const uint64_t step) {
    return (i - step >= 0 && i + step < len);
}

uint64_t longestPalindrome(const char * const s, const uint64_t len) {
    uint64_t longestPal = 0;
    for (size_t i = 0; i < len; ++i) {
        for (size_t step = 0; stepWithinBounds(len, i, step); ++step) {
            if (s[i - step] != s[i + step]) {
                break;
            }
            const uint64_t currentLength = (step * 2) + 1;
            if (currentLength > longestPal) {
                longestPal = currentLength; 
            }
        }
    }
    return longestPal;
}


int main() {
    // for (int i = 0; i < argc; ++i) {
    //     printf("arg %d: %s\n", i, argv[i]);
    // }

    // char *myString = (char *) malloc(1000 * sizeof(uint16_t));


    // struct x myX;

    // myX.a = 245;
    // myX.d = 1;

    const char test1[] = "aacabacaa";
    if (longestPalindrome(test1, sizeof(test1) - 1) != 9) {
        printf("failed: %s\n", test1);
        return 1;
    }
    return 0;
}

// struct x {
//     uint8_t a;
//     uint64_t b;
//     uint64_t c;
//     uint8_t d;
// };

