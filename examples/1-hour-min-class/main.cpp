#include <iostream>

using namespace std;

/* --------------------------------------------------------
Class definition
-------------------------------------------------------- */

/**
Stores some number of hours and minutes.
*/
class HourMin {
  public:
    /** Constructor- initializes an empty object. */
    HourMin();

    /** Constructor - initializes an object using the specified hours and minutes. */
    HourMin(int hours, int minutes);

    /** Increments the hour value stored. */
    void IncrementHour();

    /** Prints the state of the class using `cout`. */
    void Print() const;

  private:
    int m_hours;
    int m_minutes;
};

/* --------------------------------------------------------
Class member function definitions
-------------------------------------------------------- */

HourMin::HourMin()
{
    m_hours = 0;
    m_minutes = 0;
}

HourMin::HourMin(int hours, int minutes)
{
    m_hours = hours;
    m_minutes = minutes;
}

void HourMin::IncrementHour()
{
    m_hours++;
}

void HourMin::Print() const
{
    cout << m_hours << ":" << m_minutes << endl;
}

/* --------------------------------------------------------
Program
-------------------------------------------------------- */

/**
Main entry point for the program.
*/
int main()
{
    HourMin time1(10, 15);
    time1.Print();
    return 0;
}
