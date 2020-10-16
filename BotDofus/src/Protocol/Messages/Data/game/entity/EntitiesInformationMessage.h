#ifndef ENTITIESINFORMATIONMESSAGE_H
#define ENTITIESINFORMATIONMESSAGE_H

#include "src/Protocol/Types/Data/game/entity/EntityInformation.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class EntitiesInformationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_EntitiesInformationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_EntitiesInformationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_EntitiesInformationMessage(FuncTree tree);
  EntitiesInformationMessage();

  QList<EntityInformation> entities;

private:
  void _entitiestreeFunc(Reader *input);
  void _entitiesFunc(Reader *input);

  FuncTree _entitiestree;
};

#endif // ENTITIESINFORMATIONMESSAGE_H