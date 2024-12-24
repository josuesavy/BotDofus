#ifndef BASICLATENCYSTATSMESSAGE_H
#define BASICLATENCYSTATSMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class BasicLatencyStatsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BasicLatencyStatsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BasicLatencyStatsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BasicLatencyStatsMessage(FuncTree tree);
  BasicLatencyStatsMessage();

  uint latency;
  uint sampleCount;
  uint max;

private:
  void _latencyFunc(Reader *input);
  void _sampleCountFunc(Reader *input);
  void _maxFunc(Reader *input);
};

#endif // BASICLATENCYSTATSMESSAGE_H