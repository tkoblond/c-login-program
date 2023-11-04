#include <iostream>
#include <fstream>
#include <string>

using namespace std;
bool IsLoggedIn()
{
    string username, password, un, pw;

    cout <<"Vnesi uporabnisko ime: "; cin >> username;
    cout <<"Vnesi geslo: "; cin >> password;

    ifstream read("C:\\Users\\dejan\\Documents\\C++ Projects\\projects\\Login_C++\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int izbira;

    cout << "1: Registracija\n2: Prijava\nProsim izberi moznost: "; cin >> izbira;
    if( izbira == 1)
    {
        string username, password;

        cout <<"Vnesi uporabnisko ime: "; cin >> username;
        cout <<"Vnesi geslo: "; cin >> password;

        ofstream file;
        file.open("C:\\Users\\dejan\\Documents\\C++ Projects\\projects\\Login_C++\\" + username + ".txt");
        file << username << endl << password;
        file.close();

        main();
    }
    else if (izbira == 2)
    {
        bool status = IsLoggedIn();

        if(!status)
        {
            cout << "Napacno uporabnisko ime ali geslo! Prosim poskusite ponovno." << endl;
            system("PAUSE");
            return 0;
        }
        else
        {
            cout << "Uspesno ste vpisani!" << endl;
            system("PAUSE");
            return 1;
        }

    }
}