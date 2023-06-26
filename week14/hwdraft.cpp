/*#include <iostream>
#include <vector>
using namespace std;

vector<int> find_min_max(const vector<int>& v, int low, int high);
vector<int> merge_min_max(const vector<int>& min_max_1, const vector<int>& min_max_2);

int main() {
    vector<int> v = {9, 4, 8, 7, 3, 0, 6, 5};
    vector<int> min_max = find_min_max(v, 0, v.size() - 1);

    cout << "min = " << min_max[0] << ", max = " << min_max[1];

    return 0;
}

vector<int> find_min_max(const vector<int>& v, int low, int high) {
    if (low == high) {
        vector<int> min_max(2, v[low]);

        return min_max;
    } else {
        int mid = low + (high - low) / 2;
        vector<int> min_max_1 = find_min_max(v, low, mid);
        vector<int> min_max_2 = find_min_max(v, mid + 1, high);

        return merge_min_max(min_max_1, min_max_2);
    }
}

vector<int> merge_min_max(const vector<int>& min_max_1, const vector<int>& min_max_2) {
    vector<int> min_max(2);
    min_max[0] = min(min_max_1[0], min_max_2[0]);
    min_max[1] = max(min_max_1[1], min_max_2[1]);

    return min_max;
}
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> findMinMax(vector<int>& arr, int low, int high) {
    vector<int> minMax(2);

    // base case: one element
    if (low == high) {
        minMax[0] = arr[low];
        minMax[1] = arr[low];
        return minMax;
    }

    // base case: two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            minMax[0] = arr[low];
            minMax[1] = arr[high];
        } else {
            minMax[0] = arr[high];
            minMax[1] = arr[low];
        }
        return minMax;
    }

    // recursive case: more than two elements
    int mid = (low + high) / 2;
    vector<int> leftMinMax = findMinMax(arr, low, mid);
    vector<int> rightMinMax = findMinMax(arr, mid + 1, high);

    // compare the minimum of the left half with the minimum of the right half
    if (leftMinMax[0] < rightMinMax[0]) {
        minMax[0] = leftMinMax[0];
    } else {
        minMax[0] = rightMinMax[0];
    }

    // compare the maximum of the left half with the maximum of the right half
    if (leftMinMax[1] > rightMinMax[1]) {
        minMax[1] = leftMinMax[1];
    } else {
        minMax[1] = rightMinMax[1];
    }

    return minMax;
}

int main() {
    vector<int> arr = {3, 4, 2, 1, 5, 6, 8, 7};
    int n = arr.size();

    vector<int> minMax = findMinMax(arr, 0, n - 1);

    cout << "Minimum element is " << minMax[0] << endl;
    cout << "Maximum element is " << minMax[1] << endl;

    return 0;
}
