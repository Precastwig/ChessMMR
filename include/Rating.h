#ifndef RATING_H
#define RATING_H


class Rating
{
    public:
        Rating();
        virtual ~Rating();
        struct Expected predict(int rA, int rB);
        int newRating(int rA, int rB, int outcome);
    protected:
    private:
};

#endif // RATING_H
