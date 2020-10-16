#ifndef GAMEDATAPADDOCKOBJECTADDMESSAGE_H
#define GAMEDATAPADDOCKOBJECTADDMESSAGE_H

#include "src/Protocol/Types/Data/game/paddock/PaddockItem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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