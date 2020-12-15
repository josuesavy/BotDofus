#ifndef EXCHANGEONHUMANVENDORREQUESTMESSAGE_H
#define EXCHANGEONHUMANVENDORREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeOnHumanVendorRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeOnHumanVendorRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeOnHumanVendorRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeOnHumanVendorRequestMessage(FuncTree tree);
  ExchangeOnHumanVendorRequestMessage();

  double humanVendorId;
  uint humanVendorCell;

private:
  void _humanVendorIdFunc(Reader *input);
  void _humanVendorCellFunc(Reader *input);
};

#endif // EXCHANGEONHUMANVENDORREQUESTMESSAGE_H