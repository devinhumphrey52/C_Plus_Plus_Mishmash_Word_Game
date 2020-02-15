// Word Mishmash.cpp : This file contains the 'main' function. Program execution begins and ends there.
// The Ultimate Word MishMash Guessing Game

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

    //defines enumerators for accessing the 2d array
    enum fields {word = 0, hint, maxHints};

    //Declared the constant int maxWords and set it too hold a maximum of 10 items
    const int maxWords = 10;

    //Declared the 2 dimensional array 
    string mishMash[maxWords][maxHints] =
    {
        {"Belt", "Something you hold your pants up with."},
        {"Glasses", "You might need these to see."},
        {"Bingo", "A game you might play with the elderly."},
        {"Cold Water", "Something to cool you down on a warm sunny day." },
        {"Steed", "A knights best friend."},
        {"Revenge", "Better served cold."},
        {"Orage Juice", "Contains a bunch of Vitamin C."},
        {"Murder", "Redrum any one?"},
        {"Johnny Walker", "A popular brand of whiskey."},
        {"Cupid", "He's quite the little matchmaker."}

    };

    /*Test the 2d dimensional array by lopping
    for (int i = 0; i < maxWords; ++i)
    {
        for (int j = 0; j < maxHints; ++j)
        {
            cout << mishMash[i][j];
        }
    }
    */

    /*Tests Enum accessing 2d array
    cout << mishMash[0][word];
    cout << mishMash[0][hint];
    */
    
    //Seeds the random number generator based on current date and time
    srand(static_cast <unsigned int> (time(0)));

    //Generates a random number and assigns it to a int type variable not excedding the max index value
    int randomIndexNum = (rand() % maxWords);

    /*Test the generated random number and assignment of this value
    cout << randomIndexNum;
    */
    
    //Takes the random selected index and applies that to the 2d array storing the outcome to a variable
    string randomIndexWord = mishMash[randomIndexNum][word];
    string randomIndexHint = mishMash[randomIndexNum][hint];

    /*Tests variable assignments and Sorting
    int num = 0;
    while (num != 10)
    {
        int randomIndexNum = (rand() % maxWords);
        string randomIndexWord = mishMash[randomIndexNum][word];
        string randomIndexHint = mishMash[randomIndexNum][hint];
        cout << randomIndexWord << " " << randomIndexHint << "\n";
        ++num;
    }
    */
    
    //Assigns a random Mishmatched words length to a variable
    string mishMatchWord = randomIndexWord;
    int length = mishMatchWord.size();

    /*Tests the size of the variable
    cout << length;
    */

    //Allows the for loop to continue untill the length exceeds the int variable i
    for (int i = 0; i < length; ++i)
    {
        //Calls the rand function, performs modulus calcualtion of the random words length by a random number, and assigns it to a variable
        int index1 = (rand() % length);
        int index2 = (rand() % length);

        /*tests rand and modulus functions and the assignment of the result to int variables
        cout << index1 << "\n";
        cout << index2;
        */

        // Assigns the index1 int to char variable, reassigns random index2 int to array index1, and reassigns index1 to index2
        char temp = mishMatchWord[index1];
        mishMatchWord[index1] = mishMatchWord[index2];
        mishMatchWord[index2] = temp;
        
    }

    //Introduces the player to the game
    cout << "\t\t\tWelcome to The Ultimate Word MishMatch Game!\n";
    cout << "\t\t\t============================================\n";
    string charactersName;
    cout << "Please enter your desired character's name.\n";
    cout << "\n";
    getline(cin, charactersName);
    cout << "\n";
    cout << "Hello, " + charactersName + " the goal of this game is to guess the scrambled word.\n";
    cout << "If you need help with the word, just type hint.\n";
    cout << "If you want to quit, just type quit.\n";
    cout << "The first mishmatch is: " + mishMatchWord;
    string playersGuess;
    cout << "\nPlease take a guess.";
    cin >> playersGuess;

    
    //Game Loop
    while ((playersGuess != randomIndexWord) && (playersGuess != "quit"))
    {
        // If the player needs a hint give them one based on player input or else keep promting for a guess
        if (playersGuess == "hint")
        {
            cout << randomIndexHint;
        }
        else if (playersGuess == "HINT")
        {
            cout << randomIndexHint;
        }
        else if (playersGuess == "Hint")
        {
            cout << randomIndexHint;
        }
        else
        {
            cout << "Sorry, please guess again.";
        }
        cout << "\n\nPlease guess again: ";
        cin >> playersGuess;

    }

    //Game ending alternatives based on characters inputs 
    if (playersGuess == randomIndexWord)
    {
        cout << "\nImpressive, Hurry back " + charactersName + "!\n";
    }

    else
    {
        cout << "\nBetter luck next time " + charactersName + " give it another try when your not so tired!\n";
    }
    
    return 0;

    ("PAUSE");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
