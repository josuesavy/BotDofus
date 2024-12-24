#ifndef CHARACTERDELETIONPREPAREREQUESTMESSAGE_H
#define CHARACTERDELETIONPREPAREREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class CharacterDeletionPrepareRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterDeletionPrepareRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterDeletionPrepareRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterDeletionPrepareRequestMessage(FuncTree tree);
  CharacterDeletionPrepareRequestMessage();

  double characterId;

private:
  void _characterIdFunc(Reader *input);
};

#endif // CHARACTERDELETIONPREPAREREQUESTMESSAGE_H