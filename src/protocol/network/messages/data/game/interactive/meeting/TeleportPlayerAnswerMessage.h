#ifndef TELEPORTPLAYERANSWERMESSAGE_H
#define TELEPORTPLAYERANSWERMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class TeleportPlayerAnswerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TeleportPlayerAnswerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TeleportPlayerAnswerMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TeleportPlayerAnswerMessage(FuncTree tree);
  TeleportPlayerAnswerMessage();

  bool accept;
  double requesterId;

private:
  void _acceptFunc(Reader *input);
  void _requesterIdFunc(Reader *input);
};

#endif // TELEPORTPLAYERANSWERMESSAGE_H