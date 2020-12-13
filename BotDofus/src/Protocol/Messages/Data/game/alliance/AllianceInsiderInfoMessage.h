#ifndef ALLIANCEINSIDERINFOMESSAGE_H
#define ALLIANCEINSIDERINFOMESSAGE_H

#include "src/protocol/types/data/game/social/AllianceFactSheetInformations.h"
#include "src/protocol/types/data/game/social/GuildInsiderFactSheetInformations.h"
#include "src/protocol/types/data/game/prism/PrismSubareaEmptyInfo.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceInsiderInfoMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceInsiderInfoMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceInsiderInfoMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceInsiderInfoMessage(FuncTree tree);
  AllianceInsiderInfoMessage();

  QSharedPointer<AllianceFactSheetInformations> allianceInfos;
  QList<QSharedPointer<GuildInsiderFactSheetInformations>> guilds;
  QList<QSharedPointer<PrismSubareaEmptyInfo>> prisms;

private:
  void _allianceInfostreeFunc(Reader *input);
  void _guildstreeFunc(Reader *input);
  void _guildsFunc(Reader *input);
  void _prismstreeFunc(Reader *input);
  void _prismsFunc(Reader *input);

  FuncTree _allianceInfostree;
  FuncTree _guildstree;
  FuncTree _prismstree;
};

#endif // ALLIANCEINSIDERINFOMESSAGE_H