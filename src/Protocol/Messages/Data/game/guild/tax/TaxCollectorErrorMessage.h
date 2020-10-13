#ifndef TAXCOLLECTORERRORMESSAGE_H
#define TAXCOLLECTORERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class TaxCollectorErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorErrorMessage(FuncTree tree);
  TaxCollectorErrorMessage();

  int reason;

private:
  void _reasonFunc(Reader *input);
};

#endif // TAXCOLLECTORERRORMESSAGE_H