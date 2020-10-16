#ifndef GAMEROLEPLAYGROUPMONSTERWAVEINFORMATIONS_H
#define GAMEROLEPLAYGROUPMONSTERWAVEINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GroupMonsterStaticInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GameRolePlayGroupMonsterInformations.h"
#include "src/Protocol/Types/Data/game/context/EntityDispositionInformations.h"
#include "src/Protocol/Types/Data/game/look/EntityLook.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class GameRolePlayGroupMonsterWaveInformations : public GameRolePlayGroupMonsterInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayGroupMonsterWaveInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayGroupMonsterWaveInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayGroupMonsterWaveInformations(FuncTree tree);
  GameRolePlayGroupMonsterWaveInformations();
  bool operator==(const GameRolePlayGroupMonsterWaveInformations &compared);

  uint nbWaves;
  QList<QSharedPointer<GroupMonsterStaticInformations>> alternatives;

private:
  void _nbWavesFunc(Reader *input);
  void _alternativestreeFunc(Reader *input);
  void _alternativesFunc(Reader *input);

  FuncTree _alternativestree;
};

#endif // GAMEROLEPLAYGROUPMONSTERWAVEINFORMATIONS_H