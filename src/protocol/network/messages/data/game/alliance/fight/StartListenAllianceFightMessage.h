#ifndef STARTLISTENALLIANCEFIGHTMESSAGE_H
#define STARTLISTENALLIANCEFIGHTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class StartListenAllianceFightMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StartListenAllianceFightMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StartListenAllianceFightMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StartListenAllianceFightMessage(FuncTree tree);
  StartListenAllianceFightMessage();
};

#endif // STARTLISTENALLIANCEFIGHTMESSAGE_H