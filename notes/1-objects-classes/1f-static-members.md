# Static Members

Textbook sections:

- 1.14 The 'this' implicit parameter (Optional)
- 1.15 Namespaces (Optional)
- 1.16 Static data members and functions
- 1.17 Vector ADT (Optional, though recommended if you are unfamiliar with the vector class)
- 1.18 Choosing classes to create

Consider this class:

```
class Color {
  public:
    Color(int r, int g, int b);
    void Print() const;

    static Color Red();         // Static member function (public)
    static int m_publicCounter; // Static member variable (public)
    const int PUBLIC_CONST = 1; // Const member variable (public)

  private:
    int red;
    int green;
    int blue;

    static Color SecretColor();  // Static member function (private)
    static int m_privateCounter; // Static member variable (private)
    const int PRIVATE_CONST = 2; // Const member variable (private)
};
```

_The full code for this example is found in the examples directory of this repository. Look over that code for full context and usage examples._

## Questions

- Which data members are contained within every _object_ of the `Color` class? In other words, each instance of the `Color` class has its own copy of which member variables?

- Which data members can be accessed from within the `Red()` member function?

- Which data members can be accessed from within the `Print()` member function?

- Which data members can be accessed from outside the `Color` class (for example, in the `main()` function)?

## Summary

- Static member variables are not contained within each object that is created (only one copy of a static member variable exists).
- Static member functions cannot access regular member variables or functions.
- Constant data members _are_ contained within each object. They act like normal member variables except they can't be changed.
- Visibility rules (public vs private) apply like normal.
