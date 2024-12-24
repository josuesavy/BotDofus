#ifndef CHARACTERSELECTEDFORCEREADYMESSAGE_H
#define CHARACTERSELECTEDFORCEREADYMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class CharacterSelectedForceReadyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterSelectedForceReadyMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterSelectedForceReadyMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterSelectedForceReadyMessage(FuncTree tree);
  CharacterSelectedForceReadyMessage();
};

#endif // CHARACTERSELECTEDFORCEREADYMESSAGE_H