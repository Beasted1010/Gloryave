#ifndef PICKUP_H
#define PICKUP_H


class pickUp
{
    public:
        pickUp(int chance);
        virtual ~pickUp();
        int incr_heroHP();
    protected:
    private:
};

#endif // PICKUP_H
