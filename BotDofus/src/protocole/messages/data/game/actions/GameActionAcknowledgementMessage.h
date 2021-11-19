#ifndef GAMEACTIONACKNOWLEDGEMENTMESSAGE_H
#define GAMEACTIONACKNOWLEDGEMENTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameActionAcknowledgementMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionAcknowledgementMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionAcknowledgementMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionAcknowledgementMessage(FuncTree tree);
  GameActionAcknowledgementMessage();

  bool valid;
  int actionId;

private:
  void _validFunc(Reader *input);
  void _actionIdFunc(Reader *input);
};

#endif // GAMEACTIONACKNOWLEDGEMENTMESSAGE_H