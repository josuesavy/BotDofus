#ifndef ACCOUNTHOUSEMESSAGE_H
#define ACCOUNTHOUSEMESSAGE_H

#include "src/protocol/network/types/data/game/house/AccountHouseInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AccountHouseMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AccountHouseMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AccountHouseMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AccountHouseMessage(FuncTree tree);
  AccountHouseMessage();

  QList<QSharedPointer<AccountHouseInformations>> houses;

private:
  void _housestreeFunc(Reader *input);
  void _housesFunc(Reader *input);

  FuncTree _housestree;
};

#endif // ACCOUNTHOUSEMESSAGE_H