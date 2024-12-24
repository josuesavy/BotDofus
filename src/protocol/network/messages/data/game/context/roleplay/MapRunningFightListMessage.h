#ifndef MAPRUNNINGFIGHTLISTMESSAGE_H
#define MAPRUNNINGFIGHTLISTMESSAGE_H

#include "src/protocol/network/types/data/game/context/fight/FightExternalInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class MapRunningFightListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MapRunningFightListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MapRunningFightListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MapRunningFightListMessage(FuncTree tree);
  MapRunningFightListMessage();

  QList<FightExternalInformations> fights;

private:
  void _fightstreeFunc(Reader *input);
  void _fightsFunc(Reader *input);

  FuncTree _fightstree;
};

#endif // MAPRUNNINGFIGHTLISTMESSAGE_H