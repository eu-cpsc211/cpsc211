#include <iostream>

using namespace std;

/* --------------------------------------------------------
Class definition
-------------------------------------------------------- */

class Color {
  public:
    Color(int r, int g, int b);
    void Print() const;

    static Color Red();         // Static member function (public)
    static int s_publicCounter; // Static member variable (public)
    const int PUBLIC_CONST = 1; // Const member variable (public)

  private:
    int m_red;
    int m_green;
    int m_blue;

    static Color SecretColor();  // Static member function (private)
    static int s_privateCounter; // Static member variable (private)
    const int PRIVATE_CONST = 2; // Const member variable (private)
};

/* --------------------------------------------------------
Class implementation
-------------------------------------------------------- */

// Static member variables have to be initialized outside the class definition
int Color::s_publicCounter = 0;
int Color::s_privateCounter = 0;

Color::Color(int r, int g, int b)
{
    m_red = r;
    m_green = g;
    m_blue = b;
}

void Color::Print() const
{
    cout << "R: " << m_red << " G: " << m_green << " B: " << m_blue << endl;
}

Color Color::Red()
{
    s_publicCounter++;
    s_privateCounter++;
    return Color(255, 0, 0);
}

/* --------------------------------------------------------
Program
-------------------------------------------------------- */

/**
Main entry point for the program.
*/
int main()
{
    // Static member functions
    // ----------------------
    Color r = Color::Red(); // Red() can be accessed without an object
    Color r2 = r.Red();     // Red() can still be accessed with an object (does the same thing)

    // Private static member functions
    // ----------------------
    // Color s = Color::SecretColor(); // Invalid - can only be accessed within the class

    // Regular member functions
    // ----------------------
    r.Print(); // Regular member functions must be accessed with an object
    // Color::Print(); // Invalid
    r2.Print();

    // Static member variables
    // ----------------------
    Color::s_publicCounter = 10; // Public static member variables can be accessed without an object
    r.s_publicCounter = 20;      // They can be accessed with an object, but there's only a single instance of the variable
    cout << Color::s_publicCounter << endl;
    cout << r.s_publicCounter << endl;

    // Private static member variables
    // ----------------------
    // Color::s_privateCounter = 10; // Invalid - can only be accessed within the class

    // Const member variables
    // ----------------------
    cout << r.PUBLIC_CONST << endl; // Valid
    // cout << Color::PUBLIC_CONST << endl; // Invalid - must be accessed with an object
    // cout << r.PRIVATE_CONST << endl; // Invalid - private, so only accessible within the class

    return 0;
}
