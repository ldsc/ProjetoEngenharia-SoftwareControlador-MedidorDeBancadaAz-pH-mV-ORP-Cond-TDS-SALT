#ifndef UTILS_H
#define UTILS_H

#include <list>
#include <qlist.h>

#include "Instrumentor.h"

class Utils
{
private:
    Utils() {}
public:
    static double GetMediana(QList<double>* values);
    static double GetMax(QList<double>* values);
    static double GetMin(QList<double>* values);
    static double GetDesvioPadrao(QList<double>* values);
    static double GetMedia(QList<double>* values);
};

#endif // UTILS_H
