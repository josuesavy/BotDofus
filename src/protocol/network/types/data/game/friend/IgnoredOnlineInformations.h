#ifndef IGNOREDONLINEINFORMATIONS_H
#define IGNOREDONLINEINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/friend/IgnoredInformations.h"
#include "src/protocol/enums/data/PlayableBreedEnum.h"
#include "src/protocol/types/data/common/AccountTagInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"

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