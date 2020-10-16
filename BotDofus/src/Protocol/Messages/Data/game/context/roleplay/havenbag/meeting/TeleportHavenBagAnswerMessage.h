#ifndef TELEPORTHAVENBAGANSWERMESSAGE_H
#define TELEPORTHAVENBAGANSWERMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class TeleportHavenBagAnswerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TeleportHavenBagAnswerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TeleportHavenBagAnswerMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TeleportHavenBagAnswerMessage(FuncTree tree);
  TeleportHavenBagAnswerMessage();

  bool accept;

private:
  void _acceptFunc(Reader *input);
};

#endif // TELEPORTHAVENBAGANSWERMESSAGE_H