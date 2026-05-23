#pragma once

#include <iostream>
#include <string>
#include <vector>

class Player {
private:
    std::string name;
    int money;
    int guessNumber;

public:
    Player();
    Player(std::string n);

    void setGuessNumber(int number);

    int getGuessNumber() const;
    std::string getName() const;
    int getMoney() const;

    void setMoney(int amount);
};

class Bet {
protected:
    int guessNumber;

public:
    Bet();

    void setGuessNumber(int number);

    virtual bool checkWin(int spinNumber);
};

class NumberBet : public Bet {
public:
    bool checkWin(int spinNumber) override;
};

class ColorBet : public Bet {
public:
    bool checkWin(int spinNumber) override;
    std::string getColor(int number);
};

class TerminalUI {
public:
    void showTitle();
    void showPlayers(const std::vector<Player>& players);

    int askPlayerCount();
    std::string askPlayerName(int index);
    int askGuessNumber(const Player& player);

    void showSpin(int spinNumber);
    void showResult(int index, const Player& player, std::string resultText, int moneyGain);
    bool checkPlayerBalances(std::vector<Player>& players);
};