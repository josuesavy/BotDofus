#ifndef EXCHANGESTARTOKMOUNTMESSAGE_H
#define EXCHANGESTARTOKMOUNTMESSAGE_H

#include "src/Protocol/Types/Data/game/mount/MountClientData.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/exchanges/ExchangeStartOkMountWithOutPaddockMessage.h"

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