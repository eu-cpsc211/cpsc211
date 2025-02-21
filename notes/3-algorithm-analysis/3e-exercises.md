# Exercises

Use these exercises as a study guide for the quiz and exams.

## 1. Finding worst-case Big O

For each of the following blocks of code, identify the Big O notation for the time complexity of the code for the worst case. The problem size is defined by the variable `n`.

Exercise 1.1:

```cpp
val = 0;
for (int i = 3; i < n; i++) {
    val += i;
}
```

Exercise 1.2:

```cpp
val = 0;
for (int i = 0; i < 20; i++) {
    val += n;
}
```

Exercise 1.3:

```cpp
void DoSomething(const char* message, int n, char charToFind) {
    int i = 0;
    while (i < n) {
        if (message[i] == charToFind)
            return i;
    }

    return -1;
}
```

Exercise 1.4:

```cpp
void DoSomething(int* values, int n) {
    cout << "There are " << n << " values." << endl;
    int count = 5;
    for (int i = 0; i < count; i++) {
        cout << i << endl;
    }
}
```

Exercise 1.5:

```cpp
int x = 0;
int count = 0;

while (x < n) {
    for (int y = 0; y < n; y++) {
        count++;
    }

    cout << count << endl;
    x++;
}
```

Exercise 1.6:

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        for (int k = n; k > 0; k--) {
            int val = values[i][j][k];
            if (val == target) {
                return val;
            }
        }
    }
}
```

Exercise 1.7:

```cpp
position = input[n] + input[2 * n];
```

Exercise 1.8:

```cpp
int i = 0;
while (i < n) {
    i++;
}

while (i > 0) {
    i--;
}
```

Exercise 1.9:

```cpp
for (int i = n; i > 0; i = i / 2) {
    cout << i << endl;
}
```

Exercise 1.10:

```cpp
for (int i = 0; i < n; i++) {

    int k = 0;
    while (k > 1) {
        k = k / 2;
    }
}
```

Exercise 1.11:

```cpp
for (int i = 0; i < n / 2; i++) {
    cout << i << endl;
}
```

## 2. Finding Big O from $f(n)$

For the following exercises, suppose an algorithm requires $f(n)$ steps to be executed in the worst case, where $n$ represents the problem size. Determine the appropriate Big O notation for the algorithm.

Exercise 2.1:

$f(n) = 8n + log_2n + 4n^2 + 9071$

Exercise 2.2:

$f(n) = 52 + 2n^3$

Exercise 2.3:

$f(n) = n(n^2) + n + 343n$

Exercise 2.4:

$f(n) = n + n + n + n$

Exercise 2.5:

$f(n) = n^2 + n^3 + (n \cdot n \cdot n \cdot n)$

Exercise 2.6:

$f(n) = 2n + log_2 n$

Exercise 2.7:

$f(n) = 2n + log_2 n + n(log_2n)$

Exercise 2.8:

$f(n) = n^2 + 3 + n + n^2 + 1089 + log_2 n$

Exercise 2.9:

$f(n) = 9823 + 1241$

## 3. Common growth rates

List common growth rates in order from slowest to largest. Start with constant time and go up through exponential time.

## 4. Finding best-case Big O

Similar to previous exercises, but this time find the Big O notation for the **best** case scenario for each of the code snippets.

Exercise 4.1:

```cpp
void DoSomething(const char* message, int n, char charToFind) {
    int i = 0;
    while (i < n) {
        if (message[i] == charToFind)
            return i;
    }

    return -1;
}
```

Exercise 4.2:

```cpp
int total = 0;

for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
        total += k;
    }

    if (total == values[i]) {
        break;
    }
}
```

Exercise 4.3:

```cpp
position = input[n + 2] * input[n + 4];
```

Exercise 4.4:

```cpp
int i = 0;
while ( ( i < n ) && ( target != numbers[i] ) ) {
    cout << i << endl;
    i++;
}
```
