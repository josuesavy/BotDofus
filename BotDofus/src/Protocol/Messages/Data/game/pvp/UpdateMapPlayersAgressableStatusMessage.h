#ifndef UPDATEMAPPLAYERSAGRESSABLESTATUSMESSAGE_H
#define UPDATEMAPPLAYERSAGRESSABLESTATUSMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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

  QList<double> playerIds;
  QList<uint> enable;

private:
  void _playerIdstreeFunc(Reader *input);
  void _playerIdsFunc(Reader *input);
  void _enabletreeFunc(Reader *input);
  void _enableFunc(Reader *input);

  FuncTree _playerIdstree;
  FuncTree _enabletree;
};

#endif // UPDATEMAPPLAYERSAGRESSABLESTATUSMESSAGE_H