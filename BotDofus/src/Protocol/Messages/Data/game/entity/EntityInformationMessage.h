#ifndef ENTITYINFORMATIONMESSAGE_H
#define ENTITYINFORMATIONMESSAGE_H

#include "src/protocol/types/data/game/entity/EntityInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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