#ifndef ERRORMAPNOTFOUNDMESSAGE_H
#define ERRORMAPNOTFOUNDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ErrorMapNotFoundMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ErrorMapNotFoundMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ErrorMapNotFoundMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ErrorMapNotFoundMessage(FuncTree tree);
  ErrorMapNotFoundMessage();

  double mapId;

private:
  void _mapIdFunc(Reader *input);
};

#endif // ERRORMAPNOTFOUNDMESSAGE_H