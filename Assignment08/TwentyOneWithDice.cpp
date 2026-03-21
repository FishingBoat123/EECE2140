#include <iostream>
#include <random>
using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dist(1, 6);

class Die
{
    private:
        static int maxDieValue;
        int currentValue;
        bool computerStop;

    public:
        Die() : currentValue(1), computerStop(false) {}

        void setValue(int currentValue) {this->currentValue = currentValue;}
        int const getValue() {return currentValue;}
        int const getMax() {return maxDieValue;}
        bool const getComputerStop() {return computerStop;}

        void rollDie()
        {
            currentValue = dist(gen);
        }

        void computerCheck19()
        {
            if (currentValue >= 19)
                computerStop = true;
        }
};

int Die::maxDieValue = 6;

int main()
{
    Die player;
    Die computer;

    int playerTotal = 0;
    int computerTotal = 0;
    char choice;

    while (playerTotal < 21)
    {
        cout << "Roll the die? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            player.rollDie();
            playerTotal += player.getValue();
            cout << "You rolled: " << player.getValue() << "  |  Your total: " << playerTotal << "\n";

            if (playerTotal > 21)
            {
                cout << "\n Your total exceeded 21. You Lose.\n";
                break;
            }
        }
        else
        {
            break;
        }
    }


    while (!computer.getComputerStop() && computerTotal <= 21)
    {
        computer.rollDie();
        computerTotal += computer.getValue();
        cout << "Computer rolled: " << computer.getValue() << "  |  Computer total: " << computerTotal << "\n";

        computer.computerCheck19(); 

        if (computerTotal > 21)
        {
            cout << "\nTotal exceeded 21. Computer Lost.\n";
            break;
        }
    }
    if (computerTotal <= 21 && computer.getComputerStop())
    {
        cout << "Computer stops at " << computerTotal << ".\n";
    }
    
    cout << "\n========== Results ==========\n";
    cout << "  Your total: " << playerTotal   << "\n";
    cout << "  Computer total: " << computerTotal << "\n";
    cout << "====================================\n";

    bool playerLost   = playerTotal   > 21;
    bool computerLost = computerTotal > 21;

    if(playerLost && computerLost)
    {
        cout << "Both busted — it's a draw!\n";
    }
    else if (playerLost)
    {
        cout << "You lost. Computer win\n";
    }
    else if (computerLost)
    {
        cout << "Computer lost. You win\n";
    }
    else if (playerTotal == computerTotal)
    {
        cout << "You win\n";
    }
    else if (playerTotal  > computerTotal)
    {
        cout << "You win\n";
    }
    else
    {
        cout << "Computer wins\n";
    }

    return 0;
}