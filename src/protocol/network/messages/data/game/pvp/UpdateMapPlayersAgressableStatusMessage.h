#ifndef UPDATEMAPPLAYERSAGRESSABLESTATUSMESSAGE_H
#define UPDATEMAPPLAYERSAGRESSABLESTATUSMESSAGE_H

#include "src/protocol/network/types/data/game/pvp/AgressableStatusMessage.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class UpdateMapPlayersAgressableStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_UpdateMapPlayersAgressableStatusMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_UpdateMapPlayersAgressableStatusMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_UpdateMapPlayersAgressableStatusMessage(FuncTree tree);
  UpdateMapPlayersAgressableStatusMessage();

  QList<AgressableStatusMessage> playerAvAMessages;

private:
  void _playerAvAMessagestreeFunc(Reader *input);
  void _playerAvAMessagesFunc(Reader *input);

  FuncTree _playerAvAMessagestree;
};

#endif // UPDATEMAPPLAYERSAGRESSABLESTATUSMESSAGE_H