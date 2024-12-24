#ifndef GROUPTELEPORTPLAYEROFFERMESSAGE_H
#define GROUPTELEPORTPLAYEROFFERMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GroupTeleportPlayerOfferMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GroupTeleportPlayerOfferMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GroupTeleportPlayerOfferMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GroupTeleportPlayerOfferMessage(FuncTree tree);
  GroupTeleportPlayerOfferMessage();

  double mapId;
  int worldX;
  int worldY;
  uint timeLeft;
  double requesterId;
  QString requesterName;

private:
  void _mapIdFunc(Reader *input);
  void _worldXFunc(Reader *input);
  void _worldYFunc(Reader *input);
  void _timeLeftFunc(Reader *input);
  void _requesterIdFunc(Reader *input);
  void _requesterNameFunc(Reader *input);
};

#endif // GROUPTELEPORTPLAYEROFFERMESSAGE_H