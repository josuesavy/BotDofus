#ifndef ACQUAINTANCESEARCHERRORMESSAGE_H
#define ACQUAINTANCESEARCHERRORMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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