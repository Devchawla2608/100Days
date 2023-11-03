class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
    for (int i = 0; i < n; i++) {
            arr[i] = arr[i] * arr[i];
        }
 
        unordered_set<int> squaredValues(arr, arr + n);
 
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int sumOfSquares = arr[i] + arr[j];
                if (squaredValues.find(sumOfSquares) != squaredValues.end()) {
                    return true; 
                }
            }
        }
 
        return false;
	}
};