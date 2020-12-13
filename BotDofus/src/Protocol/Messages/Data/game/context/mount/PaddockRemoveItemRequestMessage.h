#ifndef PADDOCKREMOVEITEMREQUESTMESSAGE_H
#define PADDOCKREMOVEITEMREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class PaddockRemoveItemRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PaddockRemoveItemRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PaddockRemoveItemRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PaddockRemoveItemRequestMessage(FuncTree tree);
  PaddockRemoveItemRequestMessage();

  uint cellId;

private:
  void _cellIdFunc(Reader *input);
};

#endif // PADDOCKREMOVEITEMREQUESTMESSAGE_H