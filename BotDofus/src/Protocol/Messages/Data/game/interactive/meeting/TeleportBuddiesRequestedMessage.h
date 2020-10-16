#ifndef TELEPORTBUDDIESREQUESTEDMESSAGE_H
#define TELEPORTBUDDIESREQUESTEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class TeleportBuddiesRequestedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TeleportBuddiesRequestedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TeleportBuddiesRequestedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TeleportBuddiesRequestedMessage(FuncTree tree);
  TeleportBuddiesRequestedMessage();

  uint dungeonId;
  double inviterId;
  QList<double> invalidBuddiesIds;

private:
  void _dungeonIdFunc(Reader *input);
  void _inviterIdFunc(Reader *input);
  void _invalidBuddiesIdstreeFunc(Reader *input);
  void _invalidBuddiesIdsFunc(Reader *input);

  FuncTree _invalidBuddiesIdstree;
};

#endif // TELEPORTBUDDIESREQUESTEDMESSAGE_H