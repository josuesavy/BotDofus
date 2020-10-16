#ifndef EMOTEPLAYMASSIVEMESSAGE_H
#define EMOTEPLAYMASSIVEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/emote/EmotePlayAbstractMessage.h"

class EmotePlayMassiveMessage : public EmotePlayAbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_EmotePlayMassiveMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_EmotePlayMassiveMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_EmotePlayMassiveMessage(FuncTree tree);
  EmotePlayMassiveMessage();

  QList<double> actorIds;

private:
  void _actorIdstreeFunc(Reader *input);
  void _actorIdsFunc(Reader *input);

  FuncTree _actorIdstree;
};

#endif // EMOTEPLAYMASSIVEMESSAGE_H