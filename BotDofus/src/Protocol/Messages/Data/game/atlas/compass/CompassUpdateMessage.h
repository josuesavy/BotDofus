#ifndef COMPASSUPDATEMESSAGE_H
#define COMPASSUPDATEMESSAGE_H

#include "src/Protocol/Types/Data/game/context/MapCoordinates.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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