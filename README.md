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
A basic Poker engine.</br>
The program initializes 8 players with 50 chips and deals each player 2 cards, then it deals 5 cards to the table and prints which player (and the table) holds which cards. Each card is unique and is dealt randomly from a classic Poker deck of 52 cards.
### 11. Traffic Light
The program simulates an intersection with 4 traffic lights. The lights switch colors in pairs.</br>
The program prints the current situation on each traffic light every second.
### 12. Chat Filter
The program simulates a chat filter which censors a given "forbidden" word.</br>
The function CensorText takes in a string containing original text, a string with a word to censor and a character which will replace every letter of the forbidden word. The program is tested on three cases: a case with nothing to censor, a case with the forbidden word appearing once, and a case with the forbidden word appearing twice - once normally and once in rAndOmCaSe. </br>
The forbidden word that is tested is "Voldemort".
### 13. Autocapitalize
The program finds the first letter in a sentence and capitalizes it. It can also turn all other letters to lowercase, unless the word is starting with an uppercase (e.g. a name).
### 14. Caesar Cipher
The program performs the Caesar Cipher on a given string with a given key. The user can choose whether he wants to encrypt or decrypt, is prompted for a text to encrypt/decrypt and a key (both left and right shift are supported). The program then returns the encryption/decryption result.
### 15. SFML: Display Image
An exercise in using the SFML external library. The program creates a window with the size 1920x1080 and displays an image in it.
### 16. Letter Pyramid
The program takes in a string input and creates a pyramid from it.</br>
Example output:</br>
</br>
![Letter Pyramid: example output](https://github.com/Dorole/CPP-Exercises/assets/35565194/5be4ca15-d5ad-449f-b35c-3aba6ef22d6c)

