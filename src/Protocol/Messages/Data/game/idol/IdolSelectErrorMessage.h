#ifndef IDOLSELECTERRORMESSAGE_H
#define IDOLSELECTERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Engines/IO/Network/Utils/BooleanByteWrapper.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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