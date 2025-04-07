#include <iostream>
#include <vector>

using namespace std;

/**
Merge two parts of a list.
@param left The index of the left part.
@param mid The index of the last element in the left part.
@param right The index of the last element in the right part.
*/
void Merge(vector<int>& numbers, int left, int mid, int right)
{
    vector<int> temp;

    // Create index values to track progress through left and right halves
    int l = left;
    int r = mid + 1;

    // Merge elements from left and right halves into temp array
    while (l <= mid && r <= right) {
        if (numbers.at(l) < numbers.at(r)) {
            temp.push_back(numbers.at(l));
            l++;
        }
        else {
            temp.push_back(numbers.at(r));
            r++;
        }
    }

    // Copy remaining elements from left half
    while (l <= mid) {
        temp.push_back(numbers.at(l));
        l++;
    }

    // Copy remaining elements from right half
    while (r <= right) {
        temp.push_back(numbers.at(r));
        r++;
    }

    // Copy sorted elements back to original array
    for (int i = 0; i < temp.size(); i++) {
        numbers.at(left + i) = temp.at(i);
    }
}

/**
 * Sorts a list using the merge sort algorithm.
 */
void MergeSort(vector<int>& numbers, int left, int right)
{
    // Base case: sublist has 1 or 0 elements
    if (left >= right)
        return;

    // Recursive case: divide list into two halves and sort each half
    int mid = (left + right) / 2;
    MergeSort(numbers, left, mid);
    MergeSort(numbers, mid + 1, right);

    // Merge the two sorted halves
    Merge(numbers, left, mid, right);
}

/**
 * Sorts a list using the merge sort algorithm.
 */
void MergeSort(vector<int>& numbers)
{
    MergeSort(numbers, 0, numbers.size() - 1);
}

int main()
{
    vector<int> numbers = {90, 43, 1, 93, 13, 43, 84, 12};
    MergeSort(numbers);

    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers.at(i) << " ";
    }

    return 0;
}
