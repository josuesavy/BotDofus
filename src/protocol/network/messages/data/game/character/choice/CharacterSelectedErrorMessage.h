#ifndef CHARACTERSELECTEDERRORMESSAGE_H
#define CHARACTERSELECTEDERRORMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class CharacterSelectedErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterSelectedErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterSelectedErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterSelectedErrorMessage(FuncTree tree);
  CharacterSelectedErrorMessage();
};

#endif // CHARACTERSELECTEDERRORMESSAGE_H