//////////////////////////////////////////////written by mht83/////////////////////////////////////////
#include <iostream>
#include <string>


bool isPalindrome(const std::string& str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}


std::string longestPalindromicSubstring(const std::string& input) {
    int maxLength = 0;
    std::string longestPalindrome;

    for (int i = 0; i < input.length(); ++i) {
        for (int j = i; j < input.length(); ++j) {
            std::string currentSubstring = input.substr(i, j - i + 1);
            if (isPalindrome(currentSubstring) && currentSubstring.length() > maxLength) {
                maxLength = currentSubstring.length();
                longestPalindrome = currentSubstring;
            }
        }
    }
    return longestPalindrome;
}

int main() {
    std::string inputString;
    std::cout << "Enter a string: ";
    std::getline( std::cin, inputString);

    std::string longestPalindrome = longestPalindromicSubstring(inputString);
    std::cout << "The longest palindromic substring is: " << longestPalindrome << std::endl;

    return 0;
}

