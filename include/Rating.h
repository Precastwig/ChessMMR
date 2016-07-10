#ifndef RATING_H
#define RATING_H

struct Expected {
    int A;
    int B;
};

class Rating
{
    public:
        Rating();
        virtual ~Rating();
        struct Expected predict(int rA, int rB);
        struct Expected newRating(int rA, int rB, int outcome);
    protected:
    private:
};

#endif // RATING_H
