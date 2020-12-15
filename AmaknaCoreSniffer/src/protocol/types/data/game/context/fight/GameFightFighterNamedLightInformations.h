#ifndef GAMEFIGHTFIGHTERNAMEDLIGHTINFORMATIONS_H
#define GAMEFIGHTFIGHTERNAMEDLIGHTINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/fight/GameFightFighterLightInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GameFightFighterNamedLightInformations : public GameFightFighterLightInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightFighterNamedLightInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightFighterNamedLightInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightFighterNamedLightInformations(FuncTree tree);
  GameFightFighterNamedLightInformations();
  bool operator==(const GameFightFighterNamedLightInformations &compared);

  QString name;

private:
  void _nameFunc(Reader *input);
};

#endif // GAMEFIGHTFIGHTERNAMEDLIGHTINFORMATIONS_H