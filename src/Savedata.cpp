#include "Savedata.h"
#include <iostream>

static int DEFAULT_ELO;

Savedata::Savedata(int delo)
{
    DEFAULT_ELO = delo;
    first = NULL;
    numberofplayers = 0;
}

void Savedata::addplayer(struct player *p) {
    if (first == NULL) {
        first = p;
        cout << "sdfsf";
    }
}

struct player* Savedata::createplayer(string n) {
    struct player *p;
    p->ELO = DEFAULT_ELO;
    p->name = n;
    p->num_games = 0;
};

Savedata::~Savedata()
{
    //dtor
}
