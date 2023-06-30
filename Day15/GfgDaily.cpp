// Is Binary Number Multiple of 3
// Given a number in its binary form find if the given binary number is a multiple of 3. It is recommended to finish the task using one traversal of input binary number.
int isDivisible(string s) {
        int oddCount = 0;
        int evenCount = 0;
        int n = s.length();

        // Traverse the binary number from right to left
        for (int i = n - 1; i >= 0; i--) {
            // If the current bit is '1'
            if (s[i] == '1') {
                // Increment the count based on the position
                if ((n - 1 - i) % 2 == 0)
                    evenCount++;
                else
                    oddCount++;
            }
        }

        // Check if the difference between odd and even counts is divisible by 3
        if ((oddCount - evenCount) % 3 == 0)
            return 1;
        else
            return 0;
    }
