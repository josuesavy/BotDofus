#ifndef HAVENBAGROOMUPDATEMESSAGE_H
#define HAVENBAGROOMUPDATEMESSAGE_H

#include "src/protocol/types/data/game/havenbag/HavenBagRoomPreviewInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class HavenBagRoomUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HavenBagRoomUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HavenBagRoomUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HavenBagRoomUpdateMessage(FuncTree tree);
  HavenBagRoomUpdateMessage();

  uint action;
  QList<HavenBagRoomPreviewInformation> roomsPreview;

private:
  void _actionFunc(Reader *input);
  void _roomsPreviewtreeFunc(Reader *input);
  void _roomsPreviewFunc(Reader *input);

  FuncTree _roomsPreviewtree;
};

#endif // HAVENBAGROOMUPDATEMESSAGE_H