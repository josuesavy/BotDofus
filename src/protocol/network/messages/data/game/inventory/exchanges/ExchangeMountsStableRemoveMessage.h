#ifndef EXCHANGEMOUNTSSTABLEREMOVEMESSAGE_H
#define EXCHANGEMOUNTSSTABLEREMOVEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeMountsStableRemoveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeMountsStableRemoveMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeMountsStableRemoveMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeMountsStableRemoveMessage(FuncTree tree);
  ExchangeMountsStableRemoveMessage();

  QList<int> mountsId;

private:
  void _mountsIdtreeFunc(Reader *input);
  void _mountsIdFunc(Reader *input);

  FuncTree _mountsIdtree;
};

#endif // EXCHANGEMOUNTSSTABLEREMOVEMESSAGE_H