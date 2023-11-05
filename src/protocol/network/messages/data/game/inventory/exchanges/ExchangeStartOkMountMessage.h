#ifndef EXCHANGESTARTOKMOUNTMESSAGE_H
#define EXCHANGESTARTOKMOUNTMESSAGE_H

#include "src/protocol/types/data/game/mount/MountClientData.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/inventory/exchanges/ExchangeStartOkMountWithOutPaddockMessage.h"

class ExchangeStartOkMountMessage : public ExchangeStartOkMountWithOutPaddockMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeStartOkMountMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeStartOkMountMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeStartOkMountMessage(FuncTree tree);
  ExchangeStartOkMountMessage();

  QList<QSharedPointer<MountClientData>> paddockedMountsDescription;

private:
  void _paddockedMountsDescriptiontreeFunc(Reader *input);
  void _paddockedMountsDescriptionFunc(Reader *input);

  FuncTree _paddockedMountsDescriptiontree;
};

#endif // EXCHANGESTARTOKMOUNTMESSAGE_H