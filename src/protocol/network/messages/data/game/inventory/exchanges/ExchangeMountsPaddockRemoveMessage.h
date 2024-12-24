#ifndef EXCHANGEMOUNTSPADDOCKREMOVEMESSAGE_H
#define EXCHANGEMOUNTSPADDOCKREMOVEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeMountsPaddockRemoveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeMountsPaddockRemoveMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeMountsPaddockRemoveMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeMountsPaddockRemoveMessage(FuncTree tree);
  ExchangeMountsPaddockRemoveMessage();

  QList<int> mountsId;

private:
  void _mountsIdtreeFunc(Reader *input);
  void _mountsIdFunc(Reader *input);

  FuncTree _mountsIdtree;
};

#endif // EXCHANGEMOUNTSPADDOCKREMOVEMESSAGE_H