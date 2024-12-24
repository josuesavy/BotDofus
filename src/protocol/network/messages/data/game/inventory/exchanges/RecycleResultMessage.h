#ifndef RECYCLERESULTMESSAGE_H
#define RECYCLERESULTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class RecycleResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_RecycleResultMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_RecycleResultMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_RecycleResultMessage(FuncTree tree);
  RecycleResultMessage();

  uint nuggetsForPrism;
  uint nuggetsForPlayer;

private:
  void _nuggetsForPrismFunc(Reader *input);
  void _nuggetsForPlayerFunc(Reader *input);
};

#endif // RECYCLERESULTMESSAGE_H