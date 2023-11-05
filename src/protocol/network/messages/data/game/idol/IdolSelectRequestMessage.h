#ifndef IDOLSELECTREQUESTMESSAGE_H
#define IDOLSELECTREQUESTMESSAGE_H

#include "src/engines/io/network/utils/BooleanByteWrapper.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class IdolSelectRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IdolSelectRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IdolSelectRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IdolSelectRequestMessage(FuncTree tree);
  IdolSelectRequestMessage();

  uint idolId;
  bool activate;
  bool party;

private:
  void deserializeByteBoxes(Reader *input);
  void _idolIdFunc(Reader *input);
};

#endif // IDOLSELECTREQUESTMESSAGE_H