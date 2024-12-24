#ifndef LISTMAPNPCSQUESTSTATUSUPDATEMESSAGE_H
#define LISTMAPNPCSQUESTSTATUSUPDATEMESSAGE_H

#include "src/protocol/network/types/data/game/context/roleplay/npc/MapNpcQuestInfo.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ListMapNpcsQuestStatusUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ListMapNpcsQuestStatusUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ListMapNpcsQuestStatusUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ListMapNpcsQuestStatusUpdateMessage(FuncTree tree);
  ListMapNpcsQuestStatusUpdateMessage();

  QList<MapNpcQuestInfo> mapInfo;

private:
  void _mapInfotreeFunc(Reader *input);
  void _mapInfoFunc(Reader *input);

  FuncTree _mapInfotree;
};

#endif // LISTMAPNPCSQUESTSTATUSUPDATEMESSAGE_H