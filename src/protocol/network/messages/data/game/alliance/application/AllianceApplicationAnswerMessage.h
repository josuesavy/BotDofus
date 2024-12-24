#ifndef ALLIANCEAPPLICATIONANSWERMESSAGE_H
#define ALLIANCEAPPLICATIONANSWERMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AllianceApplicationAnswerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceApplicationAnswerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceApplicationAnswerMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceApplicationAnswerMessage(FuncTree tree);
  AllianceApplicationAnswerMessage();

  bool accepted;
  double playerId;

private:
  void _acceptedFunc(Reader *input);
  void _playerIdFunc(Reader *input);
};

#endif // ALLIANCEAPPLICATIONANSWERMESSAGE_H