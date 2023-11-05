#ifndef IDOLSELECTEDMESSAGE_H
#define IDOLSELECTEDMESSAGE_H

#include "src/engines/io/network/utils/BooleanByteWrapper.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class IdolSelectedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IdolSelectedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IdolSelectedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IdolSelectedMessage(FuncTree tree);
  IdolSelectedMessage();

  uint idolId;
  bool activate;
  bool party;

private:
  void deserializeByteBoxes(Reader *input);
  void _idolIdFunc(Reader *input);
};

#endif // IDOLSELECTEDMESSAGE_H