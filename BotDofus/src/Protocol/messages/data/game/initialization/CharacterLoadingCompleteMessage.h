#ifndef CHARACTERLOADINGCOMPLETEMESSAGE_H
#define CHARACTERLOADINGCOMPLETEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class CharacterLoadingCompleteMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterLoadingCompleteMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterLoadingCompleteMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterLoadingCompleteMessage(FuncTree tree);
  CharacterLoadingCompleteMessage();
};

#endif // CHARACTERLOADINGCOMPLETEMESSAGE_H