#ifndef EXCHANGESTARTOKMOUNTWITHOUTPADDOCKMESSAGE_H
#define EXCHANGESTARTOKMOUNTWITHOUTPADDOCKMESSAGE_H

#include "src/protocol/network/types/data/game/mount/MountClientData.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeStartOkMountWithOutPaddockMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeStartOkMountWithOutPaddockMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeStartOkMountWithOutPaddockMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeStartOkMountWithOutPaddockMessage(FuncTree tree);
  ExchangeStartOkMountWithOutPaddockMessage();

  QList<QSharedPointer<MountClientData>> stabledMountsDescription;

private:
  void _stabledMountsDescriptiontreeFunc(Reader *input);
  void _stabledMountsDescriptionFunc(Reader *input);

  FuncTree _stabledMountsDescriptiontree;
};

#endif // EXCHANGESTARTOKMOUNTWITHOUTPADDOCKMESSAGE_H