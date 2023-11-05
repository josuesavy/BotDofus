#ifndef AGRESSABLESTATUSMESSAGE_H
#define AGRESSABLESTATUSMESSAGE_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class AgressableStatusMessage : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AgressableStatusMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AgressableStatusMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AgressableStatusMessage(FuncTree tree);
  AgressableStatusMessage();
  bool operator==(const AgressableStatusMessage &compared);

  double playerId;
  uint enable;
  int roleAvAId;
  int pictoScore;

private:
  void _playerIdFunc(Reader *input);
  void _enableFunc(Reader *input);
  void _roleAvAIdFunc(Reader *input);
  void _pictoScoreFunc(Reader *input);
};

#endif // AGRESSABLESTATUSMESSAGE_H