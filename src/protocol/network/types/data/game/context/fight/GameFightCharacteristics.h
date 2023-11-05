#ifndef GAMEFIGHTCHARACTERISTICS_H
#define GAMEFIGHTCHARACTERISTICS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/character/characteristic/CharacterCharacteristics.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GameFightCharacteristics : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightCharacteristics(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightCharacteristics(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightCharacteristics(FuncTree tree);
  GameFightCharacteristics();
  bool operator==(const GameFightCharacteristics &compared);

  CharacterCharacteristics characteristics;
  double summoner;
  bool summoned;
  uint invisibilityState;

private:
  void _characteristicstreeFunc(Reader *input);
  void _summonerFunc(Reader *input);
  void _summonedFunc(Reader *input);
  void _invisibilityStateFunc(Reader *input);

  FuncTree _characteristicstree;
};

#endif // GAMEFIGHTCHARACTERISTICS_H