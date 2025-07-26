# README: Detailed Explanation of the Solution for “The Way to Home”

This document provides a thorough, step-by-step explanation of the C implementation below. It covers:

1. **Problem Summary**
2. **Algorithmic Approach**
3. **Code Walkthrough**
4. **Time and Space Complexity**
5. **Correctness and Edge Cases**

---

## 1. Problem Summary

* We have **n** positions numbered from 1 to **n**.
* A frog starts at position 1 and wants to reach position **n**.
* It can make a jump of length between 1 and **d** (inclusive).
* It may only land on positions marked with a lily flower.
* The presence of lilies is given by a binary string `s` of length **n**, where `s[i] == '1'` indicates a lily at position `i+1`.
* It is guaranteed that both the first (`s[0]`) and last (`s[n-1]`) characters are `'1'`.
* **Goal**: Compute the **minimum number of jumps** needed to go from position 1 to position **n**, or output **-1** if it is impossible.

---

## 2. Algorithmic Approach (Greedy)

We use a **greedy** strategy that always jumps as far forward as possible:

1. **Maintain** the frog's current index `p` (0-based; starts at 0).
2. **Repeat** until `p == n-1`:

   * Look ahead from `p+1` up to `p + d` (but not beyond `n-1`).
   * Find the **farthest** index `k` in that range where `s[k] == '1'`.
   * If no such `k` exists, **impossible** → print `-1` and exit.
   * Otherwise, set `p = k`, increment the jump counter `j`.
3. **Print** `j` when the loop ends.

This ensures the frog covers the maximum possible distance at each step, minimizing jump count.

---

## 3. Code Walkthrough

```c
#include<stdio.h>
int main(){
    int n,d,p=0,j=0,i,k,t;
    char s[101];
    if(scanf("%d%d",&n,&d)!=2)
        return 0;
    scanf("%s",s);

    while(p < n-1){
        k = -1;
        t = p + d;
        if(t > n-1) t = n-1;

        // Search for the farthest reachable lily
        for(i = t; i > p; --i)
            if(s[i] == '1'){
                k = i;
                break;
            }

        // If no lily found, cannot proceed
        if(k < 0){
            printf("-1");
            return 0;
        }

        // Jump there and increment counter
        p = k;
        j++;
    }

    // Reached the end
    printf("%d",j);
    return 0;
}
```

| Line(s)              | Description                                                  |
| -------------------- | ------------------------------------------------------------ |
| **Include**          | `<stdio.h>` for I/O functions.                               |
| **Vars**             | `n,d`: input sizes;                                          |
|                      | `p`: current position (0-based index).                       |
|                      | `j`: jump count.                                             |
|                      | `i,k,t`: loop/index helpers.                                 |
|                      | `s[101]`: input string of lilies.                            |
| **Input**            | Read `n` and `d`, then the string `s`.                       |
| **Main Loop**        | `while(p < n-1)`: continue until reaching final index.       |
| **Range Bound**      | Compute `t = min(p+d, n-1)`: farthest index we can try.      |
| **Greedy Jump**      | Scan backwards from `t` to `p+1` to pick the furthest `'1'`. |
| **Impossible Check** | If no `'1'` found (`k == -1`), output `-1` and exit.         |
| **Update**           | Set `p = k`, increment `j`.                                  |
| **Finish**           | Print total jumps `j`.                                       |

---

## 4. Time and Space Complexity

* **Time Complexity**:

  * Each iteration of the `while` loop does a backward scan of up to **d** positions.
  * In the worst case, total iterations ≤ number of jumps ≤ ⌈(n−1)/1⌉ = **O(n)**.
  * Combined, **O(n · d)**. Since **n ≤ 100**, **d ≤ n-1**, this is at most **10,000** steps—fast enough for any standard limit.

* **Space Complexity**:

  * **O(n)** for the string `s` and constant extra variables.
  * Fits well within typical limits.

---

## 5. Correctness and Edge Cases

* **Guaranteed start/end lilies**: ensures first and last positions are always reachable if intermediate lilies exist.
* **Impossible scenario**: when there is a gap of more than `d` consecutive zeros, the code will correctly detect `k < 0` and output `-1`.
* **Minimality**: Greedy farthest jump always reduces the remaining distance most at each step, yielding the minimal jump count for this 1D reachability problem.

*End of README*
