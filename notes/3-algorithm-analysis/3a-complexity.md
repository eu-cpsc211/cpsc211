# Complexity Analysis

Textbook sections:

- 3.1 O notation
- 3.2 Algorithm analysis
- 3.3 Constant time operations

## Example program

An example program can be found in [/examples/3-big-o/main.cpp](../../examples/3-big-o/main.cpp). We will reference this program as we discuss algorithm analysis.

The program contains a number of functions that operate on an array of integers.

- `Find(int* values, int numValues, int target)` - searches for a target value in the array.
- `GetLast(int* values, int numValues)` - gets the last value in the array.
- `Sort(int* values, int numValues)` - sorts the array from smallest to largest.

## Algorithm analysis

Each of the functions described above represents an algorithm. An algorithm is a series of steps to solve a problem. Each function has a particular problem it solves and provides the steps required to solve it.

By this point you should be able to read each function's C++ code and understand how each algorithm works. However, we now want to take a step back and analyze these functions through a different lens.

But what are we analyzing? For our purposes, we want to analyze the algorithms in terms of efficiency. How efficient are these algorithms?

### Efficiency

Functions can use different types of resources:

- CPU: how long does it take to execute the function? How many CPU operations are required to be executed?
- Memory: how much memory is required by the function? Does it required allocating a lot of extra memory?
- Disk: does the function require storing a large amount of data on a hard disk or external storage media?
- Network: does the function require data to be transmitted over a network connection and, if so, how much?

We can measure a functions efficiency independently for each resource, but we are going to focus on the CPU (the number of steps required to execute the algorithm).

### Performance vs complexity

Performance

- Exact measurement of how long the function takes to run (profiling).
- Varies depending on language, compiler, hardware, system state, etc.

Complexity

- How does input size affect performance?
- How well does the function scale?
- As input size increases, what happens to the number of steps required?

There are benefits to profiling and measuring performance. But we are going to focus on complexity.

### Problem size

The _problem size_ of an algorithm is the input size we are using in our analysis. For each of the functions in our [example program](../../examples/3-big-o/main.cpp), the input size will be the number of integers in the array being passed in.

For example:

```
int Find(int* values, int numValues, int target);
```

In the `Find()` function, the `numValues` parameter captures input size.

When discussing algorithm analysis, you will see the problem size referred to as the variable $n$.

### Complexity

_Complexity_: how does changing the problem size affect the number of steps required?

_Operation_: a basic or primitive step as part of the algorithm. Examples:

- A single arithmetic operation.
- A single assignment.
- A single boolean comparison.

We are not interested in the exact number of CPU instructions there actually are. This varies by language, compiler, etc. An algorithm can be implemented in other languages (an even different combinations of statements within the same language). Instead, use basic operations to get a feel for the number of steps required by an algorithm.

### Best case vs worst case

What is the best case scenario for the `Find()` function?

What is the worst case scenario for the `Find()` function?

### Example: `Find()`

Scope of analysis:

- Time: number of steps (basic operations) required.
- Complexity: how does input size affect the number of steps?
- Worst case scenario: what's the worst that could happen?
- Problem size: `numValues` (can rename to `n` for simplicity).

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

Questions:

- How many times is the loop executed?
- What is the total number of steps required in the worst case?
- How can we represent this as a mathematical formula $f(n)$?

Don't get confused between our C++ function `Find()` and our mathematical formula $f(n)$.

- `Find()` is the implementation of the algorithm. The actual steps required to find a number in the array.
- $f(n)$ is a formula that tells us how many steps are required by `Find()` based on the number $n$ items that are present in the input array.

What does $f(n)$ tell us about the `Find()` function? What is the relationship between the problem size and the number of steps required?

[Plot of f(n)](https://www.wolframalpha.com/input?i=plot+3n+%2B+3%2C+n+from+0+to+1000&assumption=%7B%22MC%22%2C+%220+to+1000%22%7D+-%3E+%7B%22VariableRange%22%7D)

## Big O

Big O ("big oh") notation helps us express the growth rate of an algorithm's complexity as the input reaches infinity. It acts as an asymptotic upper bound.

Big O provides a convenient way to communicate our complexity analysis: how does the number of steps grow relative to the input size?

Compare:

- $f(n)=3n+3$
- $g(n)=n$

The constants don't play an overwhelming role in the big picture. We don't care about exact number of operations.

### Determining Big O

Basic rules:

- Find highest order term of $f(n)$ and drop the rest.
- Drop constants.

Example for finding Big O for the `Find()` function:

- $f(n) = O(3n + 3)$
- $f(n) = O(3n)$
- $f(n) = O(n)$

The means the algorithm for `Find()`:

- "is Big Oh of n"
- "is order n"
- "takes linear time"
- "has linear time complexity"

As the size of the array passed into `Find()` gets bigger, the number of steps required by the algorithm grows linearly.

(_We slightly abuse Big O notation here; a formal definition will come later._)

### Reducing Big O

See textbook for examples.

### Example: `GetLast()`

Scope of analysis:

- Time: number of steps (basic operations) required.
- Complexity: how does input size affect the number of steps?
- Worst case scenario: what's the worst that could happen?
- Problem size: `numValues` (can rename to `n` for simplicity).

```cpp
                                  // Cost                      Times
return values[numValues - 1];     // 2 (subtraction, return)   1
```

Questions:

- What is the total number of steps for the worst case?
- What can you say about the complexity of this algorithm? What is the growth rate?
- What is the Big O notation for this algorithm?

### Example: `Sort()`

Scope of analysis:

- Same as previous example.

```cpp
                                                // cost      times
for (int i = 0;                                 // 1         1
         i < n - 1;                             // 2         n
         i++)                                   // 1         n - 1
{
    for (int j = 0;                             // 1         n - 1
         j < n - 1 - i;                         // 3         (n - i) * (n - 1)
         j++)                                   // 1         n - 1
    {
        int left = values[j];                   // 1         (n - 1 - i) * (n - 1)
        int right = values[j + 1];              // 2         ""

        if (left > right) {                     // 1         ""
            values[j] = right;                  // 1         ""
            values[j + 1] = left;               // 2         ""
        }
    }
}
```

Questions:

- How many times does the outer loop execute?
- How many times does the inner loop execute?
- How many times does the inner loop condition check (`j < n - 1 - i`) execute?
- What is the Big O notation for this algorithm?

### Big O categories

Common growth rates:

| $g(n)$        | Definition   |
| ------------- | ------------ |
| $1$           | Constant     |
| $log$ $n$     | Logarithmic  |
| $n$           | Linear       |
| $n$ $log$ $n$ | Linearithmic |
| $n^2$         | Quadratic    |
| $2^n$         | Exponential  |
| $N!$          | Factorial    |

Look at textbook for comparison graph.
