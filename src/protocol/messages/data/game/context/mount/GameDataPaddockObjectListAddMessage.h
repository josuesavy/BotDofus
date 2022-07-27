#ifndef GAMEDATAPADDOCKOBJECTLISTADDMESSAGE_H
#define GAMEDATAPADDOCKOBJECTLISTADDMESSAGE_H

#include "src/protocol/types/data/game/paddock/PaddockItem.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameDataPaddockObjectListAddMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameDataPaddockObjectListAddMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameDataPaddockObjectListAddMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameDataPaddockObjectListAddMessage(FuncTree tree);
  GameDataPaddockObjectListAddMessage();

  QList<PaddockItem> paddockItemDescription;

private:
  void _paddockItemDescriptiontreeFunc(Reader *input);
  void _paddockItemDescriptionFunc(Reader *input);

  FuncTree _paddockItemDescriptiontree;
};

#endif // GAMEDATAPADDOCKOBJECTLISTADDMESSAGE_H