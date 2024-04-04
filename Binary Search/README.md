### Description:

Binary search is an efficient algorithm for finding an element within a sorted array. It works by repeatedly dividing the search interval in half. 

1. **Initialization**: The search interval is initialized as the entire array. The left boundary is set to the first element's index (`0`), and the right boundary is set to the last element's index (`size - 1`).

2. **Midpoint Calculation**: At each step, the algorithm calculates the midpoint of the current search interval. This is done by taking the average of the left and right boundaries and rounding down to the nearest integer. 

3. **Comparison with Target**: The algorithm compares the element at the midpoint with the target element.
   - If the midpoint element is equal to the target, the search is successful, and the index of the target is returned.
   - If the midpoint element is less than the target, the search moves to the right half of the array, discarding the left half.
   - If the midpoint element is greater than the target, the search moves to the left half of the array, discarding the right half.

4. **Update Search Interval**: Based on the comparison result, the left and right boundaries of the search interval are adjusted accordingly. If the target element is not found within the current interval, the search continues with a narrowed interval until the boundaries converge.

5. **Termination**: The algorithm terminates when the left boundary exceeds the right boundary, indicating that the target element is not present in the array.

### Time Complexity:
Binary search has a time complexity of O(log n), where n is the number of elements in the array. This is because the search interval is divided in half at each step, leading to a logarithmic number of iterations.

### Space Complexity:
Binary search has a space complexity of O(1) because it only requires a constant amount of extra space for storing variables regardless of the size of the input array.
