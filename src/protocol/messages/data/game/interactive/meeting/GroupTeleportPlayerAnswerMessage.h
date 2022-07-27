#ifndef GROUPTELEPORTPLAYERANSWERMESSAGE_H
#define GROUPTELEPORTPLAYERANSWERMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GroupTeleportPlayerAnswerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GroupTeleportPlayerAnswerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GroupTeleportPlayerAnswerMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GroupTeleportPlayerAnswerMessage(FuncTree tree);
  GroupTeleportPlayerAnswerMessage();

  bool accept;
  double requesterId;

private:
  void _acceptFunc(Reader *input);
  void _requesterIdFunc(Reader *input);
};

#endif // GROUPTELEPORTPLAYERANSWERMESSAGE_H