#ifndef SOCIALMEMBER_H
#define SOCIALMEMBER_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/character/status/PlayerStatus.h"
#include "src/protocol/network/types/data/game/character/CharacterMinimalInformations.h"
#include "src/protocol/network/types/ClassManager.h"
#include "src/utils/io/type/FuncTree.h"

class SocialMember : public CharacterMinimalInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SocialMember(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SocialMember(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SocialMember(FuncTree tree);
  SocialMember();
  bool operator==(const SocialMember &compared);

  int breed;
  bool sex;
  uint connected;
  uint hoursSinceLastConnection;
  uint accountId;
  QSharedPointer<PlayerStatus> status;
  int rankId;
  double enrollmentDate;

private:
  void _breedFunc(Reader *input);
  void _sexFunc(Reader *input);
  void _connectedFunc(Reader *input);
  void _hoursSinceLastConnectionFunc(Reader *input);
  void _accountIdFunc(Reader *input);
  void _statustreeFunc(Reader *input);
  void _rankIdFunc(Reader *input);
  void _enrollmentDateFunc(Reader *input);

  FuncTree _statustree;
};

#endif // SOCIALMEMBER_H