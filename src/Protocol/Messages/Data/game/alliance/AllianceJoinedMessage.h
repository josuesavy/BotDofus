#ifndef ALLIANCEJOINEDMESSAGE_H
#define ALLIANCEJOINEDMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/AllianceInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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

  QSharedPointer<AllianceInformations> allianceInfo;
  bool enabled;
  uint leadingGuildId;

private:
  void _allianceInfotreeFunc(Reader *input);
  void _enabledFunc(Reader *input);
  void _leadingGuildIdFunc(Reader *input);

  FuncTree _allianceInfotree;
};

#endif // ALLIANCEJOINEDMESSAGE_H