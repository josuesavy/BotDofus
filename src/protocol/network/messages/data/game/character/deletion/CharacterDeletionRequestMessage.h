#ifndef CHARACTERDELETIONREQUESTMESSAGE_H
#define CHARACTERDELETIONREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class CharacterDeletionRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterDeletionRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterDeletionRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterDeletionRequestMessage(FuncTree tree);
  CharacterDeletionRequestMessage();

  double characterId;
  QString secretAnswerHash;

private:
  void _characterIdFunc(Reader *input);
  void _secretAnswerHashFunc(Reader *input);
};

#endif // CHARACTERDELETIONREQUESTMESSAGE_H