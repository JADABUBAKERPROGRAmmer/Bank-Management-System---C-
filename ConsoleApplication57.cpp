// ConsoleApplication57.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include<iostream>
using namespace std;
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include <cctype>
#include <conio.h>

struct stclient
{
    string accountnumber;
    string pincode;
    string name;
    string phone;
    string accountbalance;
};

void clearscreen()
{
    system("cls");
}

void pauseandscreen()
{
    cout << endl;
    cout << "Press any key to go back to main menu...";
    _getch();
    clearscreen();
}

void readdata(stclient& client)
{
    cout << "Enter account number: ";
    cin >> client.accountnumber;

    cout << "Enter pin code: ";
    cin >> client.pincode;

    cout << "Enter name: ";
    getline(cin >> ws, client.name);

    cout << "Enter phone: ";
    cin >> client.phone;

    cout << "Enter account balance: ";
    cin >> client.accountbalance;
}

string convertrecordtoline(stclient client, string delim = "#//#")
{
    string line = "";

    line += client.accountnumber + delim;
    line += client.pincode + delim;
    line += client.name + delim;
    line += client.phone + delim;
    line += client.accountbalance;

    return line;
}

void splitfunction(string s, stclient& client)
{
    string delim = "#//#";

    client.accountnumber = s.substr(0, s.find(delim));
    s.erase(0, s.find(delim) + delim.length());

    client.pincode = s.substr(0, s.find(delim));
    s.erase(0, s.find(delim) + delim.length());

    client.name = s.substr(0, s.find(delim));
    s.erase(0, s.find(delim) + delim.length());

    client.phone = s.substr(0, s.find(delim));
    s.erase(0, s.find(delim) + delim.length());

    client.accountbalance = s;
}

void mainmenuscreen()
{
    cout << "==================================================================================================" << endl;
    cout << setw(55) << "main menu screen" << endl;
    cout << "==================================================================================================" << endl;

    cout << setw(40) << "[1]" << " show client list" << endl;
    cout << setw(40) << "[2]" << " add new client" << endl;
    cout << setw(40) << "[3]" << " delete client" << endl;
    cout << setw(40) << "[4]" << " update client" << endl;
    cout << setw(40) << "[5]" << " find client" << endl;
    cout << setw(40) << "[6]" << " transaction" << endl;
    cout << setw(40) << "[7]" << " exit" << endl;

    cout << "==================================================================================================" << endl;
    cout << "choose what do you want to do: ";
}

void addnewclients()
{
    clearscreen();

    cout << "==============================================" << endl;
    cout << "             ADD NEW CLIENTS                  " << endl;
    cout << "==============================================" << endl;

    stclient clients;
    fstream fileclientslist;
    char x = ' ';

    fileclientslist.open("fileclientslist.txt", ios::out | ios::app);

    if (fileclientslist.is_open())
    {
        do
        {
            readdata(clients);

            fileclientslist << convertrecordtoline(clients) << endl;

            cout << "do you want to add more clients y/n \n";
            cin >> x;

        } while (toupper(x) == 'Y');

        fileclientslist.close();
    }

    pauseandscreen();
}

void showclientslist()
{
    clearscreen();

    cout << "==============================================" << endl;
    cout << "              CLIENT LIST                    " << endl;
    cout << "==============================================" << endl;

    string line;
    fstream file4;
    stclient client;

    file4.open("fileclientslist.txt", ios::in);

    if (file4.is_open())
    {
        cout << "--------------------------------------------------------------------------------------------------------" << endl;

        cout << setw(15) << "Account Number"
            << setw(15) << "Pin Code"
            << setw(25) << "Name"
            << setw(15) << "Phone"
            << setw(15) << "Balance" << endl;

        cout << "--------------------------------------------------------------------------------------------------------" << endl;

        while (getline(file4, line))
        {
            splitfunction(line, client);

            cout << setw(15) << client.accountnumber
                << setw(15) << client.pincode
                << setw(25) << client.name
                << setw(15) << client.phone
                << setw(15) << client.accountbalance
                << endl;
        }

        file4.close();
    }

    pauseandscreen();
}

