#ifndef BASICWHOISMESSAGE_H
#define BASICWHOISMESSAGE_H

#include "src/Protocol/Types/Data/game/social/AbstractSocialGroupInfos.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Engines/IO/Network/Utils/BooleanByteWrapper.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class BasicWhoIsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BasicWhoIsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BasicWhoIsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BasicWhoIsMessage(FuncTree tree);
  BasicWhoIsMessage();

  bool self;
  int position;
  QString accountNickname;
  uint accountId;
  QString playerName;
  double playerId;
  int areaId;
  int serverId;
  int originServerId;
  QList<QSharedPointer<AbstractSocialGroupInfos>> socialGroups;
  bool verbose;
  uint playerState;

private:
  void deserializeByteBoxes(Reader *input);
  void _positionFunc(Reader *input);
  void _accountNicknameFunc(Reader *input);
  void _accountIdFunc(Reader *input);
  void _playerNameFunc(Reader *input);
  void _playerIdFunc(Reader *input);
  void _areaIdFunc(Reader *input);
  void _serverIdFunc(Reader *input);
  void _originServerIdFunc(Reader *input);
  void _socialGroupstreeFunc(Reader *input);
  void _socialGroupsFunc(Reader *input);
  void _playerStateFunc(Reader *input);

  FuncTree _socialGroupstree;
};

#endif // BASICWHOISMESSAGE_H