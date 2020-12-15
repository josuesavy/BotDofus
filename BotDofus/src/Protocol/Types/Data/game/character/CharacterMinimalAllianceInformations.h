#ifndef CHARACTERMINIMALALLIANCEINFORMATIONS_H
#define CHARACTERMINIMALALLIANCEINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/BasicAllianceInformations.h"
#include "src/protocol/types/data/game/character/CharacterMinimalGuildInformations.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/protocol/types/data/game/context/roleplay/BasicGuildInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

class CharacterMinimalAllianceInformations : public CharacterMinimalGuildInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterMinimalAllianceInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterMinimalAllianceInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterMinimalAllianceInformations(FuncTree tree);
  CharacterMinimalAllianceInformations();
  bool operator==(const CharacterMinimalAllianceInformations &compared);

  QSharedPointer<BasicAllianceInformations> alliance;

private:
  void _alliancetreeFunc(Reader *input);

  FuncTree _alliancetree;
};

#endif // CHARACTERMINIMALALLIANCEINFORMATIONS_H