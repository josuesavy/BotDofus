#ifndef ALLIANCEKICKREQUESTMESSAGE_H
#define ALLIANCEKICKREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AllianceKickRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceKickRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceKickRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceKickRequestMessage(FuncTree tree);
  AllianceKickRequestMessage();

  double kickedId;

private:
  void _kickedIdFunc(Reader *input);
};

#endif // ALLIANCEKICKREQUESTMESSAGE_H