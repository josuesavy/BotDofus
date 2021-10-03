#ifndef PARAMSDECODER_H
#define PARAMSDECODER_H

#include <iostream>
#include <sstream>

#include <QDateTime>

#include "src/engines/io/d2o/game/GameDataDeclarator.h"
#include "src/engines/io/d2o/D2OManager.h"
#include "src/Public.h"

class ParamsDecoder
{
public:
    static QString applyParams(QString message, QStringList parameters, QString paramPrefix = "%");

private:
    static QString processReplace(QString param1, QString paramIdentifier, QStringList parameters);
};

#endif // PARAMSDECODER_H
