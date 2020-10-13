#ifndef EXCHANGEONHUMANVENDORREQUESTMESSAGE_H
#define EXCHANGEONHUMANVENDORREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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