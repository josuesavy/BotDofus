#ifndef ORNAMENTSELECTERRORMESSAGE_H
#define ORNAMENTSELECTERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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