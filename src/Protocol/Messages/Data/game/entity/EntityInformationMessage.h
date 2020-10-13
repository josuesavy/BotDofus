#ifndef ENTITYINFORMATIONMESSAGE_H
#define ENTITYINFORMATIONMESSAGE_H

#include "src/Protocol/Types/Data/game/entity/EntityInformation.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class EntityInformationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_EntityInformationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_EntityInformationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_EntityInformationMessage(FuncTree tree);
  EntityInformationMessage();

  EntityInformation entity;

private:
  void _entitytreeFunc(Reader *input);

  FuncTree _entitytree;
};

#endif // ENTITYINFORMATIONMESSAGE_H