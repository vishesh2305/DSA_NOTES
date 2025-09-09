// Q/- Find the minimum element in a rotated sorted array.

// -- A rotated sorted array consists of two sorted subarrays.
// -- The pivot point (drop from higher to lower) is where the minimum element lies.

// Example:

// arr= {2,3,4,5,6,7,8,9,10}

// left rotated by 3 (pivot point)

// [5, 6, 7, 8, 9, 10, 2, 3, 4]

// 1st sorted array: [5,6,7,8,9,10]
// 2nd sorted array: [2,3,4]

// But overall:
// [10 -> 2] is a point where order drops(rotation point). and that drop leads to the minimum.

// -- We will try to find where the drop occurs- the point where arr[i] > arr[i+1].

// code:



