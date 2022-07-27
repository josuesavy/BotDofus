#ifndef HELLOCONNECTMESSAGE_H
#define HELLOCONNECTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class HelloConnectMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HelloConnectMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HelloConnectMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HelloConnectMessage(FuncTree tree);
  HelloConnectMessage();

  QString salt;
  QList<int> key;

private:
  void _saltFunc(Reader *input);
  void _keytreeFunc(Reader *input);
  void _keyFunc(Reader *input);

  FuncTree _keytree;
};

#endif // HELLOCONNECTMESSAGE_H