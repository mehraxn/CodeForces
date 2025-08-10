# B. Skibidus and Ohio

## Problem Constraints
- **Time limit per test:** 1 second
- **Memory limit per test:** 256 megabytes

## Problem Description

Skibidus is given a string `s` that consists of lowercase Latin letters. If `s` contains more than 1 letter, he can perform the following operation:

### Operation Rules
- Choose an index `i` where `1 ≤ i ≤ |s| - 1` (where `|s|` denotes the current length of `s`)
- The condition must be satisfied: `s[i] = s[i+1]` (two adjacent characters must be identical)
- Replace `s[i]` with any lowercase Latin letter of his choice
- Remove `s[i+1]` from the string

### Objective
Skibidus must determine the minimum possible length he can achieve through any number of operations.

## Input Format

- The first line contains an integer `t` (`1 ≤ t ≤ 100`) — the number of test cases
- Each of the next `t` lines contains a string `s` (`1 ≤ |s| ≤ 100`)
- It is guaranteed that `s` only contains lowercase Latin letters

## Output Format

For each test case, output an integer on a new line representing the minimum achievable length of `s`.

## Examples

### Input
```
4
baa
skibidus
cc
ohio
```

### Output
```
1
8
1
4
```

## Detailed Explanation

### Test Case 1: "baa"
Skibidus can perform the following operations:
1. **Operation on i=2:** Since `s[2] = s[3] = 'a'`, he can replace `s[2]` with 'b' and remove `s[3]`. String becomes "bb"
2. **Operation on i=1:** Since `s[1] = s[2] = 'b'`, he can replace `s[1]` with any letter (e.g., 'b') and remove `s[2]`. String becomes "b"
3. Since the string now contains only 1 letter, no more operations can be performed

**Result:** Minimum length = 1

### Test Case 2: "skibidus"
- Looking at the string: s-k-i-b-i-d-u-s
- No adjacent characters are identical (no `s[i] = s[i+1]` exists)
- Therefore, no operations can be performed
- **Result:** Minimum length = 8 (original length)

### Test Case 3: "cc"
- Since `s[1] = s[2] = 'c'`, one operation can be performed
- Replace `s[1]` with any letter and remove `s[2]`
- **Result:** Minimum length = 1

### Test Case 4: "ohio"
- Looking at the string: o-h-i-o
- No adjacent characters are identical
- No operations can be performed
- **Result:** Minimum length = 4 (original length)

## Key Insights

1. **Operation Condition:** An operation can only be performed when there are two adjacent identical characters
2. **Cascading Effect:** Once you can perform one operation, it might create new opportunities for more operations
3. **Minimum Length Logic:**
   - If the string has any pair of adjacent identical characters, you can eventually reduce it to length 1
   - If no adjacent identical characters exist, the string length remains unchanged
4. **String Indexing:** The problem uses 1-based indexing (i.e., first character is at position 1)

## Algorithm Approach

The solution involves checking if there exists any index `i` such that `s[i] = s[i+1]`. If such a pair exists, the minimum achievable length is 1. Otherwise, the minimum achievable length is the original string length.