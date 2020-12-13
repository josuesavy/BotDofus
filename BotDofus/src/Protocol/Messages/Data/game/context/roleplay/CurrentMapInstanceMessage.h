#ifndef CURRENTMAPINSTANCEMESSAGE_H
#define CURRENTMAPINSTANCEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/CurrentMapMessage.h"

class CurrentMapInstanceMessage : public CurrentMapMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CurrentMapInstanceMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CurrentMapInstanceMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CurrentMapInstanceMessage(FuncTree tree);
  CurrentMapInstanceMessage();

  double instantiatedMapId;

private:
  void _instantiatedMapIdFunc(Reader *input);
};

#endif // CURRENTMAPINSTANCEMESSAGE_H