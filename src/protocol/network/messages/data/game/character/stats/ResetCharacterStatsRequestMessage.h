#ifndef RESETCHARACTERSTATSREQUESTMESSAGE_H
#define RESETCHARACTERSTATSREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ResetCharacterStatsRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ResetCharacterStatsRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ResetCharacterStatsRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ResetCharacterStatsRequestMessage(FuncTree tree);
  ResetCharacterStatsRequestMessage();
};

#endif // RESETCHARACTERSTATSREQUESTMESSAGE_H