#include <string>
#include <fstream>
#include <vector>

#ifndef SAVEDATA_H
#define SAVEDATA_H

using namespace std;

class Player {
    public:
    Player(){
        name = "";
        ELO = 1500;
        num_games = 0;
    };
    string name;
    int ELO;
    int num_games;
    friend std::ostream& operator<<(std::ostream& o, const Player& p) {
        //o << p.name << "\n";
        //o << p.rating << "\n";
        o << p.name << "\n";
        o << p.ELO << "\n";
        o << p.num_games << "\n";
        return o;
    }

    friend std::istream& operator>>(std::istream& o, Player& p) {
        //o >> p.name;
        //o >> p.rating;
        o >> p.name;
        o >> p.ELO;
        o >> p.num_games;
        return o;
    }
};

class Savedata
{
    public:
        vector<Player> people;
        Savedata(int delo, string filelocation);
        virtual ~Savedata();
        Player createplayer(string name);
        void addplayer(Player p);
        void addmatch(int ID1, int ID2,int win);
        void loadfromfile();
        void savetofile();
        void listplayers();
    protected:
};

#endif // SAVEDATA_H
