#ifndef SAVCHUK_POINT_H
#define SAVCHUK_POINT_H

#include <string>
#include <ostream>
#include "EllipticCurve.h"

/*
 *  Class that represent point with X and Y coordinates.
 *
 *  created by Vlad Savchuk on 11/12/2020.
 */
class Point {
private:
    long long x;
    long long y;
    std::string name;
    EllipticCurve *ellipticCurve;
public:
    Point(long long x, long long y);
    Point(std::string name, long long x, long long y);
    Point(std::string name, long long x, long long y, EllipticCurve *curve);


    //getters and setters
    long long getX() const {
        return x;
    }

    void setX(long long x) {
        Point::x = x;
    }

    long long getY() const {
        return y;
    }

    void setY(long long y) {
        Point::y = y;
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Point::name = name;
    }

    EllipticCurve *getEllipticCurve() const {
        return ellipticCurve;
    }

    void setEllipticCurve(EllipticCurve *ellipticCurve) {
        Point::ellipticCurve = ellipticCurve;
    }

    //operators overloading
    friend Point operator+(Point p, Point q);

    friend Point operator*(long long k, Point p);

    friend std::ostream &operator<<(std::ostream &os, const Point &point);

    //methods
    bool isOnEllipticCurve(EllipticCurve curve);
};

#endif //SAVCHUK_POINT_H