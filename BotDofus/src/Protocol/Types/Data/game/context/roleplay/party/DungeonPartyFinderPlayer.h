#ifndef DUNGEONPARTYFINDERPLAYER_H
#define DUNGEONPARTYFINDERPLAYER_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Enums/Data/PlayableBreedEnum.h"

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