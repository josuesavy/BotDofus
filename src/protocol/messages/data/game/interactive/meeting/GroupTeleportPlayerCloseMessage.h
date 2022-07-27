#ifndef GROUPTELEPORTPLAYERCLOSEMESSAGE_H
#define GROUPTELEPORTPLAYERCLOSEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GroupTeleportPlayerCloseMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GroupTeleportPlayerCloseMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GroupTeleportPlayerCloseMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GroupTeleportPlayerCloseMessage(FuncTree tree);
  GroupTeleportPlayerCloseMessage();

  double mapId;
  double requesterId;

private:
  void _mapIdFunc(Reader *input);
  void _requesterIdFunc(Reader *input);
};

#endif // GROUPTELEPORTPLAYERCLOSEMESSAGE_H