#ifndef GAMEDATACONVERTER_H
#define GAMEDATACONVERTER_H

#include "src/engines/io/d2o/game/GameDataDeclarator.h"
#include "src/engines/io/d2o/game/GameDataTypeDeclarator.h"

class GameDataConverter
{
public:
  static QSharedPointer<AbstractGameData> getClass(const QString &name);
  static GameDataTypeEnum getEnum(const QString &name);
};

#endif // GAMEDATACONVERTER_H