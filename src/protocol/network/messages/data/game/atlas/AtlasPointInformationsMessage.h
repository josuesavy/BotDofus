#ifndef ATLASPOINTINFORMATIONSMESSAGE_H
#define ATLASPOINTINFORMATIONSMESSAGE_H

#include "src/protocol/network/types/data/game/context/roleplay/AtlasPointsInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AtlasPointInformationsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AtlasPointInformationsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AtlasPointInformationsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AtlasPointInformationsMessage(FuncTree tree);
  AtlasPointInformationsMessage();

  QSharedPointer<AtlasPointsInformations> type;

private:
  void _typetreeFunc(Reader *input);

  FuncTree _typetree;
};

#endif // ATLASPOINTINFORMATIONSMESSAGE_H