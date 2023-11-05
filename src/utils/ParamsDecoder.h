#ifndef PARAMSDECODER_H
#define PARAMSDECODER_H

#include <iostream>
#include <sstream>

#include <QDateTime>

#include "src/protocol/datacenter/GameDataDeclarator.h"
#include "src/gamedata/d2o/D2OManager.h"
#include "src/utils/Public.h"

class ParamsDecoder
{
public:
    static QString applyParams(QString message, QStringList parameters, QString paramPrefix = "%");

private:
    static QString processReplace(QString param1, QString paramIdentifier, QStringList parameters);
};

#endif // PARAMSDECODER_H
