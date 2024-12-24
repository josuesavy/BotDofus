#ifndef ALLIANCEMEMBERSTARTWARNINGONCONNECTIONMESSAGE_H
#define ALLIANCEMEMBERSTARTWARNINGONCONNECTIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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