void searchclient()
{
    clearscreen();

    cout << "==============================================" << endl;
    cout << "               FIND CLIENT                   " << endl;
    cout << "==============================================" << endl;

    string accountnumber;
    fstream file5;
    string line;
    stclient client;
    vector<stclient> vstring;

    file5.open("fileclientslist.txt", ios::in);

    if (file5.is_open())
    {
        while (getline(file5, line))
        {
            splitfunction(line, client);
            vstring.push_back(client);
        }

        file5.close();
    }

    cout << "please enter account number to search: ";
    cin >> accountnumber;

    for (stclient s : vstring)
    {
        if (accountnumber == s.accountnumber)
        {
            cout << endl;
            cout << "account number is :: " << s.accountnumber << endl;
            cout << "pin code is :: " << s.pincode << endl;
            cout << "the name is :: " << s.name << endl;
            cout << "the phone is :: " << s.phone << endl;
            cout << "account balance is :: " << s.accountbalance << endl;

            pauseandscreen();
            return;
        }
    }

    cout << "client not found" << endl;

    pauseandscreen();
}

vector<stclient> deleteclient()
{
    clearscreen();

    cout << "==============================================" << endl;
    cout << "              DELETE CLIENT                  " << endl;
    cout << "==============================================" << endl;

    fstream file6;
    string line;
    stclient client;
    string accountnumber;
    vector<stclient> vstring;
    char x = ' ';

    file6.open("fileclientslist.txt", ios::in);

    if (file6.is_open())
    {
        while (getline(file6, line))
        {
            splitfunction(line, client);
            vstring.push_back(client);
        }

        file6.close();
    }

    cout << "please enter account number to search and delete: ";
    cin >> accountnumber;

    for (int i = 0; i < vstring.size(); i++)
    {
        if (accountnumber == vstring[i].accountnumber)
        {
            cout << endl;
            cout << "account number is :: " << vstring[i].accountnumber << endl;
            cout << "pin code is :: " << vstring[i].pincode << endl;
            cout << "the name is :: " << vstring[i].name << endl;
            cout << "the phone is :: " << vstring[i].phone << endl;
            cout << "account balance is :: " << vstring[i].accountbalance << endl;

            cout << endl;
            cout << "do you want to delete client y/n: ";
            cin >> x;

            if (toupper(x) == 'Y')
            {
                vstring.erase(vstring.begin() + i);
                cout << "client deleted successfully." << endl;
            }

            break;
        }
    }

    return vstring;
}

void deleteclient2(vector<stclient> deleteclientv)
{
    fstream file7;

    file7.open("fileclientslist.txt", ios::out);

    if (file7.is_open())
    {
        for (stclient client : deleteclientv)
        {
            file7 << convertrecordtoline(client) << endl;
        }

        file7.close();
    }
}

void deleteclientpage()
{
    vector<stclient> deleteclientv;

    deleteclientv = deleteclient();

    deleteclient2(deleteclientv);

    pauseandscreen();
}

vector<stclient> updateclientinfo()
{
    clearscreen();

    cout << "==============================================" << endl;
    cout << "              UPDATE CLIENT                  " << endl;
    cout << "==============================================" << endl;

    fstream file8;
    string line;
    stclient client;
    string accountnumber;
    vector<stclient> updateclient;
    char x = ' ';

    file8.open("fileclientslist.txt", ios::in);

    if (file8.is_open())
    {
        while (getline(file8, line))
        {
            splitfunction(line, client);
            updateclient.push_back(client);
        }

        file8.close();

        cout << "please enter account number: ";
        cin >> accountnumber;

        for (int i = 0; i < updateclient.size(); i++)
        {
            if (accountnumber == updateclient[i].accountnumber)
            {
                cout << endl;

                cout << "account number is :: " << updateclient[i].accountnumber << endl;
                cout << "pin code is :: " << updateclient[i].pincode << endl;
                cout << "the name is :: " << updateclient[i].name << endl;
                cout << "the phone is :: " << updateclient[i].phone << endl;
                cout << "account balance is :: " << updateclient[i].accountbalance << endl;

                cout << endl;
                cout << "do you want to update information client y/n: ";
                cin >> x;

                if (toupper(x) == 'Y')
                {
                    cout << "enter new pincode: ";
                    cin >> updateclient[i].pincode;

                    cout << "enter new name: ";
                    getline(cin >> ws, updateclient[i].name);

                    cout << "enter new phone: ";
                    cin >> updateclient[i].phone;

                    cout << "enter new accounbalance: ";
                    cin >> updateclient[i].accountbalance;

                    cout << "client updated successfully." << endl;
                }

                break;
            }
        }
    }

    return updateclient;
}

void updateclient2(vector<stclient> updateclientv)
{
    fstream file8;

    file8.open("fileclientslist.txt", ios::out);

    if (file8.is_open())
    {
        for (stclient client : updateclientv)
        {
            file8 << convertrecordtoline(client) << endl;
        }

        file8.close();
    }
}

void updateclientpage()
{
    vector<stclient> updateclient;

    updateclient = updateclientinfo();

    updateclient2(updateclient);

    pauseandscreen();
}

