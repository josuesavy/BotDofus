#ifndef DEBTSUPDATEMESSAGE_H
#define DEBTSUPDATEMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/character/debt/DebtInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class DebtsUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_DebtsUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_DebtsUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_DebtsUpdateMessage(FuncTree tree);
  DebtsUpdateMessage();

  uint action;
  QList<QSharedPointer<DebtInformation>> debts;

private:
  void _actionFunc(Reader *input);
  void _debtstreeFunc(Reader *input);
  void _debtsFunc(Reader *input);

  FuncTree _debtstree;
};

#endif // DEBTSUPDATEMESSAGE_H