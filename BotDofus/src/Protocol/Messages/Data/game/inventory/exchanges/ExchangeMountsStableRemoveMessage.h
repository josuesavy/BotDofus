#ifndef EXCHANGEMOUNTSSTABLEREMOVEMESSAGE_H
#define EXCHANGEMOUNTSSTABLEREMOVEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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