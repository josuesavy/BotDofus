#ifndef CHECKINTEGRITYMESSAGE_H
#define CHECKINTEGRITYMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class CheckIntegrityMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CheckIntegrityMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CheckIntegrityMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CheckIntegrityMessage(FuncTree tree);
  CheckIntegrityMessage();

  QList<int> data;

private:
  void _datatreeFunc(Reader *input);
  void _dataFunc(Reader *input);

  FuncTree _datatree;
};

#endif // CHECKINTEGRITYMESSAGE_H