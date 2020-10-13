#ifndef PARAMSDECODER_H
#define PARAMSDECODER_H

#include <iostream>
#include <sstream>

#include <QDateTime>

#include "src/Engines/IO/D2O/GameDataDeclarator.h"
#include "src/Engines/IO/D2O/D2OManager.h"
#include "src/Public.h"

class ParamsDecoder
{
public:
    static QString applyParams(QString message, QStringList parameters, QString paramPrefix = "%");

private:
    static QString processReplace(QString param1, QString paramIdentifier, QStringList parameters);
};

#endif // PARAMSDECODER_H
