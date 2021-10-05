#ifndef ALLIANCEGUILDLEAVINGMESSAGE_H
#define ALLIANCEGUILDLEAVINGMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceGuildLeavingMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceGuildLeavingMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceGuildLeavingMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceGuildLeavingMessage(FuncTree tree);
  AllianceGuildLeavingMessage();

  bool kicked;
  uint guildId;

private:
  void _kickedFunc(Reader *input);
  void _guildIdFunc(Reader *input);
};

#endif // ALLIANCEGUILDLEAVINGMESSAGE_H