#ifndef PARTYMEMBERARENAINFORMATIONS_H
#define PARTYMEMBERARENAINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/roleplay/party/PartyMemberInformations.h"
#include "src/protocol/network/types/data/game/character/status/PlayerStatus.h"
#include "src/protocol/network/types/data/game/context/roleplay/party/entity/PartyEntityBaseInformation.h"
#include "src/protocol/network/types/data/game/look/EntityLook.h"
#include "src/utils/io/type/FuncTree.h"

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