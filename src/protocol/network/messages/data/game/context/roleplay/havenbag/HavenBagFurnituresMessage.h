#ifndef HAVENBAGFURNITURESMESSAGE_H
#define HAVENBAGFURNITURESMESSAGE_H

#include "src/protocol/network/types/data/game/guild/HavenBagFurnitureInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class HavenBagFurnituresMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HavenBagFurnituresMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HavenBagFurnituresMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HavenBagFurnituresMessage(FuncTree tree);
  HavenBagFurnituresMessage();

  QList<HavenBagFurnitureInformation> furnituresInfos;

private:
  void _furnituresInfostreeFunc(Reader *input);
  void _furnituresInfosFunc(Reader *input);

  FuncTree _furnituresInfostree;
};

#endif // HAVENBAGFURNITURESMESSAGE_H