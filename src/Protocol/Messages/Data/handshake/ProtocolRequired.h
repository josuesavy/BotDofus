#ifndef PROTOCOLREQUIRED_H
#define PROTOCOLREQUIRED_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ProtocolRequired : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ProtocolRequired(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ProtocolRequired(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ProtocolRequired(FuncTree tree);
  ProtocolRequired();

  QString version;

private:
  void _versionFunc(Reader *input);
};

#endif // PROTOCOLREQUIRED_H