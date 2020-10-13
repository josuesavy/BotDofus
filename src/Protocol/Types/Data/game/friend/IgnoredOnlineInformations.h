#ifndef IGNOREDONLINEINFORMATIONS_H
#define IGNOREDONLINEINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/friend/IgnoredInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Enums/Data/PlayableBreedEnum.h"

class IgnoredOnlineInformations : public IgnoredInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IgnoredOnlineInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IgnoredOnlineInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IgnoredOnlineInformations(FuncTree tree);
  IgnoredOnlineInformations();
  bool operator==(const IgnoredOnlineInformations &compared);

  double playerId;
  QString playerName;
  int breed;
  bool sex;

private:
  void _playerIdFunc(Reader *input);
  void _playerNameFunc(Reader *input);
  void _breedFunc(Reader *input);
  void _sexFunc(Reader *input);
};

#endif // IGNOREDONLINEINFORMATIONS_H