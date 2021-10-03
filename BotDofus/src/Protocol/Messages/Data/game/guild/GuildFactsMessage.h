#ifndef GUILDFACTSMESSAGE_H
#define GUILDFACTSMESSAGE_H

#include "src/protocol/types/data/game/social/GuildFactSheetInformations.h"
#include "src/protocol/types/data/game/character/CharacterMinimalGuildPublicInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"

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
  uint nbTaxCollectors;
  QList<CharacterMinimalGuildPublicInformations> members;

private:
  void _infostreeFunc(Reader *input);
  void _creationDateFunc(Reader *input);
  void _nbTaxCollectorsFunc(Reader *input);
  void _memberstreeFunc(Reader *input);
  void _membersFunc(Reader *input);

  FuncTree _infostree;
  FuncTree _memberstree;
};

#endif // GUILDFACTSMESSAGE_H