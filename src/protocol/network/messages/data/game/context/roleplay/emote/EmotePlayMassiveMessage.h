#ifndef EMOTEPLAYMASSIVEMESSAGE_H
#define EMOTEPLAYMASSIVEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/context/roleplay/emote/EmotePlayAbstractMessage.h"

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