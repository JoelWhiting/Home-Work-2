#include <iostream>
#include <map>
#include <string>

using namespace std;

// Function to find the character that occurs most often
pair<char, int> findMostFrequentChar(const string& input) {
    map<char, int> charCount;  // Using map instead of unordered_map for better compatibility
    
    // Iterate over each character in the string
    for (size_t i = 0; i < input.length(); i++) {
        charCount[input[i]]++;
    }
    
    // Find the character with the highest counter
    char mostFrequent = '\0';
    int maxCount = 0;
    
    for (map<char, int>::iterator it = charCount.begin(); it != charCount.end(); ++it) {
        if (it->second > maxCount) {
            mostFrequent = it->first;
            maxCount = it->second;
        }
    }
    
    return make_pair(mostFrequent, maxCount);  // Using make_pair instead of initializer lists
}

int main() {
    string input;
    
    // Ask user for input string
    cout << "Enter a string: ";
    getline(cin, input);
    
    // Find the most frequent character
    pair<char, int> result = findMostFrequentChar(input);
    
    // Check if any character repeats
    if (result.second <= 1) {
        cout << "No character repeats in the string." << endl;
    } else {
        cout << "The most frequent character is: '" << result.first << "' with count: " << result.second << endl;
    }
    
    return 0;
}
