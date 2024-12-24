#ifndef ENTITIESINFORMATIONMESSAGE_H
#define ENTITIESINFORMATIONMESSAGE_H

#include "src/protocol/network/types/data/game/entity/EntityInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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