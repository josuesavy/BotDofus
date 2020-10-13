#ifndef ACQUAINTANCESEARCHMESSAGE_H
#define ACQUAINTANCESEARCHMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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

  QString nickname;

private:
  void _nicknameFunc(Reader *input);
};

#endif // ACQUAINTANCESEARCHMESSAGE_H