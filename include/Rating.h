#ifndef RATING_H
#define RATING_H

struct Expected {
    double A;
    double B;
};

class Rating
{
    public:
        Rating();
        virtual ~Rating();
        struct Expected predict(double rA, double rB);
        struct Expected newRating(double rA, double rB, double outcome);
    protected:
    private:
};

#endif // RATING_H
