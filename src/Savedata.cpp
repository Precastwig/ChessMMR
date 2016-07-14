#include "Savedata.h"
#include "Rating.h"
#include <iostream>
#include <fstream>
#include <iterator>

static int DEFAULT_ELO;
static string FILESTR;

Savedata::Savedata(int delo, string filelocation)
{
    DEFAULT_ELO = delo;
    FILESTR = filelocation;
}

void Savedata::addplayer(Player p) {
    people.push_back(p);
}

Player Savedata::createplayer(string n) {
    Player p;
    p.ELO = DEFAULT_ELO;
    p.name = n;
    p.num_games = 0;
    return p;
};

void Savedata::addmatch(int ID1,int ID2,int win) {
    Rating *r = new Rating();
    Player p1, p2;
    int p1i,p2i;
    if (ID1 < people.size() && ID2 < people.size()) {
        p1 = people[ID1];
        p2 = people[ID2];
    }

    Expected e = r->newRating(p1.ELO,p2.ELO,win);
    people[ID1].ELO = e.A;
    people[ID2].ELO = e.B;
    delete r;
}

void Savedata::deleteplayer(int ID) {
    people.erase(people.begin()+ ID);
}

void Savedata::listplayers() {
    for (int i = 0; i < people.size(); i++) {
        cout << i << ". " << people[i].name << " - " << people[i].ELO << "\n";
    }
}

void Savedata::loadfromfile() {
    ifstream in(FILESTR, std::ios::in | ifstream::binary);
    istream_iterator<Player> input(in);
    copy( input, istream_iterator<Player>(), back_inserter(people) );
}

void Savedata::savetofile() {
    ofstream out{FILESTR, std::ios::out | std::ofstream::binary};
    copy( begin(people), end(people), ostream_iterator<Player>{out});
}

Savedata::~Savedata()
{

}
