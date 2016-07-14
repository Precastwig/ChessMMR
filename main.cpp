#include <iostream>
#include <string>
#include <unistd.h>
#include "Rating.h"
#include "Savedata.h"

using namespace std;

Savedata *s;

void addplayer() {
    cout << "Name \n#";
    string n;
    cin >> n;
    s->addplayer(s->createplayer(n));
    cout << "* Added *\n";
}

void addmatch() {
    int ID1, ID2, win;
    cout << "Player ID:\n#";
    cin >> ID1;
    cout << "Player ID:\n#";
    cin >> ID2;
    cout << "Who won, Player ID " << ID1 << " or player ID " << ID2 << "?\n#";
    cin >> win;
    if (win == ID1) {
        win = 1;
    } else if (win == ID2) {
        win = 2;
    }
    s->addmatch(ID1,ID2,win);
}

void removeplayer() {
    cout << "Player ID:\n";
    int ID;
    cin >> ID;
    if (ID >= 0) {
        s->deleteplayer(ID);
    }
}

void menu() {
    bool con = true;
    while (con) {
        system("CLS");
        cout << "**   Chess ELO Program   **\n";
        cout << "*                         *\n";
        cout << "* List of current players: \n";
        s->listplayers();
        cout << "* ### *\n\n";
        cout << "**          Menu         **\n";
        cout << "* 1. Add player\n";
        cout << "* 2. Add match\n";
        cout << "* 3. Remove player\n";
        cout << "* 4. Save and quit\n";
        cout << "* ### *\n#";
        int choice;
        cin >> choice;
        if(choice == 1) {
            addplayer();
        } else if (choice == 2) {
            addmatch();
        } else if (choice == 3) {
            removeplayer();
        } else if (choice == 4) {
            con = false;
        }
    }
}

int main()
{
    s = new Savedata(1500, "flatsave.elo");

    cout << "Loading from file...\n";
    s->loadfromfile();
    cout << "loaded.\n";

    Rating *r = new Rating();
    Expected e = r->predict(1500,1500);
    cout << e.A << " " << e.B;

    menu();

    s->savetofile();
    delete s;
}