vector<stclient> deposit()
{
    clearscreen();

    cout << "==============================================" << endl;
    cout << "                 DEPOSIT                     " << endl;
    cout << "==============================================" << endl;

    fstream file;
    string line;
    stclient client;
    string accountnumber;
    vector<stclient> vclient;

    file.open("fileclientslist.txt", ios::in);

    if (file.is_open())
    {
        while (getline(file, line))
        {
            splitfunction(line, client);
            vclient.push_back(client);
        }

        file.close();
    }

    cout << "please enter account number: ";
    cin >> accountnumber;

    for (int i = 0; i < vclient.size(); i++)
    {
        if (accountnumber == vclient[i].accountnumber)
        {
            cout << "account number is :: " << vclient[i].accountnumber << endl;
            cout << "current balance is :: " << vclient[i].accountbalance << endl;

            int amount;

            cout << "please enter deposit amount: ";
            cin >> amount;

            int balance = stoi(vclient[i].accountbalance);

            balance += amount;

            vclient[i].accountbalance = to_string(balance);

            cout << "new balance is :: " << vclient[i].accountbalance << endl;

            break;
        }
    }

    return vclient;
}

void deposit2(vector<stclient> vclient)
{
    fstream file;

    file.open("fileclientslist.txt", ios::out);

    if (file.is_open())
    {
        for (stclient client : vclient)
        {
            file << convertrecordtoline(client) << endl;
        }

        file.close();
    }
}

vector<stclient> withdraw()
{
    clearscreen();

    cout << "==============================================" << endl;
    cout << "                 WITHDRAW                    " << endl;
    cout << "==============================================" << endl;

    fstream file;
    string line;
    stclient client;
    string accountnumber;
    vector<stclient> vclient;

    file.open("fileclientslist.txt", ios::in);

    if (file.is_open())
    {
        while (getline(file, line))
        {
            splitfunction(line, client);
            vclient.push_back(client);
        }

        file.close();
    }

    cout << "please enter account number: ";
    cin >> accountnumber;

    for (int i = 0; i < vclient.size(); i++)
    {
        if (accountnumber == vclient[i].accountnumber)
        {
            cout << "account number is :: " << vclient[i].accountnumber << endl;
            cout << "current balance is :: " << vclient[i].accountbalance << endl;

            int amount;

            cout << "please enter withdraw amount: ";
            cin >> amount;

            int balance = stoi(vclient[i].accountbalance);

            if (amount <= balance)
            {
                balance -= amount;

                vclient[i].accountbalance = to_string(balance);

                cout << "new balance is :: " << vclient[i].accountbalance << endl;
            }
            else
            {
                cout << "insufficient balance." << endl;
            }

            break;
        }
    }

    return vclient;
}

void withdraw2(vector<stclient> vclient)
{
    fstream file;

    file.open("fileclientslist.txt", ios::out);

    if (file.is_open())
    {
        for (stclient client : vclient)
        {
            file << convertrecordtoline(client) << endl;
        }

        file.close();
    }
}

void transaction()
{
    int choice;

    do
    {
        clearscreen();

        cout << "==============================================" << endl;
        cout << "               TRANSACTION                   " << endl;
        cout << "==============================================" << endl;

        cout << "[1] Deposit" << endl;
        cout << "[2] Withdraw" << endl;
        cout << "[3] Back to main menu" << endl;

        cout << "==============================================" << endl;
        cout << "choose what do you want to do: ";

        cin >> choice;

        vector<stclient> vclient;

        switch (choice)
        {
        case 1:
            vclient = deposit();
            deposit2(vclient);
            pauseandscreen();
            break;

        case 2:
            vclient = withdraw();
            withdraw2(vclient);
            pauseandscreen();
            break;

        case 3:
            break;

        default:
            cout << "invalid choice" << endl;
            pauseandscreen();
        }

    } while (choice != 3);
}

void startprogram()
{
    int choice;

    do
    {
        clearscreen();

        mainmenuscreen();

        cin >> choice;

        switch (choice)
        {
        case 1:
            showclientslist();
            break;

        case 2:
            addnewclients();
            break;

        case 3:
            deleteclientpage();
            break;

        case 4:
            updateclientpage();
            break;

        case 5:
            searchclient();
            break;

        case 6:
            transaction();
            break;

        case 7:
            clearscreen();
            cout << "program terminated..." << endl;
            break;

        default:
            clearscreen();
            cout << "invalid choice" << endl;
            pauseandscreen();
        }

    } while (choice != 7);
}

int main()
{
    startprogram();

    return 0;
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
