#ifndef GUILDAPPLICATIONISANSWEREDMESSAGE_H
#define GUILDAPPLICATIONISANSWEREDMESSAGE_H

#include "src/protocol/network/types/data/game/context/roleplay/GuildInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildApplicationIsAnsweredMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildApplicationIsAnsweredMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildApplicationIsAnsweredMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildApplicationIsAnsweredMessage(FuncTree tree);
  GuildApplicationIsAnsweredMessage();

  bool accepted;
  QSharedPointer<GuildInformations> guildInformation;

private:
  void _acceptedFunc(Reader *input);
  void _guildInformationtreeFunc(Reader *input);

  FuncTree _guildInformationtree;
};

#endif // GUILDAPPLICATIONISANSWEREDMESSAGE_H