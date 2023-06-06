# C++ Exercises

## Contents:

### 1. Luhn Digit Calculator
The program asks for a card number input. If none is given, the program uses the default number.</br> 
Then, the program determines the card type, calculates the final digit and displays the entire number.
### 2. Criss-Cross 
A classic Criss-Cross game.</br>
The program draws a 3x3 board then prompts the first player to enter a number of the row and the column where the player wishes to draw his sign.</br>
In case the field is taken, the player is prompted for a new input.</br>
The program then determines the winner or declares a draw and asks for a replay.
### 3. Chess
A classic Chess game. 
The player chooses a piece of his own color, enters the starting position and the position where the piece should be moved. If it is a valid move, the board is redrawn.</br>
**TO DO:** 
- Separate classes and structs from main.
- Allow for a new input in case the player chooses a figure with no available moves.
- Implement special moves (castling, pawn promotion, en passant)
- Beautify visuals and UI (SFML?) 
### 4. Fizz-Buzz
The program asks for the user's input (integer).</br> 
If the given number can be divided by 3, the program prints "Fizz".</br>
If the number can be divided by 5, the program prints "Buzz".</br>
If the number can be divided by both 3 and 5, the program prints "FizzBuzz".</br>
Then the user is asked whether he wants to play again.
### 5. Lotto
The program generates 6 random numbers between 1 and 45 and asks the player to enter any 6 numbers between 1 and 45.</br>
The program then compares the numbers and displays how many numbers the player guessed, as well as which numbers they were.
### 6. ASCII characters
The program prints all characters from the ASCII table (provided there is a displayable character).
### 7. Vending Machine - Coin Acceptor
The program asks for a price and money received. It calculates the difference and displays how many of which coins should be returned.</br>
The coins are returned as coins of €0.10, €0.20, €0.50, €1 and €2.
### 8. Vending Machine - Catalogue
The program initializes the vending machine (fills it with coins and generates 7 products with random prices).</br>
The user is prompted to pick a product and enter the number of the product he wishes to buy.</br>
Next, the user is prompted to enter the payment. If the user doesn't enter enough money, he is prompted to top up. </br>
The program then calculates the difference to return (if there is any), displays the difference and the quantites of each coin value to return.
**TO DO:**
- Work around the bug where the float of n.0 value is stored as (n-1).9 value, which causes an error in calculating the return.
### 9. Cards
The program generates a random Card with a value between 1 and 52 and displays the value of the card.
### 10. Poker
### 11. Traffic Light
### 12. Chat Filter
### 13. Autocapitalize
