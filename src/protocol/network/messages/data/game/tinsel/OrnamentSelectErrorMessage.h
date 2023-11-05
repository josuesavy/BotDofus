#ifndef ORNAMENTSELECTERRORMESSAGE_H
#define ORNAMENTSELECTERRORMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class OrnamentSelectErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_OrnamentSelectErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_OrnamentSelectErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_OrnamentSelectErrorMessage(FuncTree tree);
  OrnamentSelectErrorMessage();

  uint reason;

private:
  void _reasonFunc(Reader *input);
};

#endif // ORNAMENTSELECTERRORMESSAGE_H