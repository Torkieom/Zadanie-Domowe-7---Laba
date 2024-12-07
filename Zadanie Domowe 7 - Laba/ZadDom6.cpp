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
        while (std::getline(file, password)) 
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

    cout << password;


	return 0;
}