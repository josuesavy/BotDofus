#ifndef ALLIANCEMEMBERSTOPWARNINGONCONNECTIONMESSAGE_H
#define ALLIANCEMEMBERSTOPWARNINGONCONNECTIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceMemberStopWarningOnConnectionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceMemberStopWarningOnConnectionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceMemberStopWarningOnConnectionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceMemberStopWarningOnConnectionMessage(FuncTree tree);
  AllianceMemberStopWarningOnConnectionMessage();
};

#endif // ALLIANCEMEMBERSTOPWARNINGONCONNECTIONMESSAGE_H