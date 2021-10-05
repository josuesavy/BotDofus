#ifndef ERRORMAPNOTFOUNDMESSAGE_H
#define ERRORMAPNOTFOUNDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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