#ifndef PADDOCKPROPERTIESMESSAGE_H
#define PADDOCKPROPERTIESMESSAGE_H

#include "src/protocol/types/data/game/paddock/PaddockInstancesInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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

  PaddockInstancesInformations properties;

private:
  void _propertiestreeFunc(Reader *input);

  FuncTree _propertiestree;
};

#endif // PADDOCKPROPERTIESMESSAGE_H