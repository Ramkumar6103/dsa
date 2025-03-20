#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(); // Length of the input array
        int write = 0;        // Position to write in chars
        int i = 0;            // Iterator for reading the array

        while (i < n) {
            char currentChar = chars[i]; // Current character
            int count = 0;

            // Count the occurrences of the current character
            while (i < n && chars[i] == currentChar) {
                count++;
                i++;
            }

            // Write the current character
            chars[write++] = currentChar;

            // Write the count (if greater than 1)
            if (count > 1) {
                for (char c : to_string(count)) {
                    chars[write++] = c;
                }
            }
        }

        return write; // New length of the compressed array
    }
};

int main() {
    // Example input: ['a', 'a', 'b', 'b', 'c', 'c', 'c', 'c', 'c', 'c', 'c']
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c', 'c', 'c', 'c', 'c'};

    // Create a Solution object
    Solution solution;

    // Call the compress function
    int compressedLength = solution.compress(chars);

    // Output the compressed array and its new length
    cout << "Compressed Length: " << compressedLength << endl;
    cout << "Compressed Array: ";
    for (int i = 0; i < compressedLength; i++) {
        cout << chars[i] << " ";
    }
    cout << endl;

    return 0;
}
