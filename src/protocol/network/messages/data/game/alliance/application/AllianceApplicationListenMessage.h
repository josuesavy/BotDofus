#ifndef ALLIANCEAPPLICATIONLISTENMESSAGE_H
#define ALLIANCEAPPLICATIONLISTENMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceApplicationListenMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceApplicationListenMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceApplicationListenMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceApplicationListenMessage(FuncTree tree);
  AllianceApplicationListenMessage();

  bool listen;

private:
  void _listenFunc(Reader *input);
};

#endif // ALLIANCEAPPLICATIONLISTENMESSAGE_H