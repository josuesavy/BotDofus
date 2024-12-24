#ifndef PADDOCKPROPERTIESMESSAGE_H
#define PADDOCKPROPERTIESMESSAGE_H

#include "src/protocol/network/types/data/game/paddock/PaddockInstancesInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class PaddockPropertiesMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PaddockPropertiesMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PaddockPropertiesMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PaddockPropertiesMessage(FuncTree tree);
  PaddockPropertiesMessage();

  QSharedPointer<PaddockInstancesInformations> properties;

private:
  void _propertiestreeFunc(Reader *input);

  FuncTree _propertiestree;
};

#endif // PADDOCKPROPERTIESMESSAGE_H