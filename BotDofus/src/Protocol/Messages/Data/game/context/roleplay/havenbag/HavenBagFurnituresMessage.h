#ifndef HAVENBAGFURNITURESMESSAGE_H
#define HAVENBAGFURNITURESMESSAGE_H

#include "src/Protocol/Types/Data/game/guild/HavenBagFurnitureInformation.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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