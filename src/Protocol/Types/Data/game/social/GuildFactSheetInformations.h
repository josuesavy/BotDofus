#ifndef GUILDFACTSHEETINFORMATIONS_H
#define GUILDFACTSHEETINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GuildInformations.h"
#include "src/Protocol/Types/Data/game/guild/GuildEmblem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class GuildFactSheetInformations : public GuildInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildFactSheetInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildFactSheetInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildFactSheetInformations(FuncTree tree);
  GuildFactSheetInformations();
  bool operator==(const GuildFactSheetInformations &compared);

  double leaderId;
  uint nbMembers;

private:
  void _leaderIdFunc(Reader *input);
  void _nbMembersFunc(Reader *input);
};

#endif // GUILDFACTSHEETINFORMATIONS_H