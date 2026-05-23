#include "class.h"

// =======================
// Player functions
// =======================
Player::Player() {
    name = "Unknown";
    money = 200;
    guessNumber = 0;
}

Player::Player(std::string n) {
    name = n;
    money = 200;
    guessNumber = 0;
}

void Player::setGuessNumber(int number) {
    guessNumber = number;
}

int Player::getGuessNumber() const {
    return guessNumber;
}

std::string Player::getName() const {
    return name;
}

int Player::getMoney() const {
    return money;
}

void Player::setMoney(int amount) {
    money = amount;
    if (money < 0) money = 0;
}

// =======================
// Bet functions
// =======================
Bet::Bet() {
    guessNumber = 0;
}

void Bet::setGuessNumber(int number) {
    guessNumber = number;
}

bool Bet::checkWin(int spinNumber) {
    return false;
}

// =======================
// NumberBet functions
// =======================
bool NumberBet::checkWin(int spinNumber) {
    return guessNumber == spinNumber;
}

// =======================
// ColorBet functions
// =======================
std::string ColorBet::getColor(int number) {
    if (number % 2 == 0) {
        return "Black";
    }
    else {
        return "Red";
    }
}

bool ColorBet::checkWin(int spinNumber) {
    return getColor(guessNumber) == getColor(spinNumber);
}

// =======================
// TerminalUI functions
// =======================
void TerminalUI::showTitle() {
    std::cout << "=====================================\n";
    std::cout << "            ROULETTE GAME      \n";
    std::cout << "=====================================\n";
    std::cout << "Rule:\n";
    std::cout << "- Guess number from 0 to 38\n";
    std::cout << "- Even number = Black\n";
    std::cout << "- Odd number  = Red\n";
    std::cout << "- Starts with $200\n";
    std::cout << "- Correct number = +$75\n";
    std::cout << "- Correct color  = +$20\n";
    std::cout << "- Wrong guess  = -$30\n";
    std::cout << "=====================================\n\n";
}

void TerminalUI::showPlayers(const std::vector<Player>& players) {
    std::cout << "\n========== PLAYERS ==========\n";

    for (int i = 0; i < players.size(); i++) {
        std::cout << "Player " << i + 1 << ": "
                  << players[i].getName()
                  << " | Money: $" << players[i].getMoney()
                  << "\n";
    }

    std::cout << "=============================\n\n";
}

int TerminalUI::askPlayerCount() {
    int count;

    do {
        std::cout << "Enter number of players 1-4: ";
        std::cin >> count;

        if (count < 1 || count > 4) {
            std::cout << "Invalid number. Please enter 1 to 4.\n";
        }

    } while (count < 1 || count > 4);

    return count;
}

std::string TerminalUI::askPlayerName(int index) {
    std::string name;

    std::cout << "Enter name for Player " << index + 1 << ": ";
    std::cin >> name;

    return name;
}

int TerminalUI::askGuessNumber(const Player& player) {
    int guess;

    do {
        std::cout << player.getName() << ", guess number 0-38: ";
        std::cin >> guess;

        if (guess < 0 || guess > 38) {
            std::cout << "Invalid guess. Please enter 0 to 38.\n";
        }

    } while (guess < 0 || guess > 38);

    return guess;
}

void TerminalUI::showSpin(int spinNumber) {
    ColorBet colorChecker;

    std::cout << "\n";
    std::cout << "=====================================\n";
    std::cout << "             SPINNING...              \n";
    std::cout << "=====================================\n";
    std::cout << "          .----------------.          \n";
    std::cout << "         /                  \\         \n";
    std::cout << "        |        " << spinNumber;

    if (spinNumber < 10) {
        std::cout << "          |\n";
    }
    else {
        std::cout << "         |\n";
    }

    std::cout << "         \\                  /         \n";
    std::cout << "          '----------------'          \n";
    std::cout << "Spin result: " << spinNumber
              << " (" << colorChecker.getColor(spinNumber) << ")\n";
    std::cout << "=====================================\n\n";
}

void TerminalUI::showResult(int index, const Player& player, std::string resultText, int moneyGain) {
    std::cout << "Player " << index + 1
              << " name: " << player.getName()
              << " balance changed $" << moneyGain
              << " (" << resultText << ")"
              << " | Total money: $" << player.getMoney()
              << "\n";
}

bool TerminalUI::checkPlayerBalances(std::vector<Player>& players) {
    for (int i = (int)players.size() - 1; i >= 0; i--) {
        if (players[i].getMoney() <= 0) {
            std::cout << "Player " << players[i].getName() << " lose the game!\n";
            players.erase(players.begin() + i);
        }
    }
    if (players.empty()) {
        std::cout << "\n=====================================\n";
        std::cout << " GAME ENDED - No player have money left\n";
        std::cout << "=====================================\n";
        return false;
    }
    return true;
}