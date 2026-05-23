#include "class.h"

#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));

    TerminalUI ui;
    std::vector<Player> players;

    ui.showTitle();

    int playerCount = ui.askPlayerCount();

    for (int i = 0; i < playerCount; i++) {
        std::string name = ui.askPlayerName(i);
        players.push_back(Player(name));
    }

    bool playing = true;

    while (playing) {
        ui.showPlayers(players);

        for (int i = 0; i < players.size(); i++) {
            int guess = ui.askGuessNumber(players[i]);
            players[i].setGuessNumber(guess);
        }

        int spinNumber = std::rand() % 39;

        ui.showSpin(spinNumber);

        for (int i = 0; i < players.size(); i++) {
            NumberBet numberBet;
            ColorBet colorBet;

            int guess = players[i].getGuessNumber();

            numberBet.setGuessNumber(guess);
            colorBet.setGuessNumber(guess);

            if (numberBet.checkWin(spinNumber)) {
                players[i].setMoney(players[i].getMoney() + 75);
                ui.showResult(i, players[i], "correct number", 75);
            }
            else if (colorBet.checkWin(spinNumber)) {
                players[i].setMoney(players[i].getMoney() + 20);
                ui.showResult(i, players[i], "correct color", 20);
            }
            else {
                players[i].setMoney(players[i].getMoney() - 30);
                ui.showResult(i, players[i], "wrong", -30);
            }
        }

        if (!ui.checkPlayerBalances(players)) {
            playing = false;
            break;
        }

        ui.showPlayers(players);

        playing = ui.askPlayAgain();

        std::cout << "\n";
    }

    if (!players.empty()) {
        std::cout << "=====================================\n";
        std::cout << "              GAME ENDED              \n";
        std::cout << "=====================================\n";

        ui.showPlayers(players);
    }

    return 0;
}