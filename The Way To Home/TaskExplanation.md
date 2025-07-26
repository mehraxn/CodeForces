# A. The Way to Home

## Overview

This document describes the problem **"A. The Way to Home"**, including its description, input/output formats, sample tests, explanations of provided screenshots, and a recommended solution approach.

---

## Problem Statement

A frog starts at point **1** on a number line and wants to reach point **n**. It can jump to the right by any integer distance between **1** and **d**, but only onto positions that have a lily flower. It is guaranteed that positions **1** and **n** have lilies.

Determine the minimum number of jumps the frog needs to reach point **n**. If it is impossible, output **-1**.

---

## Input Format

1. Two integers:

   * `n` (2 ≤ n ≤ 100): the destination point.
   * `d` (1 ≤ d ≤ n − 1): the maximum jump length.
2. A string `s` of length `n`, consisting of characters `'0'` and `'1'`.

   * `s[i] = '1'` indicates a lily at position `i + 1`.
   * `s[i] = '0'` indicates no lily at position `i + 1`.

It is guaranteed that `s[0] = s[n−1] = '1'`.

---

## Output Format

Output a single integer:

* The minimum number of jumps needed to reach point **n** from point **1**.
* **-1** if the frog cannot reach point **n**.

---

## Sample Test Cases

| Input        | Output |
| ------------ | ------ |
| 8 4          | 2      |
| 10010101     |        |
| 4 2          | -1     |
| 1001         |        |
| 8 4          | 3      |
| 11100101     |        |
| 12 3         | 4      |
| 101111100101 |        |

---

## Explanation of Sample Cases

1. **n=8, d=4, s="10010101"**

   * Jumps: 1→4 (distance 3), then 4→8 (distance 4). Total 2.
2. **n=4, d=2, s="1001"**

   * Cannot progress from position 1 to position 4 because there is no lily within jumps of length 1 or 2 after the first move. Output **-1**.
3. **n=8, d=4, s="11100101"**

   * One optimal path: 1→5 (4), 5→7 (2), 7→8 (1). Total 3.
4. **n=12, d=3, s="101111100101"**

   * One possible path: 1→3→6→9→12. Total 4.

---

## Explanation of Provided Screenshots

1. **Title and Limits**: Shows the problem title, time limit (1 second), and memory limit (256 MB).
2. **Input/Output Description**: Details the two integers `n` and `d`, and the binary string `s` defining lily positions.
3. **Examples Section**: Presents several sample inputs with corresponding outputs, illustrating both reachable and unreachable scenarios.

---

## Constraints

* 2 ≤ n ≤ 100
* 1 ≤ d ≤ n − 1
* String length `n` with `s[0] = s[n−1] = '1'`.

---

## Recommended Approach

Use a **greedy** algorithm:

1. Track the frog's current position `pos` (starting at index 0 for position 1).
2. At each step, look ahead up to distance `d` and jump to the farthest reachable lily (`'1'`) within that range.
3. Increment the jump count and repeat until reaching the final index `n−1`, or conclude **-1** if no valid lily is found.

This runs in **O(n·d)** time, which is efficient for `n ≤ 100`.

---

*End of README*
