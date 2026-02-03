#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

class Solution {
public:
    /**
     * Finds the length of the longest substring without repeating characters.
     * Uses the Sliding Window pattern optimized with a Hash Map.
     * Time Complexity: O(N)
     * Space Complexity: O(K) where K is the size of the character set (e.g., 256 for ASCII)
     */
    int lengthOfLongestSubstring(std::string s) {
        // If the string is empty, the length is 0.
        if (s.empty()) {
            return 0;
        }

        // 1. Data Structures
        // 'char_index_map' stores {character: last seen index}
        std::unordered_map<char, int> char_index_map;
        
        // 'max_len' stores the longest length found so far.
        int max_len = 0;
        
        // 'left' pointer marks the start of the current window.
        int left = 0;
        
        // 2. Iterate with the 'right' pointer to expand the window.
        for (int right = 0; right < s.length(); ++right) {
            char current_char = s[right];

            // 3. Check for Duplicates & Shrink the Window
            // If the current character is ALREADY in the map:
            if (char_index_map.count(current_char)) {
                // The 'left' pointer must jump to the index *after* the previous occurrence.
                // We use std::max to ensure 'left' never moves backward, 
                // only forward past the last duplicate found in the current window.
                left = std::max(left, char_index_map.at(current_char) + 1);
            }

            // 4. Update Map and Max Length
            
            // Always update the current character's index to its newest position.
            char_index_map[current_char] = right;
            
            // Calculate the current valid window length (right - left + 1) and update max_len.
            max_len = std::max(max_len, right - left + 1);
        }

        return max_len;
    }
};

// --- Example Usage (Not needed in LeetCode, but useful for testing) ---
/*
int main() {
    Solution solver;
    
    std::cout << "abcabcbb -> " << solver.lengthOfLongestSubstring("abcabcbb") << std::endl; // Output: 3
    std::cout << "bbbbb -> " << solver.lengthOfLongestSubstring("bbbbb") << std::endl;     // Output: 1
    std::cout << "pwwkew -> " << solver.lengthOfLongestSubstring("pwwkew") << std::endl;   // Output: 3
    
    return 0;
}
*/