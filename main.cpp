#include <iostream>
#include <string>
#include "Rating.h"
#include "Savedata.h"

using namespace std;

int main()
{
    Rating *r = new Rating();
    Expected p = r->newRating(1444,1444,-1);
    cout << p.A << "\n";
    cout << p.B << "\n";
    Savedata *s = new Savedata(1500);
    player *play = s->createplayer("Felix");
    s->addplayer(play);
    delete r;
    delete s;
}
