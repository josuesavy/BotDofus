#ifndef CHARACTERCANBECREATEDRESULTMESSAGE_H
#define CHARACTERCANBECREATEDRESULTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class CharacterCanBeCreatedResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterCanBeCreatedResultMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterCanBeCreatedResultMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterCanBeCreatedResultMessage(FuncTree tree);
  CharacterCanBeCreatedResultMessage();

  bool yesYouCan;

private:
  void _yesYouCanFunc(Reader *input);
};

#endif // CHARACTERCANBECREATEDRESULTMESSAGE_H