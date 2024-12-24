#ifndef BASICLATENCYSTATSREQUESTMESSAGE_H
#define BASICLATENCYSTATSREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class BasicLatencyStatsRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BasicLatencyStatsRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BasicLatencyStatsRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BasicLatencyStatsRequestMessage(FuncTree tree);
  BasicLatencyStatsRequestMessage();
};

#endif // BASICLATENCYSTATSREQUESTMESSAGE_H