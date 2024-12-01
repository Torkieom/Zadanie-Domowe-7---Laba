#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class createFile
{
public:

    void createFileWithPassword(const string & password)
    {
        ofstream file("haslo.txt");
        if (file.is_open())
        {
            file << password;
            file.close();
        }
        else
        {
            cout << "Nie mozna utworzyc pliku" << endl;
        }
    }

    string readPasswordFromFile()
    {
        ifstream file("haslo.txt");
        if (file.is_open())
        {
            getline(file, password);
            file.close();
        }
        else
        {
            cout << "Nie mozna odczytac pliku" << endl;
        }
        return password;
    }

private:
    string password;

};


int main()
{
	createFile plik;
	string hasloPlik = "przyklad";
    plik.createFileWithPassword(hasloPlik);
    string hasloGra = plik.readPasswordFromFile();

    cout << hasloGra;

	return 0;
}