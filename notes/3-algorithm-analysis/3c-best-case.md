# Best-case Analysis

You can analyze a function looking at worst-case, best-case, or average-case scenarios.

Consider the `Find()` function:

```cpp
                                   // Cost                     Times
for (int i = 0;                    // 1 (assignment)           1 (start of loop)
         i < n;                    // 1 (boolean compare)      n + 1 (iteration + end)
         i++)                      // 1 (addition)             n (iteration)
{
    if (values[i] == target) {     // 1 (boolean compare)      n
        return i;                  // 1 (return)               Only if value found
    }
}

return -1;                         // 1 (return)               Only if value NOT found
```

Our original analysis was through the lens of the worst-case scenario:

- Target value is not in the list at all; we have to search through all items.

What is the best case scenario?

- The target item is the first item in the list.

We can find a formula $f(n)$ to describe the number of operations required by the `Find()` algorithm in the best-case scenario.

```cpp
                                   // Cost                     Times
for (int i = 0;                    // 1 (assignment)           1 (start of loop)
         i < n;                    // 1 (boolean compare)      1 in best case
         i++)                      // Never hit in best case
{
    if (values[i] == target) {     // 1 (boolean compare)      1 in best case
        return i;                  // 1 (return)               1 in best case
    }
}

return -1;                         // Never hit in best case
```

Based on that

> $f(n) = 1 + 1 + 1 + 1$

> $f(n) = 4$

No matter the input size, the number of steps required in the best case is always four.

What is the time complexity of this algorithm in the best case? What is the Big O?

- Constant time: $O(1)$
