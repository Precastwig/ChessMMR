#include <string>

#ifndef SAVEDATA_H
#define SAVEDATA_H

using namespace std;

struct player {
    string name;
    int ELO;
    int num_games;
    struct player *next;
};

class Savedata
{
    public:
        struct player *first;
        int numberofplayers;
        Savedata(int delo);
        virtual ~Savedata();
        player *createplayer(string name);
        void addplayer(struct player *p);
    protected:

    private:
};

#endif // SAVEDATA_H
