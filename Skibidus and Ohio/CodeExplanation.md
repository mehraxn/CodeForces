# Skibidus and Ohio - Solution Algorithm

## Problem Summary

Given a string of lowercase Latin letters, Skibidus can perform operations to reduce its length. The operation allows him to find two adjacent identical characters, replace the first one with any character of his choice, and remove the second one. The goal is to find the minimum possible length achievable.

## Key Insight

The critical observation that leads to an elegant solution is:

**If there exists ANY pair of adjacent identical characters in the string, the entire string can eventually be reduced to length 1. If no such pair exists, no operations can be performed.**

## Why This Insight Works

### Case 1: Adjacent Identical Characters Exist
When we have adjacent identical characters, we can:
1. Perform the operation to reduce string length by 1
2. The replacement character can be chosen strategically to potentially create new adjacent identical pairs
3. This process can continue until we reach length 1

**Proof by Example:**
- String: "baa" (has adjacent 'a's)
- Operation 1: Replace first 'a' with 'b', remove second 'a' → "bb"
- Operation 2: Replace first 'b' with any letter, remove second 'b' → single character
- **Result: Length 1**

### Case 2: No Adjacent Identical Characters
When no adjacent characters are identical:
- No operation can be performed (operation requires `s[i] = s[i+1]`)
- String length remains unchanged
- **Result: Original length**

**Example:**
- String: "skibidus" (s≠k, k≠i, i≠b, b≠i, i≠d, d≠u, u≠s)
- No operations possible
- **Result: Length 8**

## Algorithm Implementation

### Step-by-Step Algorithm
1. **Input Processing:** Read the number of test cases and process each string
2. **Adjacent Check:** Iterate through the string and check if any adjacent characters are identical
3. **Decision Logic:** 
   - If adjacent identical characters found → minimum length = 1
   - If no adjacent identical characters found → minimum length = original length
4. **Output:** Print the result for each test case

### Pseudocode
```
for each test case:
    read string s
    calculate length l of string s
    set flag h = 0 (no adjacent identical characters found)
    
    for i from 0 to l-2:
        if s[i] equals s[i+1]:
            set h = 1 (found adjacent identical characters)
            break from loop
    
    if h equals 1:
        print 1
    else:
        print l
```

### C Implementation Details

#### Variable Naming
- `t`: Number of test cases
- `s`: Input string (array of 101 characters to handle maximum length + null terminator)
- `l`: Length of current string
- `h`: Boolean flag (0/1) indicating if adjacent identical characters exist
- `i`: Loop counter for string iteration

#### Key Functions Used
- `scanf("%d", &t)`: Read number of test cases
- `scanf("%s", s)`: Read string input
- `strlen(s)`: Calculate string length
- `printf()`: Output results

#### Loop Structure
- **Outer loop:** `while (t--)` processes each test case
- **Inner loop:** `for (int i = 0; i < l - 1; i++)` checks adjacent characters
- **Early termination:** `break` statement exits loop when first adjacent pair is found

#### Boundary Conditions
- Loop runs from `i = 0` to `i = l - 2` to safely access `s[i+1]`
- String array size is 101 to accommodate maximum string length (100) plus null terminator
- Single character strings (length 1) automatically return length 1 since no operations are possible

## Time and Space Complexity

### Time Complexity
- **Per test case:** O(n) where n is the length of the string
- **Overall:** O(t × n) where t is number of test cases and n is average string length
- **Worst case:** O(100 × 100) = O(10,000) operations (very efficient)

### Space Complexity
- **O(1)** additional space (excluding input storage)
- Fixed-size character array regardless of input size
- No dynamic memory allocation required

## Edge Cases Handled

1. **Single character string:** Length remains 1 (no operations possible)
2. **All characters identical:** Can be reduced to length 1
3. **No identical characters:** Length remains unchanged
4. **Mixed scenarios:** Correctly identifies whether reduction is possible

## Algorithm Correctness

### Proof of Correctness
The algorithm is correct because:

1. **Necessity:** If no adjacent identical characters exist, no operations can be performed by definition
2. **Sufficiency:** If any adjacent identical characters exist, we can always reach length 1:
   - Each operation reduces length by 1
   - We can strategically choose replacement characters to maintain the ability to perform operations
   - Process continues until only one character remains

### Mathematical Foundation
- **Binary decision:** Either operations are possible (→ length 1) or impossible (→ original length)
- **No intermediate states:** The minimum achievable length is never between 1 and the original length
- **Deterministic outcome:** Given any string, the result is uniquely determined

## Performance Characteristics

- **Linear scan:** Single pass through the string
- **Early termination:** Stops as soon as first adjacent pair is found
- **Optimal efficiency:** No unnecessary computations
- **Memory efficient:** Uses minimal additional space

This algorithm provides an optimal O(n) solution to determine the minimum achievable string length through the specified operations.