#ifndef DEBTSUPDATEMESSAGE_H
#define DEBTSUPDATEMESSAGE_H

#include "src/Protocol/Types/Data/game/character/debt/DebtInformation.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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