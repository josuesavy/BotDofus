#ifndef DEBTSDELETEMESSAGE_H
#define DEBTSDELETEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class DebtsDeleteMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_DebtsDeleteMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_DebtsDeleteMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_DebtsDeleteMessage(FuncTree tree);
  DebtsDeleteMessage();

  uint reason;
  QList<double> debts;

private:
  void _reasonFunc(Reader *input);
  void _debtstreeFunc(Reader *input);
  void _debtsFunc(Reader *input);

  FuncTree _debtstree;
};

#endif // DEBTSDELETEMESSAGE_H