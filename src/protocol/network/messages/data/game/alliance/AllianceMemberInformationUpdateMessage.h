#ifndef ALLIANCEMEMBERINFORMATIONUPDATEMESSAGE_H
#define ALLIANCEMEMBERINFORMATIONUPDATEMESSAGE_H

#include "src/protocol/types/data/game/alliance/AllianceMemberInfo.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceMemberInformationUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceMemberInformationUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceMemberInformationUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceMemberInformationUpdateMessage(FuncTree tree);
  AllianceMemberInformationUpdateMessage();

  QSharedPointer<AllianceMemberInfo> member;

private:
  void _membertreeFunc(Reader *input);

  FuncTree _membertree;
};

#endif // ALLIANCEMEMBERINFORMATIONUPDATEMESSAGE_H