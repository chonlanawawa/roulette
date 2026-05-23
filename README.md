# C++ Roulette Game

A terminal-based roulette game for 1–4 players built in C++.\
by กลุ่ม 17 เฮียยุทธสั่งลุย: 6815, 6822, 6831, 6844

> [Demo Video](https://www.google.com)

## Game Rules

- Each player guess a number from **0 to 38**
- Even number = **Black**, Odd number = **Red**
- Correct number guess = **+$75**
- Correct color guess = **+$20**
- Wrong guess = **-$30**
- Each player starts with **$200**
- A player is eliminated when their balance reaches **$0**
- Game ends when all players are eliminated or everyone chooses to stop

## How to Play

### 1. Start the game

Run the executable. The title screen and rules appear automatically.

```
=====================================
        SIMPLE C++ ROULETTE GAME
=====================================
Rule:
- Guess number from 0 to 38
...
=====================================
```

### 2. Enter number of players

```
Enter number of players 1-4: 2
```

Type a number between `1` and `4`, then press **Enter**.

### 3. Enter player names

You will be prompted once per player.

```
Enter name for Player 1: A
Enter name for Player 2: B
```

### 4. Each round — guess a number

At the start of every round the current balances are shown, then each player is asked for a guess.

```
========== PLAYERS ==========
Player 1: A | Money: $200
Player 2: B | Money: $200
=============================

A, guess number 0-38: 7
B, guess number 0-38: 22
```

Type any number from `0` to `38` and press **Enter**.

### 5. Spin result

The wheel spins and the result is displayed.

```
=====================================
             SPINNING...
=====================================
          .----------------.
         /                  \
        |        14          |
         \                  /
          '----------------'
Spin result: 14 (Black)
=====================================
```

### 6. Round results

Each player's outcome is printed immediately after the spin.

```
Player 1 name: A balance changed $-30 (wrong) | Total money: $170
Player 2 name: B balance changed $20 (correct color) | Total money: $220
```

### 7. Play again prompt

After results, the remaining balances are shown and you are asked to continue.

```
========== PLAYERS ==========
Player 1: A | Money: $170
Player 2: B | Money: $220
=============================

Play again? 1 = Yes, 0 = No: 1
```

Type `1` to play another round or `0` to end the game.

### 8. Player elimination

If a player's balance hits `$0` they are removed automatically before the next round.

```
Player A lose the game!
```

If all players reach `$0` the game ends immediately without asking.

```
=====================================
   GAME ENDED - No player have money left
=====================================
```

### 9. Game over

When the game ends normally (someone typed `0`), the final balances are shown.

```
=====================================
              GAME ENDED
=====================================

========== PLAYERS ==========
Player 1: B | Money: $250
=============================
```

## Tech Stack

| Layer | Technology |
|-------|------------|
| Language | C++11 |
| Compiler | g++ (MinGW-w64 on Windows, GCC on Linux/macOS) |
| UI | Terminal / Console (stdout + stdin) |
| Build | Manual `g++` command (no build system) |

## Standard Libraries Used

| Library | Purpose |
|---------|---------|
| `<iostream>` | Console input and output (`std::cin`, `std::cout`) |
| `<string>` | Player name handling (`std::string`) |
| `<vector>` | Dynamic player list (`std::vector`) |
| `<cstdlib>` | Random number generation (`std::rand`, `std::srand`) |
| `<ctime>` | Random seed from system time (`std::time`) |

## Project Structure

```
roulette/
├── class.h       # Class declarations (Player, Bet, NumberBet, ColorBet, TerminalUI)
├── ui.cpp        # All class implementations
└── main.cpp      # Game loop entry point
```

## Requirements

- A C++ compiler with C++11 support or later
- **Windows**: MinGW-w64 via MSYS2 (recommended)
- **Linux/macOS**: g++ from your package manager

## Building

### Windows (MSYS2 / MinGW-w64)

If you have not added MinGW to your PATH yet, use the full path:

```
C:\msys64\ucrt64\bin\g++ main.cpp ui.cpp -o roulette
```

Or if `g++` is already on your PATH:

```
g++ main.cpp ui.cpp -o roulette
```

### Linux / macOS

```
g++ main.cpp ui.cpp -o roulette
```

### Adding MinGW to PATH (Windows, one-time setup)

1. Open **Start** and search for **Environment Variables**
2. Click **Edit the system environment variables**
3. Under **User variables**, select **Path** and click **Edit**
4. Click **New** and add: `C:\msys64\ucrt64\bin`
5. Click **OK** and restart your terminal

After this, you can compile with just `g++` from any folder.

## Running

```
.\roulette.exe
```

On Linux/macOS:

```
./roulette
```
