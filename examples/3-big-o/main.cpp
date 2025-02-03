#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

/**
 * Finds an integer in an array of integers.
 * @param values Pointer to an array of integers.
 * @param numValues The number of values in the array.
 * @param target The integer you want to find.
 * @returns The index of the target integer in the array, or -1 if the target is not found.
 */
int Find(int* values, int numValues, int target)
{
    // Loop through each item in the array
    for (int i = 0; i < numValues; i++) {
        // Check if this is the value we are looking for
        if (values[i] == target) {
            return i;
        }
    }

    // Not found
    return -1;
}

/**
 * Gets the last element in an array of integers.
 * @param values Pointer to an array of integers.
 * @param numValues The number of values in the array.
 */
int GetLast(int* values, int numValues)
{
    return values[numValues - 1];
}

/**
 * Sorts an array of integers from smallest to largest.
 * @param values Pointer to an array of integers.
 * @param numValues The number of values in the array.
 */
void Sort(int* values, int numValues)
{
    // Outer loop
    for (int i = 0; i < numValues - 1; i++) {

        // Inner loop: loop through each pair of numbers and swap if necessary
        for (int j = 0; j < numValues - 1 - i; j++) {
            int left = values[j];
            int right = values[j + 1];

            // Swap if needed
            if (left > right) {
                values[j] = right;
                values[j + 1] = left;
            }
        }
    }
}

/**
 * Prints a list of integers to standard output.
 * @param values Pointer to an array of integers.
 * @param numValues The number of values in the array.
 */
void Print(int* values, int numValues)
{
    for (int i = 0; i < numValues; i++)
        cout << values[i] << " ";

    cout << endl;
}

/**
Main entry point for the program.
*/
int main()
{
    // Define array of integers
    int values[] = {5, 4, 3, 2, 1};
    int numValues = sizeof(values) / sizeof(values[0]);

    // Display the current order of the values
    Print(values, numValues);

    // Get last item in the list
    int last = GetLast(values, numValues);
    cout << "Last: " << last << endl;

    // Search for the index of the value 4
    int i = Find(values, numValues, 4);
    cout << "Index of 4: " << i << endl;

    // Sort the array and print the updated order
    Sort(values, numValues);
    Print(values, numValues);

    // Get last item in the list
    last = GetLast(values, numValues);
    cout << "Last: " << last << endl;

    // Search for the updated index of the value 4 after the search
    i = Find(values, numValues, 4);
    cout << "Index of 4: " << i << endl;

    return 0;
}
