#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

const int MAX_PLAYERS = 10;

/* --------------------------------------------------------
Class definition
-------------------------------------------------------- */

class Player {
  public:
    string name;
    int number;
};

class Roster {
  public:
    Roster();

    /**
     * Adds a player to the roster.
     * @param name The player's name.
     * @param numer The player's jersey number.
     */
    void AddPlayer(string name, int number);

    /**
     * Checks if the roster is full.
     */
    bool IsFull() const;

    /**
     * Prints the roster to standard output.
     */
    void Print() const;

  private:
    Player m_players[MAX_PLAYERS]; /** Array of players on the roster. */
    int m_playersCount;            /** Number of players on the roster. */
};

/* --------------------------------------------------------
Roster implementation
-------------------------------------------------------- */

Roster::Roster()
{
    m_playersCount = 0;
}

void Roster::AddPlayer(string name, int number)
{
    if (m_playersCount == MAX_PLAYERS)
        throw length_error("Roster is full.");

    m_players[m_playersCount].name = name;
    m_players[m_playersCount].number = number;
    m_playersCount++;
}

bool Roster::IsFull() const
{
    return m_playersCount == MAX_PLAYERS;
}

void Roster::Print() const
{
    cout << "Roster" << endl;
    cout << "------" << endl;

    for (int i = 0; i < m_playersCount; ++i) {
        cout << m_players[i].number << ": " << m_players[i].name << endl;
    }
}

/* --------------------------------------------------------
Program
-------------------------------------------------------- */

/**
Main entry point for the program.
*/
int main()
{
    Roster roster;
    roster.AddPlayer("Bob", 1);
    roster.AddPlayer("George", 10);
    roster.AddPlayer("John", 30);

    roster.Print();

    return 0;
}
