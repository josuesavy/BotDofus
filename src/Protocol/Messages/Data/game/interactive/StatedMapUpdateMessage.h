#ifndef STATEDMAPUPDATEMESSAGE_H
#define STATEDMAPUPDATEMESSAGE_H

#include "src/Protocol/Types/Data/game/interactive/StatedElement.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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