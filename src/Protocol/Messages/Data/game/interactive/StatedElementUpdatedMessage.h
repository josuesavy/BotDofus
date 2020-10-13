#ifndef STATEDELEMENTUPDATEDMESSAGE_H
#define STATEDELEMENTUPDATEDMESSAGE_H

#include "src/Protocol/Types/Data/game/interactive/StatedElement.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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