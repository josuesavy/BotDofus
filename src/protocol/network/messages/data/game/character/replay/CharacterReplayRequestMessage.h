#ifndef CHARACTERREPLAYREQUESTMESSAGE_H
#define CHARACTERREPLAYREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class CharacterReplayRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterReplayRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterReplayRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterReplayRequestMessage(FuncTree tree);
  CharacterReplayRequestMessage();

  double characterId;

private:
  void _characterIdFunc(Reader *input);
};

#endif // CHARACTERREPLAYREQUESTMESSAGE_H