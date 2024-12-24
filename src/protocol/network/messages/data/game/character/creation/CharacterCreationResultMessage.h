#ifndef CHARACTERCREATIONRESULTMESSAGE_H
#define CHARACTERCREATIONRESULTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class CharacterCreationResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterCreationResultMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterCreationResultMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterCreationResultMessage(FuncTree tree);
  CharacterCreationResultMessage();

  uint result;
  uint reason;

private:
  void _resultFunc(Reader *input);
  void _reasonFunc(Reader *input);
};

#endif // CHARACTERCREATIONRESULTMESSAGE_H