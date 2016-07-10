#include <iostream>
#include "Rating.h"

using namespace std;

int main()
{
    Rating *r = new Rating();
    Expected p = r->newRating(1444,1444,-1);
    cout << p.A << "\n";
    cout << p.B << "\n";
}
