#ifndef BASICWHOISMESSAGE_H
#define BASICWHOISMESSAGE_H

#include "src/protocol/types/ClassManager.h"
#include "src/protocol/types/data/common/AccountTagInformation.h"
#include "src/protocol/types/data/game/social/AbstractSocialGroupInfos.h"
#include "src/engines/io/network/utils/BooleanByteWrapper.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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
  AccountTagInformation accountTag;
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
  void _accountTagtreeFunc(Reader *input);
  void _accountIdFunc(Reader *input);
  void _playerNameFunc(Reader *input);
  void _playerIdFunc(Reader *input);
  void _areaIdFunc(Reader *input);
  void _serverIdFunc(Reader *input);
  void _originServerIdFunc(Reader *input);
  void _socialGroupstreeFunc(Reader *input);
  void _socialGroupsFunc(Reader *input);
  void _playerStateFunc(Reader *input);

  FuncTree _accountTagtree;
  FuncTree _socialGroupstree;
};

#endif // BASICWHOISMESSAGE_H