#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class createFile
{
public:

    void createFileWithPassword()
    {
        ofstream file("haslo.txt");
        if (file.is_open())
        {
            file << "dishonored\n"; // Tytu³ gry
            file << "gladiator\n";  // Tytu³ filmu
            file << "chemia\n";     // Przedmiot szkolny
            file << "flet\n";       // Instrument
            file.close();
        }
        else
        {
            cout << "Nie mozna utworzyc pliku" << endl;
        }
    }


    string getPasswordForCategory(int category) 
    {
        ifstream file("haslo.txt");

        if (!file.is_open()) 
        {
            cout << "Nie mozna odczytac pliku" << endl;
            return "";
        }

        int currentLine = 1;
        while (getline(file, password)) 
        {
            if (currentLine == category) 
            {
                file.close();
                return password;
            }
            currentLine++;
        }

        file.close();
        return "";
    }

private:
    string password;

};

class HangmanGame 
{
public:

    HangmanGame(const string& password)
    {
        secretWord = password;
        currentWord = string(secretWord.length(), '_');
        attemptsLeft = MAX_ATTEMPTS;
    }

    void play()
    {
        cout << "Masz " << attemptsLeft << " prob podania poprawnych liter" << endl;

        while (attemptsLeft > 0) 
        {
            displayGameInfo();
            char guess;
            cout << "Podaj litere: ";
            cin >> guess;

            if (isalpha(guess)) 
            {
                guess = tolower(guess);
                bool correctGuess = updateCurrentWord(guess);

                if (correctGuess) 
                {
                    cout << "Dobra litera" << endl << endl;
                    if (currentWord == secretWord) 
                    {
                        cout << "Udalo sie, zgadles slowo: " << secretWord << endl;
                        cout << "Zrobiles to z iloscia bledow rowna: " << MAX_ATTEMPTS - attemptsLeft << endl;
                        return;
                    }
                }
                else 
                {
                    cout << "Zla litera" << endl << endl;
                    attemptsLeft--;
                }
            }
            else 
            {
                cout << "Prosze podaj poprawna wartosc" << endl;
            }
        }

        if (attemptsLeft == 0) 
        {
            displayGameInfo();
            cout << "Nie udalo sie, poprawne slowo to: " << secretWord << endl;
        }
    }


private:
    string secretWord;
    string currentWord;
    int attemptsLeft;
    int MAX_ATTEMPTS = 6;
    vector<char> guessedLetters;

    bool updateCurrentWord(char letter)
    {
        bool correctGuess = false;
        for (int i = 0; i < secretWord.length(); i++) 
        {
            if (secretWord[i] == letter) 
            {
                currentWord[i] = letter;
                correctGuess = true;
            }
        }
        guessedLetters.push_back(letter);
        return correctGuess;
    }

    void displayGameInfo()
    {
        cout << "Slowo: " << currentWord << endl;
        cout << "Pozostale proby: " << attemptsLeft << endl;
        cout << "Podane litery: ";

        for (char letter : guessedLetters) 
        {
            cout << letter << " ";
        }
        cout << endl << endl;
    }

};

int main()
{
	createFile plik;
    plik.createFileWithPassword();

    cout << "Wybierz kategorie:" << endl;
    cout << "1 - Tytul gry" << endl;
    cout << "2 - Tytul filmu" << endl;
    cout << "3 - Przedmiot szkolny" << endl;
    cout << "4 - Instrument" << endl;

    int category;
    cin >> category;

    if (category < 1 || category > 4) 
    {
        cout << "Niepoprawna kategoria" << endl;
        return 1;
    }

    string password = plik.getPasswordForCategory(category);
    if (password.empty()) 
    {
        cout << "Nie udalo sie wczytac hasla" << endl;
        return 1;
    }

    HangmanGame game(password);
    game.play();

	return 0;
}