#ifndef HUMANOPTIONORNAMENT_H
#define HUMANOPTIONORNAMENT_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/HumanOption.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class HumanOptionOrnament : public HumanOption
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HumanOptionOrnament(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HumanOptionOrnament(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HumanOptionOrnament(FuncTree tree);
  HumanOptionOrnament();
  bool operator==(const HumanOptionOrnament &compared);

  uint ornamentId;
  uint level;
  int leagueId;
  int ladderPosition;

private:
  void _ornamentIdFunc(Reader *input);
  void _levelFunc(Reader *input);
  void _leagueIdFunc(Reader *input);
  void _ladderPositionFunc(Reader *input);
};

#endif // HUMANOPTIONORNAMENT_H