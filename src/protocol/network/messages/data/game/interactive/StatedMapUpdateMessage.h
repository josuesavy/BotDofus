#ifndef STATEDMAPUPDATEMESSAGE_H
#define STATEDMAPUPDATEMESSAGE_H

#include "src/protocol/network/types/data/game/interactive/StatedElement.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class StatedMapUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StatedMapUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StatedMapUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StatedMapUpdateMessage(FuncTree tree);
  StatedMapUpdateMessage();

  QList<StatedElement> statedElements;

private:
  void _statedElementstreeFunc(Reader *input);
  void _statedElementsFunc(Reader *input);

  FuncTree _statedElementstree;
};

#endif // STATEDMAPUPDATEMESSAGE_H