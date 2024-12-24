#ifndef GAMEDATACONVERTER_H
#define GAMEDATACONVERTER_H

#include "src/protocol/datacenter/GameDataDeclarator.h"
#include "src/protocol/datacenter/GameDataTypeDeclarator.h"

class GameDataConverter
{
public:
  static QSharedPointer<AbstractGameData> getClass(const QString &name);
  static GameDataTypeEnum getEnum(const QString &name);
};

#endif // GAMEDATACONVERTER_H