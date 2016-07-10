#include "Rating.h"
#include "tgmath.h"

struct Expected {
    int A;
    int B;
};

Rating::Rating()
{
    //ctor
}

struct Expected Rating::predict(int rA, int rB) {
    Expected result;
    result.A = 1 / (1 + pow(10, (rB - rA) / 400));
    result.B = 1 / (1 + pow(10, (rA - rB) / 400));
    return result;
}

int Rating::newRating(int rA, int rB, int outcome) {

}

Rating::~Rating()
{
    //dtor
}
