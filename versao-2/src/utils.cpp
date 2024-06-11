#include "utils.h"

#include <QList>

double Utils::GetMediana(QList<double>* values)
{
    STUDY_PROFILE_FUNCTION();
    std::sort(values->begin(), values->end());

    double m1, m2;

    switch (values->count() % 2) // Seletor para calculo da mediana.
    {
      case 0:
        m1 = values->value(values->count() / 2 - 1);
        m2 =  values->value(values->count() / 2);
        m1 += m2;
        return  (m1 / 2);

      case 1: // Faixa de valores do vetor e IMPAR.
        m1 = values->value((values->count() - 1) / 2);
        return m1;
    }
}

double Utils::GetMax(QList<double>* values)
{
    STUDY_PROFILE_FUNCTION();
    double max = std::numeric_limits<double>::min();

    for (int i = 0; i < values->count(); ++i) {
        double value = values->value(i);

        if(value > max)
        {
            max = value;
        }
    }

    return max;
}

double Utils::GetMin(QList<double>* values)
{
    STUDY_PROFILE_FUNCTION();
    double min = std::numeric_limits<double>::max();

    for (int i = 0; i < values->count(); ++i) {
        double value = values->value(i);

        if(value < min)
        {
            min = value;
        }
    }

    return min;
}

double Utils::GetDesvioPadrao(QList<double>* values)
{
    STUDY_PROFILE_FUNCTION();
    double media = Utils::GetMedia(values);

    float variacoes = 0;
    for (int i = 0; i < values->count(); i++) {
        float v = values->value(i) - media;
        variacoes += v * v;
    }

    return sqrt(variacoes / values->count());
}

double Utils::GetMedia(QList<double>* values)
{
    STUDY_PROFILE_FUNCTION();
    double soma = 0;

    for (int i = 0; i < values->count(); ++i) {
        double value = values->value(i);

        soma += value;
    }

    return soma / values->count();
}
