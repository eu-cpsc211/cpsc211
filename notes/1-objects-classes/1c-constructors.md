# Constructors (cont.)

Textbook sections:

- 1.7 Classes and vectors/classes
- 1.8 Constructor overloading
- 1.9 Constructor initializer lists

## Parameterized constructors

Example of an additional constructor for the `Rectangle` class:

```cpp
class Rectangle
{
public:
    Rectangle();
    Rectangle(double initialWidth, double initialHeight);
    // ...
};
```

- General constructor: no parameters
- Parameterized constructor: has one or more parameters

Example of creating objects using each constructor:

```cpp
Rectangle rec1; // Uses default constructor
Rectangle rec2(10, 20); // Uses parameterized constructor
```

### Multiple constructors

Constructor overloads act like function overloads.

```cpp
class Foo
{
public:
    Foo(); // Valid
    Foo(int a); // Valid
    Foo(int b); // INVALID - identical to the previous overload even though variable name is different
    Foo(int a = 2); // INVALID - identical to previous overload even though there is a default value
    Foo(int a, int b); // Valid
    Foo(double a); // Valid
};
```

### Exercise: Add a constructor

Add another constructor to the `Rectangle` class. This constructor should have one parameter (a `double` named `sideLength`) and should initialize the rectangle to be a square.

Once implemented, test your constructor:

```cpp
Rectangle rec1(10);

cout << "Rectangle 1: " << endl;
cout << "Area: " << rec1.GetArea() << endl;
cout << "Perimeter: " << rec1.GetPerimeter() << endl;
```

### Omitting the default constructor

The compiler generates a default constructor if the class has no constructors declared. If any constructors are declared, the compiler will not generate a default constructor.

Should you always define a default constructor? Why or why not?

## Exercise: Create a class

Create a class named `PlayerStats`. The class tracks how many points a basketball player has in a game. The class should have the following public members:

- A constructor with `playerNumber` (integer) and `playerName` (string) parameters.
- `AddMade2ptFieldGoal()` - a member function that adds two points to the player's total score.
- `AddMade3ptFieldGoal()` - a member function that adds three points to the player's total score.
- `AddMadeFreeThrow()` - a member function that adds one point to the player's total score.
- `GetTotalPoints()` - a member function that returns how many points the player has scored. This should be a `const` function.
- `Print()` - a member function that prints out the player's name, number, and total points scored using `cout`. You can format the output however you wish. This should be a `const` function.

You can add whatever private members you need to implement the class.

Here is an example of using the `PlayerStats` class after it has been implemented:

```
PlayerStats jordan(23, "Michael Jordan");
jordan.AddMade2ptFieldGoal();
jordan.AddMade3ptFieldGoal();
jordan.AddMadeFreeThrow();
jordan.AddMadeFreeThrow();
jordan.AddMadeFreeThrow();
jordan.Print();
```

Example output:

```
Player 23 Michael Jordan has scored 8 points.
```

## Additional exercises

### Questions: general questions

- What is the difference between a default constructor and a parameterized constructor?
- How many constructors can a class have?
- When does the compiler automatically generate a default constructor?
- How/when are constructors called?

### Question: multiple constructors

Use the following code to answer the questions.

```
class Thing
{
public:
    Thing();
    Thing(int a);
    Thing(double b);
    void SetValue(double v);
private:
    double value;
};

Thing::Thing()
{
    value = 0;
}

Thing::Thing(int a)
{
    value = a;
}

Thing::Thing(double b)
{
    value = b;
}

void Thing::SetValue(double v)
{
    value = v;
}
```

- How many constructors are present in the `Thing` class?
- How would you declare a `Thing` variable named `myThing` that initializes `value` to be `105.1`?
- What does the default constructor do to `value`?
- Suppose a `Thing` object is created as follows: `Thing myThing(10);`. Can the `SetValue` member function be used to change the value of `myThing` to `25`? How?
