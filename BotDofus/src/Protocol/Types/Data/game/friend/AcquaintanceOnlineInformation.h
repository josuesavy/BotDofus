#ifndef ACQUAINTANCEONLINEINFORMATION_H
#define ACQUAINTANCEONLINEINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/character/status/PlayerStatus.h"
#include "src/protocol/types/data/game/friend/AcquaintanceInformation.h"
#include "src/protocol/types/ClassManager.h"
#include "src/engines/io/network/utils/FuncTree.h"

class AcquaintanceOnlineInformation : public AcquaintanceInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AcquaintanceOnlineInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AcquaintanceOnlineInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AcquaintanceOnlineInformation(FuncTree tree);
  AcquaintanceOnlineInformation();
  bool operator==(const AcquaintanceOnlineInformation &compared);

  double playerId;
  QString playerName;
  uint moodSmileyId;
  QSharedPointer<PlayerStatus> status;

private:
  void _playerIdFunc(Reader *input);
  void _playerNameFunc(Reader *input);
  void _moodSmileyIdFunc(Reader *input);
  void _statustreeFunc(Reader *input);

  FuncTree _statustree;
};

#endif // ACQUAINTANCEONLINEINFORMATION_H