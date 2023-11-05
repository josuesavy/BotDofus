#ifndef ALLIANCEJOINEDMESSAGE_H
#define ALLIANCEJOINEDMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/AllianceInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceJoinedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceJoinedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceJoinedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceJoinedMessage(FuncTree tree);
  AllianceJoinedMessage();

  QSharedPointer<AllianceInformation> allianceInfo;
  uint rankId;

private:
  void _allianceInfotreeFunc(Reader *input);
  void _rankIdFunc(Reader *input);

  FuncTree _allianceInfotree;
};

#endif // ALLIANCEJOINEDMESSAGE_H