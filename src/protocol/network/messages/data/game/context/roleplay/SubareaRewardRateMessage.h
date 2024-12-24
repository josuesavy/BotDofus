#ifndef SUBAREAREWARDRATEMESSAGE_H
#define SUBAREAREWARDRATEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class SubareaRewardRateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SubareaRewardRateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SubareaRewardRateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SubareaRewardRateMessage(FuncTree tree);
  SubareaRewardRateMessage();

  int subAreaRate;

private:
  void _subAreaRateFunc(Reader *input);
};

#endif // SUBAREAREWARDRATEMESSAGE_H