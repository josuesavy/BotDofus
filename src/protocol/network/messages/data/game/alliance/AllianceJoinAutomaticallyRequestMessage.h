#ifndef ALLIANCEJOINAUTOMATICALLYREQUESTMESSAGE_H
#define ALLIANCEJOINAUTOMATICALLYREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AllianceJoinAutomaticallyRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceJoinAutomaticallyRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceJoinAutomaticallyRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceJoinAutomaticallyRequestMessage(FuncTree tree);
  AllianceJoinAutomaticallyRequestMessage();

  int allianceId;

private:
  void _allianceIdFunc(Reader *input);
};

#endif // ALLIANCEJOINAUTOMATICALLYREQUESTMESSAGE_H