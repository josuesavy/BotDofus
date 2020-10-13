#ifndef PARTYMEMBERARENAINFORMATIONS_H
#define PARTYMEMBERARENAINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/party/PartyMemberInformations.h"
#include "src/Protocol/Types/Data/game/look/EntityLook.h"
#include "src/Protocol/Types/Data/game/character/status/PlayerStatus.h"
#include "src/Protocol/Types/Data/game/context/roleplay/party/entity/PartyEntityBaseInformation.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class PartyMemberArenaInformations : public PartyMemberInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyMemberArenaInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyMemberArenaInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyMemberArenaInformations(FuncTree tree);
  PartyMemberArenaInformations();
  bool operator==(const PartyMemberArenaInformations &compared);

  uint rank;

private:
  void _rankFunc(Reader *input);
};

#endif // PARTYMEMBERARENAINFORMATIONS_H