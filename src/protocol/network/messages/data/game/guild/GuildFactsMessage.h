#ifndef GUILDFACTSMESSAGE_H
#define GUILDFACTSMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/character/CharacterMinimalSocialPublicInformations.h"
#include "src/protocol/network/types/data/game/social/GuildFactSheetInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildFactsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildFactsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildFactsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildFactsMessage(FuncTree tree);
  GuildFactsMessage();

  QSharedPointer<GuildFactSheetInformations> infos;
  uint creationDate;
  QList<CharacterMinimalSocialPublicInformations> members;

private:
  void _infostreeFunc(Reader *input);
  void _creationDateFunc(Reader *input);
  void _memberstreeFunc(Reader *input);
  void _membersFunc(Reader *input);

  FuncTree _infostree;
  FuncTree _memberstree;
};

#endif // GUILDFACTSMESSAGE_H