#ifndef GAMEDATAPADDOCKOBJECTADDMESSAGE_H
#define GAMEDATAPADDOCKOBJECTADDMESSAGE_H

#include "src/protocol/network/types/data/game/paddock/PaddockItem.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameDataPaddockObjectAddMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameDataPaddockObjectAddMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameDataPaddockObjectAddMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameDataPaddockObjectAddMessage(FuncTree tree);
  GameDataPaddockObjectAddMessage();

  PaddockItem paddockItemDescription;

private:
  void _paddockItemDescriptiontreeFunc(Reader *input);

  FuncTree _paddockItemDescriptiontree;
};

#endif // GAMEDATAPADDOCKOBJECTADDMESSAGE_H