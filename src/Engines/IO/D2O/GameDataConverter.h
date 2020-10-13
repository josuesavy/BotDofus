#ifndef GAMEDATACONVERTER_H
#define GAMEDATACONVERTER_H

#include "src/Engines/IO/D2O/GameDataDeclarator.h"
#include "src/Engines/IO/D2O/GameDataTypeDeclarator.h"

class GameDataConverter
{
public:
  static QSharedPointer<AbstractGameData> getClass(const QString &name);
  static GameDataTypeEnum getEnum(const QString &name);
};

#endif // GAMEDATACONVERTER_H