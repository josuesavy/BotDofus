#ifndef ALLIANCEMEMBERSTARTWARNINGONCONNECTIONMESSAGE_H
#define ALLIANCEMEMBERSTARTWARNINGONCONNECTIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceMemberStartWarningOnConnectionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceMemberStartWarningOnConnectionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceMemberStartWarningOnConnectionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceMemberStartWarningOnConnectionMessage(FuncTree tree);
  AllianceMemberStartWarningOnConnectionMessage();
};

#endif // ALLIANCEMEMBERSTARTWARNINGONCONNECTIONMESSAGE_H