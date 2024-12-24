#ifndef STOPLISTENALLIANCEFIGHTMESSAGE_H
#define STOPLISTENALLIANCEFIGHTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class StopListenAllianceFightMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StopListenAllianceFightMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StopListenAllianceFightMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StopListenAllianceFightMessage(FuncTree tree);
  StopListenAllianceFightMessage();
};

#endif // STOPLISTENALLIANCEFIGHTMESSAGE_H