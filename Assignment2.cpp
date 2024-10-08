#include <iostream>
#include <map>
#include <string>

using namespace std;

/**
 * @brief Finds the most frequent character in a given string.
 * 
 * This function iterates over each character in the input string and 
 * counts the occurrences of each character using a map. It then finds 
 * the character with the maximum count.
 * 
 * @param input A string containing the text in which the most frequent character will be found.
 * 
 * @return A pair containing:
 *         - char: The character that appears most frequently.
 *         - int: The number of times this character appears in the string.
 * 
 * If no character repeats, the character in the returned pair will be '\0' 
 * and the count will be 0.
 */
pair<char, int> findMostFrequentChar(const string& input) {
    // Create a map to store the frequency of each character in the input string
    map<char, int> charCount;  // Using map to store character counts

    // Loop through the input string and count the occurrences of each character
    for (size_t i = 0; i < input.length(); i++) {
        charCount[input[i]]++;
    }

    // Variables to store the most frequent character and its frequency
    char mostFrequent = '\0';
    int maxCount = 0;

    // Iterate over the map to find the character with the highest count
    for (map<char, int>::iterator it = charCount.begin(); it != charCount.end(); ++it) {
        if (it->second > maxCount) {
            mostFrequent = it->first;
            maxCount = it->second;
        }
    }

    // Return the most frequent character and its count as a pair
    return make_pair(mostFrequent, maxCount);
}

/**
 * @brief Main function to run the program.
 * 
 * The program prompts the user to input a string, and then calls 
 * the `findMostFrequentChar` function to find the character that appears 
 * most frequently in the string. It then displays the result.
 * 
 * @return int Standard return value of 0 indicates successful execution.
 */
int main() {
    string input;

    // Ask the user to input a string
    cout << "Enter a string: ";
    getline(cin, input);  // Get the entire line of input including spaces

    // Call the function to find the most frequent character
    pair<char, int> result = findMostFrequentChar(input);

    // If no character repeats, output a specific message
    if (result.second <= 1) {
        cout << "No character repeats in the string." << endl;
    } else {
        // Otherwise, display the most frequent character and its count
        cout << "The most frequent character is: '" << result.first << "' with count: " << result.second << endl;
    }

    return 0;  // Return 0 to indicate successful execution
}
