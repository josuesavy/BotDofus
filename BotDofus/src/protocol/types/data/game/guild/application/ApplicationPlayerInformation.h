#ifndef APPLICATIONPLAYERINFORMATION_H
#define APPLICATIONPLAYERINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/character/status/PlayerStatus.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/enums/data/PlayableBreedEnum.h"

class ApplicationPlayerInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ApplicationPlayerInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ApplicationPlayerInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ApplicationPlayerInformation(FuncTree tree);
  ApplicationPlayerInformation();
  bool operator==(const ApplicationPlayerInformation &compared);

  double playerId;
  QString playerName;
  int breed;
  bool sex;
  uint level;
  uint accountId;
  QString accountTag;
  QString accountNickname;
  QSharedPointer<PlayerStatus> status;

private:
  void _playerIdFunc(Reader *input);
  void _playerNameFunc(Reader *input);
  void _breedFunc(Reader *input);
  void _sexFunc(Reader *input);
  void _levelFunc(Reader *input);
  void _accountIdFunc(Reader *input);
  void _accountTagFunc(Reader *input);
  void _accountNicknameFunc(Reader *input);
  void _statustreeFunc(Reader *input);

  FuncTree _statustree;
};

#endif // APPLICATIONPLAYERINFORMATION_H