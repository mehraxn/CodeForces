# Beautiful Matrix vs. Square Matrix

This README explains three related concepts used in many programming‑contest problems:

* **Beautiful matrix** (binary, with a specific border pattern)
* **Square matrix** (shape only)
* **Beautiful square** (the intersection of the two)

We’ll define each one carefully, show examples, give simple formulas, and end with a side‑by‑side comparison.

---

## 1) What is a *beautiful matrix*?

A **beautiful matrix** is a **binary** matrix (its entries are only `0` or `1`) of size `r × c` such that:

* Every cell on the **outer border** (first row, last row, first column, last column) is `1`.
* Every **strictly interior** cell (not on the border) is `0`.

Equivalently, the matrix looks like a frame of ones surrounding zeros.

### Edge cases

* If `r = 1` or `c = 1`, there is **no interior**, so *all* entries are `1`.
* If `r ≥ 2` and `c ≥ 2`, the border is the whole first and last rows and columns; only cells with row index `2..r-1` and column index `2..c-1` are interior.

### Examples

**2 × 2 (no interior):**

```
1 1
1 1
```

**1 × 5 (single row, no interior):**

```
1 1 1 1 1
```

**3 × 5 (has interior zeros):**

```
1 1 1 1 1
1 0 0 0 1
1 1 1 1 1
```

**5 × 4:**

```
1 1 1 1
1 0 0 1
1 0 0 1
1 0 0 1
1 1 1 1
```

### Counts (when useful in problems)

* Number of `1`s:

  * If `r = 1` or `c = 1`: `r · c` (every cell is `1`).
  * If `r ≥ 2` and `c ≥ 2`: `2r + 2c − 4` (the perimeter of the rectangle).
* Number of `0`s:

  * If `r ≥ 2` and `c ≥ 2`: `(r − 2) · (c − 2)` (the interior).
  * Otherwise `0`.

---

## 2) What is a *square matrix*?

A **square matrix** is any matrix whose number of rows equals its number of columns: `n × n`.

* The entries can be any numbers (integers, reals, symbols, or even just `0/1`).
* The term “square” is **only about shape**, not about the values inside.

### Examples (square, but not necessarily beautiful)

**3 × 3 arbitrary:**

```
2 5 -1
0 7  4
9 1  3
```

**4 × 4 binary (not beautiful because the center isn’t all zeros):**

```
1 1 1 1
1 1 0 1
1 0 1 1
1 1 1 1
```

---

## 3) What is a *beautiful square*?

A **beautiful square** is a matrix that is **both** beautiful **and** square. Formally, it is an `n × n` **binary** matrix with:

* `1`s on the entire border, and
* `0`s everywhere inside the border.

### Examples

**1 × 1:**

```
1
```

**3 × 3:**

```
1 1 1
1 0 1
1 1 1
```

**5 × 5:**

```
1 1 1 1 1
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
1 1 1 1 1
```

### Counts for an `n × n` beautiful square

* If `n = 1`: ones = `1`, zeros = `0`.
* If `n ≥ 2`: ones = `4n − 4` (perimeter of the square), zeros = `(n − 2)^2` (the interior).

---

## 4) Differences and distinctions

| Concept              | Values allowed        | Shape restriction | Border pattern           | Interior requirement       |
| -------------------- | --------------------- | ----------------- | ------------------------ | -------------------------- |
| **Beautiful matrix** | Binary only (`0`/`1`) | Any `r × c`       | All border cells are `1` | All interior cells are `0` |
| **Square matrix**    | Any numbers           | Must be `n × n`   | None                     | None                       |
| **Beautiful square** | Binary only           | Must be `n × n`   | All border cells are `1` | All interior cells are `0` |

**Key distinctions**

* *Beautiful vs. Square:* “Beautiful” is about the **pattern** of entries; “Square” is about the **shape**. A matrix can be beautiful but not square (e.g., `3 × 5`), or square but not beautiful (any `n × n` without the exact border/inside pattern).
* *Beautiful square:* where both conditions hold at once—**shape** (`n × n`) *and* **pattern** (border `1`s, interior `0`s\`).

---

## 5) Quick recognition checklist

* **Is it binary?** If not, it cannot be beautiful/beautiful‑square.
* **Are all border cells `1`?** If any border cell is `0`, it is not beautiful.
* **Is every interior cell `0`?** If any interior cell is `1`, it is not beautiful.
* **Is it `n × n`?** If yes and the above two checks pass, it is a **beautiful square**; if not square but the pattern passes, it is a **beautiful (rectangular) matrix**.

---

### Visual intuition

Think of a beautiful matrix as a **picture frame** made of `1`s surrounding a field of `0`s. When the frame is a perfect square, you have a **beautiful square**.
