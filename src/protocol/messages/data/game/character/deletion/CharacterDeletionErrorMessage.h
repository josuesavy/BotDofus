#ifndef CHARACTERDELETIONERRORMESSAGE_H
#define CHARACTERDELETIONERRORMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class CharacterDeletionErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterDeletionErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterDeletionErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterDeletionErrorMessage(FuncTree tree);
  CharacterDeletionErrorMessage();

  uint reason;

private:
  void _reasonFunc(Reader *input);
};

#endif // CHARACTERDELETIONERRORMESSAGE_H