#ifndef MAPREWARDRATEMESSAGE_H
#define MAPREWARDRATEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class MapRewardRateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MapRewardRateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MapRewardRateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MapRewardRateMessage(FuncTree tree);
  MapRewardRateMessage();

  int mapRate;
  int subAreaRate;
  int totalRate;

private:
  void _mapRateFunc(Reader *input);
  void _subAreaRateFunc(Reader *input);
  void _totalRateFunc(Reader *input);
};

#endif // MAPREWARDRATEMESSAGE_H