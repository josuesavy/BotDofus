#ifndef GAMEROLEPLAYGROUPMONSTERWAVEINFORMATIONS_H
#define GAMEROLEPLAYGROUPMONSTERWAVEINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/GroupMonsterStaticInformations.h"
#include "src/protocol/types/data/game/context/roleplay/GameRolePlayGroupMonsterInformations.h"
#include "src/protocol/types/data/game/context/EntityDispositionInformations.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/protocol/types/ClassManager.h"
#include "src/engines/io/network/utils/FuncTree.h"

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