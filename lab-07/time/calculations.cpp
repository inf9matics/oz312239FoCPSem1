#include "calculations.h"

//DRY - Don't Repeat Yourself
tim add(const tim& t1, const tim& t2)
{
    // tim t;
    // t.h = t1.h + t2.h;
    // t.m = t1.m + t2.m;
    // t.s = t1.s + t2.s;

    // if(t.s > 59)
    // {
    //     t.s = t.s - 60;
    //     t.m = t.m + 1;
    // }

    // if(t.m > 59)
    // {
    //     t.m = t.m - 60;
    //     t.h = t.h + 1;
    // }

    // if(t.h < 0)
    // {
    //     t.m = 60 - t.m;
    //     t.s = 60 - t.s;
    // }

    // return t;
    return totime(tosec(t1) + tosec(t2));
}

tim subtract(const tim& t1, const tim& t2)
{
    // tim t;
    // t.h = t1.h - t2.h;
    // t.m = t1.m - t2.m;
    // t.s = t1.s - t2.s;

    // if(t.s < 0)
    // {
    //     t.s = t.s + 60;
    //     t.m = t.m - 1;
    // }

    // if(t.m < 0)
    // {
    //     t.m = t.m + 60;
    //     t.h = t.h - 1;
    // }

    // if(t.h < 0)
    // {
    //     t.m = 60 - t.m;
    //     t.s = 60 - t.s;
    // }

    // return t;
    return totime(tosec(t1) - tosec(t2));
}

int tosec(const tim& t1)
{
    return (((t1.h * 60) + t1.m) * 60 + t1.s);
}

// void compare(const tim& t1, const tim& t2) //Not really sure whether I understood it
int compare(const tim& t1, const tim& t2) //Not really sure whether I understood it
{
    // if(tosec(t1) > tosec(t2))
    // {
    //     std::cout << "Time 1 > Time 2";
    // }
    // else
    // {
    //     std::cout << "Time 1 < Time 2"; 
    // }
    return tosec(t1) - tosec(t2);
}

tim totime(int s)
{
    tim t;
    
    t.m = s / 60;
    t.s = s - (t.m * 60);
    t.h = t.m / 60;
    t.m = t.m - (t.h * 60);
    
    return t;
}