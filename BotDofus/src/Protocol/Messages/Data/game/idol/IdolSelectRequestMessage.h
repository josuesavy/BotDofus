#ifndef IDOLSELECTREQUESTMESSAGE_H
#define IDOLSELECTREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Engines/IO/Network/Utils/BooleanByteWrapper.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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