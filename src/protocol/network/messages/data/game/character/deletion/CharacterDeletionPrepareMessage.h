#ifndef CHARACTERDELETIONPREPAREMESSAGE_H
#define CHARACTERDELETIONPREPAREMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class CharacterDeletionPrepareMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterDeletionPrepareMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterDeletionPrepareMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterDeletionPrepareMessage(FuncTree tree);
  CharacterDeletionPrepareMessage();

  double characterId;
  QString characterName;
  QString secretQuestion;
  bool needSecretAnswer;

private:
  void _characterIdFunc(Reader *input);
  void _characterNameFunc(Reader *input);
  void _secretQuestionFunc(Reader *input);
  void _needSecretAnswerFunc(Reader *input);
};

#endif // CHARACTERDELETIONPREPAREMESSAGE_H