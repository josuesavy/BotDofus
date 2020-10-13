#ifndef GUILDFACTSMESSAGE_H
#define GUILDFACTSMESSAGE_H

#include "src/Protocol/Types/Data/game/social/GuildFactSheetInformations.h"
#include "src/Protocol/Types/Data/game/character/CharacterMinimalGuildPublicInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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