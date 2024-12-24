#ifndef SHOWCELLMESSAGE_H
#define SHOWCELLMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ShowCellMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ShowCellMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ShowCellMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ShowCellMessage(FuncTree tree);
  ShowCellMessage();

  double sourceId;
  uint cellId;

private:
  void _sourceIdFunc(Reader *input);
  void _cellIdFunc(Reader *input);
};

#endif // SHOWCELLMESSAGE_H