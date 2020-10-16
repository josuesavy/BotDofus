#ifndef CHARACTERCREATIONRESULTMESSAGE_H
#define CHARACTERCREATIONRESULTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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

private:
  void _resultFunc(Reader *input);
};

#endif // CHARACTERCREATIONRESULTMESSAGE_H