#ifndef GAMEFIGHTFIGHTERNAMEDLIGHTINFORMATIONS_H
#define GAMEFIGHTFIGHTERNAMEDLIGHTINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/fight/GameFightFighterLightInformations.h"
#include "src/utils/io/type/FuncTree.h"

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