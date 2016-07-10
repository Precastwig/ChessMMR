#include "Rating.h"
#include "tgmath.h"

int K = 32;

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

struct Expected Rating::newRating(int rA, int rB, int outcome) {
    Expected result;
    Expected p = predict(rA, rB);
    result.A = rA + (K * (outcome - p.A));
    result.B = rB + (K * (-outcome - p.B));
    return result;
}

Rating::~Rating()
{
    //dtor
}
