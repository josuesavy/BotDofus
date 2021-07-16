#ifndef ACQUAINTANCESEARCHMESSAGE_H
#define ACQUAINTANCESEARCHMESSAGE_H

#include "src/protocol/types/data/common/AccountTagInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AcquaintanceSearchMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AcquaintanceSearchMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AcquaintanceSearchMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AcquaintanceSearchMessage(FuncTree tree);
  AcquaintanceSearchMessage();

  AccountTagInformation tag;

private:
  void _tagtreeFunc(Reader *input);

  FuncTree _tagtree;
};

#endif // ACQUAINTANCESEARCHMESSAGE_H