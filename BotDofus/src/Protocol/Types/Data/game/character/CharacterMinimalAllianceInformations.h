#ifndef CHARACTERMINIMALALLIANCEINFORMATIONS_H
#define CHARACTERMINIMALALLIANCEINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/BasicAllianceInformations.h"
#include "src/Protocol/Types/Data/game/character/CharacterMinimalGuildInformations.h"
#include "src/Protocol/Types/Data/game/look/EntityLook.h"
#include "src/Protocol/Types/Data/game/context/roleplay/BasicGuildInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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