#include "Rating.h"
#include "tgmath.h"

int K = 32;

Rating::Rating()
{
    //ctor
}

struct Expected Rating::predict(double rA, double rB) {
    Expected result;
    result.A = 1 / (1 + pow(10, (rB - rA) / 400));
    result.B = 1 / (1 + pow(10, (rA - rB) / 400));
    return result;
}

struct Expected Rating::newRating(double rA, double rB, double outcome) {
    Expected result;
    Expected p = predict(rA, rB);
    if (outcome == 1) {
        result.A = rA + (K * (1 - p.A));
        result.B = rB + (K * (0 - p.B));
    } else if (outcome == 2) {
        result.A = rA + (K * (0 - p.A));
        result.B = rB + (K * (1 - p.B));
    } else {
        result.A = rA + (K * (0.5 - p.A));
        result.B = rB + (K * (0.5 - p.B));
    }
    return result;
}

Rating::~Rating()
{
    //dtor
}
