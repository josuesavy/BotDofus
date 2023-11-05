#ifndef STATEDELEMENTUPDATEDMESSAGE_H
#define STATEDELEMENTUPDATEDMESSAGE_H

#include "src/protocol/types/data/game/interactive/StatedElement.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class StatedElementUpdatedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StatedElementUpdatedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StatedElementUpdatedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StatedElementUpdatedMessage(FuncTree tree);
  StatedElementUpdatedMessage();

  StatedElement statedElement;

private:
  void _statedElementtreeFunc(Reader *input);

  FuncTree _statedElementtree;
};

#endif // STATEDELEMENTUPDATEDMESSAGE_H