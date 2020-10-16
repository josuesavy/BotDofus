#ifndef ALLIANCEINVITEDMESSAGE_H
#define ALLIANCEINVITEDMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/BasicNamedAllianceInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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

  double recruterId;
  QString recruterName;
  QSharedPointer<BasicNamedAllianceInformations> allianceInfo;

private:
  void _recruterIdFunc(Reader *input);
  void _recruterNameFunc(Reader *input);
  void _allianceInfotreeFunc(Reader *input);

  FuncTree _allianceInfotree;
};

#endif // ALLIANCEINVITEDMESSAGE_H