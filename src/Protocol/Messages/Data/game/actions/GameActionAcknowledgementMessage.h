#ifndef GAMEACTIONACKNOWLEDGEMENTMESSAGE_H
#define GAMEACTIONACKNOWLEDGEMENTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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