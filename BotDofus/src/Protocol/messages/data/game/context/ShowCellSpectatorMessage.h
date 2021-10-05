#ifndef SHOWCELLSPECTATORMESSAGE_H
#define SHOWCELLSPECTATORMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/ShowCellMessage.h"

class ShowCellSpectatorMessage : public ShowCellMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ShowCellSpectatorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ShowCellSpectatorMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ShowCellSpectatorMessage(FuncTree tree);
  ShowCellSpectatorMessage();

  QString playerName;

private:
  void _playerNameFunc(Reader *input);
};

#endif // SHOWCELLSPECTATORMESSAGE_H