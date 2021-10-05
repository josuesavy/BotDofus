#ifndef OBJECTERRORMESSAGE_H
#define OBJECTERRORMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ObjectErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectErrorMessage(FuncTree tree);
  ObjectErrorMessage();

  int reason;

private:
  void _reasonFunc(Reader *input);
};

#endif // OBJECTERRORMESSAGE_H