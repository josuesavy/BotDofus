#ifndef IDOLSELECTERRORMESSAGE_H
#define IDOLSELECTERRORMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/engines/io/network/utils/BooleanByteWrapper.h"
#include "src/protocol/messages/AbstractMessage.h"

class IdolSelectErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IdolSelectErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IdolSelectErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IdolSelectErrorMessage(FuncTree tree);
  IdolSelectErrorMessage();

  uint reason;
  uint idolId;
  bool activate;
  bool party;

private:
  void deserializeByteBoxes(Reader *input);
  void _reasonFunc(Reader *input);
  void _idolIdFunc(Reader *input);
};

#endif // IDOLSELECTERRORMESSAGE_H