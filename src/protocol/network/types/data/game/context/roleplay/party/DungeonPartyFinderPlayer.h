#ifndef DUNGEONPARTYFINDERPLAYER_H
#define DUNGEONPARTYFINDERPLAYER_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/enums/data/PlayableBreedEnum.h"
#include "src/utils/io/type/FuncTree.h"

class DungeonPartyFinderPlayer : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_DungeonPartyFinderPlayer(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_DungeonPartyFinderPlayer(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_DungeonPartyFinderPlayer(FuncTree tree);
  DungeonPartyFinderPlayer();
  bool operator==(const DungeonPartyFinderPlayer &compared);

  double playerId;
  QString playerName;
  int breed;
  bool sex;
  uint level;

private:
  void _playerIdFunc(Reader *input);
  void _playerNameFunc(Reader *input);
  void _breedFunc(Reader *input);
  void _sexFunc(Reader *input);
  void _levelFunc(Reader *input);
};

#endif // DUNGEONPARTYFINDERPLAYER_H