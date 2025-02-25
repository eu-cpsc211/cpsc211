# C++ Templates

Textbook sections:

- 4.14 Function templates
- 4.15 Class templates

We'll use the following repository during lecture: https://github.com/eu-cpsc211/exercise-template

## Class templates

You may find yourself writing a class where the only thing that changes is the data type of certain variables.

Consider a class that stores a pair of integers:

```cpp
class PairOfInt {
  public:
    PairOfInt();
    PairOfInt(int first, int second);

    int GetFirst() const;
    int GetSecond() const;
    int GetLarger() const;
    int GetSmaller() const;

  private:
    int m_first;
    int m_second;
};
```

If we wanted a class that stores a pair of strings, we'd have to create a new class. The only different would be the data type of `m_first` and `m_second`.

A class template let's you do this without needing to manually creating copies of the class.

### Vectors

The built-in `vector` class is an example of a class template.

```cpp
vector<int> ints = { 1, 2, 3, 4 };
vector<string> strs = { "aaa", "bbb", "ccc" };
vector<char> chars = { 'a', 'b', 'c' };

for (auto a : ints)
    cout << a << endl;

for (auto a : strs)
    cout << a << endl;

for (auto a : chars)
    cout << a << endl;
```

You get to choose what data type the `vector` class uses for each object you create by specifying it inside the angle brackets (`<>`).

### Pair class

To define a class template:

```cpp
template <typename T>
class Pair {
  // ...
};
```

The `template <typename T>` tells the compiler this is a template. You define what template parameters you want within the angle brackets. You can have one or more template parameters.

Examples:

```cpp
template <typename T>
template <typename TItem>
template <typename CoolType>
template <typename MyTypeName>
```

Using `T` by itself or as a prefix is common, so that's what we'll use for this example.

You can now use `T` like any other data type within your class definition.

```cpp
template <typename T>
class Pair {
  // ...
 private:
    T m_first;
    T m_second;
};
```

When an object is created using the class template, the `T` will be replaced by whatever data type is chosen for that particular object.

Member function definitions also need updated when using a class template. Here's an example of the constructor for the `Pair` class:

```cpp
template <typename T>
Pair<T>::Pair(T first, T second)
{
    m_first = first;
    m_second = second;
}
```

Once the class is fully implemented, you can create `Pair` objects using different type parameters.

```cpp
Pair<int> p(12, 9);
Pair<char> p('a', 'b');
Pair<string> p("abc", "def");
```

## Study guide

Given a class template definition, know how to create a variable using that class. For example:

```cpp
Pair<int> p(12, 9);
```

Also know how to dynamically allocate an object using a class template. For example:

```cpp
Pair<int> p* = new Pair<int>(12, 9);
```
