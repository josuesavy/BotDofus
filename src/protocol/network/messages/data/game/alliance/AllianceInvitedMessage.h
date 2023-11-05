#ifndef ALLIANCEINVITEDMESSAGE_H
#define ALLIANCEINVITEDMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/AllianceInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceInvitedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceInvitedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceInvitedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceInvitedMessage(FuncTree tree);
  AllianceInvitedMessage();

  QString recruterName;
  QSharedPointer<AllianceInformation> allianceInfo;

private:
  void _recruterNameFunc(Reader *input);
  void _allianceInfotreeFunc(Reader *input);

  FuncTree _allianceInfotree;
};

#endif // ALLIANCEINVITEDMESSAGE_H