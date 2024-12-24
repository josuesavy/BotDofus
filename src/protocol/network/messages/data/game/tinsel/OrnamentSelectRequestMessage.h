#ifndef ORNAMENTSELECTREQUESTMESSAGE_H
#define ORNAMENTSELECTREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class OrnamentSelectRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_OrnamentSelectRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_OrnamentSelectRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_OrnamentSelectRequestMessage(FuncTree tree);
  OrnamentSelectRequestMessage();

  uint ornamentId;

private:
  void _ornamentIdFunc(Reader *input);
};

#endif // ORNAMENTSELECTREQUESTMESSAGE_H