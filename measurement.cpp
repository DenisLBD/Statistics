#include "measurement.h"

#include <iostream>
#include <vector>


    Measurement::Measurement() 
    {
        number = 0;
        data = 0;
        time = 0;
    }

    int Measurement::getNumber()
    {
        return number;
    }

    double Measurement::getData()
    {
        return data;
    }

    double Measurement::getTime()
    {
        return time;
    }

    void Measurement::setNumber(int numToSet)
    {
        number = numToSet;
    }

    void Measurement::setData(double dataToSet)
    {
        data = dataToSet;
    }

    void Measurement::setTime(double timeToSet)
    {
        time = timeToSet;
    }

