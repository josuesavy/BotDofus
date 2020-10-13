#ifndef GAMEFIGHTFIGHTERLIGHTINFORMATIONS_H
#define GAMEFIGHTFIGHTERLIGHTINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/BooleanByteWrapper.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class GameFightFighterLightInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightFighterLightInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightFighterLightInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightFighterLightInformations(FuncTree tree);
  GameFightFighterLightInformations();
  bool operator==(const GameFightFighterLightInformations &compared);

  double id;
  uint wave;
  uint level;
  int breed;
  bool sex;
  bool alive;

private:
  void deserializeByteBoxes(Reader *input);
  void _idFunc(Reader *input);
  void _waveFunc(Reader *input);
  void _levelFunc(Reader *input);
  void _breedFunc(Reader *input);
};

#endif // GAMEFIGHTFIGHTERLIGHTINFORMATIONS_H