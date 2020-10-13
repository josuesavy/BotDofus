#ifndef ACQUAINTANCESEARCHERRORMESSAGE_H
#define ACQUAINTANCESEARCHERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class AcquaintanceSearchErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AcquaintanceSearchErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AcquaintanceSearchErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AcquaintanceSearchErrorMessage(FuncTree tree);
  AcquaintanceSearchErrorMessage();

  uint reason;

private:
  void _reasonFunc(Reader *input);
};

#endif // ACQUAINTANCESEARCHERRORMESSAGE_H