#ifndef COMPASSUPDATEMESSAGE_H
#define COMPASSUPDATEMESSAGE_H

#include "src/protocol/types/ClassManager.h"
#include "src/protocol/types/data/game/context/MapCoordinates.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class CompassUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CompassUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CompassUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CompassUpdateMessage(FuncTree tree);
  CompassUpdateMessage();

  uint type;
  QSharedPointer<MapCoordinates> coords;

private:
  void _typeFunc(Reader *input);
  void _coordstreeFunc(Reader *input);

  FuncTree _coordstree;
};

#endif // COMPASSUPDATEMESSAGE_H