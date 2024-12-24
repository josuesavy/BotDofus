#ifndef CONFIRMATIONOFLISTENINGTAXCOLLECTORUPDATESMESSAGE_H
#define CONFIRMATIONOFLISTENINGTAXCOLLECTORUPDATESMESSAGE_H

#include "src/protocol/network/types/data/game/collector/tax/TaxCollectorInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ConfirmationOfListeningTaxCollectorUpdatesMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ConfirmationOfListeningTaxCollectorUpdatesMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ConfirmationOfListeningTaxCollectorUpdatesMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ConfirmationOfListeningTaxCollectorUpdatesMessage(FuncTree tree);
  ConfirmationOfListeningTaxCollectorUpdatesMessage();

  QSharedPointer<TaxCollectorInformations> information;

private:
  void _informationtreeFunc(Reader *input);

  FuncTree _informationtree;
};

#endif // CONFIRMATIONOFLISTENINGTAXCOLLECTORUPDATESMESSAGE_H